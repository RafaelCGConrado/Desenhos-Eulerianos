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

