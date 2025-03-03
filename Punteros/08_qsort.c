#include <stdio.h>
#include <string.h>
#include "utils_memoria.h"
#include "utils_consola.h"
#include "utils_algoritmos.h"

#define MAXLINES 5000
char *lineptr[MAXLINES];

int main(int argc, char *argv[]){

    int nlines;
    int numeric = 0;

    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
        //if (numeric)
            qsortGen(lineptr, 0, nlines-1, (int (*)(void *, void *))(numeric?numcmp:mystrcmp));
        //else
            //qsort(lineptr, 0, nlines-1, (int (*)(void *, void *))strcmp);
        writelines(lineptr, nlines);
    } else {
        printf("Entrada demasiado grande para ser ordenada\n");
        return 1;
    }

    return 0;
}