#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Oct 19 22:55:59 2017

@author: root
"""
# http://codeforces.com/contest/875/problem/C

n, m = [int(el) for el in input().split(" ")]
# n -> no. of words
# m - 1 -> no. of letters (in  the Alphabet)

words = []
for i in range(n):
    letts = input().split(" ")[1:]
    tmp = []
    for let in letts:
        tmp.append(int(let))
        
    words.append(tmp)
    
# compared to next in line, ~lex
# choose one let -> change in all occurences
    
# optimization : 
#  1. could keep word len and index into it

# 3' < 2, 2'<3', 2'<3
# where differ, first's let < second's let
# or first is prefix of second


# output:
# yes / no after capitalization of 0 or more let 
#  no. of letts to subti, what are those

def foo(words):
    
    return sth
    
