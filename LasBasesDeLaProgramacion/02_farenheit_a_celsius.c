#include <stdio.h>

int main(){
    float fahr, celsius;
    int lower = 0, upper = 300, step = 20;

    fahr = lower;

    printf("Temperatura F(lower): %d\n", lower);
    printf("Temperatura F(upper): %d\n", upper);

    while (fahr <= upper) {
        celsius = (5.0/9.0)*(fahr-32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr += step;
    }

    printf("\n");

    for (fahr = lower; fahr <= upper; fahr += step){
        celsius = (5.0/9.0)*(fahr-32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
    }

    return 0;
}