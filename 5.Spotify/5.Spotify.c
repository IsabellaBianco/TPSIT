#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

//Inizializzo una struttura canzone formata dal numero della canzone il titolo e l'autore
typedef struct s_canzone{

    int numero_canzone;
    char nome_canzone[MAX];
    char autore[MAX];
}canzone;

//Creo una funziona in cui passo due parametri ovvero il puntatore al file e un vettore canzone
int memorizzazione_playlist(canzone* v, FILE* fin);
//Creo la funzione per il random ordering
void random_ordering(int* ordine_canzoni, int numero_canzoni);


int main (){

    //Creo un puntatore di tipo file e apro il file playlist.csv e controllo una corretta apertura
    FILE *fp;

    if((fp = fopen("Playlist.csv", "r")) == NULL){
        printf("Errore nell'apertura del file!\n");
        return -1;
    }
    //Creo un vettore di tipo canzone e di dimensione MAX
    canzone playlist[MAX];
    int  numero_canzoni;
   //Chiamo la funzione per memorizzare i dati della playlist nel vettore di canzoni
   numero_canzoni = memorizzazione_playlist(playlist, fp);

   int ordine_canzoni[numero_canzoni];

    //Chiamo la funzione che crea un ordine randomico per le canzoni
   random_ordering(ordine_canzoni, numero_canzoni);
   printf("L'ordine delle canzoni è: \n");
   for(int f = 0; f < numero_canzoni; f++){
        printf("%d\n", playlist[*(ordine_canzoni+f)].numero_canzone);
        printf("%s\n", playlist[*(ordine_canzoni+f)].nome_canzone);
        printf("%s\n", playlist[*(ordine_canzoni+f)].autore);
   }

    fclose(fp);

    return 0;
}

int memorizzazione_playlist(canzone* v, FILE* fin){

    int u = 0, g = 0, i, j;
    char f[MAX];//Creo un array di appoggio MAX
    //Salvo il numero della canzone della playlist
    fscanf(fin, "%d,", &v[u].numero_canzone);
    //Faccio un ciclo che va a avanti fino alla fine del file
    for (u = 0; fgets(f, 100, fin)!=NULL; u++){  
        //Faccio un for che va avanti fino alla , ovvero memorizza il nome della canzone
        for(i = 0; f[i]!=','; i++){
            v[u].nome_canzone[i]=f[i];
        }
        v[u].nome_canzone[i] = '\0';
        //Faccio un for che memorizza i caratteri tra la , e \n ovvero l'autore
        for(j = i+1; f[j]!='\n'; j++){
        
            v[u].autore[g]= f[j];
            g++;
        }
      
         //Prendo il numero successivo
        fscanf(fin, "%d,", &v[u+1].numero_canzone);
        g = 0;

    }
    return u;

}

void random_ordering(int* ordine_canzoni, int numero_canzoni){


    for(int t = 0; t < numero_canzoni; t++){
        //Scelgo randomicamente la canzone
        *(ordine_canzoni+t) = rand() % numero_canzoni;
        //Verifico che la canzone non sia ancora uscita
        for(int r = 0; r < t; r++){
            if(*(ordine_canzoni+r)== *(ordine_canzoni+t)){
                r = t;
                t--;
            }
        }

    }
    return;

}