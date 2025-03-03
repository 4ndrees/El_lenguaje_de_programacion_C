#include <stdio.h>
#include <string.h>

struct Jugador
{
    char nombre[64];
    float altura;
    int dorsal;
    int ptos_totales;
};

int main(int argc, char *argv){

    struct Jugador jugador;
    strcpy(jugador.nombre, "Paco");
    jugador.altura = 1.90f;
    jugador.dorsal = 1;
    jugador.ptos_totales = 45;
}