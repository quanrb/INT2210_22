#include "bits/stdc++.h"
using namespace std;
using namespace chrono;

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

void proceed(int u, vector<vector<pair<int, int>>> graph, vector<bool>& check, priority_queue<pair<int, Edge>, vector<pair<int, Edge>>, greater<pair<int, Edge>>>& pq) {
    check[u] = true;
    for(pair<int, int> neighbor : graph[u]) {
        int v = neighbor.first;
        int weight = neighbor.second;
        if(!check[v]) {
            pq.push({weight, Edge(u, v, weight)});
        }
    }
}

vector<Edge> prim(vector<vector<pair<int, int>>> graph) {
    int V = graph.size();
    vector<bool> check(V, false);
    vector<Edge> mstEdges;
    priority_queue<pair<int, Edge>, vector<pair<int, Edge>>, greater<pair<int, Edge>>> pq;
    proceed(0, graph, check, pq);
    while(!pq.empty()) {
        int u = pq.top().second.u;
        int v = pq.top().second.v;
        int weight = pq.top().second.weight;
        pq.pop();
        if(check[u] && check[v]) {
            continue;
        }
        mstEdges.push_back(Edge(u, v, weight));
        if(!check[u]) {
            proceed(u, graph, check, pq);
        }
        if(!check[v]) {
            proceed(v, graph, check, pq);
        }
    }
    return mstEdges;
}

vector<Edge> primQueue( vector<vector<pair<int, int>>> graph) {
    int V = graph.size();
    vector<bool> check(V, false);
    vector<Edge> mstEdges;
    vector<int> key(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    key[0] = 0;
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        check[u] = true;
        for(pair<int, int> neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!check[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                mstEdges.push_back(Edge(u, v, weight));
            }
        }
    }
    return mstEdges;
}


int main() {

}
