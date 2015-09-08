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

#define CAPACIDAD 9

typedef struct _cola{
	int capacidad;
	int ultimo;
	char *elementos;
}Cola;

Cola *creaCola(){
	Cola *tmp;
	tmp = malloc(sizeof(Cola));
	tmp->capacidad = CAPACIDAD;
	tmp->ultimo = -1;
	//tmp->elementos = malloc(tmp->capacidad*sizeof(char));
	return tmp;
}

int esVaciaCola(Cola *cola){
	if(cola->ultimo == -1){
		return 1;
	}else{
		return 0;
	}
}

