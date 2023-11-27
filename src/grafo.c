#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>


Grafo* crearGrafo(int vertices) {
    //Crea un grafo con la cantidad de vertices indicada
    Grafo* grafo = malloc(sizeof(Grafo)); 
    grafo->vertices = vertices;

    //Inicializar Lista de adyacencia del grafo
    grafo->lista_ady = malloc(vertices * sizeof(Vertice*));
    for (int i = 0; i < vertices; i ++) {
        grafo->lista_ady[i] = NULL;
    }

    return grafo;
}

//Crear nuevo vertice y conectarlo con un destino
Vertice* crearVertice(int dest) {
    Vertice* new_vertice = malloc(sizeof(Vertice)); 
    new_vertice->dest = dest;
    new_vertice->next = NULL;
    return new_vertice;
}

//Convierte la lista de Adj a Matriz
int** listaAMatrizAdj(Grafo* grafo) {
    int n = grafo->vertices; //cantidad de vertices del grafo
    int **matriz_ady = malloc(n * sizeof(int*)); //creacion de matriz 
    
    for (int i = 0; i < n; i++) {
        matriz_ady[i] = calloc(n, sizeof(int)); //inicializar filas
        Vertice* vert = grafo->lista_ady[i];

        while(vert != NULL) {
            matriz_ady[i][vert->dest] = 1;
            vert = vert->next;
        }
    }

    return matriz_ady;
}

void printMatrizAdj(int **matriz_adj, int vertices) {

    printf("V ");
    printf("|");
    for (int i = 0; i < vertices; i++) {
        printf("%d ", i);
    }
    printf("\n- ");
    for (int i = 0; i < vertices; i++) {
        printf(" -");
    }
    printf("\n");

    for (int i = 0; i < vertices; i++) {
        printf("%d ", i);
        printf("|");
        for (int j = 0; j < vertices; j++){
            printf("%d ", matriz_adj[i][j]);
        }
        printf("\n");
        
    }
}

void freeMatrizAdj(int **matriz_adj, int vertices) {
    int n = vertices;
    
    for (int i = 0; i < n; i++) {
        free(matriz_adj[i]);
    }
    free(matriz_adj);
}

void addArco(Grafo* grafo, int src, int dest) {
    Vertice* new_vertice = crearVertice(dest);
    new_vertice->next = grafo->lista_ady[src];
    grafo->lista_ady[src] = new_vertice;
}

void printGrafo(Grafo* grafo) {
    int n = grafo->vertices;
    for(int i = 0; i < n; i++) {
        printf("Lista de adyacencia del vertice %d: ", i);
        Vertice* vert = grafo->lista_ady[i];
        while (vert) {
            printf("%d -> ", vert->dest);
            vert = vert->next;
        }
        printf("NULO\n");
    }
}

void freeGrafo(Grafo* grafo) {
    int n = grafo->vertices;
    for (int i = 0; i < n; i++) {
        Vertice* vert = grafo->lista_ady[i];
        while (vert) {
            Vertice* vert_sig = vert->next;
            free(vert);
            vert = vert_sig;
        }
    }
    free(grafo->lista_ady);
    free(grafo);
} 