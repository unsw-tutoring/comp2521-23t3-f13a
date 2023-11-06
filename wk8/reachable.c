#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

struct graph {
	int nV;
    bool **adj; // g->adj[i][j] == true if edge from i to j
};

typedef int Vertex;
typedef struct graph *Graph;

Set reachable(Graph g, Vertex src) {
	Set s = SetNew();

	doReachable(g, s, src);

	return s;
}

void doReachable(Graph g, Set s, Vertex curr) {
	if (SetContains(s, curr)) return; // base case
	SetInsert(s, curr);
	for (int i = 0; i < g->nV; i++) {
		if (g->adj[curr][i]) {
			doReachable(g, s, i);
		}
	}
}
