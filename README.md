
re AVL

Dado uma entrada de instruções e chaves numéricas, simula-se uma árvore do tipo AVL. A saída será as chaves impressas em ordem, acompanhadas de sua altura na estrutura de dados.
*A raiz tem altura zero!*

------

### Passos para usar:
Dentro da pasta do projeto, use:
```
make 
./myavl < input.txt > output.txt
```
Onde o arquivo input.txt é deste formato:
```
<instrucao> <chave>
<instrucao> <chave>
<instrucao> <chave>
(...)
```
E o arquivo output.txt gerado sera:
```
<chave> <altura>
<chave> <altura>
<chave> <altura>
```
---
### Instruções

*A ser inserido*

---
#### Exemplo
Para o uma entrada: 
```
i 10
i 20
i 30
i 40
i 50
i 45
i 48
r 40
i 5
i 4
i 3
r 50
```
Teremos uma saída:
```
3,3
4,2
5,3
10,1
20,2
30,0
45,2
48,1
```

**Projeto Produzido para a disciplina CI057 da UFPR**
