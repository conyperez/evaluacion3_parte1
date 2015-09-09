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

typedef struct _cola{
	int capacidad;
	int ultimo;
	char *elementos;
}Cola;

Cola *creaCola(int unaCapacidad){
	Cola *tmp;
	tmp = malloc(sizeof(Cola));
	tmp->capacidad = unaCapacidad;
	tmp->ultimo = -1;
	tmp->elementos = malloc(tmp->capacidad*sizeof(char));
	return tmp;
}

int esVaciaCola(Cola *cola){
	if(cola->ultimo == -1){
		return 1;
	}else{
		return 0;
	}
}

int encolar(Cola *cola, char unaUbicacion){
    if(cola->ultimo+1 == cola->capacidad){
        return -1;
    }
    cola->ultimo++;
    cola->elementos[cola->ultimo] = unaUbicacion;
    return 1;
}

int decolar(Cola *cola){
    if(esVaciaCola(cola)){
        return -1;
    }
    char ubicacion = cola->elementos[0];
    int i;
    for(i=0; i<cola->ultimo; i++){
        cola->elementos[i] = cola->elementos[i+1];
    }
    cola->ultimo--;
    return ubicacion;
}

void vaciaCola(Cola *cola){
    while(!esVaciaCola(cola)){
        decolar(cola);
    }
}

void eliminaCola(Cola *cola){
    free(cola->elementos);
    free(cola);
}

void recorrerCola(Cola *cola){
    printf("Inicio Cola\n");
    printf("Tamaño cola: %d\n", cola->ultimo+1);
    int i;
    for(i=0; i<=cola->ultimo; i++){
        printf("Lista[%d] = %d\n", i, cola->elementos[i]);
    }
    printf("Fin Cola\n");
}

