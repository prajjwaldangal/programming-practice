#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Aug  7 23:58:26 2017

@author: root
"""
# question: http://codeforces.com/contest/837/problem/C


def compatible(arr1, arr2, a, b): 
    as_it_is=(arr1[0]+arr2[0]<=a and arr1[1]<=b and arr2[1]<=b) or (
            arr1[1]+arr2[1]<=b and arr1[0]<=a and arr2[0]<=a)
    rot_first = (arr1[1]+arr2[0]<=a and arr1[0]<=b and arr2[1]<=b) or (
            arr1[0]+arr2[1]<=b and arr1[1]<=a and arr2[0]<=a)
    rot_sec = (arr1[0]+arr2[1]<=a and arr1[1]<=b and arr2[0]<=b) or (
            arr1[1]+arr2[0]<=b and arr1[1]<=a and arr2[0]<=a)
    rot_both = (arr1[0]+arr2[0]<=b and arr1[1]<=a and arr2[1]<=a) or (
            arr1[1]+arr2[1]<=a and arr1[0]<=b and arr2[0]<=b)
    return as_it_is or rot_first or rot_sec or rot_both

def main():
    n, a, b = [int(num) for num in input().split(" ")]
    # print(n, a, b)
    rects = []
    for i in range(n):
        x, y = [int(num) for num in input().split(" ")]
        rects.append([x, y])
    # print("Rects: ", rects)
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
# # you don't like to be not chosen
# a <= a1 and b <= b1 or a <= b1 and b <= a1
# a' <= a1 and b' <= b1 or a' <= b1 and b' <= a1
# 
# # be crazy, be unreasonable mostly with yourself
# 
# # both compatible as they are
# as_it_is = a+a'<=a1 and b<=b1 and b'<=b1 or b+b'<=b1 and a<=a1 and a'<=a1
# rot_first = b+a'<=a1 and a<=b1 and b'<=b1
# rot_sec = a+b'<=a1 and b<=b1 and a'<=b1
# rot_both = b+b'***sth out of nothing (ignore)*** <=a1 and a<=b1 and a'<=b1
# 
#==============================================================================