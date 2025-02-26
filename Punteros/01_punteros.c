int main(int argc, char *argv[]){
    
    int x = 1;  // Variable integer x
    int y = 2;  // Variable integer y

    int *ip;    // puntero de integer
    ip = &x;    // el puntero ip contiene la dirección de memoria de x
                // También se seuel decir que ip apunta a x

    *ip = 0;    // *i prepresenta el contenido de lo que apunta ip que es x
                // Es decir *ip, es lo mismo que utilizar x
                // Por lo tanto *ip = 0 es lo mismo que x = 0

    int *ipy;
    ipy = &y;
    *ipy = 5;
}