#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Dec 16 21:09:11 2017

@author: root
"""

"""
A.

n = int(input())

def foo(n):
    if n % 10 > 5:
        return int(n/10) * 10 + 10 
    else:
        return int(n/10) * 10

print(foo(n))
# print(foo(5), foo(113), foo(100000), foo(5432359))

"""

""""
B.
n = int(input())
a = int(input())

b = int(input())

def foo(n, a, b):
    i = 1
    while i <= n:
        j = (n - i * a) / b
        if j == int(j):
            return i, j
        i += 1
    return 0, 0
    

i, j = foo(n , a, b)
if i == j == 0:
    print("NO")
else:
    print("YES")
    print(i, int(j))
"""


# http://codeforces.com/contest/907/problem/A
#V = [int(el) for el in input().split(" ")]

# a <= b, lik -> 2a >= b
''' 
at j can kill at i, if i < j and i >= j - L[j]
min(j-L[j])   





'''