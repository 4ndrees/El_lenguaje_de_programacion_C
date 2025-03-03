#include <stdio.h>
#include <string.h>

int suma(int a, int b);
int resta(int a, int b);

int main(int argc, char* argv[]){

    int (* ptrOperacion)(int, int);
    int sumaOp = 1;

    if(argc > 1 && strcmp(argv[1], "-suma")==0) sumaOp == 0;

    if (sumaOp == 0){
        ptrOperacion = suma;
    } else{
        ptrOperacion = resta;
    }

    printf("El resulatdo de la operacion es %d", ptrOperacion(5, 6));

    return 0;
}

int suma(int a, int b){return a + b;}
int resta(int a, int b){return a - b;}