#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *ifp, FILE *ofp);

int main(int argc, char *argv[]){

    FILE *fp;
    
    if (argc != 2){
        printf("Not enough arguments: lectura_fichero <nombre_fichero>");
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "r"))==NULL){
        perror("File open error");
        exit(EXIT_FAILURE);
    }

    filecopy(fp, stdout);

    if(fclose(fp)!=0){
        perror("File close error");
        exit(EXIT_FAILURE);
    }
    
    return EXIT_SUCCESS;
}

void filecopy(FILE *ifp, FILE *ofp){
    int c;

    while((c = getc(ifp)) != EOF)
        putc(c, ofp);
}