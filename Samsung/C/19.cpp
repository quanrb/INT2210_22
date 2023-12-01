#include "bits/stdc++.h"
using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

class Graph {
public:
    int V, E;
    vector<Edge> edges;
    Graph(int vertices, int cnt) : V(vertices), E(cnt) {}
    void addEdge(int u, int v, int weight) {
        edges.emplace_back(u, v, weight);
    }
    void dfs(int u, int parent, int& time, vector<int>& d, vector<int>& l, vector<bool>& visited, vector<Edge> bridges) {
        d[u] = l[u] = ++time;
        visited[u] = true;
        for(const Edge& edge : edges) {
            int v = (edge.u == u) ? edge.v : (edge.v == u) ? edge.u : -1;
            if(v == -1) continue;
            if(!visited[v]) {
                dfs(v, u, time, d, l, visited, bridges);
                l[u] = min(l[u], l[v]);
                if(l[v] > d[u]) {
                    bridges.push_back(edge);
                }
            } else if(v != parent) {
                l[u] = min(l[u], d[v]);
            }
        }
    }

    vector<Edge> findCriticalEdges() {
        vector<int> d(V, -1);
        vector<int> l(V, -1);
        vector<bool> visited(V, false);
        vector<Edge> criticalEdges;
        int time = 0;
        for(int i = 0; i < V; ++i) {
            if(!visited[i]) {
                dfs(i, -1, time, d, l, visited, criticalEdges);
            }
        }
        return criticalEdges;
    }
};

int main() {

}
