#include <stdlib.h>
#include <stdio.h>
#include "AVLStruct.h"

void imprimeArvore(nodo_t *nodo, int altura) {
    if (nodo == NULL)
        return;
    imprimeArvore(nodo->esq, altura+1);
    printf("%d,%d,%d\n", nodo->chave, altura, nodo->fator);
    imprimeArvore(nodo->dir, altura+1);
}

nodo_t *insereAVL(nodo_t *nodo, int chave) {
    // Insere mantendo prop. BST
    // Inicializa nova arvore se necessario. Cria nodo de altura 1
    if (nodo == NULL) 
        return novoNodo(chave);
    //printf("Chave: %d\n Altura: %d\n Fator:%d\n----\n",
    //        nodo->chave, nodo->altura, nodo->fator);
    if (chave > nodo->chave)
        nodo->dir = insereAVL(nodo->dir, chave);
    else if(chave < nodo->chave)
        nodo->esq = insereAVL(nodo->esq, chave);
    else
        return nodo;
    // Atualiza altura do nodo
    atualizaAltura(nodo);
    //Balanceamento AVL
    return balanceamentoAVL(nodo);
}

nodo_t *balanceamentoAVL(nodo_t *nodo) {
    if (nodo->fator > 1) {
        // Desbalanceamento na esquerda
        if (nodo->esq->fator > 0) {
            return rotDir(nodo);

        } else {
            nodo->esq = rotEsq(nodo->esq);
            return rotDir(nodo);
        }   
    } else if (nodo->fator < -1) {
        // Desbalanceamento na direita
        if (nodo->dir->fator < 0) {
            return rotEsq(nodo);
        } else {
            nodo->dir = rotDir(nodo->dir);
            return rotEsq(nodo);
        }        
    }
    // Nodo balanceado.
    return nodo;
}

nodo_t *novoNodo(int chave) {
    // Cria um novo nodo e retorna ponteiro para o mesmo
    nodo_t *novo = (nodo_t*) malloc(sizeof(nodo_t));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->chave = chave;
    novo->altura = 0;
    novo->fator = 0;
    return novo;
}

void atualizaAltura(nodo_t *nodo) {
    int altEsq = -1;
    int altDir = -1;
    if (nodo->esq != NULL)
        altEsq = nodo->esq->altura;
    if (nodo->dir != NULL)
        altDir = nodo->dir->altura;
    nodo->altura = max(altEsq, altDir) + 1;
    nodo->fator = altEsq - altDir;
}

nodo_t *rotDir(nodo_t *a) {
    nodo_t *b = a->esq;
    a->esq = b->dir;
    b->dir = a;
    atualizaAltura(a);
    atualizaAltura(b);
    return b;
}

nodo_t *rotEsq(nodo_t *a) {
    nodo_t *b = a->dir;
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
