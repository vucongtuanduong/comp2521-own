#include "Graph.h"
using namespace std;
struct adjNode{
    Vertex v;
    adjNode *next;
};
struct Graph{
    int nV;//number of vertices
    int nE; //number of edges
    adjNode **edges;
};
static bool validVertex(Graph *g, Vertex v);

Graph *GraphNew(int nV) {
    Graph *g = new Graph;
    g->nV = nV;
    g->nE = 0;
    g->edges = new adjNode*[nV];
    for (int i = 0; i < nV; i++) {
        g->edges[i] = new adjNode[nV];
    }
    return g;
}
void GraphFree(Graph *g) {
    for (int i = 0; i < g->nV; i++) {
        adjNode *curr = g->edges[i];
        while (curr != NULL) {
            adjNode *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    delete[] g->edges;
    delete g;
}
int GraphNumVertices(Graph *g) {
    return g->nV;
}
int GraphNumEdges(Graph *g) {
    return g->nE;
}
bool GraphIsAdjacent(Graph *g, Vertex v, Vertex w) {
    assert(validVertex(g,v));
    assert(validVertex(g,w));

    adjNode *curr = g->edges[v];
    for (; curr != NULL && w >= curr->v; curr = curr->next) {
        if (curr->v == w) {
            return true;
        }
    }
    return false;

}
static bool validVertex(Graph *g, Vertex v) {
    return (v >= 0 && v < g->nV);
}