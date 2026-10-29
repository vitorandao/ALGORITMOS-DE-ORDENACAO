<!-- ================================================ -->
<!--        BUBBLE SORT x QUICK SORT                  -->
<!--        README otimizado para GitHub              -->
<!-- ================================================ -->

<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:0F172A,50:1D4ED8,100:38BDF8&height=230&section=header&text=Bubble%20Sort%20x%20Quick%20Sort&fontSize=44&fontColor=ffffff&animation=fadeIn&fontAlignY=37&desc=Ordena%C3%A7%C3%A3o%20de%20Pre%C3%A7os%20de%20Supermercado%20em%20C&descAlignY=59&descSize=19" width="100%" alt="Banner Bubble Sort x Quick Sort"/>

<br/>

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=21&duration=3000&pause=1000&color=38BDF8&center=true&vCenter=true&width=750&lines=Dois+algoritmos%2C+os+mesmos+dados.;Comparar+e+trocar+vs+dividir+e+conquistar.;Linguagem+C+%7C+Structs+%7C+Recurs%C3%A3o;Engenharia+de+Software+na+pr%C3%A1tica." alt="Typing SVG"/>

<strong>Algoritmos • Ordenação • Pensamento Computacional • Linguagem C</strong>

</div>

---

<div align="center">

<h2> Sobre o Projeto</h2>

Este projeto é uma aplicação em <strong>linguagem C</strong> que ordena os <strong>mesmos dados</strong> com dois algoritmos, o <strong>Bubble Sort</strong> e o <strong>Quick Sort</strong>, e mostra quanto trabalho (comparações e trocas) cada um precisou fazer.

Ele faz parte dos meus estudos em <strong>Engenharia de Software</strong>, na disciplina de Algoritmos e Pensamento Computacional, aplicando <strong>structs</strong>, <strong>funções</strong>, <strong>recursão</strong>, <strong>estruturas de repetição</strong> e <strong>versionamento com Git e GitHub</strong>.

<br/>

<em>Mesmo problema, duas estratégias, resultados que dá para comparar.</em>

</div>

<br/>

<div align="center">

<h2> Situação-Problema</h2>

</div>

Um **supermercado** precisa listar seus produtos do **mais barato ao mais caro** para comparar preços, montar ofertas e analisar margens. Com 12 produtos fora de ordem, achar o item mais barato ou o mais caro exige olhar um por um; com a lista ordenada, a resposta está nas pontas.

A aplicação guarda **12 registros** (nome e preço), ordena uma cópia dos dados com cada algoritmo e mostra a lista **antes e depois**, sempre em **ordem crescente de preço**.

<br/>

<div align="center">

<h2> Objetivos do Projeto</h2>

</div>

<table>
<tr>
<td align="center" width="50%">
<h3> Bubble Sort</h3>
Implementar a ordenação por comparação e troca de elementos vizinhos.
</td>
<td align="center" width="50%">
<h3> Quick Sort</h3>
Implementar a ordenação por divisão e conquista, com pivô e recursão.
</td>
</tr>
<tr>
<td align="center">
<h3> Mesmos dados</h3>
Ordenar cópias da mesma lista para que a comparação seja justa.
</td>
<td align="center">
<h3> Medir</h3>
Contar comparações e trocas de cada algoritmo e interpretar a diferença.
</td>
</tr>
</table>

<br/>

<div align="center">

<h2> Os Algoritmos</h2>

</div>

<table>
<tr>
<th align="center">Bubble Sort</th>
<th align="center">Quick Sort</th>
</tr>
<tr>
<td valign="top">
<b>Ideia:</b> compara pares <b>vizinhos</b> e troca os que estão fora de ordem. A cada passada, o maior valor restante "sobe" até o final.<br/><br/>
<b>No código:</b> dois <code>for</code> aninhados. O de fora conta as passadas; o de dentro compara <code>v[j]</code> com <code>v[j + 1]</code> e troca se <code>v[j] &gt; v[j + 1]</code>. Se uma passada não troca nada, o vetor já está ordenado e o laço para.
</td>
<td valign="top">
<b>Ideia:</b> escolhe um <b>pivô</b>, separa os menores à esquerda e os maiores à direita, e repete o processo em cada lado.<br/><br/>
<b>No código:</b> a função <code>particionar</code> usa o último elemento como pivô e o coloca na posição definitiva. <code>quick_sort</code> chama a si mesma para os dois lados; com 0 ou 1 elemento, para.
</td>
</tr>
</table>

<details>
<summary><strong> Visualizar exemplo do Bubble Sort (uma passada)</strong></summary>

<br/>

Vetor `{5, 2, 4, 1}`:

<pre>
[5, 2, 4, 1]  → compara 5 e 2 → troca   → [2, 5, 4, 1]
[2, 5, 4, 1]  → compara 5 e 4 → troca   → [2, 4, 5, 1]
[2, 4, 5, 1]  → compara 5 e 1 → troca   → [2, 4, 1, 5]   ✔ 5 chegou ao final
</pre>

