#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Aug 20 11:03:55 2017

@author: root
"""
def sol():
	n = int(input())
	ints = [int(num) for num in input().split(" ")]
	for num in ints:
		if num % 2 == 1:
			print("First")
			return

	print("Second")
	return


def SOS():
	pass

if __name__=="__main__":
	sol()