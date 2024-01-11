
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "GraphPrivate.h"

// static void dfsRecOwn(Graph g, Vertex v, bool *visited);
static void dfsRec(Graph g, Vertex v, bool *visited);
static bool dfsHasPath(Graph g, Vertex v, Vertex dest, bool *visited);

void dfs(Graph g, Vertex src) {
	bool *visited = calloc(g->nV, sizeof(bool));
	printf("DFS visit order: ");
	dfsRec(g, src, visited);
	printf("\n");
	free(visited);
}

static void dfsRec(Graph g, Vertex v, bool *visited) {
	printf("%d ", v);
	visited[v] = true;

	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		Vertex w = curr->v;
		if (!visited[w]) {
			dfsRec(g, w, visited);
		}
	}
}
bool hasPath(Graph g, Vertex src, Vertex dest) {
	bool *visited = calloc(g->nV, sizeof(bool));
	bool result =  dfsHasPath(g, src, dest, visited);
	free(visited);
	// GraphFree(g);
	return result;
}
bool dfsHasPath(Graph g, Vertex v, Vertex dest, bool *visited) {
	visited[v] = true;
	if (v == dest) {
		return true;
	}
	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		Vertex w = curr->v;
		if (!visited[w]) {
			if (dfsHasPath(g, w, dest, visited)) {
				return true;
			}
		}
	}
	free(curr);
	return false;
}


//unconnected graph
void dfs(Graph g) {
	Vertex *predecessor = malloc(g->nV * sizeof(Vertex));
	for (Vertex i = 0; i < g->nV; i++) {
		predecessor[i] = -1;
	}
	for (Vertex v = 0; v < g->nV; v++) {
		if (predecessor[v] == -1) {
			dfsRec(g, v, predecessor);
		}
	}
}