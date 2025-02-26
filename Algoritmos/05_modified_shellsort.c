#include <stdio.h>
#include <stdlib.h>

void shellsort(int arr[], int size);
void shellsort2(char* valuesArr[], int keysArr[], int size);
void exchange(char** one, char** other);

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

    int keysArr[6] = {7, 10, 9, 8, 8, 9};
    char* valuesArr[6] = {"Paco", "Sandra", "Arturo", "Javier", "Marcos", "Tomas"};

    printf("\nArray desordenado:\n");
    for (int i = 0; i < 6; i++)
        printf("Key: %2d     Value: %s\n", keysArr[i], valuesArr[i]);

    shellsort2(valuesArr, keysArr, 6);

    printf("Array ordenado:\n");
    for (int i = 0; i < 6; i++)
        printf("Key: %2d     Value: %s\n", keysArr[i], valuesArr[i]);

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

void shellsort2(char* valuesArr[], int keysArr[], int size){
    int temp;
    for(int gap = size/2; gap > 0; gap/=2)
        for (int i = gap; i < size; i++)
            for (int j = i - gap; j >= 0 && (keysArr[j] > keysArr[j + gap] || (keysArr[j] == keysArr[j + gap] && valuesArr[j] > valuesArr[j+gap])); j-=gap){
                temp = keysArr[j];
                keysArr[j] = keysArr[j+gap];
                keysArr[j+gap] = temp;
                exchange(&valuesArr[j], &valuesArr[j+gap]);
            }
}

void exchange(char** one, char** other){
    char *aux = *one;
    *one = *other;
    *other = aux;
}