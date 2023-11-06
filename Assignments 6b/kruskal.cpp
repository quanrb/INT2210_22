#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, c;
    Edge(int _u, int _v, int _c): u(_u), v(_v), c(_c) {};
};

struct cmp {
    bool operator() (const Edge& a, const Edge& b) {
        return (a.c < b.c);
    }
};

struct Dsu {
    vector<int> parents;
    void init(int n) {
        parents.resize(n + 2, 0);
        for (int i = 1; i <= n; i++) parents[i] = i;
    }
    int find(int u) {
        if(parents[u] == u) return u;
        return parents[u] = find(parents[u]);
    }
    bool join(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return false;
        parents[v] = u;
        return true;
    }
} dsu;

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    vector<Edge> spanning;
    int totalWeight = 0;
    for(int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }
    dsu.init(n);
    sort(edges.begin(), edges.end(), cmp());
    for(auto e : edges) {
        if(!dsu.join(e.u, e.v)) continue;
        spanning.push_back(e);
        totalWeight += e.c;
    }
    cout << totalWeight << endl;
    for(auto e : spanning) {
        cout << e.u << " " << e.v << " " << e.c << endl;
    }
}