#include <stdio.h>
#include <math.h>

void getParams(int *base, int *n);
int power(int base, int n);

int main(){
    int base, n;
    getParams(&base, &n);
    printf("El valor de la potencia es: %d", power(2, 2));
    return 0;
}

void getParams(int *base, int *n){
    printf("Introduce el valor de la base: ");
    base = getchar() - '0'; getchar();
    printf("Introduce el valor del exponente: ");
    n = getchar() - '0'; getchar();
}

int power(int base, int n){
    printf("El valor de la bases es: %d\n", base);
    printf("El valor de n es: %d\n", n);
    return pow(base, n);
}