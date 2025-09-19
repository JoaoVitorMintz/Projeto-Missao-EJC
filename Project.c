#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int procurar(int posLinhas, int posColunas, char** v, int tamLinha, int tamColuna);

// TODO: REALIZAR OS TESTES!

int main () {
    int n, m, posLinha, posColuna; // n são as linhas (andares) e m são as colunas (quantidade de quartos), posição da linha e coluna;
    FILE *entrada;
    char buffer[200];

    // Abertura do arquivo:
    entrada = fopen("arquivo.txt", "r");

    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fscanf(entrada, "%d", &n);


    // Alocando memória para construção da matriz:
    char **v = malloc(n * sizeof(char *));
    if (v == NULL) {
        perror("Erro ao alocar memória das linhas");
        return 1;
    }

    // Construção da matriz:
    for (int i = 0; i < n; i++) {
        fscanf(entrada, "%s", buffer);
        m = strlen(buffer); // Comprimento da linha (quantidade de quartos)
        v[i] = malloc((m+1) * sizeof(char));
        if (v[i] == NULL) {
            perror("Erro ao alocar memória das colunas");
            return 1;
        }
        strcpy(v[i], buffer);
    }

    fscanf(entrada, "%d %d", &posLinha, &posColuna); // Posição inicial

    // Apresentando a matriz inserida pelo usuário;
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        printf("%s\n", v[i]);
    }
    printf("%d  %d\n", posLinha, posColuna);

    fclose(entrada);

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


int procurar(int posLinhas, int posColunas, char** v,  int tamLinha, int tamColuna) {
    
    // Condições de parada (0 para caso de sucesso e 1 para falha ao buscar a chave)
    if (posLinhas < 0 || posLinhas >= tamLinha || posColunas < 0 || posColunas >= tamColuna) return 1;
    if (v[posLinhas][posColunas] == '*') return 0;
    if (v[posLinhas][posColunas] == 'X') return 1; //Evita revisitar posições já visitadas (prevenção de loop infinito)
     
    char atual = v[posLinhas][posColunas];
    v[posLinhas][posColunas] = 'X'; //Marca posição como visitada para não voltar nela depois

    // Verificação da letra e realiza a chama recursiva com base na letra
    if (atual == 'H') {
       if (procurar(posLinhas + 1, posColunas, v, tamLinha, tamColuna) == 0) return 0;//cima
       if (procurar(posLinhas - 1, posColunas, v, tamLinha, tamColuna) == 0) return 0;//baixo
    } else if (atual == 'V') {
        if (procurar(posLinhas, posColunas + 1, v, tamLinha, tamColuna) == 0) return 0;//direita
        if (procurar(posLinhas, posColunas - 1, v, tamLinha, tamColuna) == 0) return 0;//esquerda
    }

    return 1;

}
