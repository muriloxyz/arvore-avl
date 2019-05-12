#ifndef __AVLSTRUCT__
#define __AVLSTRUCT__

typedef struct Nodo {
    Nodo *esq;
    Nodo *pai;
    Nodo *dir;
    int chave;
    int altura;
}Nodo;

#endif
