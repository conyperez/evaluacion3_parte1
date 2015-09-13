#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#ifndef LISTA_H
#include "lista.h"
#define LISTA_H
#endif

#ifndef COLA_H
#include "cola.h"
#define COLA_H
#endif

#define tam 9

typedef NodoLista VECINO;
int tiempo;

typedef struct _nodo{
	char color;    // W: blanco; B:negro; G:gris 
	int distancia;
	int padre;
	VECINO *vecino;
}Nodo;

int inicializaVecinos(Nodo grafo[tam]){
	for(int i=0; i<tam; i++){
		grafo[i].vecino = NULL;
	}
	return 1;
}

int agregaArista(Nodo grafo[tam], int i, int j){    // Agrega arista NO dirigida
    grafo[i].vecino = insertaNodo(grafo[i].vecino, j);
    grafo[j].vecino = insertaNodo(grafo[i].vecino, i);
    return 1;
}

int BFS(Nodo grafo[tam], int s){
    int i;
    for(i=0; i<tam; i++){
        grafo[i].color = 'W';
        grafo[i].distancia = -1;
        grafo[i].padre = -1;
    }
    printf("Vertices inicializados: \n");
    printf("   Color: Blanco \n   Distancia = -1 \n   Padre = -1 (NULL)\n");
    grafo[s].color = 'G';
    grafo[s].distancia = 0;
    grafo[s].padre = -1;
    printf("\nVertice inicial %d:\n", s);
    printf("   Color: Gris \n   Distancia = 0 \n   Padre = -1 (NULL)\n");
    Cola *Q = creaCola(tam);
    encolar(Q, s);
    printf("\nCola inicializada\n");
    while(!esVaciaCola(Q)){
        i = decolar(Q);
        printf("\nVertice sacado de la cola: %d\n", i);
        VECINO *aux = grafo[i].vecino;
        printf("Revisando cada vecino del vertice %d\n\n", i);
        while(aux != NULL){
            if(grafo[aux->idNodo].color == 'W'){
                printf("Vecino encontrado: %d\n", aux->idNodo);
                grafo[aux->idNodo].color = 'G';
                grafo[aux->idNodo].distancia = grafo[i].distancia + 1;
                grafo[aux->idNodo].padre = i;
                encolar(Q, aux->idNodo);
                printf("   Color: Gris \n   Distancia = %d \n   Padre = %d\n", grafo[aux->idNodo].distancia, grafo[aux->idNodo].padre);
                printf("Se agrega a la cola el vertice: %d\n\n", aux->idNodo);
            }
            aux = aux->sgte;
        }
        grafo[i].color = 'B';
        printf("Vertice %d\n", i);
        printf("   Color: Negro\n\n");
        printf("------------------------\n");
    }
    return 1;
}

int DFS(Nodo grafo[tam]){
    int i;
    for(i=0; i<tam; i++){
        grafo[i].color = 'W';
        grafo[i].padre = -1;
    }
    printf("Vertices inicializados: \n");
    printf("   Color: Blanco \n   Padre = -1 (NULL)\n");
    tiempo = 0;
    printf("Tiempo = 0\n\n");
    for(i=0; i<tam; i++){
        if(grafo[i].color == 'W'){
            printf("Vertice blanco encontrado: %d\nPasa a visitarDFS\n", i);
            visitarDFS(grafo, i);
        }
    }
    return 1;
}

int visitarDFS(Nodo grafo[tam], int i){
    tiempo++;
    grafo[i].distancia = tiempo;
    grafo[i].color = 'G';
    printf("Tiempo = %d\n", tiempo);
    printf("Color: Gris \nDistancia = %d\n", grafo[i].distancia);
    VECINO *aux = grafo[i].vecino;
    printf("\nRevisando cada vecino del vertice %d\n\n", i);
    while(aux != NULL){
        if(grafo[aux->idNodo].color == 'W'){
            grafo[aux->idNodo].padre = i;
            printf("Vecino encontrado: %d\n", aux->idNodo);
            printf("   Padre = %d\n\n", i);
            visitarDFS(grafo, aux->idNodo);
        }
        aux = aux->sgte;
    }
    grafo[i].color = 'B';
    tiempo++;
    printf("Vertice %d\n", i);
    printf("   Color: Negro\n   Tiempo = %d\n\n", tiempo);
    printf("------------------------\n");
    return 1;
}

