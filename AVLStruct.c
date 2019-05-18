#include <stdlib.h>

#include "AVLStruct.h"

void imprimeArvore(Nodo_t *nodo, int altura) {
    if (nodo == NULL)
        return;
    imprimeArvore(nodo->esq, altura+1);
    printf("%d,%d\n", nodo->chave, altura);
    imrpimeArvore(nodo->dir, altura+1);
}

Nodo_t *insereAVL(Nodo_t *nodo, int chave) {
    // Insere mantendo prop. BST
    // Inicializa nova arvore se necessario. Cria nodo de altura 1
    if (nodo == NULL) 
        return novoNodo(chave);
    if (chave > nodo->chave)
        nodo->dir = insereAVL(nodo->dir, chave);
    else if(chave < raiz->chave)
        nodo->esq = insereAVL(nodo->esq, chave);
    else
        return nodo;
    // Atualiza altura do nodo
    atualizaAltura(nodo);
    //Balanceamento AVL
    return balanceamentoAVL(nodo);
}

Nodo *balanceamentoAVL(Nodo_t *nodo) {
    if (nodo->fator > 1) {
        // Desbalanceamento na direita
        if (nodo->dir->fator >= 0)
            return rotEsq(nodo);
        else {
            nodo->esq = rotDir(nodo);
            return rotEsq(nodo);
        }   
    } else if (nodo->fator < 1) {
        // Desbalanceamento na esquerda
        if (nodo->esq->fator <= 0)
            return rotDir(nodo);
        else {
            nodo->dir = rotEsq(nodo);
            return rotDir(nodo);
        }        
    }
    // Nodo balanceado.
    return nodo;
}

Nodo *novoNodo(int chave) {
    // Cria um novo nodo e retorna ponteiro para o mesmo
    Nodo_t *novo = (Nodo*) malloc(sizeof(Nodo));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->chave = chave;
    novo->altura = 1;
    novo->fator = 0;
    return novo;
}

void atualizaAltura(Nodo_t *nodo) {
    int altEsq = -1;
    int altDir = -1;
    if (nodo->esq != NULL)
        altEsq = nodo->esq->altura;
    if (nodo->dir != NULL)
        altDir = nodo->dir->altura;
    nodo->altura = max(altEsq, altDir) + 1;
    nodo->fator = altEsq - altDir;
}

Nodo_t *rotDir(Nodo_t *a) {
    Nodo_t *b = a->esq;
    a->esq = b->dir;
    b->dir = a;
    atualizaAltura(a);
    atualizaAltura(b);
    return b;
}

Nodo_t *rotEsq(Nodo_t *a) {
    Nodo_t *b = a->dir;
    a->dir = b->esq;
    b->esq = a;
    atualizaAltura(a);
    atualizaAltura(b);
    return b;
}

int max(int a, int b) {
    if (a >= b)
        return a;
    return b;
}
