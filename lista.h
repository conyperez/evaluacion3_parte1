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

