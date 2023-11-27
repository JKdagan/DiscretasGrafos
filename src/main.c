#include <stdio.h>
#include "grafo.h"

int main(void) {
    Grafo* grafo = crearGrafo(5);

    addArco(grafo, 0, 1);
    addArco(grafo, 0, 4);
    addArco(grafo, 1, 2);
    addArco(grafo, 1, 3);
    addArco(grafo, 1, 4);
    addArco(grafo, 2, 3);
    addArco(grafo, 3, 4);

    int** matriz_adj = listaAMatrizAdj(grafo);
    printMatrizAdj(matriz_adj, grafo->vertices);
    freeMatrizAdj(matriz_adj, grafo->vertices);
    printGrafo(grafo);
    freeGrafo(grafo);

    return 0;
}