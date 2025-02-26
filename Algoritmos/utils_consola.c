#include <stdio.h>
#include "utils_consola.h"

int getline(char line[], int lim){
    int c, i;
    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n'){
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
}