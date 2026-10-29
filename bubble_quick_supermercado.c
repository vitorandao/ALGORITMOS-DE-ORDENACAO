/*
 * ============================================================
 *  Bubble Sort x Quick Sort - Organizador de Precos de Supermercado
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

/* Contadores do trabalho feito pelo algoritmo em execucao.
   shortcut: variaveis globais para simplificar; trocar por parametro
   se o programa passar a ordenar varias listas ao mesmo tempo. */
static long comparacoes = 0;
static long trocas = 0;

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
    trocas++;
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
            comparacoes++;

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
        comparacoes++;

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

/* ---------- Execucao de um algoritmo ---------- */

/* Roda o algoritmo escolhido (1 = Bubble, 2 = Quick) sobre uma copia dos
   dados originais, mostra antes/depois e o trabalho realizado. */
void executar(int algoritmo, const Produto original[], Produto resultado[]) {
    copiar(original, resultado, N);
    comparacoes = 0;
    trocas = 0;

    printf("\n--- ANTES da ordenacao ---\n");
    exibir(resultado, N);

    if (algoritmo == 1) bubble_sort(resultado, N);
    else                quick_sort(resultado, 0, N - 1);

    printf("\n--- DEPOIS (%s, crescente) ---\n",
           algoritmo == 1 ? "Bubble Sort" : "Quick Sort");
    exibir(resultado, N);
    printf("\n  Comparacoes: %ld | Trocas: %ld\n", comparacoes, trocas);
}

/* Confere se dois resultados tem a mesma sequencia de precos */
int mesmos_precos(const Produto a[], const Produto b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i].preco != b[i].preco) return 0;
    }
    return 1;
}

int main(void) {
    /* Dados originais (desordenados). Dois produtos custam R$ 5.49
       de proposito, para observar o que cada algoritmo faz com empates. */
    const Produto original[N] = {
        {"Arroz 5kg", 27.90f},   {"Feijao 1kg", 8.49f},   {"Cafe 500g", 16.75f},
        {"Leite 1L", 5.29f},     {"Acucar 1kg", 4.99f},   {"Oleo de soja", 7.89f},
        {"Macarrao 500g", 4.29f},{"Sabao em po", 18.50f}, {"Biscoito", 3.99f},
        {"Farinha 1kg", 5.49f},  {"Manteiga", 12.90f},    {"Banana 1kg", 5.49f}
    };
    Produto bolha[N], rapido[N];
    int opcao;

    printf("==============================================\n");
    printf("   BUBBLE SORT x QUICK SORT - SUPERMERCADO\n");
    printf("==============================================\n");
    printf("Criterio: preco CRESCENTE (menor -> maior)\n");

    do {
        printf("\n[1] Bubble Sort  [2] Quick Sort  [3] Comparar os dois  [0] Sair\n");
        printf("Escolha: ");

        /* Entrada invalida (letra, por exemplo): limpa o buffer e repete */
        if (scanf("%d", &opcao) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) { }
            if (c == EOF) break;
            opcao = -1;
        }

        if (opcao == 1 || opcao == 2) {
            executar(opcao, original, opcao == 1 ? bolha : rapido);
        } else if (opcao == 3) {
            executar(1, original, bolha);
            long comp_bolha = comparacoes, trocas_bolha = trocas;
            executar(2, original, rapido);

            printf("\n--- COMPARACAO ---\n");
            printf("  %-12s %12s %10s\n", "Algoritmo", "Comparacoes", "Trocas");
            printf("  %-12s %12ld %10ld\n", "Bubble Sort", comp_bolha, trocas_bolha);
            printf("  %-12s %12ld %10ld\n", "Quick Sort", comparacoes, trocas);
            printf("  Mesma sequencia de precos: %s\n",
                   mesmos_precos(bolha, rapido, N) ? "sim" : "NAO");
        } else if (opcao != 0) {
            printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    printf("\nEncerrado.\n");
    return 0;
}
