#include "bits/stdc++.h"
using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

class UF {
public:
    vector<int> parent, rank;
    UF(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x, int y) {
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

class Graph {
public:
    int V, E;
    vector<Edge> edges;
    Graph(int vertices, int edgesCount) : V(vertices), E(edgesCount) {}
    void addEdge(int u, int v, int weight) {
        edges.emplace_back(u, v, weight);
    }
    vector<Edge> MST() {
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight > b.weight; // Sắp xếp giảm dần theo trọng số
        });

        UF uf(V);
        vector<Edge> mst;

        for (const Edge& edge : edges) {
            int rootU = uf.find(edge.u);
            int rootV = uf.find(edge.v);

            if (rootU != rootV) {
                uf.unite(rootU, rootV);
                mst.push_back(edge);
            }
        }

        return mst;
    }
};

int main() {
}
