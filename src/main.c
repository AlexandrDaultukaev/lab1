#include "main.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int kol;
    // char* token
    // char* y;
    int ch = choose();
    kol = print(&kol, ch);
    if (ch == 2) {
        verification_c(kol);
    }
    if (ch == 1) {
        verification_t(kol);
    }

    return 0;
}
