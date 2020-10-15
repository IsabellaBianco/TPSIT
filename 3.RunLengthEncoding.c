//Isabella Bianco   4BROB

//Includo delle librerie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 100

int main (){

    //Dichiaro delle variabili
    char e_d, a[MAX];
    bool corretto;
    corretto = false;
    int lunghezza_parola, i;

    while(corretto == false){
        //Chiedo all'utente se vuole fare encoding o decoding
        printf("Se si vuole eseguire l'operazione di encoding prema e, se si vuole fare un'operazione di decoding prema d: ");
        scanf("%c", &e_d);
        //Verifico che non abbia inserito altri caratteri
        if(e_d == 'e' || e_d == 'd'){
            corretto = true;
            
        }
        else{
            printf("Errore!Il carattere inserito non è valido!\n");
            scanf("%*c"); //Salto un carattere
        } 
    }

    corretto = false;
    //Chiedo di inserire una stringa
    printf("Inserire una stringa: ");
    scanf("%s", a);
    //Guardo la lunghezza della stringa 
    lunghezza_parola = strlen(a);

    if(e_d != 'd'){ //Controllo se nel caso di encoding la stringa non contenga numeri
        while(corretto == false){
            
            if(e_d == 'e'){ 
                corretto = true;
                for(i=0; i<lunghezza_parola; i++){  //controllo cella per cella
                
                    if(a[i]>= '0' && a[i]<= '9'){ 
                        //Se il carattere è un numero
                         i = lunghezza_parola; 
                        printf("Errore!La stringa non può contenere numeri!\n"); //Stampo questa stringa
                        corretto = false;
                        printf("Inserire una stringa: ");//E chiedo all'utente di inserire nuovamente la stringa
                        scanf("%s", a);
                        lunghezza_parola = strlen(a);//Guardo la lunghezza della stringa
                    }

                }
            
            }

        }
    }
   

    if(e_d == 'e'){
    //Funzione encoding
        int t, f, ripetizione = 1;
        bool uguale;
        for(t=0; t<lunghezza_parola; t++){ //Vado avanti fino alla fine di tutti i caratteri
            uguale = true;

            for(f = t+1; uguale == true; f++){ //Guardo se i caratteri sono uguali

                if(a[t]==a[f]){ //Sono uguali incremento ripetizione
                    ripetizione++;
                }
                else{ //Se sono diverse
                   uguale = false;
                   if(ripetizione == 1){//Se ripetizione è uguale a 1 stampo solo il carattere
                       printf("%c", a[t]);
                   }
                   else{ //Altrimenti stampo il numeo di occorrenze e poi il carattere
                    printf("%d%c", ripetizione, a[t]);
                   }
                }
            }
            
            t=f-2; //t diventa uguale a f-2

            ripetizione = 1; //Resetto ripetizione a 1

        }
    }

    if(e_d == 'd'){
        //Decoding
        int g, m, numero_cifre =0, numero;

        for(g=0; g<lunghezza_parola; g++){ //Vado avanti fino alla fine di tutti i caratteri

            for(m=g; a[m] >= '0' && a[m] <='9'; m++){ //Verifico se la cella corrente contiene un numero
                
                if(a[m] >= '0' && a[m] <='9'){ //Se si allora faccio il numero in codice ASCII - 48 (ovvero lo 0 in ASCII)
                    numero = a[m]-48;
                    
                    numero_cifre = numero_cifre*10 + numero; //Aggiungo il numero a numero_cifre
                }

            }
            
        
        
        int y;
        for(y=0; y<numero_cifre; y++){  //Stampo tante volte il carattere quante sono il numero_cifre

            printf("%c", a[m]);
        }
        g = m;
        numero = 0;
        numero_cifre = 0;
        }
        if(numero_cifre == 0){ //Se invece si ha solo un occorrenza la stampo qui una singola volta
            printf("%c", a[m]);
        }

    }
    
    


    return 0;
}
