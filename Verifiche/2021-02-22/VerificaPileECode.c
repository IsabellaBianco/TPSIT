/*
Un mazzo di carte da gioco è costituito da 52 carte: 13 carte per ogni seme. Realizzare un programma in linguaggio C in cui ogni seme è rappresentato da un char :
‘C’: cuori
‘P’: picche
‘D’: quadri
‘F’: fiori
mentre ogni carta di un seme è rappresentata da un numero intero compreso tra 1 e 13.

All’interno del programma:

Realizzate una struttura auto-referenziata opportuna che permetta di memorizzare l’intero mazzo di carte sotto forma di coda FIFO. 

All’interno del main(), riempire il mazzo di carte, utilizzando l’opportuno metodo delle code. (BONUS: riempire il mazzo con le carte in ordine casuale)

Successivamente all’interno del main() realizzate il seguente procedimento:
Ad ogni turno viene estratta la carta in fondo al mazzo
Se la carta estratta è nera (fiori o picche) viene scartata, altrimenti se la carta estratta è rossa (cuori o quadri) essa viene collocata in cima al mazzo
I turni finiscono quando il mazzo è composto soltanto di carte rosse
Stampate tutte le carte del mazzo dopo l’intero procedimento
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TOT_CARTE 52
#define MAZZO_ROSSO 24
#define PICCHE 1
#define FIORI 2
#define CUORI 3
#define QUADRI 4

//Definisco una struttura 20autoreferenziata
typedef struct s_queue_node{
    char seme;
    int numero;
    struct s_queue_node* next;
}queue_node;

//Definisco le strutture per poter effettuare delle operazioni sulla coda
int is_empty(queue_node* head);
void enqueue(queue_node **head, queue_node **tail, queue_node *element);
queue_node* dequeue(queue_node **head, queue_node **tail);
void riempimento_mazzo(queue_node**head, queue_node** tail);
char calcola_seme(int seme_carta);
void estrazione_carte(queue_node**head, queue_node** tail);
void stampa_coda(queue_node**head, queue_node** tail);

int main(){
    //Dichiaro e inizializzo head e tail
    queue_node* head = NULL;
    queue_node* tail = NULL;
    //Richiamo le funzioni
    riempimento_mazzo(&head, &tail);
    estrazione_carte(&head, &tail);
    stampa_coda(&head, &tail);
    return 0;
}

//Controllo che la coda non sia vuota
int is_empty(queue_node* head){
    if(head==NULL) return 1;
    else return 0;
}

//Aggiungo un elemento alla coda
void enqueue( queue_node **head,  queue_node **tail,  queue_node *element){ //con il doppio asterisco mi riferisco al puntatore passato per referenza dato che voglio modificarlo
    if(is_empty(*head)){
        *head = element;
    }else{
        (*tail)->next = element;
    }
    *tail = element;
    element->next=NULL;
}

//Tolgo un elemento dalla coda
 queue_node* dequeue( queue_node **head,  queue_node **tail){  //bisogna anche fare l'eleminazione dell'elemento con free(), ma bisogna farlo fuori dalla funzione
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

//Questa funzione riempe il mazzo in maniera casuale
void riempimento_mazzo(queue_node**head, queue_node**tail){
    int carte_estratte[TOT_CARTE];
    int carta;
    int seme_carta;
    
    for(int i = 0; i < TOT_CARTE; i++){
        int ripetizioni = 1;
        //Estraggo a sorte il seme e la carta
            seme_carta = rand()%4+1;
            carta = rand()%13+1;
            ripetizioni = 0;
            printf("E: %d\n", seme_carta*100+carta);
        //Se la carta si trova nell'array di carte già estratte decremento il contatore altrimenti la memorizzo
            for(int j = 0; j<i; j++){
                if(carte_estratte[j]==(seme_carta*100+carta)){
                    ripetizioni++;
                }
            }
        if(ripetizioni == 0){
            queue_node* element = (queue_node*) malloc(sizeof(queue_node)); 
            element->numero = carta;
            element->seme = calcola_seme(seme_carta);
            enqueue(head, tail, element);
        }
        else{
            i--;
        }
    }
}
//Calcolo il seme delle  carte e ritorno un char
char calcola_seme(int seme_carta){
    char seme = 'E';
    switch (seme_carta)
    {
    case PICCHE:
        seme = 'P';
        break;
    case FIORI:
        seme = 'F';
        break;
    case CUORI:
        seme = 'C';
        break;
    case QUADRI:
        seme = 'D';
        break;
    default:
        printf("Errore durante l'estrazione delle carte!\n");
        break;
    }
    return seme;
}

//Estraggo le carte 
void estrazione_carte(queue_node**head, queue_node** tail){
    int carte_estratte =1;
    while(carte_estratte < MAZZO_ROSSO){
        queue_node* el_estratto;
        el_estratto = dequeue(head, tail);
        //se sono Nere allora incremento le carte estratte altrimenti le reinserisco nella coda
        if(el_estratto->seme == 'P' || el_estratto->seme == 'F'){
            carte_estratte++;
        }
        else{
            enqueue(head, tail, el_estratto);
        }
    }
    printf("Tutte le carte sono state estratte!\n");
}

//Stampo la coda
void stampa_coda(queue_node**head, queue_node** tail){
    for(int i = 0; i<MAZZO_ROSSO; i++){
        queue_node* el_da_stampare;
        el_da_stampare = dequeue(head, tail);
        printf("Elemento %d: %d%c\n",i+1, el_da_stampare->numero, el_da_stampare->seme);
    }
}
