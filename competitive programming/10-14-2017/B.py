#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Oct 16 22:56:25 2017

@author: root
"""

# http://codeforces.com/contest/875/problem/B
n = int(input())
li = [int(el) for el in input().split(" ")]


def bubblesort( A ):
  for i in range( len( A ) ):
    for k in range( len( A ) - 1, i, -1 ):
      if ( A[k] < A[k - 1] ):
        swap( A, k, k - 1 )
 
def swap( A, x, y ):
  tmp = A[x]
  A[x] = A[y]
  A[y] = tmp
  
# 2, 3, 4, 1, 0 -> 3, 2, 4, 1, 0->3,4,2,1,0

# XX0XX->X0XXX
# n=6
#  0X0XX0
#  at the start of each iteration looks like following:
#  0X0XX0->00XX0X->00X0XX->000XXX

# # software to extract signs from video -> image data
# putting image data on the cloud
