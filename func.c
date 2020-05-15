#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

#define pi 3.1415

double area(int r) {
    return (pi * r * r);
}

double perimeter(int r) {
    return (2 * pi * r);
}

int print(int* kol) {
	printf("Введите количество окружностей ");
    scanf("%d", kol);
    return *kol;
}

void verification (int kol) {
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
    for (int i = 0; i < kol; i++) {
        if (strcmp(c[i].name, "Circle") == 0) {
            if (c[i].r > 0) {
                double S, P;
                S = area(c[i].r);
                P = perimeter(c[i].r);
                printf("Окружность %s номер %d : x=%f,y=%f,r=%f, S = %f, P = %f\n",
                       c[i].name,
                       i,
                       c[i].x,
                       c[i].y,
                       c[i].r, S, P);
            } else {
                printf("#%d invalid Circle\n", i);
            }
        } else {
            printf("Unknown name %s\n", c[i].name);
        }
    }
}