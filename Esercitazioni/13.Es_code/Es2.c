/*
Scrivere una funzione che inverta una coda, ovvero produca una coda invertendo l’ordine
degli elementi della coda di partenza. Suggerimento: utilizzare una pila.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_queue_node{
    int elemento;
    struct s_queue_node* next;
}queue_node;

typedef struct s_pila{
    int elemento;
    struct s_pila* next;
}pila;


int is_empty(queue_node* head);
void enqueue(queue_node **head, queue_node **tail, queue_node *element);
queue_node* dequeue(queue_node **head, queue_node **tail);
int p_is_empty(pila* head);
void push(pila** head, pila* elemento);
pila* pop(pila **head);


int main(){

    /* CODA */
    queue_node* head=NULL;
    queue_node* tail=NULL;
    queue_node* struct_return=NULL;    
    queue_node* element=NULL;

    /* PILA */
    pila* p_head=NULL;
    pila* p_element=NULL;
    pila* p_struct_return=NULL;

    /* ALTRE VARIABILI */
    int dato;
    int numero_elementi;
    printf("Inserire il numero di elementi che si vogliono inserire dentro la coda: ");
    scanf("%d", &numero_elementi);

    //acquisizione dati in coda
    for(int i = 0;i<numero_elementi; i++){
        printf("Inserire il %d° elemento: ", i+1);
        scanf("%d", &dato);
        element = (queue_node*)malloc(sizeof(queue_node));
        element->elemento=dato;
        enqueue(&head, &tail, element);
    }

    //estrazione dati da coda e salvataggio in pila
    while((struct_return=dequeue(&head, &tail))!=NULL){
        p_element=(pila*)malloc(sizeof(pila));
        p_element->elemento=struct_return->elemento;
        push(&p_head, p_element);
    }

    //estrazioni dati da pila
    printf("Gli elementi invertiti sono:\t");
    while((p_struct_return=pop(&p_head))!=NULL){
        printf("%d\t", p_struct_return->elemento);
        free(p_struct_return);
    }

    return 0;
}


int is_empty(queue_node* head){
    if(head==NULL) return 1;
    else return 0;
}

/*
*head e *tail si possono vedere come due celle fisiche a cui si cambiano valori interni
*/

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
int p_is_empty(pila* head){
    if(head==NULL) return 1;
    else return 0;
}


void push(pila** head, pila* elemento){
    if(p_is_empty(*head)){
        *head = elemento;
        elemento->next=NULL;
    }else{
        elemento->next=*head;
        *head=elemento;
    }
}


pila* pop(pila **head){
    pila* ret=*head;
    if(p_is_empty(*head)){
        return NULL;
    }else{
        *head=ret->next;
    }
    return ret;
}