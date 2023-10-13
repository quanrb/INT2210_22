#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> graph, vector<bool>& visited, int node) {
    visited[node] = true;
    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

int countConnectedComponents(vector<vector<int>> graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(!visited[i]) {
            dfs(graph, visited, i);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; 
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return 0;
}
