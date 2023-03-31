#include "grafo.h"

int main(){

    //Parte da leitura do arquivo
    // char *nome_arquivo[20];
    // scanf("%s", nome_arquivo);
    // fopen(nome_arquivo, "r");
    
    
    
    
    
    
    
    graph *g = graph_create(6, 8);
    // add_edge(g, 0, 1);
    // add_edge(g, 0, 2);
    // add_edge(g, 1, 2);
    
    // print_graph(g);
    // destroy_graph(g);
    teste(g, 8);
    print_graph(g);
    if(even_nodes(g) == false) printf("Nao é euleriano\n");
    else printf("é euleriano\n");
    //A MODELAGEM DO GRAFO ESTÁ COMPLETA
    //e o resto do problema???


    return 0;
}