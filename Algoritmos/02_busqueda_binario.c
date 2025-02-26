#include <stdio.h>

int binary_search(int arr[], int size, int x);

int main(){

    int arr[9] = {10, 15, 17, 32, 41, 78, 79, 85, 92};
    int result, x = 41;

    result = binary_search(arr, 9, x);
    if (result != -1) 
        printf("Position: %d  Value: %d\n", result, arr[result]);
    else 
        printf("El número no se encuentra en el array");

    return 0;
}

int binary_search(int arr[], int size, int x){

    int i = 0, j = size - 1, mid;

    while (i <= j){
        mid = (j+i)/2;
        if (arr[mid] > x){
            j = mid - 1;
        }
        else if (arr[mid] < x){
            i = mid + 1;
        }
        else return mid;
    }
    return -1;
}