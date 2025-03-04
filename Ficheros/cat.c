#include <stdio.h>
#include <stdlib.h>

void filecopy(FILE *ifp, FILE *ofp);

int main(int argc, char *argv[]){
    
    if (argc == 1 || argc > 3){
        printf("uso de cat.exe\n");
        printf("cat.exe ruta_fichero : Imprime fichero por pantalla\n");
        printf("cat.exe ruta_fichero1 ruta_fichero2 : Copia fichero 1 en fichero1\n");
        exit(EXIT_FAILURE);
    }
    else{
        FILE *ifp;
        FILE *ofp;

        if((ifp = fopen(argv[1], "r"))==NULL){
            perror("File open error");
            exit(EXIT_FAILURE);
        }
    
        if (argc == 3){
            if((ofp = fopen(argv[2], "w"))==NULL){
                perror("File open error");
                exit(EXIT_FAILURE);
            }
            
            filecopy(ifp, ofp);
            
            if(fclose(ofp)!=0){
                perror("File close error");
                exit(EXIT_FAILURE);
            }
        }
        else filecopy(ifp, stdout);

        if(fclose(ifp)!=0){
            perror("File close error");
            exit(EXIT_FAILURE);
        }
    }


    return EXIT_SUCCESS;
}

void filecopy(FILE *ifp, FILE *ofp){
    int c;

    while((c = getc(ifp)) != EOF)
        putc(c, ofp);
}