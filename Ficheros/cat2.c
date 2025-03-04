#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void filecopy(FILE *ifp, FILE *ofp);

int main(int argc, char *argv[]){
    
    FILE *ifp, *ofp;
    freopen("error.log", "w", stderr);

    if (argc == 1 || argc > 3){
        printf("uso de cat.exe\n");
        printf("cat.exe ruta_fichero : Imprime fichero por pantalla\n");
        printf("cat.exe ruta_fichero1 ruta_fichero2 : Copia fichero 1 en fichero1\n");
        exit(EXIT_FAILURE);
    }
    else{
        if((ifp = fopen(argv[1], "r"))==NULL){
            time_t rawtime;
            struct tm * timeinfo;
          
            time ( &rawtime );
            timeinfo = localtime ( &rawtime );

            fprintf(stderr, "%scat: no puede abrir el fichero %s\n", asctime (timeinfo), argv[1]);
            return EXIT_FAILURE;
        }else{
            if(argc == 2){
                filecopy(ifp, stdout);
                fclose(ifp);
            }
            if(argc==3){
                if((ofp = fopen(argv[3], "w"))==NULL){
                    time_t rawtime;
                    struct tm * timeinfo;
                  
                    time ( &rawtime );
                    timeinfo = localtime ( &rawtime );

                    fprintf(stderr, "%scat: no puede abrir el fichero %s\n", asctime (timeinfo), argv[2]);
                    return EXIT_FAILURE;
                }else{
                    filecopy(ifp, ofp);
                    fclose(ifp);
                    fclose(ofp);
                }
            }
        }
    }

    return EXIT_SUCCESS;
}

void filecopy(FILE *ifp, FILE *ofp){
    int c;

    while((c = getc(ifp)) != EOF)
        putc(c, ofp);
}