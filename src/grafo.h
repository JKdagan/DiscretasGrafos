
typedef struct Vertice {
    int dest;
    struct Vertice* next;
} Vertice;

typedef struct Grafo {
    int vertices; //numero de vertices
    Vertice** lista_ady; //array de lista de adyacencia
} Grafo;

Grafo* crearGrafo(int vertices);
Vertice* crearVertice(int dest);
int** listaAMatrizAdj(Grafo* grafo);
void printMatrizAdj(int** matriz_adj, int vertices);
void freeMatrizAdj(int** matriz_adj, int vertices);
void addArco(Grafo* grafo, int src, int dest);
void printGrafo(Grafo* grafo);
void freeGrafo(Grafo* grafo);