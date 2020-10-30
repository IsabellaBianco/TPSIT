#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    FILE* fin;

    char car;
    //Apro il file e verifico la corretta apertura
    if((fin = fopen("rna.txt", "r"))== NULL){
        printf("Errore nell'apertura del file!\n");
    }
    //Dichiaro ed inizializzo le variabili
    int a = 0, c = 0, g = 0, t = 0;
    int n;


    while((car = fgetc(fin))!= EOF){

        //Leggo un carattere e nello switch guardo se il carattere acquisito è uguale ad a, c, g o t
            switch(car){

                case 'a':
                    a++;
                    break;
                case 'g':
                    g++;
                    break;
                case 't':
                    t++;
                    break;
                case 'c':
                    c++;
                    break;
                default:
                break;
            }
        
    }

    printf("a:%d\nc:%d\ng:%d\nt:%d\n", a, c, g, t);
    fclose(fin);
    return 0;
}
