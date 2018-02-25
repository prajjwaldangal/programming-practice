#x is the number of yellow balls, y is the number of green balls, z is the number of blue balls needed.
#y is the number of green balls

'''
yel, b = [int(el) for el in input().split(' ')]
x, y, z = [int(ball) for ball in input().split(' ')]

yel_req = x * 2 + y * 1
b_req = y * 1 + z * 3

yel_req = max(0, yel_req-yel)
b_req = max(0, b_req-b)
print(yel_req+b_req)
'''


'''
# http://codeforces.com/contest/913/problem/0
n = int(input())
m = int(input())

print(m % 2**n)
'''

from collections import defaultdict
import sys

# http://codeforces.com/contest/913/problem/B
n = int(input())
# every vertex except the root has a unique parent

arr = []
for i in range(n-1):
	arr.append(int(input()))

d = defaultdict(list)
i = 1
for el in arr:
	i += 1
	j = d.get(el)
	if j == []:
		d[el] = [i]
	else:
		d[el].append(i)
# {1: [2,3,4], 2:[5,6,7]}

#print(d)
for par in d:
	in_root = 0
	for el in d[par]:
		j = d.get(el)
		if j:
			in_root += 1
	#print("parent: {0}, n_chdrn: {1}, n_in_root: {2}".format(par, len(d[par]), in_root))
	if len(d[par]) - in_root < 3:
		print("No")
		sys.exit()
print("Yes")



