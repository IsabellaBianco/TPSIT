/*Creare un programma che dato un numero intero, avente un numero arbitrario di cifre inserite
dall’utente, lo scriva in output con le cifre in ordine inverso. Utilizzare una pila e le implementazioni
dei metodi push e pop.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nodo{
    int valore;
    struct nodo *next; 

} Nodo;

bool is_empty(Nodo *head);
Nodo* pop(Nodo* head);
void push(Nodo* head, int valore);
//USO UNA PILA FIFO

int main(){
    int numero;
    printf("Inserisci un numero: ");
    scanf("%d", &numero);
    //Inserisco il primo numero nella lista
    Nodo* head = (Nodo*) malloc(sizeof(Nodo));
    head->valore = numero%10;
    head->next = NULL;
    numero = numero/10;

    //Inserisco gli altri numero utilizzando la push
    while(numero != 0){
        push(head, numero%10);
        numero = numero/10;
    }
    //Stampo i valore con la pop
    while(!is_empty(head)){
        printf("%d-", head->valore);
        head = pop(head);
    }

    return 0;
}

bool is_empty(Nodo *head){
    
    if (head == NULL) return true;
    else return false;
}

void push(Nodo* head, int valore){
    if(is_empty(head->next)){
        head->next = (Nodo*) malloc(sizeof(Nodo));
        head = head->next;
        head->valore = valore;
        head->next = NULL;
    }
    else{
        push(head->next, valore);
    }
    return;
}

Nodo* pop(Nodo* head){
    head = head->next;
    return head;
}