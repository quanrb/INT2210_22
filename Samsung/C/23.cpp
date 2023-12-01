#include "bits/stdc++.h"
using namespace std;
class UF {
public:
    vector<int> parent, rank;
    UF(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if(rootX != rootY) {
            if(rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                if(rank[rootX] == rank[rootY]) {
                    rank[rootY]++;
                }
            }
        }
    }
};

struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

vector<Edge> boruvkaMST(vector<Edge> graph, int V) {
    vector<Edge> mstEdges;
    UF uf(V);
    while(mstEdges.size() < V - 1) {
        vector<int> lowEdge(V, -1);
        for(const Edge& edge : graph) {
            int rootU = uf.find(edge.u);
            int rootV = uf.find(edge.v);
            if(rootU != rootV) {
                if(lowEdge[rootU] == -1 || edge.weight < graph[lowEdge[rootU]].weight) {
                    lowEdge[rootU] = edge.u;
                }
                if(lowEdge[rootV] == -1 || edge.weight < graph[lowEdge[rootV]].weight) {
                    lowEdge[rootV] = edge.v;
                }
            }
        }

        for(int i = 0; i < V; ++i) {
            if(lowEdge[i] != -1) {
                int rootU = uf.find(lowEdge[i]);
                int rootV = uf.find(i);
                if (rootU != rootV) {
                    uf.unionSet(rootU, rootV);
                    mstEdges.push_back(Edge(lowEdge[i], i, graph[lowEdge[i]].weight));
                }
            }
        }
    }
    return mstEdges;
}

int main() {
}
