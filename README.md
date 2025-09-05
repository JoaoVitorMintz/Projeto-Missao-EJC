# Projeto-Missao-EJC

Na matéria de Projeto e Análise de Algoritmos 2, recebemos como primeiro projeto do quarto semestre desenvolver um código recursivo que determine se é possível, a partir de uma posição inicial, alcançar a sala onde determinada chave está escondida, respeitando o tipo de movimentação de cada trecho do Edifício João Calvino (Prédio presente dentro do campus da Universidade Presbiteriana Mackenzie).

O edifício é representado por vários andares, onde em cada corredor há restrições de movimento:
    ● Alguns corredores permitem apenas deslocamento horizontal (esquerda ↔ direita).
    ● Outros permitem apenas deslocamento vertical (subir ↑ ou descer ↓ entre andares).

## O funcionamento é o seguinte:

Primeiro, o programa lerá um inteiro n, representando a quantidade de andares do edifício (ou linhas do mapa), e, em seguida, receberá n linhas com as marcações:
● H indica corredores que permitem apenas movimento horizontal (esquerda ou direita).
● V indica corredores que permitem apenas movimento vertical (subida ou descida de andares). 
● * marca a sala onde a Chave Perdida está escondida.

Depois, o programa lerá dois inteiros representando a posição inicial (linha e coluna), sendo que a linha 0 representa o Térreo, linha 1 o Primeiro Andar, e assim por diante. Escreva um programa iterativo para resolver esta missão.

Entrada:
● Um número inteiro n.
● n linhas contendo os caracteres H, V ou *, separados por espaço.
● Dois inteiros correspondendo à linha (andar) e à coluna iniciais.
Saída:
Se o trajeto até a chave for possível, imprimir:
```
Chave encontrada no Edifício João Calvino!
```
Caso contrário, imprimir:
```
Não conseguimos encontrar a chave no Edifício João Calvino.
```

## Exemplos de Entrada e Saída:

### Teste 01

Entrada
5
HVVVHV
HHVVVV
HVHVVH
*HVVHV
HHHVHH
0 0

Saída
```
Chave encontrada no Edifício João Calvino!
```

### Teste 02

Entrada
5
HVVVHV
HHVVVV
HVHVVH
*HVVHV
HHHVHH
0 4

Saída
```
Não conseguimos encontrar a chave no Edifício João Calvino.
```

### Teste 03

Entrada
7
HVVVHHHVV
HVVVHVVHV
HHHVVHHHV
VVHVVHVVV
HHHVVHVH*
HHVHHHHHH
VVVVVVVVV
0 4

Saída
```
Chave encontrada no Edifício João Calvino!
```

## Alunos:
 - João Vitor Garcia Aguiar Mintz
 - Giovanni 
 - Yan Andreotti