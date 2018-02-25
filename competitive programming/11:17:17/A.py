#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Nov 17 09:34:11 2017

@author: root
"""
"""
def top_two(a, b, n):
    sec = 0
    fir = 0
    for i in range(n):
        if b[i] > sec and b[i] < fir:
            sec = b[i]
        elif b[i] > sec and b[i] > fir:
            sec = fir
            fir = b[i]
    return [sec, fir]

def main():
    n = int(input())
    a = [int(el) for el in input().split(" ")]
    b = [int (el) for el in input().split(" ")]
    max_sum = sum(top_two(a, b, n))
    rem = sum(a)
    if max_sum >= rem:
        print("YES")
    else:
        print("NO")
        
if __name__ == "__main__":
    main()
"""
# E: the given graph is guaranteed to be connected.

def cond(one, two):
    if one >= two:
        return True
    else:
        return False

def main():
    n = int(input())
    L = [int(el) for el in input().split(" ")]
    j = n-2
    i = n-1
    while j >= 0:
        if j >= i-L[i]:
            
        j -= 1
    
    # i = 3, Li = 10
    # j = 2, 2 < 3, 2 >= 3-10 -> 2 >= -7


    
