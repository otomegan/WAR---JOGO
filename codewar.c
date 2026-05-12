#include <stdio.h>
#include <stdlib.h> // Para system()
#include <string.h> // Para strcspn()

// --- Definições Globais ---
#define MAX_NOME 30
#define MAX_COR 10
#define TOTAL_TERRITORIOS 5

// --- Definição da Struct ---
struct Territorio {
    char nome[MAX_NOME];
    char cor[MAX_COR];
    int tropas;
};

// --- Função para limpar o buffer ---
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função Principal ---
int main() {
    // Declaração do array de structs
    struct Territorio mapa_mundi[TOTAL_TERRITORIOS];

    system("clear || cls"); // Limpa a tela no início

    printf("========================================\n");
    printf("Vamos cadastrar os %d territórios do jogo\n", TOTAL_TERRITORIOS);
    printf("========================================\n");

    // --- Laço para CADASTRAR os territórios ---
    for (int i = 0; i < TOTAL_TERRITORIOS; i++) {
        printf("\n--- Cadastro do Território %d ---\n", i + 1);

        printf("Nome do Território: ");
        // Uso correto do fgets: (destino, tamanho_maximo, origem)
        fgets(mapa_mundi[i].nome, MAX_NOME, stdin);

        printf("Cor do Exército (ex: Azul, Verde...): ");
        fgets(mapa_mundi[i].cor, MAX_COR, stdin);

        printf("Número de Tropas: ");
        scanf("%d", &mapa_mundi[i].tropas);
        limparBuffer(); // Limpa o '\n' deixado pelo scanf

        mapa_mundi[i].nome[strcspn(mapa_mundi[i].nome, "\n")] = '\0';
        mapa_mundi[i].cor[strcspn(mapa_mundi[i].cor, "\n")] = '\0';
    }

    printf("\n========================================\n");
    printf("Territórios cadastrados com sucesso!\n");
    printf("========================================\n");
    printf("\nPressione Enter para ver a lista...");
    getchar();

    system("clear || cls"); // Limpa a tela de novo

    // --- Laço para LISTAR os territórios ---
    printf("--- Lista de Territórios Cadastrados ---\n\n");
    for (int i = 0; i < TOTAL_TERRITORIOS; i++) {
        printf("--------------------------------\n");
        printf("Território %d\n", i + 1);
        printf("Nome: %s\n", mapa_mundi[i].nome);
        printf("Cor: %s\n", mapa_mundi[i].cor);
        printf("Tropas: %d\n", mapa_mundi[i].tropas);
    }
    printf("--------------------------------\n");

    return 0; // Fim do programa
}

