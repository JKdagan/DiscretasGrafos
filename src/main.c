#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "grafo.h"

int **llenarMatriz();
void printMatriz(int **matriz);
void printGrafo(int **matriz);
void djikstra(int **matriz, int start, int end);


int main(void) {
    int **matriz_ady = llenarMatriz();
    djikstra(matriz_ady, 0, 15);
    return 0;
}

int** llenarMatriz() {

    int **matriz = calloc(NUM_INTERSECCIONES, sizeof(int*));

    for (int i = 0; i < NUM_INTERSECCIONES; i++) {
        matriz[i] = calloc(NUM_INTERSECCIONES, sizeof(int));
    }
    for (int i = 0; i < NUM_INTERSECCIONES; i++) {
        for (int j = 0; j < NUM_INTERSECCIONES; j++) {
            matriz[i][j] = 0;
        }
    }

    for (int i = 0; i < NUM_CALLES; i++) {
        for (int j = 0; j < NUM_CALLES; j++) {
            matriz[CALLES[i].src][CALLES[i].dest] = CALLES[i].peso;
        }
    }
    return matriz;
}

void printMatriz(int **matriz) {
    FILE *fp = fopen("matriz.txt", "w");

    for (int i = 0; i < NUM_INTERSECCIONES;i++) {
        for (int j = 0; j < NUM_INTERSECCIONES;j++) {
            fprintf(fp,"%d ", matriz[i][j]);
        }
        fprintf(fp,"\n");
    }
}

void djikstra(int **matriz, int start, int end) {
    int distancias[NUM_INTERSECCIONES], anteriores[NUM_INTERSECCIONES], visitados[NUM_INTERSECCIONES], camino[NUM_INTERSECCIONES];
    int desde = start;

    for (int i = 0; i < NUM_INTERSECCIONES; i++) {
        distancias[i] = 9999;
        anteriores[i] = -1;
        visitados[i] = 0;
    }

    visitados[desde] = 1;
    distancias[desde] = 0;

    while (!visitados[end]) {
        int distancia_min = 9999;
        int vertice = 0;

        for (int i = 0; i < NUM_INTERSECCIONES; i++) {
            int distancia = distancias[desde] + matriz[desde][i] * 100;
            if (distancia < distancias[i] && !visitados[i]) {
                distancias[i] = distancia;
                anteriores[i] = desde;
            }
            if (distancia_min > distancias[i] && !visitados[i]) {
                distancia_min = distancias[i];
                vertice = i;
            }
        }

        desde = vertice;
        visitados[desde] = 1;

    }

    desde = end;

    int longitud = 0;
    while (desde != start) {
        camino[longitud++] = desde;
        desde = anteriores[desde];
    }
    camino[longitud++] = desde;

    for (int i = 0; i < longitud / 2; i++) {
        int aux = camino[i];
        camino[i] = camino[longitud - i - 1];
        camino[longitud - i - 1] = aux;
    }

    printf("Camino desde %d hasta %d: ", start, end);
    for (int i = 0; i < longitud; i++) {
        if (i == longitud - 1) {
            printf("%d\n", camino[i]);
        }
        else {
            printf("%d->", camino[i]);
        }
    }

    printf("Distancia desde %d hasta %d: %d\n", start, end, distancias[end]);
}