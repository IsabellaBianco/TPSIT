/*
Modificare il programma sopra creando due funzioni: push per caricare la lista e stampa-lista per
stamparla.
*/
#include <stdio.h>
#include <stdlib.h>
struct El
{
int valore;
struct El* next;
};

int main(){
    int n;
    struct El* lista;
    struct El* l;
    lista=NULL; /*Il puntatore lista è uguale a NULL*/

    do
    {
        printf("Inserisci un naturale o -1 per terminare\n");
        scanf("%d",&n);
        if (n>=0)
        {
            if (lista==NULL) /* se il puntatore lista è uguale a NULL */
            {
                /* allora lo alloco dinamicamente */

                lista = (struct El*) malloc(sizeof(struct El));

                l = lista;
                }
            else /* altrimenti*/
            {
                /* alloco dinamicamente il puntatore l->next */

                l->next = (struct El*) malloc(sizeof(struct El));

                l = l->next;
            }
            l->valore = n; /* il valore diventa uguale ad n  */
            l->next = NULL; /*il puntatore next punta a NULL */
        }
    } while (n>=0);

    l=lista; /* l punta alla testa(lista) */
    printf("numeri inseriti: ");
    while (l!=NULL)
    {
        printf("%d - %p \n",l->valore, l->next);
        l=l->next; /* l diventa al puntatore next */
    }
    printf("\n");
    return 0;
}
