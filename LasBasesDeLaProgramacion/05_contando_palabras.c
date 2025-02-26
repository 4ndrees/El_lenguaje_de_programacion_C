#include <stdio.h>

#define IN 1
#define OUT 0

int main(){
    char c;
    int state = OUT, nw = 0;

    while((c=getchar())!=EOF){
        if (c==' '||c=='\t'||c=='\n') state = OUT;
        else if(state==OUT){
            state = IN;
            nw++;
        }
    }

    printf("Numero de palabras: %d", nw);

    return 0;
}