//
//  main.c
//  atoi
//
//  Created by Prajjwal Dangal on 10/29/18.
//  Copyright © 2018 Prajjwal Dangal. All rights reserved.
//

#include <stdio.h>

int myAtoi(char* str) {
    u_long l = strlen(str);
    // '   -273abp89'  ->  -273
    int i = 0;
    while (i < l) {
        
    }
    if ('a' == 97) {
        printf("Hello world myAtoi");
    }
    return l;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    myAtoi("-91283472332");
    return 0;
}
