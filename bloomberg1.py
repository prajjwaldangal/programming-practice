#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Nov 14 17:07:24 2017

@author: root
"""

# glove 1, glov2 -> apple, elppa


    
# only lowercase, duplicates also

def Pal(st):
    n = len(st)
    
    # 5 -> 0,4  1,3  2,3
    # 6 -> 0,6  1,5  2,4  3,3
    # apple
    #  a==e, p==l, p
    # banana
    # b==a, a==n, n==a
    for i in range(int(n/2)):
        if st[i] != st[n-1-i]:
            return False
    return True
        
        
n = int(input())

S = []
for i in range(n):
    S[i] = input()
    
d = {}
for i in range(n):
    if !Pal(S[i]):
        if d.get(S[i][::-1], ""):
            
        