import numpy as np
import requests
from functools import reduce

##### activation function: sigmoid
##### cost function: 1 / 2 * (correct - predicted)^2
## for delta calculation check: https://en.wikipedia.org/wiki/Delta_rule

word_site = "http://svnweb.freebsd.org/csrg/share/dict/words?view=co&content-type=text/plain"

NUM_HIDDEN_LAYERS = 8
def nonlin(x, deriv=False):
    if (deriv==True):
        return (x*(1-x))

    return 1/(1+np.exp(-x))

max_len = 0
response = requests.get(word_site)
WORDS = response.content.splitlines()
WORDS2 = [word.decode('utf-8').lower() for word in WORDS]

f = open('file.txt', 'w')
for word in WORDS2:
	w = str(word)
	f.write(w+" ")
f.close()

l = len(WORDS2)
for word in WORDS2:
    if len(word) > max_len:
        max_len = len(word)
x_new = np.empty([l, max_len])
y_new = np.empty([l, max_len])
# ascii array method
i = 0
for ind, word in enumerate(WORDS2):
    in_arr = np.zeros([1, max_len])
    for ind2, let in enumerate(word):
        # np.insert()  -->  axis:  0 -> x, 1 -> y
        in_arr = np.insert(in_arr, ind2, ord(let))
        in_arr = np.delete(in_arr, ind2+1)
    if i < 20:
        print (word)
    i+=1
    x_new = np.insert(x_new, ind, in_arr, 0)
    x_new = np.delete(x_new, ind+1, 0)
    y_new = np.insert(y_new, ind, in_arr[::-1], 0)
    y_new = np.delete(y_new, ind+1, 0)

print("X_new: , Y new: ", x_new, y_new)

# each of the input (in x) is mapped to one member in y

# seed is good for debugging, makes sure we start at
# the same time
np.random.seed(1)
sig = 0.7 # ratio between layers sort of

# synapses (or connections)
syn0 = 2 * np.random.random((max_len, int(max_len*sig)))   # -> extends 1x3 to 1x4 as per node basis; meaning? idk
syn1 = 2 * np.random.random((int(max_len*sig), int(max_len/sig)))
syn2 = 2 * np.random.random((int(max_len/sig), int(max_len*sig)))
synn = 2 * np.random.random((int(max_len*sig),max_len))     # this is going to be


def predict(word):
    x = np.empty((1, max_len))
    for ind, let in enumerate(word):
        x = np.insert(x, ind, ord(let))
        x = np.delete(x, ind+1)
    l0 = x # 1 x max_len
    l1 = nonlin(np.dot(l0, syn0)) # 1 x max_len . max_len x msm   ,  msg = max_len * sig
    l2 = nonlin(np.dot(l1, syn1)) # 1 x msm . msm x msd   ,   msd = max_len / sig
    l3 = nonlin(np.dot(l2, syn2)) # 1 x msd . msd x msm
    l4 = nonlin(np.dot(l3, synn)) # 1 x msm . msm x max_len
    # st = ""
    # for i in range(0, len(l2)):
    # 	if l2[i] < int(l2[i]) + 0.5:
    # 		st += chr(int(l2[i]))
    # 	else:
    # 		st += chr(int(l2[i]) + 1)
    return l2

def ret_word(arr):
    st = ""
    for el in arr:
        st += chr(int(el))
    return st

# training
i = 0
for j in range(0, len(WORDS2)):
    x = x_new[j] # 1 x max_len
    x = x.reshape(1, max_len)
    y = y_new[j] #
    y = y.reshape(1, max_len)
    # print("X is: ", ret_word(x))
    # layers
    l0 = x # 1 x max_len
    l1 = nonlin(np.dot(l0, syn0)) # 1 x max_len . max_len x msm   ,  msg = max_len * sig
    l2 = nonlin(np.dot(l1, syn1)) # 1 x msm . msm x msd   ,   msd = max_len / sig
    l3 = nonlin(np.dot(l2, syn2)) # 1 x msd . msd x msm
    l4 = nonlin(np.dot(l3, synn)) # 1 x msm . msm x max_len

    #backpropagation
    # l2_error = y - l2 # 1 x max_len, prev. also list
    l4_error = y - l4
    # if j % 100 == 0:
        # print("Error: " + str(np.mean(np.abs(l2_error))))

    # calculate deltas
    l4_delta = l4_error * nonlin(l4, deriv=True)
    l3_error = l4_delta.dot(synn.T)

    l3_delta = l3_error * nonlin(l3, deriv=True)
    l2_error = l3_delta.dot(syn2.T)

    l2_delta = l2_error * nonlin(l2, deriv=True)
    l1_error = l2_delta.dot(syn1.T)

    l1_delta = l1_error * nonlin(l1, deriv=True)

    #update synapses
    synn += l3.T.dot(l4_delta)
    syn2 += l2.T.dot(l3_delta)
    syn1 += l1.T.dot(l2_delta) # 10 x max_len (dim consistent)
    syn0 += l0.T.dot(l1_delta) # max_len x 10 (dim consitent)

    print("Shape of l4 error: {0}\nShape of deriv term{1}".format(l4_error.shape, nonlin(l4, deriv=True).shape))
    print("Shape of l3 error: {0}\nShape of deriv term{1}".format(l3_error.shape, nonlin(l3, deriv=True).shape))
    print("Shape of l2 error: {0}\nShape of deriv term{1}".format(l2_error.shape, nonlin(l2, deriv=True).shape))
    print("Shape of l1 error: {0}\nShape of deriv term{1}".format(l1_error.shape, nonlin(l1, deriv=True).shape))

    # l2_delta = l2_error * nonlin(l2, deriv=True) # 1 x max_len (pointwise mult)
    #
    # l1_error = l2_delta.dot(syn1.T) # 1 x 10
    #
    # l1_delta = l1_error * nonlin(l1, deriv=True) # 1 x 10


# print('Output after training')
# print (l2)
print("synn: {}\nsyn2: {}\nsyn1: {}\n".format(synn, syn2, syn1))
print("\n\nPrediction\n")
[print (predict(word)) for word in ["thisshouldnotbe", "inthetraining", "samplecoz", "thisjustasentence"]]

