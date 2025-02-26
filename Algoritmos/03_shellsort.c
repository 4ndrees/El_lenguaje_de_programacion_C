#include <stdio.h>

void shellsort(int arr[], int size);

int main(){

    int arr[10] = {13, 14, 94, 32, 82, 25, 59, 85, 12, 43};
    int size = 10;

    printf("Array desordenado:\n");
    for (int i = 0; i < size; i++)
        printf("Posicion: %d    Valor: %d\n", i, arr[i]);

    shellsort(arr, size);

    printf("\nArray ordenado:\n");
    for (int i = 0; i < size; i++)
        printf("Posicion: %d    Valor: %d\n", i, arr[i]);

    return 0;
}

void shellsort(int arr[], int size){
    int temp;
    for(int gap = size/2; gap > 0; gap/=2)
        for (int i = gap; i < size; i++)
            for (int j = i - gap; j >= 0 && arr[j] > arr[j + gap]; j-=gap){
                temp = arr[j];
                arr[j] = arr[j+gap];
                arr[j+gap] = temp;
            }
}