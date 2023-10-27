#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct graph {
	int nV;
    bool **adj; // g->adj[i][j] == true if edge from i to j
};

typedef struct graph *Graph;

bool isComplete(Graph g) {
	for (int i = 0; i < g->nV; i++) {
		for (int j = 0; j < g->nV; j++) {
			bool isAdj = g->adj[i][j];
			if (!isAdj && i != j) {
				return false;
			}
		}
	}

	return true;
}
