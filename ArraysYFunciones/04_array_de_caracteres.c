#include <stdio.h>

#define MAXLINE 1000 /* tamaño máximo de la línea de entrada */

int getline(char line[], int maxline); /* Función qeu captura una linea del usuario, la almacena y devuelve su longitud */

int main(){

    /* Definiciones */
    int len;
    char line[MAXLINE];

    len = getline(line, MAXLINE);
    printf("--%s-- numCar=%d\n", line, len);

    return 0;
}

int getline(char line[], int lim){
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    line[i] = '\0';
    return i;
}