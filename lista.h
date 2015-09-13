#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

typedef struct tipo_nodo{
	int idNodo;
	struct tipo_nodo *sgte;
}NodoLista;

NodoLista *insertaNodo(NodoLista *lista, int e){
    NodoLista *nuevo;
    nuevo = (NodoLista*)malloc(sizeof(NodoLista));
    nuevo->idNodo = e;
    nuevo->sgte = NULL;
    if(lista == NULL){
        lista = nuevo;
    }else{
        NodoLista *aux;
        aux = lista;
        while(aux->sgte != NULL){
            aux = aux->sgte;
        }
        aux->sgte = nuevo;
    }
    return lista;
}
