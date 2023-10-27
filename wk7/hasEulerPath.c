#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct graph {
	int nV;
    bool **adj; // g->adj[i][j] == true if edge from i to j
};

typedef struct graph *Graph;

// assume graph is connected
bool hasEulerPath(Graph g) {
	int *degree = calloc(g->nV, sizeof(int));

	for (int i = 0; i < g->nV; i++) {
		// calculate degree and store in degree array
		for (int j = 0; j < g->nV; j++) {
			if (g->adj[i][j]) {
				degree[i]++;
			}
		}
	}

	int numOddDegree = 0;
	for (int i = 0; i < g->nV; i++) {
		if (degree[i] % 2 == 1) {
			numOddDegree++;
		}
	}

	return (numOddDegree == 0) || (numOddDegree == 2);
}
