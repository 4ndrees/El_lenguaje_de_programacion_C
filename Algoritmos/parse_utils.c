#include <stdio.h>
#include <ctype.h>
#include "parse_utils.h"

void parsePlayerResult(int randNums[], int playerNums[], char playerOperations[]){

    printf("Introduce la operacion resultado: ");

    for (int i = 0; i < 5; i++){
        // Obtener números introducidos por el usuario
        int n = parseNum();
        if (checkNum(randNums, n)) playerNums[i] = n;   // Control de errores al introducir un número 
        else {
            printf("Error al introducir un numero");
            break;
        }
        // Obtener operaciones introducidas por el usuario
        if (i < 4) {
            char c = parseOperation();  
            if (c == '!'){  // Control de errores al introducir una operacion
                printf("Error al introducir una operacion");
                break;
            }
            else playerOperations[i] = c;
        }
    }
    printf("\n");
}

int parseNum(){

    int num = 0, valid = 1;
    char c;

    while ((c = getchar()) != ' ' && c != '\n' && valid){
        if (!isdigit(c)) valid = 0; // Si en algún momento se introduce un caracter que no sea un número deja de ser valido
        num =  num * 10 + (c - '0');
    }

    return (valid) ? num : -1;
}

int checkNum(int nums[], int num){
    for (int i = 0; i < 5; i++)
        if (nums[i] == num){
            nums[i] = -1; // Eliminamos el número para que no se repita
            return 1;
        }
    return 0;
}

char parseOperation(){
    char op, aux;

    op = getchar(); 
    if ((aux = getchar()) != ' ' && op != '+' && op != '-' && op != '*' && op != '/') return '!';

    return op;
}