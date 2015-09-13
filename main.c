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

#define tam 9

typedef Nodo Grafo;

int main(){
  
  Grafo grafo[tam];
  
  inicializaVecinos(grafo);

  agregaArista(grafo, 0, 1);
  agregaArista(grafo, 0, 2);
  agregaArista(grafo, 1, 2);
  agregaArista(grafo, 1, 4);
  agregaArista(grafo, 3, 4);
  agregaArista(grafo, 2, 7);
  agregaArista(grafo, 3, 5);
  agregaArista(grafo, 4, 7);
  agregaArista(grafo, 5, 6);
  agregaArista(grafo, 1, 5);
  agregaArista(grafo, 6, 7);
  agregaArista(grafo, 5, 7);
  agregaArista(grafo, 7, 8);

  printf("RECORRIDO DE GRAFO POR: BREADTH-FIRST SEARCH (BFS)\n\n");
  BFS(grafo, 0);

  printf("\nRECORRIDO DE GRAFO POR: DEPTH-FIRST SEARCH (DFS)\n\n");
  DFS(grafo);

  return 0;
}
