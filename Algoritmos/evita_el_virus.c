#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "parse_utils.h"

void printHistoria();
void generateChallenge(int* objetiveNumber, int randNums[]);
void printChallenge(int objetiveNumber, int randNums[]);
int checkResult(int objetivNum, int playerNums[], char playerOperations[]);

int main(){

    // Variables
    int objetiveNum;
    int randNums[5];
    int playerNums[5];
    char playerOperations[4];

    // Imprimir historia
    printHistoria();
    // Generación del desafio
    generateChallenge(&objetiveNum, randNums);
    // Imprimir el desafio
    printChallenge(objetiveNum, randNums);
    // Resultado del jugador
    parsePlayerResult(randNums, playerNums, playerOperations);
    // Comprueba el cálculo
    if (checkResult(objetiveNum, playerNums, playerOperations)) 
        printf("Has destruido el virus!!\n");
    else 
        printf("El virus consumio tu sistema\n");

    return 0;
}

void printHistoria(){
    printf("========================================\n");
    printf("      ALERTA! VIRUS MATEMATICO\n");
    printf("========================================\n\n");
    
    printf("Un matematico loco ha liberado un virus informatico mortal.\n");
    printf("La unica manera de detenerlo es resolviendo su desafio numerico\n");
    printf("antes de que el codigo malicioso se active y destruya nuestro sistema.\n\n");
    
    printf("En la pantalla parpadea un numero objetivo, la clave para neutralizar la amenaza.\n");
    printf("Para alcanzarlo, solo podemos usar cinco numeros generados al azar y\n");
    printf("combinarlos con operaciones matematicas basicas: +, -, *, /.\n");
    printf("El resultado debe escribirse como una operacion matematica en una sola linea con\n");
    printf("espacios entre los numeros y simbolos y sin utilizar parentesis.\n\n");

    printf("Formato de los resultado: 4 / 2 * 3 + 2 - 1\n");
    
    printf("El tiempo corre... Podremos encontrar la solucion antes de que sea demasiado tarde?\n\n");
}

void generateChallenge(int* objetiveNumber, int randNums[]){

    srand(time(NULL));
    *objetiveNumber = (rand() % 91) + 10; // Random num between 0 and 90 using %, then add 10     

    for (int i = 0; i < 5; i++)
        randNums[i] = (rand() % 12) + 1; // 5 Random nums betwwn 0 and 11, then add 1
}

void printChallenge(int objetiveNumber, int randNums[]){
    printf("El numero objetivo es: %d\n", objetiveNumber);
    printf("Los numeros aleatorios que puedes utilizar son: ");
    for (int i = 0; i < 5; i++)
        printf("%d ", randNums[i]);
    printf("\n");
}

int checkResult(int objetivNum, int playerNums[], char playerOperations[]){
    int temp[5]; // Array auxiliar para almacenar resultados parciales
    char temp_op[4]; // Array de operadores después de procesar * y /
    int j = 0;

    // Primero procesamos * y /
    for (int i = 0; i < 5; i++)
        temp[i]=playerNums[i];

    for (int i = 0; i < 4; i++) {
        if (playerOperations[i] == '*') {
            temp[j] *= playerNums[i + 1];
        } else if (playerOperations[i] == '/') {
            if (playerNums[i + 1] == 0) {
                printf("Error: División por cero\n");
                return 0;
            }
            temp[j] /= playerNums[i + 1];
        } else {
            temp_op[j] = playerOperations[i]; // Guardamos solo + o -
            j++;
            temp[j] = playerNums[i + 1];
        }
    }

    // Ahora procesamos + y -
    int resultado = temp[0];
    for (int i = 0; i < j; i++) {
        if (temp_op[i] == '+') {
            resultado += temp[i + 1];
        } else if (temp_op[i] == '-') {
            resultado -= temp[i + 1];
        }
    }

    return (resultado == objetivNum) ? 1 : 0;
}