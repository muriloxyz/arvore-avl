#include <stdlib.h>
#include <stdio.h>
#include "AVLStruct.h"

/* Esta funcao recebe a raiz de uma arvore e realiza a impressao 
   EM ORDEM da arvore (as chaves acompanham sua altura na arvore) */
void imprimeArvore(nodo_t *nodo, int altura) {
    if (nodo == NULL)
        return;
    imprimeArvore(nodo->esq, altura+1);
    printf("%d,%d\n", nodo->chave, altura);
    imprimeArvore(nodo->dir, altura+1);
}

/* Faz a insercao AVL! Primeiro executa-se uma insercao BST
   Atualiza a altura/fator de balanceamento e executa o 
   balanceamento se necessario */
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

/* Faz a remocao AVL! Primeira executa-se uma remocao BST
   Atualiza a altura/fator de balanceamento e executa o 
   balanceamento se necessario */
nodo_t *removeAVL(nodo_t *nodo, int chave) {
    // Remocao BST
    if (nodo == NULL)
        return nodo;

    if (chave > nodo->chave)
        nodo->dir = removeAVL(nodo->dir, chave);
    else if (chave < nodo->chave) 
        nodo->esq = removeAVL(nodo->esq, chave);
    else {
       if ((nodo->dir != NULL) && (nodo->esq != NULL)) {
           nodo_t *antecessor = achaAntecessor(nodo->esq);
           nodo->chave = antecessor->chave;
           nodo->esq = removeAVL(nodo->esq, antecessor->chave);
       } else if (nodo->dir != NULL) {
            nodo_t *aux = nodo;
            nodo = nodo->dir;
            free(aux);   
       } else if (nodo-> esq != NULL) {
           nodo_t *aux = nodo;
           nodo = nodo->esq;
           free(aux);
       } else {
           free(nodo);
           nodo = NULL;
       }
    }

    if (nodo == NULL) return nodo;
    atualizaAltura(nodo);
    return balanceamentoAVL(nodo);

}
/* Acha o nodo com maior chave em uma arvore */
nodo_t *achaAntecessor(nodo_t *nodo) {
    nodo_t *aux = nodo; 
    while (aux->dir != NULL)
        aux = aux->dir;
    //printf("Antecessor:%d \n", aux->chave);
    return aux;
}

nodo_t *balanceamentoAVL(nodo_t *nodo) {
    // Desbalanceamento na esquerda
    if (nodo->fator > 1) {
        if (nodo->esq->fator >= 0) {
            return rotDir(nodo);

        } else {
            nodo->esq = rotEsq(nodo->esq);
            return rotDir(nodo);
        }   
    }

    // Desbalanceamento na direita
    if (nodo->fator < -1) {
        if (nodo->dir->fator <= 0) {
            return rotEsq(nodo);
        } else {
            nodo->dir = rotDir(nodo->dir);
            return rotEsq(nodo);
        }        
    }
    // Nodo balanceado.
    return nodo;
}

/* Dada uma chave, cria-se um novo nodo com altura e balanceamento zero
   Os ponteiros para filhos sao nulos */
nodo_t *novoNodo(int chave) {
    nodo_t *novo = (nodo_t*) malloc(sizeof(nodo_t));
    novo->esq = NULL;
    novo->dir = NULL;
    novo->chave = chave;
    novo->altura = 0;
    novo->fator = 0;
    return novo;
}


/* Esta funcao atualiza a altura E fator de balanceamento do nodo!
   Utiliza informacao dos filhos do nodo para calcular a atualizacao
   Importante utilizar de baixo para cima */
void atualizaAltura(nodo_t *nodo) {
    int altEsq = -1;
    int altDir = -1;
    // Se filhos nao forem nulos, entao atualize as variaveis 
    if (nodo->esq != NULL)
        altEsq = nodo->esq->altura;
    if (nodo->dir != NULL)
        altDir = nodo->dir->altura;
    nodo->altura = max(altEsq, altDir) + 1;
    nodo->fator = altEsq - altDir;
}

/* Funcao BST de rotacao para direita */
nodo_t *rotDir(nodo_t *a) {
    //printf("rotdir\n");
    nodo_t *b = a->esq;
    a->esq = b->dir;
    b->dir = a;
    atualizaAltura(a);
    atualizaAltura(b);
    return b;
}
/* Funcao BST de rotacao para esquerda */
nodo_t *rotEsq(nodo_t *a) {
    //printf("rotesq\n");
    nodo_t *b = a->dir;
    a->dir = b->esq;
    b->esq = a;
    atualizaAltura(a);
    atualizaAltura(b);
    return b;
}

/* Funcao auxiliar que recebe dois inteiros e retorna o maior deles */
int max(int a, int b) {
    if (a >= b)
        return a;
    return b;
}
