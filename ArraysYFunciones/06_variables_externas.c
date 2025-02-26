#include <stdio.h>

#define MAXLINE 1000 /* tamaño máximo de la línea de entrada */

int max;
char line[MAXLINE];
char longest[MAXLINE];

int getline(int maxline); /* Función qeu captura una linea del usuario, la almacena y devuelve su longitud */
void copy(void);

int main(){

    /* Definiciones */
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while((len = getline(MAXLINE))>0){
        if (len>max){
            max=len;
            copy();
        }
    }

    if (max > 0)
        printf("%s", longest);

    return 0;
}

int getline(int lim){
    int c, i;
    extern char line[];

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n'){
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void copy(void){
    int i = 0;
    extern char line[];
    extern char longest[];

    while ((longest[i]=line[i])!='\0')
        ++i;
}