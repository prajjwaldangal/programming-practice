#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Aug  7 23:58:26 2017

@author: root
"""
# question: http://codeforces.com/contest/837/problem/C

def compatible(arr1, arr2, a, b):
    # l, m, n, o,
    l = arr1[0]
    m = arr1[1]
    n = arr2[0]
    o = arr2[1]
    # (2, 3) (9, 11)

    as_it_is = l + n <= a and m <= b and o <= b or m + o <= b and l <= a \
    and n <= a
    # rotate first
    l = arr1[1]
    m = arr1[0] # (3, 2), (9, 11)
    rot_first = l + n <= a and m <= b and o <= b or m + o <= b and l <= a \
    and n <= a
    #rotate second
    l = arr1[0]
    m = arr1[1]
    n = arr2[1]
    o = arr2[0] # 
    rot_sec = l + n <= a and m <= b and o <= b or m + o <= b and l <= a \
    and n <= a
    # rotate both
    l = arr1[1]
    m = arr1[0]
    n = arr2[1]
    o = arr2[0]
    rot_both = l + n <= a and m <= b and o <= b or m + o <= b and l <= a \
    and n <= a
    
    return as_it_is or rot_first or rot_sec or rot_both

def main():
    n, a, b = [int(num) for num in input().split(" ")]
    rects = []
    for i in range(n):
        x, y = [int(num) for num in input().split(" ")]
        rects.append([x, y])
    
    inds = []
    for i in range(0, len(rects)):
        inds.append([rects[i][0]*rects[i][1]+rects[j][0]*rects[j][1]
        for j in range(i+1, len(rects)) if compatible(rects[i], rects[j],a,b)])
    
    # print("Inds: ", inds)
    m = 0
    for ind in inds:
        for more in ind:
            if more > m:
                m = more
            
    print(m)
    
if __name__ == "__main__":
    main()

#==============================================================================
# 
# a <= a1 and b <= b1 or a <= b1 and b <= a1
# a' <= a1 and b' <= b1 or a' <= b1 and b' <= a1
# 
# 
# 
# # both compatible as they are
# as_it_is = a+a'<=a1 and b<=b1 and b'<=b1 or b+b'<=b1 and a<=a1 and a'<=a1
# rot_first = b+a'<=a1 and a<=b1 and b'<=b1
# rot_sec = a+b'<=a1 and b<=b1 and a'<=b1
# rot_both = b+b'***sth out of nothing (ignore)*** <=a1 and a<=b1 and a'<=b1
# 
#==============================================================================