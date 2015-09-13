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
