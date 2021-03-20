/*
Creare una lista e aggiungere degli elementi
*/
#include <stdio.h>
#include <stdlib.h>

//STRUTTURA AUTOREFERENZIALE
typedef struct nodos{
    int val;
    struct nodos* next;
}Nodo;

void push(Nodo*head, int valore);

int main(){

    Nodo* primo_elemento;
    primo_elemento = (Nodo*) malloc(sizeof(Nodo));
    primo_elemento->val = 1;
    primo_elemento->next = NULL;
    push(primo_elemento, 2);
    push(primo_elemento, 3);
    /*
    Nodo* secondo_elemento;
    Nodo* terzo_elemento;    
    secondo_elemento = (Nodo*) malloc(sizeof(Nodo));
    terzo_elemento = (Nodo*) malloc(sizeof(Nodo));
    primo_elemento->next = secondo_elemento;
    secondo_elemento->val = 2;
    secondo_elemento->next = terzo_elemento;
    terzo_elemento->val = 3;
    terzo_elemento->next = NULL;
    */
    Nodo* puntatore_appoggio;
    puntatore_appoggio = primo_elemento;
    while(puntatore_appoggio != NULL){

        printf("Il valore è: %d", puntatore_appoggio->val);
        puntatore_appoggio = puntatore_appoggio->next;

    }


    return 0;
}
//Aggiungere un elemento in fondo alla lista contenente il valore
void push(Nodo*head, int valore){
    Nodo* puntatore_appoggio = head;

    while(puntatore_appoggio->next != NULL){
        puntatore_appoggio = puntatore_appoggio->next;
    }
    puntatore_appoggio->next = (Nodo*) malloc(sizeof(Nodo));
    puntatore_appoggio->next->val = valore;
    puntatore_appoggio->next->next = NULL;
}
