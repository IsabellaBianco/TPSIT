/*Creare un programma che chieda all'utente di inserire dei valori finché lo desidera, infine inserirli in un albero binario e 
e bilanciato*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// STRUTTURA DI UNA ALBERO
typedef struct node{
    struct node* left;
    struct node* right;
    int val;  // si scrive anche: void* data;
    int key;  // numero univoco
}tree_node;

void in_order_view(tree_node* tree);
void insert(tree_node **tree, tree_node* new);

int main(){
    tree_node* root = NULL;
    int valore;
    printf("Inserire un valore o premere -1 per uscire: ");
    scanf("%d", &valore);
    //Inserisco tanti nodi fino a quando l'utente non mette -1
    while(valore !=-1){
        tree_node* nuovoElemento;
        nuovoElemento = (tree_node*) malloc(sizeof(tree_node));
        nuovoElemento->key = valore;
        insert(&root, nuovoElemento);
        printf("Inserire un valore o premere -1 per uscire: ");
        scanf("%d", &valore);
    }
    printf("L'albero è: \n");
    in_order_view(root);

    return 0;
}


// VISTA
void in_order_view(tree_node* tree) {
    if (tree !=NULL) {
        in_order_view(tree->left);
        printf("Key %d, value %d\n", tree->key, tree->val);
        in_order_view(tree->right);
    }

}


// INSERIMENTO
void insert(tree_node **tree, tree_node* new){
    if (*tree == NULL) {
        *tree = new;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }else{
        if (new->key < (*tree)->key) 
            insert(&(*tree)->left, new);
        else if (new->key > (*tree)->key)
            insert (&(*tree)->right, new);
        else
            printf("Chiave duplicata\n");
    }

}
