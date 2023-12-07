//Programa de ayuda para ingresar las calles manualmente de manera rapdia
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char* argv[]) {
    FILE *fp = fopen("aux.txt", "w");
    if (fp == NULL) return -1;

    int index = 0;
    char *calle1 = argv[1]; 
    char *calle2[] = {"Arturo_Prat", "Serrano", "Salas", "Angol", "Lincoyan", "Rengo", "Caupolican", "Anibal_Pinto", "Colo_Colo", "Castellon", "Tucapel", "Orompello", "Ongolmo", "Paicavi"};
    int dir1 = atoi(argv[2]); 
    int dir2 = atoi(argv[3]);

    for (int i = 0; i <= 1300; i+= 100) {
        fprintf(fp, "{%d, \"%s %d\" , \"%s %d\" },\n", dir1++, calle1, i, calle2[index], dir2);
        index++;
    }
}
