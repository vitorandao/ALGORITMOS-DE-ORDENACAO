/*
 * ============================================================
 *  Bubble Sort x Quick Sort (etapa 3: Quick Sort) - Organizador de Precos de Supermercado
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

/* Copia 'origem' em 'destino': cada algoritmo ordena uma COPIA,
   assim os dois partem exatamente dos mesmos dados. */
void copiar(const Produto origem[], Produto destino[], int n) {
    for (int i = 0; i < n; i++) destino[i] = origem[i];
}

/* Troca dois registros usando uma variavel temporaria */
void trocar(Produto *a, Produto *b) {
    Produto temp = *a;
    *a = *b;
    *b = temp;
}

/* ---------- Bubble Sort ---------- */

/*
 * Compara pares ADJACENTES e troca os que estao fora de ordem.
 * A cada passada, o maior valor restante "sobe" ate o final.
 */
void bubble_sort(Produto v[], int n) {
    /* Laco externo: cada passada fixa o maior valor restante no fim */
    for (int i = 0; i < n - 1; i++) {
        int houve_troca = 0;  /* detecta passada sem trocas (ja ordenado) */

        /* Laco interno: percorre so a parte ainda nao ordenada */
        for (int j = 0; j < n - i - 1; j++) {
            /* Preco da esquerda maior que o da direita? Fora de ordem. */
            if (v[j].preco > v[j + 1].preco) {
                trocar(&v[j], &v[j + 1]);
                houve_troca = 1;
            }
        }

        /* Passada sem nenhuma troca: o vetor ja esta ordenado */
        if (!houve_troca) break;
    }
}

/* ---------- Quick Sort ---------- */

/*
 * Particiona v[baixo..alto] em torno de um PIVO (o ultimo elemento).
 * Ao final, os precos <= pivo ficam a esquerda, os maiores a direita,
 * e o pivo fica na sua posicao DEFINITIVA, cujo indice e devolvido.
 */
int particionar(Produto v[], int baixo, int alto) {
    float pivo = v[alto].preco;
    int i = baixo - 1;  /* fim da regiao dos elementos <= pivo */

    for (int j = baixo; j < alto; j++) {
        if (v[j].preco <= pivo) {
            i++;                                /* amplia a regiao dos menores */
            if (i != j) trocar(&v[i], &v[j]);   /* traz o menor para ela */
        }
    }

    /* Coloca o pivo entre as duas regioes */
    if (i + 1 != alto) trocar(&v[i + 1], &v[alto]);
    return i + 1;
}

/*
 * Divide para conquistar: particiona e ordena cada lado por recursao.
 * Caso base: com 0 ou 1 elemento (baixo >= alto) ja esta ordenado.
 */
void quick_sort(Produto v[], int baixo, int alto) {
    if (baixo < alto) {
        int p = particionar(v, baixo, alto);  /* pivo ja esta no lugar */
        quick_sort(v, baixo, p - 1);          /* lado dos menores */
        quick_sort(v, p + 1, alto);           /* lado dos maiores */
    }
}

int main(void) {
    const Produto original[N] = {
        {"Arroz 5kg", 27.90f},   {"Feijao 1kg", 8.49f},   {"Cafe 500g", 16.75f},
        {"Leite 1L", 5.29f},     {"Acucar 1kg", 4.99f},   {"Oleo de soja", 7.89f},
        {"Macarrao 500g", 4.29f},{"Sabao em po", 18.50f}, {"Biscoito", 3.99f},
        {"Farinha 1kg", 5.49f},  {"Manteiga", 12.90f},    {"Banana 1kg", 5.49f}
    };
    Produto bolha[N], rapido[N];

    copiar(original, bolha, N);
    copiar(original, rapido, N);
    bubble_sort(bolha, N);
    quick_sort(rapido, 0, N - 1);

    printf("--- Bubble Sort (crescente) ---\n");
    exibir(bolha, N);
    printf("\n--- Quick Sort (crescente) ---\n");
    exibir(rapido, N);
    return 0;
}
