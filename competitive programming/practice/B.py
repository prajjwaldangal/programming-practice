#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Aug  3 12:31:50 2017

@author: root
"""
n_r = n_g = 0
n_b = 0
prev = ""

def check(arr):
    j = True
    global n_r, n_g, n_b, prev
    if arr[0] == 'R' != prev:
        n_r += 1
    elif arr[0] == 'G' != prev:
        n_g += 1
    elif arr[0] == 'B' != prev:
        n_b += 1
    prev = arr[0]
    for i in range(0, len(arr)-1):
        j = arr[i] == arr[i+1]
        if not j:
            return False
    return True

def foo():
    # global prev
    n, m = input().split(" ")
    n, m = int(n), int(m) 
    if n % 3 == 0:
        row = True
    elif m % 3 == 0:
        row = False
    else:
        print("NO")
        return

    arr = []
    for i in range(n):
        arr.append(input())
    # prev = arr[0][0]
        
    
    k = n
    if not row:
        arr = list(zip(*arr))
        k = m
    for i in range(k):
        if not check(arr[i]):
            print('NO')
            return
    if n_r == n_g == n_b == 1:
        print('YES')
    else:
        print('NO')
    return

foo()

