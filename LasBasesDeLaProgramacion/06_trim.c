#include <stdio.h>
#include <string.h>

int trim(char s[]);

int main(int argc, char *argv[]){

    char linea[] = "Esta es una primera prueba       ";
    int tamanyoLinea = 0;

    tamanyoLinea=trim(linea);

    printf("La linea final es --%s--\n", linea);
    printf("El tamanyo final es: %d\n", tamanyoLinea);

    return 0;
}

// trim: elmimina blancos, tabuladores y nueva linea al final
int trim(char s[]){
    int i;
    for (i = strlen(s)-1; i >= 0; i--)
        if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n') break;
    s[i+1] = '\0';
    return i;
}