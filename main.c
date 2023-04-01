#include "grafo.h"

int main(){
    
    graph *g = leitura_preenche_grafo();
    
    print_graph(g);
    if(even_nodes(g) == true) printf("SIM\n");
    else printf("NAO\n");

    // //A MODELAGEM DO GRAFO ESTÁ COMPLETA
    // //e o resto do problema???


    return 0;
}