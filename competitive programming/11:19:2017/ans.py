#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Nov 19 09:10:28 2017

@author: root
"""

# http://codeforces.com/contest/894/problem/0

# By lines we mean rows. In each row and column the product 
# should be equal to k.

#for i in range(10):
#    inp = input()
#
#    q = qa= qaq = 0
## ut = 0
#    for let in inp:
#        if let == 'Q':
#            q += 1
#    
#        if q > 0 and let=='A':
#            qa += q
#        
#        if qa > 0 and let=='Q':
#            qaq += qa
#    #print(q, qa, qaq)
#    
#        print(qaq)

        
        # qaqaqysiaq

n,m, k = [int(inp) for inp in input().split(" ")]

ans = 0

mat = [[0 for i in range(m)] for j in range(n)]
[print (row) for row in mat]

# prod row and col = 1 or -1

print(ans %1000000007)

    
    