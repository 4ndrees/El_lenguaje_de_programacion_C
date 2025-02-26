#include <stdio.h>

int main(){

    int nwhite = 0, ndigit = 0, nother = 0, ndot = 0, ncoma = 0, c;
    
    while((c = getchar())!=EOF){
        if(c == '\t' || c == '\n' || c == ' ') nwhite++;
        else if (c >= '0' && c <= '9') ndigit++;
        else if (c == '.') ndot++;
        else if (c == ',') ncoma++;
        else nother++;
    }

    printf("White: %d, Digit: %d, Dots: %d, Comas: %d, Other: %d", nwhite, ndigit, ndot, ncoma, nother);

    return 0;
}