//
//  main.c
//  advanced_C
//
//  Created by Prajjwal Dangal on 7/15/20.
//  Copyright © 2020 Prajjwal Dangal. All rights reserved.
//

// Playing around with C function pointers, array of function pointers etc.

#include <stdio.h>
#include <stdlib.h>

int *foo(int a, float b);
int baz(int, float);
int boz(int, float);

// a pointer to a function that returns int
int (*bar) (int a, float b);

// an array of pointers to functions that return long
long (*fparr[])(int, float);
long fparr0(int, float);
long fparr1(int, float);
int main() {
        printf("Known case:%d\n", *foo(2, 2.0));
        bar = baz;
        printf("Unknown case: %d\n", (*bar)(2, 2.0));

        printf("Array case [0]: %ld\n", fparr[0](2, 2.0));
        printf("Array case [1]: %ld\n", fparr[1](2, 2.0));

        return 0;
}
// function returning pointer to int
int *foo(int a, float b) {
        int * x = malloc(4);
        *x  = a + (int) b;
        return x;
}
int baz(int a, float b) {
        return a+b;
}

long fparr0(int a, float b) {
    return (long) a+b;
}

long fparr1(int a, float b) {
    return (long) a+b;
}

long (*fparr[])(int, float) = {
    fparr0, fparr1
};
