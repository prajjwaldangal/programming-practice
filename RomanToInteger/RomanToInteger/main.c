//
//  main.c
//  RomanToInteger
//
//  Created by Prajjwal Dangal on 6/15/18.
//  Copyright © 2018 Prajjwal Dangal. All rights reserved.
//


#include <stdio.h>
#include <string.h>

int indexof(char c) {
    //char * s = malloc(sizeof(char) * 7);
    char s[8] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    //char s[8] = {"I", "V", "X", "L", "C", "D", "M"};
    for (int i=0; i<7; i++) {
        if (s[i] == c) {
            return i;
        }
    }
    return 7;
}

int val(char c) {
    if (c == 'I')
        return 1;
    else if (c == 'V')
        return 5;
    else if (c == 'X')
        return 10;
    else if (c == 'L')
        return 50;
    else if (c == 'C')
        return 100;
    else if (c=='D')
        return 500;
    else if (c=='M')
        return 1000;
    else
        return -1;
}



// This function calls indexof function to get
//      the index of roman digits in ascending sequence
//      like X's sequence is 2 (0 index) and C's is 4 and so on.
// It also calls val() to get the value of each
//      roman digit like I is 1, V is 5.
int romanToInt(char* s) {
    int n = 0;
    char curr;
    int i_p;
    int i_c;
    char prev = 'r'; // r for random char other than roman chars
    int len_s = 0;
    while (s[len_s] != '\0') {
        len_s  += 1;
    }
    for (int i=0; i<len_s; i++) {
        curr = s[i];
        i_p = indexof(prev);
        i_c = indexof(curr);
        if (i_p < i_c) {
            n -= val(prev);
            n += val(s[i])-val(prev);
            prev = 'r';
        } else {
            n += val(s[i]);
            //n += val(s[i]);M
            // Zayetiang
            prev = s[i];
        }
        // get rid of repetition
    }
    //n += val(prev);
    return n;
}

int main() {
    char a[5][14];
    strcpy(a[0], "III");
    strcpy(a[1], "XVII");
    strcpy(a[2], "MCMXCIV");
    strcpy(a[3], "LVIII");
    strcpy(a[4], "IX");
    for (int i=0; i<5; i++) {
        printf("%s\n", a[i]);
        printf("Integer repr is: %d\n\n", romanToInt(a[i]));
    }
    //printf("Index of that is: %d\n", indexof('\0'));2
}
