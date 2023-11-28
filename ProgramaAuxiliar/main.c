//Programa de ayuda para ingresar las calles manualmente de manera rapdia
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vertice {
    //Cada vertice es una interseccion de calles
    int index;
    char* interseccion;
} Vertice;

const Vertice esquinas[] = {
    {0, "Los Carrera - Arturo Prat"},
    {1, "Los Carrera - Serrano"},
    {2, "Los Carrera - Salas"},
    {3, "Los Carrera - Angol"},
    {4, "Los Carrera - Lincoyan"},
    {5, "Los Carrera - Rengo"},
    {6, "Los Carrera - Caupolican"},
    {7, "Los Carrera - Anibal Pinto"},
    {8, "Los Carrera - Colo Colo"},
    {9, "Los Carrera - Castellon"},
    {10, "Los Carrera - Tucapel"},
    {11, "Los Carrera - Orompello"},
    {12, "Los Carrera - Ongolmo"},
    {13, "Los Carrera - Paicavi"},
    {14, "Maipu - Arturo Prat"},
    {15, "Maipu - Serrano"},
    {16, "Maipu - Salas"},
    {17, "Maipu - Angol"},
    {18, "Maipu - Lincoyan"},
    {19, "Maipu - Rengo"},
    {20, "Maipu - Caupolican"},
    {21, "Maipu - Anibal Pinto"},
    {22, "Maipu - Colo Colo"},
    {23, "Maipu - Castellon"},
    {24, "Maipu - Tucapel"},
    {25, "Maipu - Orompello"},
    {26, "Maipu - Ongolmo"},
    {27, "Maipu - Paicavi"},
    {28, "Freire - Arturo Prat"},
    {29, "Freire - Serrano"},
    {30, "Freire - Salas"},
    {31, "Freire - Angol"},
    {32, "Freire - Lincoyan"},
    {33, "Freire - Rengo"},
    {34, "Freire - Caupolican"},
    {35, "Freire - Anibal Pinto"},
    {36, "Freire - Colo Colo"},
    {37, "Freire - Castellon"},
    {38, "Freire - Tucapel"},
    {39, "Freire - Orompello"},
    {40, "Freire - Ongolmo"},
    {41, "Freire - Paicavi"},
    {42, "Barros Arana - Arturo Prat"}, //Plaza españa
    {43, "Barros Arana - Serrano"},
    {44, "Barros Arana - Salas"},
    {45, "Barros Arana - Angol"},
    {46, "Barros Arana - Lincoyan"},
    {47, "Barros Arana - Rengo"},
    {48, "Barros Arana - Caupolican"},
    {49, "Barros Arana - Anibal Pinto"},
    {50, "Barros Arana - Colo Colo"},
    {51, "Barros Arana - Castellon"},
    {52, "Barros Arana - Tucapel"},
    {53, "Barros Arana - Orompello"},
    {54, "Barros Arana - Ongolmo"},
    {55, "Barros Arana - Paicavi"},
    {56, "O'Higgins - Arturo Prat"},
    {57, "O'Higgins - Serrano"},
    {58, "O'Higgins - Salas"},
    {59, "O'Higgins - Angol"},
    {60, "O'Higgins - Lincoyan"},
    {61, "O'Higgins - Rengo"},
    {62, "O'Higgins - Caupolican"},
    {63, "O'Higgins - Anibal Pinto"},
    {64, "O'Higgins - Colo Colo"},
    {65, "O'Higgins - Castellon"},
    {66, "O'Higgins - Tucapel"},
    {67, "O'Higgins - Orompello"},
    {68, "O'Higgins - Ongolmo"},
    {69, "O'Higgins - Paicavi"},
    {70, "San Martin - Arturo Prat"},
    {71, "San Martin - Serrano"},
    {72, "San Martin - Salas"},
    {73, "San Martin - Angol"},
    {74, "San Martin - Lincoyan"},
    {75, "San Martin - Rengo"},
    {76, "San Martin - Caupolican"},
    {77, "San Martin - Anibal Pinto"},
    {78, "San Martin - Colo Colo"},
    {79, "San Martin - Castellon"},
    {80, "San Martin - Tucapel"},
    {81, "San Martin - Orompello"},
    {82, "San Martin - Ongolmo"},
    {83, "San Martin - Paicavi"},
    {84, "Cochrane - Arturo Prat"},
    {85, "Cochrane - Serrano"},
    {86, "Cochrane - Salas"},
    {87, "Cochrane - Angol"},
    {88, "Cochrane - Lincoyan"},
    {89, "Cochrane - Rengo"},
    {90, "Cochrane - Caupolican"},
    {91, "Cochrane - Anibal Pinto"},
    {92, "Cochrane - Colo Colo"},
    {93, "Cochrane - Castellon"},
    {94, "Cochrane - Tucapel"},
    {95, "Cochrane - Orompello"},
    {96, "Cochrane - Ongolmo"},
    {97, "Cochrane - Paicavi"},
    {98, "Chacabuco - Arturo Prat"},
    {99, "Chacabuco - Serrano"},
    {100, "Chacabuco - Salas"},
    {101, "Chacabuco - Angol"},
    {102, "Chacabuco - Lincoyan"},
    {103, "Chacabuco - Rengo"},
    {104, "Chacabuco - Caupolican"},
    {105, "Chacabuco - Anibal Pinto"},
    {106, "Chacabuco - Colo Colo"},
    {107, "Chacabuco - Castellon"},
    {108, "Chacabuco - Tucapel"},
    {109, "Chacabuco - Orompello"},
    {110, "Chacabuco - Ongolmo"},
    {111, "Chacabuco - Paicavi"} //Plaza peru
};

const int NUM_INTERSECCIONES = 112;

char *quitarEspacios(char *s);

int main(void) {

    char *filename = "arcos.txt";
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) return -1;

    char *interseccion = esquinas[0].interseccion;
    char *calle = quitarEspacios(interseccion);
    int direccion;
    printf("%s\n (1 izq, 2 der, 3 bid): ", calle);
    scanf("%d", &direccion);

    if (direccion == 1) {

    }
    else if (direccion == 2) {
        for (int i = 0; i < 13; i++) {
            fprintf(fp, "{%d,%d,1},\n", i, i + 1);
        }
    }
    else if (direccion == 3) {

    }

}

char *quitarEspacios(char *s) {
    int n = 32;
    char *d = malloc(n * sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(s); i++) {
        
        if (s[i] == '-') {
            d[j] = '\0';
            return d;
        }

        if (s[i] != ' ') {
            d[j++] = s[i];
        }

        

    }

    return d;
}

void printToTxT() {

}
    

