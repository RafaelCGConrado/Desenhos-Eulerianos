#include "grafo.h"

int main(){

    graph *g = graph_create(3, 2);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 0);
    add_edge(g, 2, 0);
    
    print_graph(g);

    return 0;
}