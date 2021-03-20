/*
reare un programma in C che facendo uso di array dinamici e della aritmetica dei puntatori (OBBLIGATORIO), legga il file dati.csv e lo carichi in memoria.
Successivamente calcolare:
1) top 3 delle regioni per numero di ricoveri in terapia intensiva
2) totale dei ricoverati in terapia intensiva
3) top 3 delle regioni con meno casi totali positivi.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4096

//Definisco una strcut con tutti i parametri presenti all'interno del file .csv
typedef struct SdatiCovid{

    char data[MAX];
    char stato[MAX];
    int codice_regione;
    char Regione[MAX];
    float lat;
    float longi;
    int ricoverati_con_sintomi;
    int terapia_intensiva;
    int totale_ospedalizzati;
    int isolamento_domiciliare;
    int totale_positivi;
    int variazione_totale_positivi;
    int nuovi_positivi;
    int dimessi_guariti;
    int deceduti;
    int casi_da_sospetto_diagnostico;
    int casi_da_screening;
    int totale_casi;
    int tamponi;
    int casi_testati;

}datiCovid;

//Questa funzione memorizza i dati del file 
void memorizzazione_dati(datiCovid* dati_totali, int dimensione, FILE* fin);
//Memorizza un intero
void memorizzazione_intero(FILE* fin, int* intero);
//Memorizza un float
void memorizzazione_float(FILE* fin, float* floatingPoint);
//Memorizza una stringa
void memorizzazione_stringa(FILE* fin, char* stringa);
//Calcola le 3 regioni con il maggior numero di casi in terapia intensiva
void top_3_terapia_intensiva(datiCovid* dati_totali, int dimensione);
//Calcola il massimo tra una serie di numero e tenendo conto di due limitazioni
int trova_maggiore(datiCovid* dati_totali, int lim_1, int lim_2, int dimensione);
//Calcola il totale dei casi in terapia intensiva
void totale_TP(datiCovid* dati_totali, int dimensione);
//Calcola le 3 regioni con il minor numero di casi positivi
void top_3_casi_positivi(datiCovid* dati_totali, int dimensione);
//Calcola il minimo tra una serie di numeri e tenendo conto di due limitazioni
int trova_minore(datiCovid* dati_totali, int lim_1, int lim_2, int dimensione);


int main(){
    FILE* fin;
    int dimensione = 0;
    //Apro il file
    if((fin=fopen("dati.csv", "r"))==NULL){
        printf("Errore nell'apertura del file!\n");
        return -1;
    }
    char t;
    //Conto le righe
    while((t= fgetc(fin))!=EOF){
        if (t == '\n'){
            dimensione++;
        }
    }
    dimensione--; //Decremento dimensione perché non tengo conto della prima riga dove ci sono solo il nome dei parametri
    rewind(fin); //Faccio si che fin punti di nuovo all'inizio del file
    char* prova;
    //Salto la prima riga
    fgets(prova, MAX, fin);

    //Alloco dinamicamente un array di datiCovid
    datiCovid* datiCovid_totali;
    datiCovid_totali = (datiCovid*) malloc(dimensione*sizeof(datiCovid));
    
    //Chiamo le seguenti funzioni per memorizzare i dati e calcolare quello che mi è stato chiesto
    memorizzazione_dati(datiCovid_totali, dimensione, fin);
    top_3_terapia_intensiva(datiCovid_totali, dimensione);
    totale_TP( datiCovid_totali, dimensione);
    top_3_casi_positivi(datiCovid_totali, dimensione);
    

    //Libero l'aria di memoria e chiudo il file
    free(datiCovid_totali);
    fclose(fin);
    return 0;
}

void memorizzazione_dati(datiCovid* dati_totali, int dimensione, FILE* fin){

    //Nel ciclo memorizzo N volte (numero di righe) tutti i parametri richiesti richiamando ogni volta una funzione in base al 
    //tipo che voglio memorizzare

    for(int i = 0; i < dimensione; i++){
        memorizzazione_stringa(fin, (dati_totali+i)->data);
        memorizzazione_stringa(fin, (dati_totali+i)->stato);
        memorizzazione_intero(fin, &(dati_totali+i)->codice_regione);
        memorizzazione_stringa(fin, (dati_totali+i)->Regione);
        memorizzazione_float(fin, &(dati_totali+i)->lat);
        memorizzazione_float(fin, &(dati_totali+i)->longi);
        memorizzazione_intero(fin, &(dati_totali+i)->ricoverati_con_sintomi);
        memorizzazione_intero(fin, &(dati_totali+i)->terapia_intensiva);
        memorizzazione_intero(fin, &(dati_totali+i)->totale_ospedalizzati);
        memorizzazione_intero(fin, &(dati_totali+i)->isolamento_domiciliare);
        memorizzazione_intero(fin, &(dati_totali+i)->totale_positivi);
        memorizzazione_intero(fin, &(dati_totali+i)->variazione_totale_positivi);
        memorizzazione_intero(fin, &(dati_totali+i)->nuovi_positivi);
        memorizzazione_intero(fin, &(dati_totali+i)->dimessi_guariti);
        memorizzazione_intero(fin, &(dati_totali+i)->deceduti);
        memorizzazione_intero(fin, &(dati_totali+i)->casi_da_sospetto_diagnostico);
        memorizzazione_intero(fin, &(dati_totali+i)->casi_da_screening);
        memorizzazione_intero(fin, &(dati_totali+i)->totale_casi);
        memorizzazione_intero(fin, &(dati_totali+i)->tamponi);
        fscanf(fin, "%d\n", &dati_totali->casi_testati);
  }

    return;

}
//Memorizzo un intero
void memorizzazione_intero(FILE* fin, int* intero){
    fscanf(fin, "%d,", intero);
    return;
}
//Memorizzo un float
void memorizzazione_float(FILE* fin, float* floatingPoint){
    fscanf(fin, "%f,", floatingPoint);
    return;
}
//Memorizzo una stringa
void memorizzazione_stringa(FILE* fin, char* stringa){
    int i;
    for( i = 0; (stringa[i] =fgetc(fin))!=','; i++){
    }
    *(stringa+i) = '\0';

}


void top_3_terapia_intensiva(datiCovid* dati_totali, int dimensione){
    int max1 = -5;
    int max2; -4;
    int indice = -3;
    //Trovo il massimo tenendo conto di tutte le regioni
    indice = trova_maggiore(dati_totali, max1, max2, dimensione);
    printf("La prima regione con %d persone in terapia intensiva è la/il %s\n", (dati_totali+indice)->terapia_intensiva, (dati_totali+indice)->Regione);
    //Trovo il massimo escludendo quella con il maggior numero di terapie intensive
    max1 = (dati_totali+indice)->terapia_intensiva;
    indice = trova_maggiore(dati_totali, max1, max2, dimensione);
    printf("La seconda regione con %d persone in terapia intensiva è la/il %s\n", (dati_totali+indice)->terapia_intensiva, (dati_totali+indice)->Regione);
     //Trovo il massimo escludendo le 2 con il maggior numero di terapie intensive
    max2 = (dati_totali+indice)->terapia_intensiva;
    indice = trova_maggiore(dati_totali, max1, max2, dimensione);
    printf("La terza regione con %d persone in terapia intensiva è la/il %s\n", (dati_totali+indice)->terapia_intensiva, (dati_totali+indice)->Regione);
    return;
}


int trova_maggiore(datiCovid* dati_totali, int lim_1, int lim_2, int dimensione){
    int max = 0;
    int indice;
    for(int i = 0; i < dimensione; i++){
        //Trovo il maggiore e controllo che sia diverso dalle limitazioni
        if((dati_totali+i)->terapia_intensiva > max && (dati_totali+i)->terapia_intensiva != lim_1 && (dati_totali+i)->terapia_intensiva != lim_2){
            max = (dati_totali+i)->terapia_intensiva;
            indice = i;
        }
    }
    return indice;
}

void totale_TP(datiCovid* dati_totali, int dimensione){
    int totaleTP = 0;
    //Calcolo la somma delle terapie intensive delle varie regioni
    for(int i = 0; i < dimensione; i++){

        totaleTP = totaleTP + ((dati_totali+i)->terapia_intensiva);      
    }
    printf("Il totale di persone ricoverate in terapia intensiva in Italia è %d\n", totaleTP);

    return;
}


void top_3_casi_positivi(datiCovid* dati_totali, int dimensione){

    int min1 = -5;
    int min2; -4;
    int indice = -3;
    //Trovo il minimo
    indice = trova_minore(dati_totali, min1, min2, dimensione);
    printf("La regione con meno persone positive (%d) è la/il %s\n", (dati_totali+indice)->totale_positivi, (dati_totali+indice)->Regione);
    //Trovo il minimo escludendo il minore
    min1 = (dati_totali+indice)->totale_positivi;
    indice = trova_minore(dati_totali, min1, min2, dimensione);
    printf("La seconda regione con meno persone positive (%d) è la/il %s\n", (dati_totali+indice)->totale_positivi, (dati_totali+indice)->Regione);
    //Trovo il minimo escludendo i due minori
    min2 = (dati_totali+indice)->totale_positivi;
    indice = trova_minore(dati_totali, min1, min2, dimensione);
    printf("La terza regione con meno persone positive (%d) è la/il %s\n", (dati_totali+indice)->totale_positivi, (dati_totali+indice)->Regione);
    
    return;
}

int trova_minore(datiCovid* dati_totali, int lim_1, int lim_2, int dimensione){

    int min =  10000000;
    int indice;
    for(int i = 0; i < dimensione; i++){
        //Trovo il minimo e tengo conto che sia diverso dalle limitazioni
        if((dati_totali+i)->totale_positivi < min && (dati_totali+i)->totale_positivi != lim_1 && (dati_totali+i)->totale_positivi != lim_2){
            min = (dati_totali+i)->totale_positivi;
            indice = i;
        }
    }

    return indice;
}
