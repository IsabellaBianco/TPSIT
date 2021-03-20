/*
Scrivere un programma che chieda all’utente una stringa composta da parentesi aperte e chiuse: (,),[,],{,} e
che verifichi se le coppie e l’ordine delle (,),[,],{,} sono corretti. Utilizzare uno stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 4096

typedef struct nodo{
    char valore;
    struct nodo *next; 

} Nodo;

bool is_empty(Nodo *head);
Nodo* pop(Nodo *head);
Nodo* push(Nodo* head, char parentesi);

int main(){
    char* stringa = (char*) malloc(MAX*sizeof(char));
    printf("Inserire una stringa di parentesi: ");
    scanf("%s", stringa);
    int i = 0;
    Nodo* head = (Nodo*) malloc(sizeof(Nodo));
    bool parentesi_sbagliata = false;
    while(stringa[i]!='\0' && !parentesi_sbagliata){
        if(stringa[i]=='(' || stringa[i]=='[' || stringa[i]=='{'){
            head = push(head, stringa[i]);
        }
        else if(stringa[i]==')' || stringa[i]==']' || stringa[i]=='}'){
            char p = head->valore;
            head = pop(head);
            if(stringa[i]!=p+1 && stringa[i]!=p+2){
                printf("Errore nella chiusura delle parentesi!\n");
                parentesi_sbagliata = true;
            }
        }
        i++;
        
    }
    if(!parentesi_sbagliata){
        printf("Tutte le parentesi sono state aperte e chiuse correttamente!\n");
    }


    return 0;
}

bool is_empty(Nodo *head){
    
    if (head == NULL) return true;
    else return false;
}

Nodo* push(Nodo* head, char parentesi){
     //Passo il puntatore per referenza
    if(is_empty(head)){
        head->next = NULL; // elemento è già allocato
        head->valore = parentesi;
    }
    else{
        Nodo* elemento = (Nodo*) malloc(sizeof(Nodo));
        elemento->next = head;
        elemento->valore = parentesi;
        head = elemento;
    }
    return head;
}



Nodo* pop(Nodo *head){
    Nodo* ret = head; //Mi serve una variabile di appoggio perchè se sostituisco la testa poi non ce l'ho più
    if(is_empty(head)){
        return NULL;
    }
    else{
        head = ret->next;
    }

    return head;
}