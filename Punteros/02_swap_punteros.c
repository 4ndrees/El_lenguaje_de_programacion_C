#include <stdio.h>

void swap(int *a, int *b);
void swap3(int *px, int *py, int *pz);

int main(int argc, char* argv[]){
    // Valores de prueba
    int num1=1, num10=10;
    // Imprimimos valores antes del intercambio
    printf(" [num1=%d] - [num10=%d]\n", num1, num10);
    swap(&num1, &num10);
    // Imprimimos valores después del intercambio
    printf(" [num1=%d] - [num10=%d]\n", num1, num10);

    int num2 = 2, num3 = 3, num4 = 4;
    // Imprimimos valores antes del intercambio
    printf(" [num2=%d] - [num3=%d] - [num4=%d]\n", num2, num3, num4);
    swap3(&num2, &num3, &num4);
    // Imprimimos valores después del intercambio
    printf(" [num2=%d] - [num3=%d] - [num4=%d]\n", num2, num3, num4);

    return 0;
}

void swap(int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void swap3(int *px, int *py, int *pz){
    int temp = *px;
    *px = *py;
    *py  = *pz;
    *pz = temp;
}