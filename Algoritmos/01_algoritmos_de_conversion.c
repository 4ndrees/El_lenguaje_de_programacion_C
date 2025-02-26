#include <stdio.h>
#include "utils_consola.h"

#define MAXLINE 1000

int atoi(char s[]);

int main(){
    
    int len, num;
    char line[MAXLINE];

    printf("Escribe un numero por consola de maximo 10 cifras\n");
    len=getline(line, MAXLINE);

    num=atoi(line);
    printf("El numero convertido es: %d\n", num);

    return 0;
}

int atoi(char s[]){
    int i,n,signo;
    n = 0;
    signo = (s[0]=='-'||s[0]=='+') ? 1 : 0;
    for (i=signo;s[i]>='0'&&s[i]<='9';++i)
        n=10*n+(s[i]-'0');
    return (s[0]=='-') ? -n : n;
}