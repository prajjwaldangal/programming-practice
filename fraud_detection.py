# -*- coding: utf-8 -*-
"""
Created on Wed Jun 28 21:18:17 2017

@author: prajjwaldangal
"""

import pandas as pd
import numpy as np 
# import tensorflow as tf
from sklearn.cross_validation import train_test_split
import matplotlib.pyplot as plt
from sklearn.utils import shuffle
from sklearn.metrics import confusion_matrix
import seaborn as sns
import matplotlib.gridspec as gridspec
from sklearn.preprocessing import StandardScaler
from sklearn.manifold import TSNE

# 1. read data
df = pd.read_csv("~/Downloads/creditcard.csv")

# 2. describe variables' stats, like based on Time, amount
#==============================================================================
# print ("Fraud-time stats:")
# print (df.Time[df.Class == 1].describe())
# print()
# print("Not fraud-time stats:")
# print(df.Time[df.Class == 0].describe())
# 
# print()
# print()
# 
# print("Fraud-V1 stats:")
# print(df.V1[df.Class == 1].describe())
# print()
# print("Not Fraud - V1 stats:")
# print(df.V1[df.Class == 0].describe())
# 
# print()
# print()
# 
# print("Fraud-amount stats:")
# print(df.Amount[df.Class==1].describe())
# print()
# print("Not fraud - amount stats:")
# print(df.Amount[df.Class==0].describe())
# 
#==============================================================================


# generate histogram

#==============================================================================
# f, (ax1, ax2) = plt.subplots(2, 1, figsize=(12,4))
# 
# bins = 50
# 
# ax1.hist(df.Time[df.Class == 1], bins = bins)
# ax1.set_title('Fraud')
# 
# ax2.hist(df.Time[df.Class == 0], bins = bins)
# ax2.set_title('Normal')
# 
# plt.xlabel('Time (in Seconds)')
# plt.ylabel('Number of Transactions')
# plt.show()
# 
# f, (ax3, ax4, _, _) = plt.subplots(4,1, figsize=(12,4))
# bins = 30
# ax3.hist(df.Amount[df.Class == 1], bins = bins)
# ax3.set_title('Fraud-bin')
# 
# ax4.hist(df.Amount[df.Class == 0], bins = bins)
# ax4.set_title('Not Fraud')
# 
# plt.xlabel('Amount')
# plt.ylabel('Number of Transactions')
# plt.yscale('log')
# plt.show()
#==============================================================================

# scatter plot

# another type histogram
# v_features = df.ix[:, 1:29].columns
# plt.figure(figsize=(12,28*4))
# gs = gridspec.GridSpec(28, 1)
# for i, cn in enumerate(df[v_features]):
#     ax = plt.subplot(gs[i])
#     sns.distplot(df[cn][df.Class == 1], bins=50)
#     sns.distplot(df[cn][df.Class == 0], bins=50)
#     ax.set_xlabel('')
#     ax.set_title('histogram of feature: ' + str(cn))
# plt.show()
#==============================================================================

