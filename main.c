#include "grafo.h"

int main(){
    
    graph *g = leitura_preenche_grafo();

    if(even_nodes(g) == true){
        printf("Sim\n");
        find_path_algorithm(g);

    }
    else printf("Não\n");
    
    
    // //A MODELAGEM DO GRAFO ESTÁ COMPLETA
    // //e o resto do problema???


    return 0;
}