#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov 30 16:44:04 2017

@author: root
"""

# http://codeforces.com/contest/895/problem/A

n = int(input())
a = [int(num) for num in input().split(" ")]

# 100 20 40 100 100
vas = 0
pet = 0
mini = 0
for i in range(n):
    vas += a[i]
    pet += sum(a[i+1:])
    mini = abs(vas-pet)