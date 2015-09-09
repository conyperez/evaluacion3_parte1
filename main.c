#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#ifndef GRAFO_H
#include "grafo.h"
#define GRAFO_H
#endif

typedef Nodo Grafo;

int main(){
  Grafo grafo[tam];
  inicializaVecinos(grafo);

  return 0;
}
