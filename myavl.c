#include <stdio.h>
#include <stdlib.h>

int main() {
    char instrucao;
    int chave;
    // Loop de operacoes na arvore
    // Quebra se scanf falahar em colher stdin
    Nodo *arvore = NULL;
    while (scanf("%c %d\n", &instrucao, &chave) >= 0) {
        // Operacoes na arvore
        if (instrucao == 'i')
            
        else if (instrucao == 'r')
            
        else
            exit(1);
    }
    escreve_arvore(arvore);
    return 0;
}
