/*Esempio su come ciclare su un array in C*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int vet[5] = {11, 22, 33, 44, 55};
    int *pi = vet;
    int offset = 3;


    //Sono tutte quante la stessa istruzione
    vet[offset] = 88;
    /**(vet + offset) = 88;
    pi[offset] = 88;
    *(pi + offset) = 88;*/

    //Tre modi per fare un ciclo for 
    int i;
    for(i = 0; i < 5; i++){

        printf("La cella numero %d è %d\n", i, *(pi + i));
    }
    for(i = 0; i < 5; i++){
        printf("%d", *(a+i));
    }

    for(pi = vet; pi < vet+5; pi++){
        printf("%d", *p);
    }

    return 0;
}
