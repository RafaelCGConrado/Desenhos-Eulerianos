#include "grafo.h"

int main(){

    graph *g = graph_create(5, 6);
    // add_edge(g, 0, 1);
    // add_edge(g, 0, 2);
    // add_edge(g, 1, 2);
    
    // print_graph(g);
    // destroy_graph(g);
    teste(g, 6);
    print_graph(g);

    //A MODELAGEM DO GRAFO ESTÁ COMPLETA
    //e o resto do problema???


    return 0;
}