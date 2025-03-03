#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXWORDS 100
#define MAXLEN 30

void addPalabra(char *listaPalabras[], char* palabra);
void parsePalabras();
void generarFrase();

char *nombres[MAXWORDS];
char *articulos[MAXWORDS];
char *sustantivos[MAXWORDS];
char *verbos[MAXWORDS];

int nombresCount = 0;
int articulosCount = 0;
int sustantivosCount = 0;
int verbosCount = 0;

int main(int argc, char *argv[]){
    srand(time(NULL));

    addPalabra(nombres, "Mario");
    addPalabra(nombres, "Laura");
    addPalabra(nombres, "Paco");

    addPalabra(articulos, "el");
    addPalabra(articulos, "la");
    addPalabra(articulos, "un");

    addPalabra(sustantivos, "gato");
    addPalabra(sustantivos, "ventana");
    addPalabra(sustantivos, "plato");

    addPalabra(verbos, "maulla");
    addPalabra(verbos, "abre");
    addPalabra(verbos, "usa");

    char opt;
    char palabra[MAXLEN];
    char tipo;

    parsePalabras();

    printf("\nGenerando discurso:\n");
    for (int i = 0; i < 5; i++) {
        generarFrase();
    }
}

void addPalabra(char *listaPalabras[], char* palabra){
    int *count;
    if (listaPalabras == nombres) {
        count = &nombresCount;
    } else if (listaPalabras == articulos) {
        count = &articulosCount;
    } else if (listaPalabras == sustantivos) {
        count = &sustantivosCount;
    } else if (listaPalabras == verbos) {
        count = &verbosCount;
    } else {
        return;
    }

    if (*count < MAXWORDS) {
        listaPalabras[*count] = malloc(strlen(palabra) + 1);
        strcpy(listaPalabras[*count], palabra);
        (*count)++;
    } else {
        printf("Lista llena, no se pueden agregar mas palabras.\n");
    }
}

void parsePalabras(){

    char opt, tipo, c;

    do {
        char palabra[MAXLEN];
        int i = 0;
        printf("Desea incluir una nueva palabra? (s/n): ");
        opt = getchar(); getchar();
        if (opt == 's') {
            printf("Ingrese la categoria (n: nombre, a: articulo, s: sustantivo, v: verbo): ");
            tipo = getchar(); getchar();
            printf("Ingrese la palabra: ");
            
            while((c = getchar()) != '\n' && i < MAXLEN - 1){
                palabra[i] = c;
                i++;
            }
            palabra[i + 1]='\0';

            switch (tipo)
            {
            case 'n':
                addPalabra(nombres, palabra);
                break;
            case 'a':
                addPalabra(articulos, palabra);
                break;
            case 's':
                addPalabra(sustantivos, palabra);
                break;
            case 'v':
                addPalabra(verbos, palabra);
                break;
            default:
                printf("Categoria invalida.\n");
            }
        }
    } while (opt == 's');
}

void generarFrase() {
    if (nombresCount == 0 || articulosCount == 0 || sustantivosCount == 0 || verbosCount == 0) {
        printf("No hay suficientes palabras para generar una frase.\n");
        return;
    }
    printf("%s %s %s %s.\n", 
        nombres[rand() % nombresCount],
        verbos[rand() % verbosCount],
        articulos[rand() % articulosCount],
        sustantivos[rand() % sustantivosCount]
    );
}