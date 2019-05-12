#include <stdlib.h>
#include "AVLStruct.h"

Nodo *insereAVL(Nodo *raiz, int chave) {
    // Inicializa nova arvore se necessario. Cria nodo de altura 0
    if (raiz == NULL) 
        raiz = novoNodo(chave, 0, NULL);
        return raiz;
    // Insercao padrao BST, na folha.
    Nodo *novo = insereBST(chave, raiz, NULL);
    
    return raiz;
}

Nodo *insereBST(int chave, Nodo *raiz, Nodo *pai) {
    if (raiz == NULL)
        return novoNodo(chave, pai);
    if (chave >= raiz->chave)
        nodo->dir = insere(chave, raiz->dir, raiz);
    else
        nodo->esq = insere(chave, raiz->esq, raiz)
    return raiz;
}





Nodo *novoNodo(int chave, Nodo *pai) {
    // Cria um novo nodo e retorna ponteiro para o mesmo
    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = pai;
    novo->chave = chave;
    novo->altura = pai->Altura + 1;
    return novo;
}


