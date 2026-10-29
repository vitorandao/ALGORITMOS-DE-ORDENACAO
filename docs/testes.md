# Testes do programa

Programa: `bubble_quick_supermercado.c` (12 produtos, ordem crescente por preço).
Cada caso foi testado trocando só os preços da lista, recompilando e comparando os dois algoritmos.

| # | Caso | Bubble Sort (comp. / trocas) | Quick Sort (comp. / trocas) | Mesma sequência de preços |
|:-:|:-----|:----------------------------:|:---------------------------:|:-------------------------:|
| 1 | Dados do exemplo (desordenados) | 63 / 41 | 32 / 13 | Sim |
| 2 | Já ordenado | 11 / 0 | 66 / 0 | Sim |
| 3 | Ordem inversa | 66 / 66 | 66 / 6 | Sim |
| 4 | Todos os preços iguais | 11 / 0 | 66 / 0 | Sim |
| 5 | Preços repetidos | 60 / 25 | 32 / 9 | Sim |

## Conclusões

- **Caso comum (1 e 5):** o Quick Sort fez cerca da metade das comparações e bem menos trocas.
- **Já ordenado (2) e todos iguais (4):** o Bubble Sort termina na 1ª passada (11 comparações, nenhuma troca), graças à parada antecipada. O Quick Sort cai no pior caso, porque o pivô (último elemento) não divide a lista: 66 comparações, o mesmo que 11 + 10 + ... + 1.
- **Ordem inversa (3):** os dois fazem 66 comparações, mas o Quick Sort troca bem menos (6 contra 66).
- Em todos os casos, os dois algoritmos produziram a mesma sequência de preços.
- Além desses casos, as duas funções foram testadas com 2.000 listas aleatórias de 12 preços (com muitos empates): todas saíram em ordem crescente, sem perder nenhum registro.
- O Bubble Sort é estável (empates mantêm a ordem original); o Quick Sort desta implementação não garante isso.
