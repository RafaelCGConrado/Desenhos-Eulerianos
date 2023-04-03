#include "grafo.h"

/*
Trabalho 1: Desenhos Eulerianos
Aluno: Rafael C. G. Conrado - 13671806
Disciplina: Modelagem Computacional em Grafos
*/

int main(){
    
    //Gria grafo, lê o arquivo e preenche o grafo
    graph *g = leitura_preenche_grafo();

    //Verifica se o número de vértices é par. Se for,
    //prosseguimos com a determinação do ciclo euleriano.
    //Caso contrário, já podemos "descartar" o grafo,
    //pois sabemos que não é possível formar o ciclo
    //euleriano em questão (teorema).
    if(even_nodes(g) == true){
        printf("Sim\n");
        find_path_algorithm(g);

    }
    else printf("Não\n");

    return 0;
}