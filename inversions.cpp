//
//  main.cpp
//  Interview Prac
//
//  Created by Prajjwal Dangal on 1/30/17.
//  Copyright © 2017 Prajjwal Dangal. All rights reserved.
//

// Problem: 0-1 sequences
// Website: Kattis

#include <string.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>

// number of inversion problem
// 1?0?  -> [ 1000, 1001, 1100, 1101 ]
// 1000 -> 0001, 3
// 1001 -> 0011, 2
// 1100 -> 0011, 4
// 1101 -> 0111, 2


// ((node *) arr)[i]

void reverseStr(std::string &st) {
    int n = st.length();
    
    for (int i=0; i < n/2; i++) {
        std::swap(st[i], st[n-1-i]);
    }
}

std::string ConvToBin(int num, int bits) {
    int rem = 0;
    std::string inn;
    while (num > 0) {
        rem = num % 2;
        inn = inn + std::to_string(rem);
        num = num / 2;
    }
    
    reverseStr(inn);
    while (int n = inn.length() < bits) {
        inn = "0" + inn;
    }
    return inn;
}

void MakeCombs(std::string bits, std::vector <std::string> &combs) {
    std::vector <int> q_ind;
    for (int i=0; i < bits.length(); i++) {
        if (bits[i] == '?') {
            q_ind.push_back(i);
        }
    }
    int q_c = q_ind.size();
    int total = pow(2, q_c);
    std::string bin;
    for (int i=0; i < total; i++) {
        bin = ConvToBin(i, q_c); //
        for (int j=0; j < bin.length(); j++) {
            bits[q_ind[j]] = bin[j];
        }
        combs.push_back(bits);
    }
}

// 11??00?11  -->  (111100111)  -->

int n_inv (std::string bits) {
    int n = 0; // n is no. of inversions
    int zeros_so_far = 0;
    for (int i = 0; i < bits.length(); i++) {
        if (std::strncmp(&bits[i], "0", 1) == 0) {
            n = n + i - zeros_so_far;
            zeros_so_far ++;
        }
    }
    return n;
}

int main() {
    std::string bits;
    std::getline(std::cin, bits);
    std::vector <std::string> combs;
    MakeCombs(bits, combs);
    int total = 0;
    for (int i=0; i< combs.size(); i++) {
        total = total + n_inv(combs[i]);
        // std::cout << combs[i] << " : " << "(" << total << " , " << n_inv(combs[i]) << ")" << "\t";
    }
    std::cout << total % 1000000007 << std::endl;
    return 0;
}
