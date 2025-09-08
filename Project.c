#include <stdio.h>
#include <stdlib.h>

void construirMatriz(int linhas, int colunas, char** v);

int main () {
    int n, m; // n são as linhas (andares) e m são as colunas (quantidade de quartos);

    printf("Indique o número de andares do prédio: ");
    scanf("%d", &n);
    printf("Indique o número de salas por andar: ");
    scanf("%d", &m);

    // Alocando memória para construção da matriz:
    char **v = malloc(n * sizeof(char));
    if (v == NULL) {
        perror("Erro ao alocar memória das linha");
        return 1;
    } 

    for (int i = 0; i < n; i++) {
        v[i] = malloc((m + 1) * sizeof(char));
        if (v[i] != NULL) {
            perror("Erro ao alocar memória das colunas");
            return 1;
        }
    }

    construirMatriz(n, m, v);

    // Apresentando a matriz inserida pelo usuário;
    printf("\nMatriz final:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", v[i]);
    }

    for (int i = 0; i < n; i++) {
        free(v[i]);
    }
    free(v);
    return 0;
}

void construirMatriz(int linhas, int colunas, char** v) {
    for (int i = 0; i < linhas; i++) {
        if (i == 0 ) {
            printf("Térreo: ", i);
        } else {
            printf("%d° andar: ");
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