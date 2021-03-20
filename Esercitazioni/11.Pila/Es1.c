#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Inserire degli elementi in una pila e decidere quanti ne fare uscire.
*/

typedef struct nodo{
    int valore;
    struct nodo *next; 

} Nodo;

int is_empty(Nodo *head);
void push(Nodo **head, Nodo* elemento);
Nodo* pop(Nodo **head);
void estrazioneElementi(Nodo**head, int n_elementi);


int main(){
    Nodo* head = NULL;
    int scelta;
    int n_elementi;
    printf("Quanti elementi si vogliono inserire: ");
    scanf("%d", &n_elementi);
    for(int i = 0; i < n_elementi; i++){
        Nodo* elemento = (Nodo*) malloc(sizeof(Nodo));
        printf("Inserire il %d° elemento: ", i+1);
        scanf("%d", &(elemento->valore));
        push(&head, elemento);
    }
    printf("Quanti elementi si vogliono estrarre: ");
    scanf("%d", &scelta);
    if(scelta > n_elementi){
        printf("Non ci sono %d elementi, ma verrano estratti %d elementi...\n", scelta, n_elementi);
        scelta = n_elementi;
    }
    estrazioneElementi(&head, scelta);


    return 0;
}


void estrazioneElementi(Nodo** head, int n_elementi){
    for(int i = 0; i < n_elementi; i++){
        printf("Elemento: %d \n", (pop(head)->valore));
    }
}

//Controllo se è vuota
int is_empty(Nodo *head){
    
    if (head == NULL) return 1;
    else return 0;
}



void push(Nodo **head, Nodo* elemento){
    //Passo il puntatore per referenza
    if(is_empty(*head)){
        *head = elemento;
        elemento->next = NULL; // elemento è già allocato
    }
    else{
        elemento->next = *head;
        *head = elemento;
    }

}

Nodo* pop(Nodo **head){
    Nodo* ret = *head; //Mi serve una variabile di appoggio perchè se sostituisco la testa poi non ce l'ho più
    if(is_empty(*head)){
        return NULL;
    }
    else{
        *head = ret->next;
    }
    return ret;
}