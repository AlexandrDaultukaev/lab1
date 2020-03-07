#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    double r;
    double x;
    double y;
    char name[50];
    char str[80];
} Circle;

int main()
{
    int kol;
    char* token;
    char* y;
    printf("Введите количество окружностей ");
    scanf("%d", &kol);
    Circle c[kol];
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
                if (c[i].y == 0) {
                    printf("Invalid input y\n");
                }
            } else if (u % 3 == 0) {
                y = token;
                c[i].x = strtod(token, &y);
                if (c[i].x == 0) {
                    printf("Invalid input x\n");
                }
            } else if (u % 2 == 0) {
                c[i].r = atof(token);
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
                printf("Окружность %s номер %d : x=%f,y=%f,r=%f\n",
                       c[i].name,
                       i,
                       c[i].x,
                       c[i].y,
                       c[i].r);
            } else {
                printf("invalid Circle\n");
            }
        } else {
            printf("Unknown name %s\n", c[i].name);
        }
    }
    return 0;
}
