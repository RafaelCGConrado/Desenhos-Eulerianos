#include "grafo.h"

int main(){

    graph *g = graph_create(3, 2);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    
    print_graph(g);
    destroy_graph(g);

    return 0;
}