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
    grafo[s].color = 'G';
    grafo[s].distancia = 0;
    grafo[s].padre = -1;
    Cola *Q = creaCola(tam);
    encolar(Q, s);
    while(!esVaciaCola(Q)){
        i = decolar(Q);
        VECINO *aux = grafo[i].vecino;
        while(aux != NULL){
            if(grafo[aux->idNodo].color == 'W'){
                grafo[aux->idNodo].color = 'G';
                grafo[aux->idNodo].distancia = grafo[i].distancia + 1;
                grafo[aux->idNodo].padre = i;
                encolar(Q, aux->idNodo);
            }
            aux = aux->sgte;
        }
        grafo[i].color = 'B';
    }
    return 1;
}

int DFS(Nodo grafo[tam]){
    int i;
    for(i=0; i<tam; i++){
        grafo[i].color = 'W';
        grafo[i].padre = -1;
    }
    tiempo = 0;
    for(i=0; i<tam; i++){
        if(grafo[i].color == 'W'){
            visitarDFS(grafo, i);
        }
    }
    return 1;
}

int visitarDFS(Nodo grafo[tam], int i){
    tiempo++;
    grafo[i].distancia = tiempo;
    grafo[i].color = 'G';
    VECINO *aux = grafo[i].vecino;
    while(aux != NULL){
        if(grafo[aux->idNodo].color == 'W'){
            grafo[aux->idNodo].padre = i;
            visitarDFS(grafo, aux->idNodo);
        }
        aux = aux->sgte;
    }
    grafo[i].color = 'B';
    tiempo++;
    return 1;
}

