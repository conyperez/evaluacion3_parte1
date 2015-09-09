#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#ifndef STRING_H
#include <string.h>
#define STRING_H
#endif

typedef struct tipo_nodo{
	char *ubicacion;
	struct tipo_nodo *sgte;
}NodoLista;

NodoLista *insertaNodo(NodoLista *lista, char unaUbicacion){
    NodoLista *nuevo;
    nuevo = (NodoLista*)malloc(sizeof(NodoLista));
    nuevo->ubicacion = unaUbicacion;
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

void muestraLista(NodoLista *lista){
    NodoLista *tmp;
    while(tmp != NULL){
        printf("%c -> ", tmp->ubicacion);
        tmp = tmp->sgte;
    }
    printf("NULL\n");
}
