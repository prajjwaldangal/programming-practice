# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

# https://icpcarchive.ecs.baylor.edu/external/76/7697.pdf


from collections import defaultdict
def find_max_p(x_ys):
    seen_x = defaultdict(list)
    seen_y = defaultdict(list)
    for xy in x_ys:
        seen_x[xy[0]].append(xy[1])
        seen_y[xy[1]].append(xy[0])
        
    

n = int(input())
x_ys = []
for i in range(n):
    x, y  = [int(a) for a in input().split(" ")]
    x_ys.append([x, y])
    
find_max_p(x_ys)