print("No. columns before: ", len(df.columns))
df = df.drop(['V28', 'V26', 'V24', 'V23',
'V22','V20','V15','V13','V8'], axis = 1)
print("No. columns after: ", len(df.columns))
df['V1_'] = df.V1.map(lambda x: 1 if x < -3 else 0)
df['V2_'] = df.V2.map(lambda x: 1 if x > 2.5 else 0)
df['V3_'] = df.V3.map(lambda x: 1 if x < -4 else 0)
df['V4_'] = df.V4.map(lambda x: 1 if x > 2.5 else 0)
df['V5_'] = df.V5.map(lambda x: 1 if x < -4.5 else 0)
df['V6_'] = df.V6.map(lambda x: 1 if x < -2.5 else 0)
df['V7_'] = df.V7.map(lambda x: 1 if x < -3 else 0)
df['V9_'] = df.V9.map(lambda x: 1 if x < -2 else 0)
df['V10_'] = df.V10.map(lambda x: 1 if x < -2.5 else 0)
df['V11_'] = df.V11.map(lambda x: 1 if x > 2 else 0)
df['V12_'] = df.V12.map(lambda x: 1 if x < -2 else 0)
df['V14_'] = df.V14.map(lambda x: 1 if x < -2.5 else 0)
df['V16_'] = df.V16.map(lambda x: 1 if x < -2 else 0)
df['V17_'] = df.V17.map(lambda x: 1 if x < -2 else 0)
df['V18_'] = df.V18.map(lambda x: 1 if x < -2 else 0)
df['V19_'] = df.V19.map(lambda x: 1 if x > 1.5 else 0)
df['V21_'] = df.V21.map(lambda x: 1 if x > 0.6 else 0)
# sources of err below (V25, V27):
df['V25_'] = df.V25.map(lambda x: 1 if x < -1.5 and x > 1.5 else 0)
df['V27_'] = df.V27.map(lambda x: 1 if x > 1 else 0)

df.loc[df.Class == 0, 'Normal'] = 1
df.loc[df.Class == 1, 'Normal'] = 0
df = df.rename(columns={'Class': 'Fraud'})
print(df.Normal.value_counts())
print()
print(df.Fraud.value_counts())

Fraud = df[df.Fraud == 1]
Normal = df[df.Normal == 1]

X_train = Fraud.sample(frac=0.8)
count_f = len(X_train)
X_train = pd.concat([X_train, Normal.sample(frac = 0.8)], axis = 0)
X_test = df.loc[~df.index.isin(X_train.index)]
X_train = shuffle(X_train)
X_test = shuffle(X_test)
y_train = X_train.Fraud
y_train = pd.concat([y_train, X_train.Normal], axis=1)

y_test = X_test.Fraud
y_test = pd.concat([y_test, X_test.Normal], axis=1)

X_train = X_train.drop(['Fraud','Normal'], axis = 1)
X_test = X_test.drop(['Fraud','Normal'], axis = 1)

ratio = len(X_train) / count_f
y_train.Fraud = y_train.Fraud * ratio
y_test.Fraud = y_test.Fraud * ratio

# in y: 124
print("X_train: {0}\n\nY_train: {1}".format(X_train, y_train))

# compare with and without err injunctions
#

#Names of all of the features in X_train.
features = X_train.columns.values

#Transform each feature in features so that it has a mean of 0 and standard deviation of 1; 
#this helps with training the neural network (a.k.a Normalizing)

for feature in features:
    mean, std = df[feature].mean(), df[feature].std()
    X_train.loc[:, feature] = (X_train[feature] - mean) / std
    X_test.loc[:, feature] = (X_test[feature] - mean) / std

split = int(len(y_test)/2)

inputX = X_train.as_matrix()
inputY = y_train.as_matrix()
inputX_valid = X_test.as_matrix()[:split]
inputY_valid = y_test.as_matrix()[:split]
inputX_test = X_test.as_matrix()[split:]
inputY_test = y_test.as_matrix()[split:]

# Number of input nodes.
input_nodes = 37

# Multiplier maintains a fixed ratio of nodes between each layer.
mulitplier = 1.5 

# Number of nodes in each hidden layer
hidden_nodes1 = 18
hidden_nodes2 = round(hidden_nodes1 * mulitplier)
hidden_nodes3 = round(hidden_nodes2 * mulitplier)

# Percent of nodes to keep during dropout.
pkeep = tf.placeholder(tf.float32)

# input
x = tf.placeholder(tf.float32, [None, input_nodes])

# layer 1
W1 = tf.Variable(tf.truncated_normal([input_nodes, hidden_nodes1], stddev = 0.15))
b1 = tf.Variable(tf.zeros([hidden_nodes1]))
y1 = tf.nn.sigmoid(tf.matmul(x, W1) + b1)

