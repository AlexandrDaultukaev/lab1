#ifndef H_MAIN
#define H_MAIN

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
typedef struct {
    double r;
    double x;
    double y;
    char name[50];
    char str[80];
} Circle;

typedef struct {
    double a;
    double b;
    double c;
    char name[50];
    char str[80];
} Triangle;

int print(int* kol, int ch);
void verification_c(int kol);
void verification_t(int kol);
double area(int r);
double perimeter(int r);
int choose();
double area_t(double a, double b, double c, double p);
double perimeter_t(double a, double b, double c);
int check_to_existence_t(double a, double b, double c);

#endif