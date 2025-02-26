#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPORT_INI 10

int main(){

    // Declaración de variables iniciales
    int num_oport = OPORT_INI, acierto = 0, random_c, player_c;
    
    // Obtener una letra aleatoria
    srand(time(NULL));
    random_c = (rand() % 26) + 'a';

    // Bucle del juego
    while(num_oport > 0 && !acierto && player_c != EOF){
        // Pedir al usuario que introduzca una letra
        printf("Introduce a letter: ");
        player_c = getchar();
        getchar(); // Ignoramos el segundo caracter que es el espacio
        // Comprobar si la letra cohincide
        if (player_c == random_c) acierto = 1;
        else {
            num_oport--;
            printf("Fail!!, you have %d opportunities more\n", num_oport);
        }
    }

    // Resultado de la partida
    acierto ? printf("\nPlayer win!!") : printf("\nComputer win!!");

    return 0;
}