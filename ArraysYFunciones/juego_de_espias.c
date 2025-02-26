#include <stdio.h>
#include <ctype.h>

#define DECO 0
#define CODE 1
#define MAXLINE 1000

int parseMode();
int parseShift();
void parseLine(char line[], int lim);
void code(char line[], int shift);
void decode(char line[], int shift);

int main(){

    int mode, shift;
    char line[MAXLINE];

    // Preguntar el modo: codificación o decodificación
    mode = parseMode();
    // Preguntar desplazamiento
    shift = parseShift(); 
    // Preguntar frase
    parseLine(line, MAXLINE);
    // Devolver el resultado
    (mode == CODE) ? code(line, shift) : decode(line, shift);
    printf("Linea transformada: %s", line);

    return 0;
}

/* Pregunta hasta que el usuario introduce D o C (modos válidos) */
int parseMode(){
    char c;
    int mode = -1;
    // Preguntar decodificar o codificar
    printf("Quieres codificar o decodificar? [C/D]: ");

    while (mode == -1){
        c = getchar(); getchar();
        if (c == 'C' || c == 'c') mode = CODE;
        else if (c == 'D' || c == 'd') mode = DECO;
        else{
            while((c = getchar())!='\n'){} // consume el resto de la entrada restante
            printf("Introduce una respuesta valida [C/D]:");
        }
    }

    return mode;
}

/* Pregunta hasta que el usuario introduce un número válido */
int parseShift(){

    int num, valid = 1;
    char c;

    printf("Introduce el desplazamiento que desees: ");

    while (1){  // Se mantiene el número hasta que se intruduzca uno válido
        num = 0;
        while ((c = getchar()) != '\n' && valid){
            if (!isdigit(c)) valid = 0; // Si en algún momento se introduce un caracter que no sea un número deja de ser valido
            num =  num * 10 + (c - '0');
        }

        if (valid) break;   // si el número es válido termina el bucle
        else {  // si no se termina de consumir la entrada, se vuelve a porner valid a true y se pide un nuevo número 
            while((c = getchar())!='\n'){}  
            valid = 1; 
            printf("Introduce un numero: ");
        }
    }

    return num;
}

void parseLine(char line[], int lim){
    int c, i;
    
    printf("Introduce una linea que quieras modificar: ");

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n'){
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
}

void code(char line[], int shift){
    int i = 0;
    while(line[i] != '\n'){
        if (line[i] >= 'a' && line[i] <= 'z')
            line[i] = ((line[i]-'a'+shift)%26) + 'a';
        i++;
    }
}

void decode(char line[], int shift){
    int i = 0;
    while(line[i] != '\n'){
        if (line[i] >= 'a' && line[i] <= 'z'){
            if ((line[i]-'a'-shift) < 0) line[i] = (26 - (-(line[i]-'a'-shift))%26) + 'a';
            else line[i] = ((line[i]-'a'-shift)%26) + 'a';
        }
        i++;
    }
}