/*
Implementare le pile e i metodi pop() e push() utilizzando una coda con i suoi metodi
enqueue() and dequeue().
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

    /* CODA */
    queue_node* head=NULL;
    queue_node* struct_return=NULL;    
    queue_node* element=NULL;
    bool condizione = true;
while(condizione){
        int scelta;
        printf("MENÙ\n\n- scegliere '1' per la push\n- scegliere '2' per la pop\n- scegliere '3' per uscire dal programma\n\nInserire numero: ");
        scanf("%d", &scelta);
        int dato;
        queue_node* tail= NULL;
        switch (scelta)
        {
        case 1:
            printf("Inserire elemento: ");
            scanf("%d", &dato);
            tail = head;
            if(tail != NULL){
                while(tail->next!=NULL){
                tail = tail->next;
                }
            }
            element = (queue_node*) malloc(sizeof(queue_node)); 
            element->elemento = dato;
            enqueue(&head, &tail, element);
            break;
        case 2:
            printf("L'ultimo elemento nella lista è: \t");
            tail = head;
            while(tail->next!=NULL){
               tail = tail->next;
            }
            printf("%d", dequeue(&head, &tail)->elemento);
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