/* Esercizio sui puntatori e sugli indirizzi */

#include <stdlib.h>
#include <stdio.h>

int main(){

    int *pi;
    int a=5, b;

    pi = &a;
    b= *pi; // viene inizializzato con il valore puntato da pi, ovvero il valore di a

    *pi = 9; // solo a diventa 9 perche *pi adesso sta puntando ad a 

    printf("*pi = %d\n", *pi);
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;

}
