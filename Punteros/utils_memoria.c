#include <stdio.h>
#include "utils_memoria.h"

static char allocbuf[ALLOCSIZE];    /* almacenamiento para alloc */
static char *allocp = allocbuf;     /* siguiente posición libre */

/* regresa un apuntador a n caracteres */
char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n){
        allocp += n;
        return allocp - n;
    }
}

/* almacenamiento libre apuntado por p */
void afree(char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}