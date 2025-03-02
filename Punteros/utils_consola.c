#include <stdio.h>
#include "utils_consola.h"
#include "utils_memoria.h"

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;

    while((len = getline(line, MAXLEN)) > 0){
        if(nlines >= maxlines || (p=alloc(len)) == NULL)
            return -1;
        else{
            line[len-1]='\0';
            strcpyPunteros(p, line);
            lineptr[nlines++]=p;
        }
    }
}

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
void strcpyPunteros(char *s, char *t){
    while((*s++=*t++)!='\0');
}