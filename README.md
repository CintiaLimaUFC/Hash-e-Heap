# Hash-e-Heap
Desenvolvimento do Hash com tratamento externo e interno e Heap mínimo e máximo.

## HASH
Ao executar o arquivo aparece um menu com as seguintes com as funções de dispersão.<br />
Após escolher a função aparece um novo menu com as seguintes opções:

1- Buscar: função que busca um elemento na estrutura.<br />
2- Inserir: função para digitar cada elemento para ser inserido na estrutura.<br />
3- Remover: função para remover um elemento da estrutura.<br />
5- Imprimir: função que imprime a estrutura na ordem.<br />

### Hash externo
Imprime a estrutura da seguinte forma:<br />
[X] -> A -> B -> C

X = Posição no vetor<br />
A,B,C = Chaves em ordem da lista encadeada

### Hash interno
Imprime a estrutura da seguinte forma:<br />
00-(A)   01-(B)   02-(C) …. 98-(D)   99-(E)

00, 01, 02, … , 98, 99 = Posição no vetor <br />
A, B, C, D, E = Chaves. Caso, seja -1, significa que o espaço no vetor ainda não foi preenchido 



## HEAP
Ao executar o arquivo aparece um menu com as seguintes opções:

1- Construir: função receber os valores para construção da Heap<br />
2- Inserir: função para digitar cada elemento para ser inserido na estrutura <br />
3- Remover: função para remover um elemento da estrutura <br />
4- HeapSort: função que ordena o vetor usando o alg. HeapSort <br />
5- Imprimir: função que imprime a estrutura na ordem <br />

Aconselha-se começar escolhendo a função 1-Construir, para digitar todos os elementos que se desejar colocar na estrutura. Ao executar essa função primeiro aparece um espaço para digitar a quantidade de números (N) que serão inseridos e posteriormente o espaço para digitar o N números
