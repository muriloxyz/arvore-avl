#include <stdlib.h>
#include "AVLStruct.h"

Nodo *insereAVL(Nodo *raiz, int chave) {
    // Inicializa nova arvore se necessario. Cria nodo de altura 0
    if (raiz == NULL) 
        raiz = novoNodo(chave, 0, NULL);
        return raiz;
    // Insercao padrao BST, na folha.
    Nodo *novo = insereBST(chave, raiz, NULL);
    // Atualiza altura dos nodos acima
    atualizaAltura(novo->pai);
    //Balanceamento AVL
    raiz = balanceamentoAVL();
    return raiz;
}

Nodo *insereBST(int chave, Nodo *raiz, Nodo *pai) {
    // Insere mantendo a propriedade BST
    // Ignora chaves repetidas
    if (raiz == NULL)
        return novoNodo(chave, pai);
    if (chave > raiz->chave)
        nodo->dir = insere(chave, raiz->dir, raiz);
    else if (chave < raiz->chave)
        nodo->esq = insere(chave, raiz->esq, raiz);
    return raiz;
}

Nodo *balanceamentoAVL(Nodo *nodo) {
    
}



Nodo *novoNodo(int chave, Nodo *pai) {
    // Cria um novo nodo e retorna ponteiro para o mesmo
    Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->pai = pai;
    novo->chave = chave;
    novo->altura = 0;
    return novo;
}

Nodo *rotDir(Nodo *a) {
    
}

Nodo *rotEsq(Nodo *a) {

}

void atualizaAltura(Nodo *nodo) {
    if (nodo == NULL || nodo->altura >= nodo->filho->altura+1)
        return; 
    nodo->altura++;
    atualizaAltura(nodo->pai);
}
