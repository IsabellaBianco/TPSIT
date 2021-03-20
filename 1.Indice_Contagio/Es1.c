//Realizzare un programma che calcoli l'indice di contagio del COVID-19

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Definisco una costante
#define MAX 1000

int main() {

	//Definisco le variabili
	int N;
	float R, A[MAX];

	//Chiedo all'utente di mettere i valori di R e N
	printf("Inserisci il valore R, ovvero quante persone contagia una malato di Covid-19 al giorno: ");
	scanf("%f", &R);
	printf("Inserisci il numero di studenti della classe: ");
	scanf("%d", &N);

	//Inizializzo A[0]
	A[0] = 1;

	printf("Nel giorno 0 ho un contagio\n");

	for (int y = 1; y < MAX; y++) {

		//Calcolo il numero di contagi totali e lo salva dentro ad una cella dell'array
		A[y] = (pow(R, y))*A[0];


		printf("Nel giorno %d ho un numero di contagi pari a %f\n", y, (A[y]));
		
		//Verifico che il numero di contagi sia uguale o maggiore ad N
		if (A[y] >= N) {
			
			printf("Per contagiare tutti gli studenti ci vogliono %d giorni\n", y);
			y = MAX;
		}
		
				

	}

	return 0;
}
