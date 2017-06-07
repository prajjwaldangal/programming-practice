import numpy as np
import requests

word_site = "http://svnweb.freebsd.org/csrg/share/dict/words?view=co&content-type=text/plain"

def nonlin(x, deriv=False):
	if (deriv==True):
		return (x*(1-x))

	return 1/(1+np.exp(-x))

max_len = 0
response = requests.get(word_site)
WORDS = response.content.splitlines()
WORDS2 = [word.decode('utf-8').lower() for word in WORDS[:2000]]
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
	y_new = np.insert(y_new, ind, in_arr[::-1], 0)

print("X_new: , Y new: ", x_new, y_new)


x = np.array([[0, 0, 1],    # could view [_,_,_,_] as the vocabulary matrix?
				[0, 1, 1],
				[1, 0, 1],
				[1, 1, 1]])

y = np.array([[0], 
			 [1],
			 [1], 
			 [0]])


# each of the input (in x) is mapped to one member in y

# seed is good for debugging, makes sure we start at
# the same time
np.random.seed(1)

# synapses (or connections)
syn0 = 2 * np.random.random((3,4)) - 1  # -> extends 1x3 to 1x4 as per node basis; meaning? idk
syn1 = 2 * np.random.random((4,1)) - 1      # this is going to be 

# training
for j in range(0, 60000):

	#layers
	l0 = x
	l1 = nonlin(np.dot(l0, syn0))
	l2 = nonlin(np.dot(l1, syn1))

	#backpropagation
	l2_error = y - l2
	if j % 10000 == 0:
		print("Error: " + str(np.mean(np.abs(l2_error))))

	# calculate deltas
	l2_delta = l2_error * nonlin(l2, deriv=True)

	l1_error = l2_delta.dot(syn1.T)

	l1_delta = l1_error * nonlin(l1, deriv=True)

	#update synapses
	syn1 += l1.T.dot(l2_delta)
	syn0 += l0.T.dot(l1_delta)

print('Output after training')
print (l2)

'''
	1  2  3
	2  3  4
	3  4  5

	make full_input_handle_module
		 full_layers_dimensions_handle_module
'''

















