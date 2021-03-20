/*Nel file instagram.csv trovate alcuni dati esportati dal vostro account Instagram. 
Ogni riga del file corrisponde ad un post pubblicato nel 2020 e su ogni riga trovate in ordine: mese, giorno del mese, 
identificativo del post, numero di like.
Scrivere un programma in C, che faccia uso della allocazione dinamica e della aritmetica dei puntatori (requisiti obbligatori):
 il programma deve richiedere all'utente il nome di un mese e poi deve fornire in output il numero di post di quel mese ed
  il numero totale di like ricevuto durante quel mese.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

//Definisco la struct
typedef struct Spost_instagram{
    char mese [MAX];
    int giorno;
    int ID_post;
    int like;

}post_instagram;
//Definisco le varie funzioni
int conta_righe(FILE* fin);
void memorizzazione_del_file(FILE* fin, post_instagram* post_tot, int dimensione);
void memorizza_intero(FILE*fin, int* numero);
void memorizzazione_stringa(FILE* fin, char* stringa);
void trova_dati(post_instagram* post_totali, int dimensione);

int main (){
    //Apri il file
    FILE* fin;
    if((fin = fopen("instagram.csv", "r"))== NULL){
        printf("Errore nell'apertura del file!\n");
        return -1;
    }
    //Chiamo la funzione conta_righe
    int dimensione = conta_righe(fin);
    //Alloco dinamicamente l'array di post_instagram
    post_instagram* post_totali;
    post_totali = (post_instagram*) malloc(dimensione*sizeof(post_instagram));
    
    rewind(fin); //Il puntatore a file torna  all'inizio
    //Chiamo la funzione per memorizzare il file
    memorizzazione_del_file(fin, post_totali, dimensione);
    //Chiamo la funzione per verificare i post e i like di un determinato mese
    trova_dati(post_totali, dimensione);
    

    free(post_totali);
    fclose(fin);

    return 0;
}
//Contro le righe alla fine decremento di una perché non tengo conto della prima
int conta_righe(FILE* fin){
    int numero_post = 0;
    char c;
    //Faccio un ciclo while che conta il numero di righe del file
    while((c = fgetc(fin))!=EOF){ 
        if(c =='\n'){
            numero_post++;
        }
        }    
    return numero_post--;
}

void memorizzazione_del_file(FILE* fin, post_instagram* post_tot, int dimensione){
    //Salto la prima riga
    char c;
    int y = 1;
    while( y != 0){ 
        c = fgetc(fin);
        if(c =='\n'){
            y = 0;
        }
    } 
    //Memorizzo tutti i dati 
    for(int i = 0; i < dimensione; i++){
        memorizzazione_stringa(fin, (post_tot+i)->mese);
        memorizza_intero(fin, &((post_tot+i)->giorno));
        memorizza_intero(fin, &((post_tot+i)->ID_post));
        fscanf(fin, "%d\n", &((post_tot+i)->like));
        
    }

    return;
}
//La funzione che memorizza un numero intero
void memorizza_intero(FILE*fin, int* numero){
        fscanf(fin, "%d,", numero);
    return;
}

//La funzione che memorizza una stringa
void memorizzazione_stringa(FILE* fin, char* stringa){
    int i;
    for( i = 0; (*(stringa+i) = fgetc(fin))!=','; i++){
    }
    *(stringa+i) = '\0';
    return;
}

//Trova il numero di like e di post dato il mese
void trova_dati(post_instagram* post_totali, int dimensione){
    //Chiedo all'utente un file
    char* mese_input = (char*) malloc(MAX*(sizeof(char)));
    printf("Inserire un mese: ");
    fgets(mese_input, MAX, stdin);
    int totale_like = 0; 
    int totale_post = 0;

    //printf("%s", mese_input);
    //COnfronto il mese dato in input con quelli memorizzati
    for(int i = 0; i < dimensione; i++){
        //printf("%s", (post_totali+i)->mese);
        if(mese_input == ((post_totali+i)->mese)){
            totale_like = totale_like + (post_totali+i)->like;
            totale_post++;
        }
    }
    //stampo l'output
    printf("%d", totale_like);
    if(totale_post == 0){
        printf("Non ci sono post per questo mese!\n");
    }
    else{
        printf("Il numero totale di post del mese di %s è %d, mentre il numero totale di like è %d.\n", mese_input, totale_post, totale_like);
    }
    return;
}
