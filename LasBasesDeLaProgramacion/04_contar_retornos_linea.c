#include <stdio.h>

int main(){
    int nl = 0, nt = 0, ne = 0;
    char c = getchar();
    do{
        switch (c)
        {
            case '\n':
                nl++;
                break;
            case '\t':
                nt++;
                break;
            case ' ':
                ne++;
        }
        c = getchar();
    } while (c != EOF);

    printf("Lineas: %d, Espacios: %d, Tabuladores: %d\n", nl, ne, nt);
}