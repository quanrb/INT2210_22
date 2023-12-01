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

vector<Edge> MST(vector<Edge> graph, int V, vector<Edge> Edges) {
    vector<Edge> allEdges = graph;
    allEdges.insert(allEdges.end(), Edges.begin(), Edges.end());
    sort(allEdges.begin(), allEdges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    UF uf(V);
    vector<Edge> mstEdges;

    for(const Edge& edge : allEdges) {
        int rootU = uf.find(edge.u);
        int rootV = uf.find(edge.v);

        if(rootU != rootV) {
            uf.unionSet(rootU, rootV);
            mstEdges.push_back(edge);
        }
    }
    return mstEdges;
}

int main() {

}
