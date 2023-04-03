#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct graph_ graph;

//Função que cria o grafo e retorna o ponteiro
//correspondente
graph *graph_create(int n_nodes, int n_edges);

//Função que adiciona uma aresta ao grafo já criado
bool add_edge(graph *g, int origin, int destiny);

//Função responsável por destruir o grafo
void destroy_graph(graph *g);

//Função responsável por printar o grafo (usada)
//principalmente para testes
void print_graph(graph *g);

//Verifica se todos os vértices do grafo tem
//grau par. Caso não seja, já sabemos que não é
//um grafo euleriano.
bool even_nodes(graph *g);

//Verifica se um determinado só possui mais uma aresta ligada a ele.
//É fundamental no find_path_algorithm
bool lonely_node(graph *g, int index);


//Encontra o caminho euleriano do grafo e retorna
//o ponteiro para o vetor em questão
void find_path_algorithm(graph *g);

//Lê o nome do arquivo, abre o arquivo, cria e preenche o grafo
graph *leitura_preenche_grafo();
