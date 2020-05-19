#include "main.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define pi 3.1415

double area_t(double a, double b, double c, double p)
{
    if ((a <= 0) || (b <= 0) || (c <= 0)) {
        return -2;
    }
    p = p / 2;
    double S = ((p * (p - a) * (p - b) * (p - c)));
    S = sqrt(S);
    return S;
}

double perimeter_t(double a, double b, double c)
{
    if ((a <= 0) || (b <= 0) || (c <= 0)) {
        return -2;
    }
    return (a + b + c);
}

double area(int r)
{
    if (r <= 0) {
        return -2;
    }
    return (pi * r * r);
}

double perimeter(int r)
{
    if (r <= 0)
        return -2;
    return (2 * pi * r);
}

int check_to_existence_t(double a, double b, double c)
{
    if ((a <= 0) || (b <= 0) || (c <= 0)) {
        return -2;
    }
    if ((a + b > c) && (a + c > b) && (b + c > a))
        return 0;
    else
        printf("Треугольник со сторонами a=%f, b=%f, c=%f не существует\n",
               a,
               b,
               c);
    return 1;
}

int choose()
{
    char str[30];
    do {
        printf("Напишите какую фигуру вы хотите использовать: "
               "triangle/circle\n");
        scanf("%s", str);
    } while (((strcmp(str, "triangle")) != 0)
             && ((strcmp(str, "circle")) != 0));
    if ((strcmp(str, "triangle")) == 0)
        return 1;
    if ((strcmp(str, "circle")) == 0)
        return 2;
    return -1;
}

int print(int* kol, int ch)
{
    do {
        if (ch == 2) {
            printf("Введите количество окружностей(не более 999) ");
        }
        if (ch == 1) {
            printf("Введите количество треугольников(не более 999) ");
        }
        scanf("%d", kol);
    } while (*kol >= 1000);
    return *kol;
}

void verification_t(int kol)
{
    Triangle t[kol];
    char* y;
    char* token;
    for (int i = 0; i < kol; i++) {
        printf("Введите треугольники следующим образом Triangle(a,b,c) ");
        scanf("%s", t[i].str);
    }
    for (int i = 0; i < kol; i++) {
        if (strstr(t[i].str, ")") == NULL) {
            printf("#%d Invalid input\n", i);
        }
    }
    for (int i = 0; i < kol; i++) {
        int u = 1;
        token = strtok(t[i].str, "(,)");
        while (token != NULL) {
            if (u % 4 == 0) {
                y = token;
                t[i].c = strtod(token, &y);
                if (strlen(y) != 0) {
                    printf("#%d Invalid input\n", i);
                }
                if (t[i].c == 0) {
                    printf("#%d Invalid input y\n", i);
                }
            } else if (u % 3 == 0) {
                y = token;
                t[i].b = strtod(token, &y);
                if (strlen(y) != 0) {
                    printf("#%d Invalid input\n", i);
                }
                if (t[i].b == 0) {
                    printf("#%d Invalid input x\n", i);
                }
            } else if (u % 2 == 0) {
                t[i].a = strtod(token, &y);
                if (strlen(y) != 0) {
                    printf("#%d Invalid input\n", i);
                    exit(1);
                }
            } else {
                strcpy(t[i].name, token);
            }
            u++;
            token = strtok(NULL, "(,)");
        }
    }
    Print_Triangle(kol, t);
}

void Print_Triangle(int kol, Triangle* t)
{
    for (int i = 0; i < kol; i++) {
        if (strcmp(t[i].name, "Triangle") == 0) {
            if ((t[i].a > 0) && (t[i].c > 0) && (t[i].b > 0)) {
                if (check_to_existence_t(t[i].a, t[i].b, t[i].c) == 0) {
                    double S, P;
                    P = perimeter_t(t[i].a, t[i].b, t[i].c);
                    S = area_t(t[i].a, t[i].c, t[i].b, P);
                    printf("Треугольник %s номер %d : a=%f,b=%f,c=%f, S = %f, "
                           "P = %f\n",
                           t[i].name,
                           i,
                           t[i].a,
                           t[i].b,
                           t[i].c,
                           S,
                           P);
                } else {
                    printf("#%d invalid Triangle\n", i);
                }
            } else {
                printf("Unknown name %s\n", t[i].name);
            }
        }
    }
}

void verification_c(int kol)
{
    Circle c[kol];
    char* token;
    char* y;
    for (int i = 0; i < kol; i++) {
        printf("Введите окружности следующим образом Circle(r,x,y) ");
        scanf("%s", c[i].str);
    }
    for (int i = 0; i < kol; i++) {
        if (strstr(c[i].str, ")") == NULL) {
            printf("#%d Invalid input\n", i);
        }
    }
    for (int i = 0; i < kol; i++) {
        int u = 1;
        token = strtok(c[i].str, "(,)");
        while (token != NULL) {
            if (u % 4 == 0) {
                y = token;
                c[i].y = strtod(token, &y);
                if (strlen(y) != 0) {
                    printf("#%d Invalid input\n", i);
                }
                if (c[i].y == 0) {
                    printf("#%d Invalid input y\n", i);
                }
            } else if (u % 3 == 0) {
                y = token;
                c[i].x = strtod(token, &y);
                if (strlen(y) != 0) {
                    printf("#%d Invalid input\n", i);
                }
                if (c[i].x == 0) {
                    printf("#%d Invalid input x\n", i);
                }
            } else if (u % 2 == 0) {
                c[i].r = strtod(token, &y);
                if (strlen(y) != 0) {
                    printf("#%d Invalid input\n", i);
                    exit(1);
                }
            } else {
                strcpy(c[i].name, token);
            }
            u++;
            token = strtok(NULL, "(,)");
        }
    }
    Print_Circle(kol, c);
}

void intersects(int amount, int i, Circle* c)
{
    int j;
    printf("\tIntersects:\n");
    for (j = 0; j < amount; j++) {
        if (i != j) {
            if ((abs(sqrt(pow(c[i].x - c[j].x, 2) + pow(c[i].y - c[j].y, 2))))
                <= (c[i].r + c[j].r)) {
                printf("\t  %d. circle\n", j + 1);
            }
        }
    }
}

void Print_Circle(int kol, Circle* c)
{
    for (int i = 0; i < kol; i++) {
        if (strcmp(c[i].name, "Circle") == 0) {
            if (c[i].r > 0) {
                double S, P;
                S = area(c[i].r);
                P = perimeter(c[i].r);
                printf("Окружность %s номер %d : x=%f,y=%f,r=%f, S = %f, P = "
                       "%f\n",
                       c[i].name,
                       i + 1,
                       c[i].x,
                       c[i].y,
                       c[i].r,
                       S,
                       P);
                intersects(kol, i, c);
            } else {
                printf("#%d invalid Circle\n", i);
            }
        } else {
            printf("Unknown name %s\n", c[i].name);
        }
    }
}
