/*
Implementare i metodi enqueue() e dequeue()  e creare un programma che permetta
all’utente di riempire una coda di numeri interi di lunghezza arbitraria. Successivamente
testare la funzione dequeue per svuotare la coda.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_queue_node{
    int elemento;
    struct s_queue_node* next;
}queue_node;

int is_empty(queue_node* head);
void enqueue(queue_node **head, queue_node **tail, queue_node *element);
queue_node* dequeue(queue_node **head, queue_node **tail);

int main(){
    queue_node *head=NULL;
    queue_node *tail=NULL;
    queue_node *struct_return=NULL;   
    queue_node* element; 
    bool condizione = true;
    int dato;

    while(condizione){
        int scelta;
        printf("MENÙ\n\n- scegliere '1' per inserire elementi nella coda\n- scegliere '2' per svuotare la coda\n- scegliere '3' per uscire dal programma\n\nInserire numero: ");
        scanf("%d", &scelta);
        switch (scelta)
        
        {
        case 1:
            printf("Inserire elemento: ");
            scanf("%d", &dato);
            element = (queue_node*) malloc(sizeof(queue_node)); 
            element->elemento = dato;
            enqueue(&head, &tail, element);
            break;
        case 2:
            printf("Gli elementi inseriti fino ad ora nella lista sono: \t");
            while((struct_return=dequeue(&head, &tail))!=NULL){
               printf("%d\t", struct_return->elemento);
                free(struct_return);
            }
            break;
        case 3:
            printf("EXIT...");
            condizione=false;
            break;
        default:
            printf("[ carattere inserito non valido ]\n\n");
            break;
        }

    }

    return 0;
}


int is_empty(queue_node* head){
    if(head==NULL) return 1;
    else return 0;
}

void enqueue(queue_node **head, queue_node **tail, queue_node *element){ //con il doppio asterisco mi riferisco al puntatore passato per referenza dato che voglio modificarlo
    if(is_empty(*head)){
        *head = element;
    }else{
        (*tail)->next = element;
    }
    *tail = element;
    element->next=NULL;
}

queue_node* dequeue(queue_node **head, queue_node **tail){  //bisogna anche fare l'eleminazione dell'elemento con free(), ma bisogna farlo fuori dalla funzione
    queue_node* ret = *head;

    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }

    if(*head ==NULL){
        *tail = NULL;
    }

    return ret;
}