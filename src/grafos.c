#include <stdio.h>

// Suponha de que o nr de nos no grafo seja constante
// os arcos podem ser acrescentados mas os nos nao
#define MAXNODES 50
#define TRUE 1
#define FALSE 0

typedef struct node {
  // Informações adicionais a cada nó
} node;

typedef struct edge {
  int adj;
  // Informações adicionais para cada arco
} edge;

struct graph {
  // Os nós são enumerados de 0 a MAXNODES-1
  struct node nodes[MAXNODES];
  // Matriz adjacencia
  struct edge edges[MAXNODES][MAXNODES];
};

struct graph g;

void join (edge *adj, node1, node2){
  adj[node1][node2]=TRUE;
};

void remov (edge *adj, node1, node2){
  adj[node1][node2]=FALSE;
};

int adjacent (edge *adj, node1, node2){
  return ((adj[node1][node2] == TRUE)? TRUE : FALSE);
};