</details>

<details>
<summary><strong> Visualizar exemplo do Quick Sort (uma partição)</strong></summary>

<br/>

Vetor `{5, 2, 4, 1, 3}`, pivô = 3 (último):

<pre>
menores ou iguais a 3: 2, 1        maiores que 3: 5, 4
[2, 1, | 3 |, 5, 4]                ✔ o 3 já está na posição final
depois: repete em {2, 1} e em {5, 4}
</pre>

</details>

| Característica | Bubble Sort | Quick Sort |
|:---:|:---:|:---:|
| Estratégia | Comparar e trocar vizinhos | Dividir em torno de um pivô |
| Tempo (caso médio) | O(n²) | O(n log n) |
| Tempo (pior caso) | O(n²) | O(n²) |
| Estável | Sim | Não |
| Usa recursão | Não | Sim |

>  Com o pivô sendo o **último** elemento, o pior caso do Quick Sort acontece quando o vetor **já vem ordenado** (ou com todos os valores iguais). Veja os testes em [`docs/testes.md`](docs/testes.md): nesse caso o Bubble Sort, com a parada antecipada, ganha.

<br/>

<div align="center">

<h2> Funcionalidades</h2>

</div>

<table>
<tr>
<th align="center">Funcionalidade</th>
<th align="center">Descrição</th>
</tr>
<tr>
<td> Registros</td>
<td>12 produtos com nome e preço, guardados em uma <code>struct</code>.</td>
</tr>
<tr>
<td> Bubble Sort</td>
<td>Ordenação crescente por preço, com parada antecipada.</td>
</tr>
<tr>
<td> Quick Sort</td>
<td>Ordenação crescente por preço, com pivô e recursão.</td>
</tr>
<tr>
<td> Mesmos dados</td>
<td>Cada algoritmo ordena uma cópia da lista original.</td>
</tr>
<tr>
<td> Antes e depois</td>
<td>A lista é exibida antes e depois de cada ordenação.</td>
</tr>
<tr>
<td> Comparação</td>
<td>Tabela com comparações e trocas, e conferência de que os dois resultados têm a mesma sequência de preços.</td>
</tr>
<tr>
<td> Menu</td>
<td>Escolha entre Bubble, Quick, comparar os dois ou sair; entradas inválidas são tratadas.</td>
</tr>
</table>

<br/>

<div align="center">

<h2> Exemplo de Execução</h2>

</div>

<details open>
<summary><strong> Visualizar a opção 3 (comparar os dois)</strong></summary>

<br/>

<pre>
==============================================
   BUBBLE SORT x QUICK SORT - SUPERMERCADO
==============================================
Criterio: preco CRESCENTE (menor -> maior)

[1] Bubble Sort  [2] Quick Sort  [3] Comparar os dois  [0] Sair
Escolha: 3

--- ANTES da ordenacao ---
   1. Arroz 5kg        R$   27.90
   2. Feijao 1kg       R$    8.49
   3. Cafe 500g        R$   16.75
   4. Leite 1L         R$    5.29
   5. Acucar 1kg       R$    4.99
   6. Oleo de soja     R$    7.89
   7. Macarrao 500g    R$    4.29
   8. Sabao em po      R$   18.50
   9. Biscoito         R$    3.99
  10. Farinha 1kg      R$    5.49
  11. Manteiga         R$   12.90
  12. Banana 1kg       R$    5.49

--- DEPOIS (Bubble Sort, crescente) ---
   1. Biscoito         R$    3.99
   2. Macarrao 500g    R$    4.29
   3. Acucar 1kg       R$    4.99
   4. Leite 1L         R$    5.29
   5. Farinha 1kg      R$    5.49
   6. Banana 1kg       R$    5.49
   7. Oleo de soja     R$    7.89
   8. Feijao 1kg       R$    8.49
   9. Manteiga         R$   12.90
  10. Cafe 500g        R$   16.75
  11. Sabao em po      R$   18.50
  12. Arroz 5kg        R$   27.90

  Comparacoes: 63 | Trocas: 41

  (o Quick Sort exibe o mesmo antes/depois, com Comparacoes: 32 | Trocas: 13)

--- COMPARACAO ---
  Algoritmo     Comparacoes     Trocas
  Bubble Sort            63         41
  Quick Sort             32         13
  Mesma sequencia de precos: sim
</pre>

</details>

Com os dados de exemplo, o Quick Sort fez cerca de metade das comparações e menos de um terço das trocas do Bubble Sort.

<br/>

<div align="center">

<h2> Como Executar o Projeto</h2>

</div>

<details open>
<summary><strong> Visualizar compilação e execução</strong></summary>

<br/>

**Pré-requisito:** compilador **GCC** instalado.

**1. Clone o repositório e entre na pasta**

<pre>
git clone https://github.com/vitorandao/ALGORITMOS-DE-ORDENACAO.git
cd ALGORITMOS-DE-ORDENACAO
</pre>

**2. Compile**

<pre>
gcc bubble_quick_supermercado.c -o ordenador
</pre>

