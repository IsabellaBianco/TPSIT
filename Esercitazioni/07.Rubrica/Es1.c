/*
Programmare una rubrica telefonica
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_NUM_CONTATTI 1024
#define MAX_NOME 64
#define MAX_NUMERO 16

typedef struct Scontatto{
    int id;
    char nome [MAX_NOME];
    char numero [MAX_NUMERO];
}contatto;

typedef struct Srubrica{

    int num_inseriti;
    contatto db[MAX_NUM_CONTATTI];
}rubrica;

int inserisci(rubrica *r, char * nome, char * numero);
char* trova_numero_da_nome(rubrica* r, char* nome);
void stampa_rubrica(rubrica* r);
bool controllo_numero(char* numero);

int main (){

    rubrica rubrica_dei_contatti;
    int opzione = 0;
    char nome_contatto[MAX_NOME];
    char numero_contatto[MAX_NUMERO];

    int dimensione = 0;
    while(opzione != 4){
        printf("Scegliere una delle seguenti operazioni: \n1.Inserisci un contatto\n2.Trova il numero di una persona\n3.Stampa la rubrica\n4.Esci dal programma\n");
        scanf("%d", &opzione);
        while(opzione > 4 || opzione < 1){
            printf("Errore!Numero inserito non valido\nScegliere una delle seguenti operazioni: \n1.Inserisci un contatto\n2.Trova il numero di una persona\n3.Stampa la rubrica\n4.Esci dal programma\n");
        scanf("%d", &opzione);
        }
        switch (opzione)
        {
        case 1:
            scanf("%*c");
            printf("Inserisci il nome del contatto: ");
            fgets (nome_contatto, MAX_NOME, stdin);
            dimensione = strlen(nome_contatto);
            nome_contatto[dimensione-1]='\0';
            printf("Inserire il numero di telefono del contatto: ");
            fgets(numero_contatto, MAX_NUMERO, stdin);
            while(controllo_numero(numero_contatto)== false){
                 printf("Inserire il numero di telefono del contatto: ");
                fgets(numero_contatto, MAX_NUMERO, stdin);
            }
            inserisci(&rubrica_dei_contatti, nome_contatto, numero_contatto);            
            break;
        case 2:
            scanf("%*c");
            printf("Inserisci il nome del contatto: ");
            fgets (nome_contatto, MAX_NOME, stdin);
            dimensione = strlen(nome_contatto);
            nome_contatto[dimensione-1]='\0';
            *numero_contatto = *trova_numero_da_nome(&rubrica_dei_contatti, nome_contatto);
            if(&numero_contatto == NULL){
                printf("Non c'è nessuna persona con quel nome in rubrica!\n");
            }
            else{
                printf("Il numero di telefono di %s è %s\n", nome_contatto, numero_contatto);
            }
            break;
        case 3:
            stampa_rubrica(&rubrica_dei_contatti);
            break;
        
        default:
            break;
        }
    }

    return 0;
}

int inserisci(rubrica *r, char * nome, char * numero){

    contatto *p;
    if(r->num_inseriti == MAX_NUM_CONTATTI){
        printf("La rubrica è piena!\n");
        return -1;
    }
    p = &r->db[r->num_inseriti]; //Il puntatore avrà l'indirizzo db[numero_inserito]

    strcpy(p->nome, nome);
    strcpy(p->numero, numero);
    p->id = r->num_inseriti;
    r->num_inseriti++;
    printf("Contatto memorizzato correttamente!\n");
    return 0;
}

char* trova_numero_da_nome(rubrica* r, char* nome){
    int i;
    contatto* p;
    for(i = 0; i <r->num_inseriti; i++){
        p = &r->db[i];
       if(strcmp(p->nome, nome)== 0){
           return p->numero;
       }

    }
    char* pe;
    pe = 0;
           return pe;
}

void stampa_rubrica(rubrica* r){

    int i;
    contatto* p;
    printf("\nStampa rubrica: %d contatti\n", r->num_inseriti);

    for(i = 0; i <r->num_inseriti; i++){
        p = &r->db[i];

        printf("%s %s\n", p->nome, p->numero);
    }
    return;
}

bool controllo_numero(char* numero){
    int grandezza_numero = strlen(numero)-1;
    if(grandezza_numero < 10){
        printf("Numero di telefono non valido!È troppo corto\n");
        return false;
    }
    for(int i = 0; i < grandezza_numero; i++){
        if(*(numero+i) < '0' || *(numero+i) > '9'){
            return false;
        }
    }
    return true;
}

