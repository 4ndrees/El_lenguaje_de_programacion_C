#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

void strcpyIndices(char* s, char* t);
void strcpyPunteros(char *s, char* t);

int main(int argc, int* argv[]){

    char origen[] = "Hola Mundo\0";
    char copia[MAXLINE]="";

    printf("Linea vacia: %s\n", copia);
    //strcpyIndices(copia, origen);
    strcpyPunteros(copia, origen);
    printf("Linea copiada: %s\n", copia);

    return 0;
}

void strcpyIndices(char* s, char* t){
    int i = 0;
    while ((s[i]=t[i])!='\0')
        i++;
}

void strcpyPunteros(char *s, char *t){
    while((*s++=*t++)!='\0');
}