**3. Execute** (Windows: `ordenador.exe`)

<pre>
./ordenador
</pre>

Digite `3` para comparar os dois algoritmos e `0` para sair.

**Sem instalar nada:** copie o conteúdo de `bubble_quick_supermercado.c` no [OnlineGDB](https://www.onlinegdb.com/online_c_compiler), escolha a linguagem **C** e clique em **Run**.

</details>

<br/>

<div align="center">

<h2> Execução Online</h2>

</div>

<div align="center">

<a href="COLE_AQUI_O_LINK_COMPARTILHADO_DO_ONLINEGDB">
<img src="https://img.shields.io/badge/Executar%20online-OnlineGDB-1D4ED8?style=for-the-badge&logo=gnu&logoColor=white" alt="Executar online no OnlineGDB"/>
</a>

</div>

<br/>

<div align="center">

<h2> Tecnologias Utilizadas</h2>

<img src="https://skillicons.dev/icons?i=c,git,github,vscode,linux&theme=dark" alt="Tecnologias do projeto"/>

<br/><br/>

</div>

| Tecnologia | Finalidade |
|:---:|:---|
| **Linguagem C** | Implementação completa dos algoritmos |
| **GCC** | Compilação do código-fonte |
| **Git** | Versionamento do código |
| **GitHub** | Repositório e histórico de commits |
| **OnlineGDB** | Execução online do programa |

<br/>

<div align="center">

<h2> Estrutura do Projeto</h2>

</div>

<details>
<summary><strong> Visualizar estrutura de pastas</strong></summary>

<br/>

<pre>
ALGORITMOS-DE-ORDENACAO/
│
├── bubble_quick_supermercado.c   # programa completo (comentado)
├── docs/
│   └── testes.md                 # 5 casos de teste com resultados
├── .gitignore                    # ignora o executável gerado
└── README.md
</pre>

</details>

<br/>

<div align="center">

<h2> Requisitos da Atividade</h2>

</div>

| Requisito | Como foi atendido |
|:---:|:---|
| **Aplicação em C** | `bubble_quick_supermercado.c` |
| **Bubble Sort e Quick Sort** | Funções `bubble_sort` e `quick_sort` (com `particionar`) |
| **Pelo menos 10 registros** | 12 produtos em `struct Produto` |
| **Mesmos dados nos dois algoritmos** | Função `copiar` cria uma cópia da lista original para cada um |
| **Dados antes e depois** | Função `exibir`, chamada antes e depois de cada ordenação |
| **Comentários explicativos** | Laços, comparações, trocas, pivô e recursão comentados no código |
| **Contexto do cotidiano** | Preços de supermercado, explicados na situação-problema |

<br/>

<div align="center">

<h2> Evolução do Desenvolvimento</h2>

</div>

O projeto foi construído em etapas, cada uma registrada em um commit:

| # | Commit | O que mudou |
|:---:|:---|:---|
| 1 | `feat: cria estrutura base com struct Produto e exibição` | Dados, `struct` e `exibir` |
| 2 | `feat: implementa Bubble Sort com troca de registros` | `trocar` e `bubble_sort` |
| 3 | `feat: implementa Quick Sort com partição e recursão` | `particionar` e `quick_sort` |
| 4 | `feat: adiciona menu, contadores e comparação dos algoritmos` | Menu, contagem de trabalho e tabela comparativa |
| 5 | `docs: adiciona README e .gitignore` | Documentação do projeto |
| 6 | `docs: adiciona casos de teste` | `docs/testes.md` |

<br/>

<div align="center">

<h2>🔮 Melhorias Futuras</h2>

</div>

- Permitir escolher ordem crescente ou decrescente.
- Permitir ordenar por outro critério (estoque, nome).
- Escolher o pivô do Quick Sort pela mediana de três valores, evitando o pior caso em listas ordenadas.
- Ler os produtos de um arquivo ou digitá-los no terminal.

<br/>

<div align="center">

<h2> Aprendizados Esperados</h2>

Ao longo do desenvolvimento, o objetivo é colocar em prática:

<strong>Arrays • Structs • Funções • Recursão • Algoritmos de Ordenação • Análise de Comparações e Trocas • Git e GitHub</strong>

<br/><br/>

<h2> Desenvolvedor</h2>

<strong>Vitor Brandão Machado</strong>

Estudante de Engenharia de Software no Centro Universitário do Distrito Federal (UDF).

<br/>

<a href="https://github.com/vitorandao">
<img src="https://img.shields.io/badge/GitHub-vitorandao-181717?style=for-the-badge&logo=github&logoColor=white" alt="Perfil GitHub"/>
</a>

<br/><br/>

<strong>Algoritmos e Pensamento Computacional © 2026</strong>

<br/>

<em>Desenvolvido para aprender, evoluir e transformar ideias em soluções reais.</em>

<br/><br/>

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:38BDF8,50:1D4ED8,100:0F172A&height=120&section=footer" width="100%" alt="Rodapé"/>

</div>
