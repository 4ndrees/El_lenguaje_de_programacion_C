#include <stdio.h>

int main(){
    char c; // Almacenamos la letra convertida en un número

    c=getchar(); // Esperamos a qeu el usuario introduzca una letra

    while (c != EOF){
        printf("%c", c); // Imprimimos por consola
        c=getchar();
    }
    return 0;
}