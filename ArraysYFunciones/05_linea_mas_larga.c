#include <stdio.h>

#define MAXLINE 1000 /* tamaño máximo de la línea de entrada */

int getline(char line[], int maxline); /* Función qeu captura una linea del usuario, la almacena y devuelve su longitud */
void copy(char to[], char from[]);

int main(){

    /* Definiciones */
    int len, max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];

    while((len = getline(line, MAXLINE))>0){
        if (len > max){
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)
        printf("%s", longest);

    return 0;
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
    return i;
}

void copy(char to[], char from[]){
    int i = 0;
    while ((to[i]=from[i])!='\0')
        ++i;
}