#include "bits/stdc++.h"
using namespace std;

struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

class Prim {
public:
    vector<vector<pair<int, int>>> adj;

    Prim(int V) : adj(V) {}
    void addEdge(int u, int v, int weight) {
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight);
    }

    vector<Edge> prim(int maxn) {
        vector<Edge> mstEdges;
        vector<bool> inMST(adj.size(), false);
        vector<int> key(adj.size(), numeric_limits<int>::max());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        key[0] = 0;
        pq.push({0, 0});
        while(!pq.empty() && mstEdges.size() < min(maxn, adj.size() - 1)) {
            int u = pq.top().second;
            pq.pop();
            if(inMST[u]) {
                continue;
            }
            inMST[u] = true;
            for(auto neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if(!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    mstEdges.emplace_back(u, v, weight);
                }
            }
        }
        return mstEdges;
    }
};

int main() {
}
