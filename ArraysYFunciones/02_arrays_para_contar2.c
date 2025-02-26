#include <stdio.h>

int main(){

    int nwhite, ndigit[10], nother, c;
    
    nwhite=nother=0;

    for(int i = 0; i < 10; i++)
        ndigit[i] = 0;

    while((c = getchar())!=EOF){

        if (c == ' ' || c == '\t' || c == '\n') nwhite++;
        else if (c >= '0' && c <= '9') ndigit[c-'0']++; 
        else nother++;
/*
        switch (c)
        {
            case ' ': case '\t': case '\n': 
                nwhite++;
                break;
            case '0':
                ndigit0++;
                break;
            case '1':
                ndigit1++;
                break;
            case '2':
                ndigit2++;
                break;
            case '3':
                ndigit3++;
                break;
            case '4':
                ndigit4++;
                break;
            case '5':
                ndigit5++;
                break;
            case '6':
                ndigit6++;
                break;
            case '7':
                ndigit7++;
                break;
            case '8':
                ndigit8++;
                break;
            case '9':
                ndigit9++;
                break;
            default:
                nother++;
        }+*/
    }

    printf("White: %d, Other: %d\n", nwhite, nother);
    for (int i = 0; i < 10; i++)
        printf("Digit%d: %d\n", i, ndigit[i]);

    return 0;
}