#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void construirMatriz(int linhas, int colunas, char** v);
int procurar(int posLinhas, int posColunas, char** v, int tamLinha, int tamColuna);

// TODO: REALIZAR OS TESTES!

int main () {
    int n, m, posLinha, posColuna; // n são as linhas (andares) e m são as colunas (quantidade de quartos);

    printf("Indique o número de andares do prédio: ");
    scanf("%d", &n);
    printf("Indique o número de salas por andar: ");
    scanf("%d", &m);

    // Alocando memória para construção da matriz:
    char **v = malloc(n * sizeof(char *));
    if (v == NULL) {
        perror("Erro ao alocar memória das linhas");
        return 1;
    } 

    for (int i = 0; i < n; i++) {
        v[i] = malloc((m + 1) * sizeof(char));
        if (v[i] == NULL) {
            perror("Erro ao alocar memória das colunas");
            return 1;
        }
    }
    

    construirMatriz(n, m, v);

    printf("\nIndique o andar em que começará a porcurar: ");
    scanf("%d", &posLinha);
    printf("\nIndique a posição da sala que começará a procurar: ");
    scanf("%d", &posColuna);

    // Apresentando a matriz inserida pelo usuário;
    printf("%d\n", n);
    for (int i = n - 1; i >= 0; i--) {
        printf("%s\n", v[i]);
    }
    printf("%d  %d\n", posLinha, posColuna);

    int resposta = procurar(posLinha, posColuna, v, n, m);

    if (resposta == 0) {
        printf("Chave encontrada no Edifício João Calvino!");
    } else {
        printf("Não conseguimos encontrar a chave no Edifício João Calvino.");
    }

    for (int i = 0; i < n; i++) {
        free(v[i]);
    }
    free(v);
    return 0;
}

void construirMatriz(int linhas, int colunas, char** v) {
    printf("Escreva cada andar seguindo o seguinte exemplo: H H H V H H (Dando os espaços entre as salas):\n\n");
    for (int i = 0; i < linhas; i++) {   // Preenche do térreo até o último andar
        if (i == 0 ) {
            printf("Térreo: ");
        } else {
            printf("%d° andar: ", i);
        }
        for (int j = 0; j < colunas; j++) {
            char entrada[20];
            while (1) {
                scanf("%s", entrada);

                if (strcmp(entrada, "H") == 0 || strcmp(entrada, "h") == 0) {
                    v[i][j] = 'H';
                    break;
                } else if (strcmp(entrada, "V") == 0 || strcmp(entrada, "v") == 0) {
                    v[i][j] = 'V';
                    break;
                } else if (strcmp(entrada, "*") == 0) {
                    v[i][j] = '*';
                    break;
                } else {
                    printf("ERRO: ENTRADA INVÁLIDA (apenas H, V ou *). Digite novamente: ");
                }
            }
        }
        v[i][colunas] = '\0';
    }
}


int procurar(int posLinhas, int posColunas, char** v,  int tamLinha, int tamColuna) {
    // Condições de parada (0 para caso de sucesso e 1 para falha ao buscar a chave)
    if (v[posLinhas][posColunas] == '*') return 0;
    if (posLinhas < 0 || posLinhas >= tamLinha || posColunas < 0 || posColunas >= tamColuna) return 1;


    // Verificação da letra e realiza a chama recursiva com base na letra
    if (v[posLinhas][posColunas] == 'H') {
       if (procurar(posLinhas + 1, posColunas, v, tamLinha, tamColuna) == 0) return 0;
       if (procurar(posLinhas - 1, posColunas, v, tamLinha, tamColuna) == 0) return 0;
    } else if (v[posLinhas][posColunas] == 'V') {
        if (procurar(posLinhas, posColunas + 1, v, tamLinha, tamColuna) == 0) return 0;
        if (procurar(posLinhas, posColunas - 1, v, tamLinha, tamColuna) == 0) return 0;
    }

    return 1;

}
