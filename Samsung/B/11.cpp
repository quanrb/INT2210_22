//Hamilton trong đồ thị có hướng phi chu trình

#include "bits/stdc++.h"
using namespace std;

int N;

class Graph {
public:
    int V;
    vector<vector<int>> adj;
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
};

bool hamilton(vector<vector<int>> graph) {
	vector<int> in(N, 0);
	for(int u = 0; u < N; u++) {
		for(int v: graph[u]) {
			++in[v];
		}
	}
	queue<int> q;
    for(int u = 0; u < N; u++) {
        if(in[u] == 0) {
            q.push(u);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : graph[u]) {
            in[v]--;
            if(in[v] == 0) {
                q.push(v);
            }
        }
    }
    for(int u = 0; u < N; u++) {
        if(in[u] != 0) {
            return false;
        }
    }
    return true;
}


int main() {
    cin >> N;
    //nhap cac cap dinh
}
