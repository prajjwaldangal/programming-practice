#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Aug  3 11:18:58 2017

@author: root
"""
n = int(input())
st = input()
c = 0
m = n
for let in st:
    if let.upper() == let != " ":
        c += 1
    if let == " " and c < m:
        m = c
        c = 0
print(m)

'''
Problem B. Flag of Berland
----------

Each line should have **exactly one color**, 
each color should be used in **exactly one** line.
'''

'''
Problem B. Flag of Berland
----------

In this problem line==stripe, 
i.e. rectangular block of the same color.
'''