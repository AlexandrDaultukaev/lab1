#ifndef H_MAIN
#define H_MAIN

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct {
    double r;
    double x;
    double y;
    char name[50];
    char str[80];
} Circle;

int print(int* kol);
void verification (int kol);

#endif