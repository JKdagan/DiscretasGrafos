
typedef struct Vertice {
    //Cada vertice es una interseccion de calles
    int index;
    char* interseccion;
} Vertice;

typedef struct Arco {
                        //Cada arco representa una cuadra
    Vertice vert_src;   //vertice donde parte el arco
    Vertice vert_dest;  //vertice donde llega el arco
    int peso;           //peso para algoritmo
} Arco;

//Intersecciones de calles, parte de Los Carrera con Arturo Prat y va de izq a derecha, arriba a abajo
const Vertice ESQUINAS[] = {
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

const char* NOMBRES_CALLES[] = {
    "Arturo Prat", "Serrano", "Salas","Angol", "Lincoyan", "Rengo", "Caupolican", 
    "Anibal Pinto", "Colo Colo", "Castellon", "Tucapel", "Orompello", "Ongolmo", 
    "Paicavi", "Chacabuco", "Cochrane", "San Martin", "O'Higgins", "Barros Arana", 
    "Freire", "Maipu", "Los Carrera", "Pedro Aguirre Cerda"
};

const Arco CALLES[] = {
    //HORIZONTALES
    //Los Carrera: Bidireccional
    {0,1,1},
    {1,2,1},
    {2,3,1},
    {3,4,1},
    {4,5,1},
    {5,6,1},
    {6,7,1},
    {7,8,1},
    {8,9,1},
    {9,10,1},
    {10,11,1},
    {11,12,1},
    {12,13,1},
    {13,12,1},
    {12,11,1},
    {11,10,1},
    {10,9,1},
    {9,8,1},
    {8,7,1},
    {7,6,1},
    {6,5,1},
    {5,4,1},
    {4,3,1},
    {3,2,1},
    {2,1,1},
    {1,0,1},
    //--------------
    //Maipu: Der
    {14,15,1},
    {15,16,1},
    {16,17,1},
    {17,18,1},
    {18,19,1},
    {19,20,1},
    {20,21,1},
    {21,22,1},
    {22,23,1},
    {23,24,1},
    {24,25,1},
    {25,26,1},
    {26,27,1},
    //--------------
    //Freire: Izq
    {41,40,1},
    {40,39,1},
    {39,38,1},
    {38,37,1},
    {37,36,1},
    {36,35,1},
    {35,34,1},
    {34,33,1},
    {33,32,1},
    {32,31,1},
    {31,30,1},
    {30,29,1},
    {29,28,1},
    //--------------
    //Barros Arana: Der
    {42,43,1},
    {43,44,1},
    {44,45,1},
    {45,46,1},
    {46,47,1},
    {47,48,1},
    {48,49,1},
    {49,50,1},
    {50,51,1},
    {51,52,1},
    {52,53,1},
    {53,54,1},
    {54,55,1},
    //--------------
    //O'Higgins: Izq
    {69,68,1},
    {68,67,1},
    {67,66,1},
    {66,65,1},
    {65,64,1},
    {64,63,1},
    {63,62,1},
    {62,61,1},
    {61,60,1},
    {60,59,1},
    {59,58,1},
    {58,57,1},
    {57,56,1},
    //--------------
    //San Martin: Der
    {70,71,1},
    {71,72,1},
    {72,73,1},
    {73,74,1},
    {74,75,1},
    {75,76,1},
    {76,77,1},
    {77,78,1},
    {78,79,1},
    {79,80,1},
    {80,81,1},
    {81,82,1},
    {82,83,1},
    //--------------
    //Cochrane: Izq
    {97,96,1},
    {96,95,1},
    {95,94,1},
    {94,93,1},
    {93,92,1},
    {92,91,1},
    {91,90,1},
    {90,89,1},
    {89,88,1},
    {88,87,1},
    {87,86,1},
    {86,85,1},
    {85,84,1},
    //--------------
    //Chacabuco: Bidireccional
    {98,99,1},
    {99,100,1},
    {100,101,1},
    {101,102,1},
    {102,103,1},
    {103,104,1},
    {104,105,1},
    {105,106,1},
    {106,107,1},
    {107,108,1},
    {108,109,1},
    {109,110,1},
    {110,111,1},
    {111,110,1},
    {110,109,1},
    {109,108,1},
    {108,107,1},
    {107,106,1},
    {106,105,1},
    {105,104,1},
    {104,103,1},
    {103,102,1},
    {102,101,1},
    {101,100,1},
    {100,99,1},
    {99,98,1},
    //-----------------------------------
    //VERTICALES
};