# layer 2
W2 = tf.Variable(tf.truncated_normal([hidden_nodes1, hidden_nodes2], stddev = 0.15))
b2 = tf.Variable(tf.zeros([hidden_nodes2]))
y2 = tf.nn.sigmoid(tf.matmul(y1, W2) + b2)

# layer 3
W3 = tf.Variable(tf.truncated_normal([hidden_nodes2, hidden_nodes3], stddev = 0.15)) 
b3 = tf.Variable(tf.zeros([hidden_nodes3]))
y3 = tf.nn.sigmoid(tf.matmul(y2, W3) + b3)
y3 = tf.nn.dropout(y3, pkeep)

# layer 4
W4 = tf.Variable(tf.truncated_normal([hidden_nodes3, 2], stddev = 0.15)) 
b4 = tf.Variable(tf.zeros([2]))
y4 = tf.nn.softmax(tf.matmul(y3, W4) + b4)

# output
y = y4
y_ = tf.placeholder(tf.float32, [None, 2])

# Hyper Parameters
training_epochs = 5 # should be 2000, it will timeout when uploading
training_dropout = 0.9
display_step = 1 # 10 
n_samples = y_train.shape[0]
batch_size = 2048
learning_rate = 0.005

# Cost function: Cross Entropy
cost = -tf.reduce_sum(y_ * tf.log(y))

# We will optimize our model via AdamOptimizer
optimizer = tf.train.AdamOptimizer(learning_rate).minimize(cost)

# Correct prediction if the most likely value (Fraud or Normal) from softmax equals the target value.
correct_prediction = tf.equal(tf.argmax(y,1), tf.argmax(y_,1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))

accuracy_summary = [] # Record accuracy values for plot
cost_summary = [] # Record cost values for plot
valid_accuracy_summary = [] 
valid_cost_summary = [] 
stop_early = 0 # To keep track of the number of epochs before early stopping

# Save the best weights so that they can be used to make the final predictions
#checkpoint = "location_on_your_computer/best_model.ckpt"
saver = tf.train.Saver(max_to_keep=1)

# Initialize variables and tensorflow session
with tf.Session() as sess:
    sess.run(tf.global_variables_initializer())
    
    for epoch in range(training_epochs): 
        for batch in range(int(n_samples/batch_size)):
            batch_x = inputX[batch*batch_size : (1+batch)*batch_size]
            batch_y = inputY[batch*batch_size : (1+batch)*batch_size]

            sess.run([optimizer], feed_dict={x: batch_x, 
                                             y_: batch_y,
                                             pkeep: training_dropout})

        # Display logs after every 10 epochs
        if (epoch) % display_step == 0:
            train_accuracy, newCost = sess.run([accuracy, cost], feed_dict={x: inputX, 
                                                                            y_: inputY,
                                                                            pkeep: training_dropout})

            valid_accuracy, valid_newCost = sess.run([accuracy, cost], feed_dict={x: inputX_valid, 
                                                                                  y_: inputY_valid,
                                                                                  pkeep: 1})

            print ("Epoch:", epoch,
                   "Acc =", "{:.5f}".format(train_accuracy), 
                   "Cost =", "{:.5f}".format(newCost),
                   "Valid_Acc =", "{:.5f}".format(valid_accuracy), 
                   "Valid_Cost = ", "{:.5f}".format(valid_newCost))
            
            # Save the weights if these conditions are met.
            #if epoch > 0 and valid_accuracy > max(valid_accuracy_summary) and valid_accuracy > 0.999:
            #    saver.save(sess, checkpoint)
            
            # Record the results of the model
            accuracy_summary.append(train_accuracy)
            cost_summary.append(newCost)
            valid_accuracy_summary.append(valid_accuracy)
            valid_cost_summary.append(valid_newCost)
            
            # If the model does not improve after 15 logs, stop the training.
            if valid_accuracy < max(valid_accuracy_summary) and epoch > 100:
                stop_early += 1
                if stop_early == 15:
                    break
            else:
                stop_early = 0
            
    print()
    print("Optimization Finished!")
    print()   