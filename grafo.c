#include "grafo.h"

struct graph_{
    int n_nodes;
    int n_edges;
    int **edges;

};


graph *graph_create(int n_nodes, int n_edges){
    //cria o grafo e verifica se é nulo
    graph *g = (graph *)calloc(1, sizeof(graph));
    if(g == NULL) return NULL;

    g -> n_nodes = n_nodes;
    g -> n_edges = n_edges;

    //não sendo nulo, prosseguimos e alocaremos as
    // linhas da matriz de adjacências
    g -> edges = (int **)calloc(g -> n_nodes, sizeof(int*));
    if(g -> edges == NULL){
        printf("Erro na alocação da matriz\n");
        free(g);
        return NULL;

    }

    //prosseguimos e alocamos as colunas
    for(int i = 0; i < g -> n_nodes; i++){
        g -> edges[i] = (int*)calloc(g -> n_nodes, sizeof(int));
        if(g -> edges[i] == NULL){
            destroy_graph(g);
            return NULL;

        }
    }

    //Caso nenhum problema tenha acontecido, retornamos o ponteiro
    //para o grafo
    return g;

}

bool add_edge(graph *g, int origin, int destiny){
    
    if(g -> edges[origin][destiny] != 0){
        printf("Essa aresta já existe.\n");
        return false;
    }

    g -> edges[origin][destiny] = 1;

    //ficar atendo com esta parte aqui:
    g->edges[destiny][origin] = 1;

    return true;

}





void destroy_graph(graph *g){
    //Se o grafo já está "vazio", nada precisa
    //ser feito
    if(g == NULL) return;

    //Vamos liberar cada linha da matriz
    for(int i = 0; i < g -> n_nodes; i++){
        if(g -> edges[i] != NULL){
            free(g -> edges[i]);
        }

        //Finalizamos liberando o próprio grafo
        free(g);
        
    }


}


void print_graph(graph *g){
    
    printf("Representação do grafo:\n");
    for(int origin = 0; origin < g -> n_nodes; origin++){
        for(int dest = 0; dest < g -> n_nodes; dest++){
            if(g -> edges[origin][dest] == 1) printf("%d -> %d\n", origin, dest);

        }
        printf("\n");
    }



}

bool even_nodes(graph *g){

    for(int i = 0; i < g -> n_nodes; i++){
        int sum_nnodes = 0;
        for(int j = 0; j < g -> n_nodes; j++){
            if(g -> edges[i][j] == 1) sum_nnodes++;
        }
        if((sum_nnodes % 2) != 0) return false;
    }

    return true;

}

void find_path_algorithm(graph *g){
    
    //O ponteiro de inteiro path será o vetor que conterá o caminho euleriano.
    //n_edges, n_nodes representam respectivamente o numero de vértices e de arestas
    //current node guardará a posição atual em nosso caminho, e count será
    //utilizada para controlar o posicionamento no vetor path
    int *path = NULL;
    int n_edges = g -> n_edges, n_nodes = g -> n_nodes, current_node = 0;
    int count = 0;
    while(n_edges != 0){
        
        path = realloc(path, (count + 1) * sizeof(int));
        path[count] = current_node;
        for(int i = 0; i < n_nodes; i++){
            //Percorrendo a linha até achar o primeiro 1
            //Ou seja, tentando achar a aresta que leva para
            //o menor vértice
            if(g -> edges[current_node][i] == 1){
                g -> edges[current_node][i] = 0;
                g -> edges[i][current_node] = 0;
                current_node = i;
                break;
            }
        }
        //Terminada a verificação em um determinado vértice,
        //a variável current_node é modificada
        count++;
        n_edges--;


    }

    //O caminho já está praticamente completo. Retornamos ao 0.
    path[count] = 0;

    for(int i = 0; i <= count; i++){
        printf("%d ", path[i]);
    }
    printf("\n");
    
}



graph *leitura_preenche_grafo(){

    char nome_arquivo[10];
    scanf("%s", nome_arquivo);
    FILE *arq = fopen(nome_arquivo, "r");

    int v, a;
    fscanf(arq, "%d %d", &v, &a);

    graph *g = graph_create(v, a);

    int origem, destino;
    for(int i = 0; i < a; i++){
        fscanf(arq, "%d %d", &origem, &destino);
        add_edge(g, origem, destino);
    }

    fclose(arq);

    return g;

}