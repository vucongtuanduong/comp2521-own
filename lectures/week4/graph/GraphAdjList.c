// Implementation of the Graph ADT
// Undirected, unweighted
// Vertices are given by integers between 0 and V - 1

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

struct graph {
	int nV;
	int nE;
	struct adjNode **edges;
};

struct adjNode {
	Vertex v;
	struct adjNode *next;
};

static bool validVertex(Graph g, Vertex v);

/**
 * Returns a new graph with nV vertices
 */
Graph GraphNew(int nV) {
	Graph g = malloc(sizeof(struct graph));
	g->edges = calloc(nV, sizeof(struct adjNode *));
	g->nV = nV;
	g->nE = 0;
	return g;
}

/**
 * Frees all memory allocated to a graph
 */
void GraphFree(Graph g) {
	for (int i = 0; i < g->nV; i++) {
        struct adjNode *curr = g->edges[i];
        while (curr != NULL) {
            struct adjNode *temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(g->edges);
    free(g);
}

/**
 * Returns the number of vertices in a graph
 */
int GraphNumVertices(Graph g) {
	return g->nV;
}

/**
 * Returns the number of edges in a graph
 */
int GraphNumEdges(Graph g) {
	return g->nE;
}

/**
 * Returns true if there is an edge between v and w,
 * and false otherwise
 */
bool GraphIsAdjacent(Graph g, Vertex v, Vertex w) {
	assert(validVertex(g, v));
	assert(validVertex(g, w));

    for (int i  =0 ; i < g->nV; i++) {
        struct adjNode *curr = g->edges[i];
        while (curr != NULL) {
            if (curr->v == w) {
                return true;
            }
            curr = curr->next;
        }
    }
	return false;
}

/**
 * Inserts an edge between v and w
 */
void GraphInsertEdge(Graph g, Vertex v, Vertex w) {
	assert(validVertex(g, v));
	assert(validVertex(g, w));

	// TODO - exercise for you
	// Note that adjacency lists should be in ascending order
    struct adjNode *newNode = malloc(sizeof(struct adjNode));
	newNode->v = w;
	newNode->next = NULL;
	struct adjNode *newNode2 = malloc(sizeof(struct adjNode));
	newNode2->v = v;
	newNode2->next = NULL;
	g->nE++;
	if (g->edges[v] == NULL || g->edges[v]->v > w) {
		newNode->next = g->edges[v];
		g->edges[v] = newNode;

	} else {
		struct adjNode *curr = g->edges[v];
		while (curr->next != NULL && curr->next->v < w) {
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
	}
	if (g->edges[w] == NULL || g->edges[w]->v > v) {
		newNode2->next = g->edges[w];
		g->edges[w] = newNode2;
	} else {
		struct adjNode *curr = g->edges[w];
		while (curr->next != NULL && curr->next->v < v) {
			curr = curr->next;
		}
		newNode2->next = curr->next;
		curr->next = newNode2;
	}
}

/**
 * Removes an edge between v and w
 */
void GraphRemoveEdge(Graph g, Vertex v, Vertex w) {
	assert(validVertex(g, v));
	assert(validVertex(g, w));

	// TODO - exercise for you
	g->nE--;
	if (g->edges[v]->v == w) {
		struct adjNode *temp = g->edges[v];
		g->edges[v] = g->edges[v]->next;
		free(temp);
	} else {
		struct adjNode *curr = g->edges[v];
		while (curr->next != NULL && curr->next->v != w) {
			curr = curr->next;
		}
		struct adjNode *temp = curr->next;
		curr->next = curr->next->next;
		free(temp);
	}
	if (g->edges[w]->v == v) {
		struct adjNode *temp = g->edges[w];
		g->edges[w] = g->edges[w]->next;
		free(temp);
	} else {
		struct adjNode *curr = g->edges[w];
		while (curr->next != NULL && curr->next->v != v) {
			curr = curr->next;
		}
		struct adjNode *temp = curr->next;
		curr->next = curr->next->next;
		free(temp);
	}
}

/**
 * Returns the degree of a vertex
 */
int GraphDegree(Graph g, Vertex v) {
	assert(validVertex(g, v));

	int degree = 0;
	struct adjNode *curr = g->edges[v];
	for (; curr != NULL; curr = curr->next) {
		degree++;
	}
	return degree;
}

/**
 * Displays a graph
 */
void GraphShow(Graph g) {
	printf("Number of vertices: %d\n", g->nV);
	printf("Number of edges: %d\n", g->nE);
	printf("Edges:\n");
	for (int i = 0; i < g->nV; i++) {
		printf("%2d:", i);
		for (struct adjNode *curr = g->edges[i]; curr != NULL; curr = curr->next) {
			printf(" %d", curr->v);
		}
		printf("\n");
	}
	printf("\n");
}

static bool validVertex(Graph g, Vertex v) {
	return (v >= 0 && v < g->nV);
}

