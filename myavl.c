#include <stdio.h>
#include <stdlib.h>
#include "AVLStruct.h"

int main() {
    char instrucao;
    int chave;
    // Loop de operacoes na arvore
    // Quebra se scanf falahar em colher stdin
    nodo_t *arvore = NULL;
    while (scanf("%c %d\n", &instrucao, &chave) >= 0) {
        // Operacoes na arvore
        if (instrucao == 'i')
            arvore = insereAVL(arvore, chave);
        else if (instrucao == 'r')
            printf("nao i");
    }
    imprimeArvore(arvore, 0);
    return 0;
}
