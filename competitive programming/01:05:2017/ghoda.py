# https://open.kattis.com/contests/vsxfjc/problems/hidingplaces
from collections import defaultdict

n = int(input())
graph = defaultdict(list)
m = {'a':1, 'b':2, 'c':3, 'd':4, 'e':5, 'f':6, 'g':7, 'h':8}

def get_positions(pos):
	l = []
	u_l1 = (pos[0]-1, pos[1]+2) # 0-><1, 1->>8
	if not u_ll[0] < 1 and not u_l1[1] > 8:
		l.append(u_ll)
	else:
		l.append((-1,-1))
	
	u_ls = (pos[0]-2, pos[1]+1) # 0-><1, 1->>8 
	if not u_ls[0] < 1 and not u_ls[1] > 8:
		l.append(u_ls)
	else:
		l.append((-1,-1))
	
	u_rl = (pos[0]+1, pos[1]+2) # 0>8, 1>8	
	if not u_rl[0] > 8 and not u_rl[1] > 8:
		l.append(u_rl)
	else:
		l.append((-1,-1))
	
	u_rs = (pos[0]+2, pos[1]+1) # 0>8, 1>8
	if not u_rs[0] > 8 and not u_rs[1] > 8:
		l.append(u_rs)
	else:
		l.append((-1,-1))
	
	l_ll = (pos[0]-1, pos[1]-2) # 0<1, 1<1
	if not l_ll[0] < 1 and not l_ll[1] < 1:
		l.append(l_ll)
	else:
		l.append((-1,-1))
	
	l_ls = (pos[0]-2, pos[1]-1) # 0<1, 1<1
	if not l_ls[0] < 1 and not l_ls[1] < 1:
		l.append(l_ls)
	else:
		l.append((-1,-1))
	
	l_rl = (pos[0]+1, pos[1]-2) # 0>8, 1<1
	if not l_rl[0] > 8 and not l_rl[1] < 1:
		l.append(l_rl)
	else:
		l.append((-1,-1))
	
	l_rs = (pos[0]+2, pos[1]-1) # 0>8, 1<1
	if not l_rs[0] > 8 and not l_rs[1] < 1:
		l.append(l_rs)
	else:
		l.append((-1,-1))
	# [ull, uls, url, urs, lll, lls, lrl, lrs]
	return l

# { 'd5' : ['b4', 'c3', 'f4', 'e3', 'c7', 'b6', 'e7', 'f6'],
#   'b4' : ['a6', 'd5', 'd3', 'c2', 'a2', ' 
#

for i in range(n):
	pos = input()
	# d5 -> 4,5
	pos = (m[pos[0]], int(pos[1]))
	# fill 0, disregard while parsing list
	# upper left two, lower left two
	# upper right two, lower right two
	# b4:
	# [[u_ll, u_ls], [l_ls, l_ls],
	#  [u_rl, u_rs], [l_rl, l_rs]]
	
	l = get_positions(pos)
	graph[pos] = l
	for el in l:

