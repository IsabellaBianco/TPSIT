/*
Scrivere il seguente programma che crea e stampa una lista. Studiarne il funzionamento ed inserire i
commenti necessari a spiegarlo.
*/
#include <stdio.h>
#include <stdlib.h>
struct El
{
int valore;
struct El* next;
};

void stampa_lista(struct El* head);
void push(struct El* head, int n);

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
                
                push(l, n);
                l = l->next;
                
                printf("%d", l->valore);
                
            }

        }
    } while (n>=0);
    
    l=lista; /* l punta alla testa(lista) */
    stampa_lista(l);
   
    return 0;
}
void push(struct El* head, int n){

    head->next = (struct El*) malloc(sizeof(struct El));
    head = head->next;
    head->valore = n;
    head->next = NULL;

    return;
}

void stampa_lista(struct El* head){

    printf("numeri inseriti: \n");
    while (head!=NULL)
    {
        printf("%d - %p \n",head->valore, head->next);   
        head = head->next; /* l diventa al puntatore next */
    }
    printf("\n");

    return;
}
