/*
 * ============================================================
 *  Bubble Sort x Quick Sort (etapa 1: dados e exibicao) - Organizador de Precos de Supermercado
 * ============================================================
 *  Problema: um supermercado precisa listar seus produtos do mais
 *  barato ao mais caro (comparar precos, montar ofertas, analisar
 *  margens). Este programa ordena os MESMOS dados com dois
 *  algoritmos e mostra quanto trabalho cada um precisou fazer.
 *
 *  Criterio de ordenacao: CRESCENTE pelo preco (menor -> maior).
 *
 *  Compilar: gcc bubble_quick_supermercado.c -o ordenador
 *  Executar: ./ordenador
 * ============================================================
 */

#include <stdio.h>

#define N 12  /* quantidade de registros (minimo exigido: 10) */

/* Cada registro guarda o nome e o preco de um produto */
typedef struct {
    char  nome[20];
    float preco;
} Produto;


/* ---------- Utilitarios ---------- */

/* Exibe a lista de produtos, um por linha */
void exibir(const Produto v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("  %2d. %-16s R$ %7.2f\n", i + 1, v[i].nome, v[i].preco);
    }
}

int main(void) {
    const Produto original[N] = {
        {"Arroz 5kg", 27.90f},   {"Feijao 1kg", 8.49f},   {"Cafe 500g", 16.75f},
        {"Leite 1L", 5.29f},     {"Acucar 1kg", 4.99f},   {"Oleo de soja", 7.89f},
        {"Macarrao 500g", 4.29f},{"Sabao em po", 18.50f}, {"Biscoito", 3.99f},
        {"Farinha 1kg", 5.49f},  {"Manteiga", 12.90f},    {"Banana 1kg", 5.49f}
    };

    printf("--- ANTES da ordenacao ---\n");
    exibir(original, N);
    return 0;
}
