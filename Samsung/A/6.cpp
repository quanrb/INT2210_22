#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e4;
int N;

void DFS(int v, vector<vector<int>> graph, vector<bool>& visited) {
	visited[v] = true;
	for(auto i : graph[v]) {
		if(!visited[i]) {
			DFS(i, graph, visited);
		}
	}
}

bool isEdgeConnected(int u, int v, vector<vector<int>> graph) {
	for(auto i = graph[u].begin(); i != graph[u].end(); i++) {
		if(graph[u][*i] == v) {
			graph[u].erase(i);
			break;
		}
	}
	for(auto i = graph[v].begin(); i != graph[v].end(); i++) {
		if(graph[v][*i] == u) {
			graph[v].erase(i);
			break;
		}
	}
	vector<bool> visited(N, false);
	DFS(u, graph, visited);
	graph[u].push_back(v);
	graph[v].push_back(u);
	return count(visited.begin(), visited.end(), false) <= 1;
}

int main() {
	cin >> N;
	vector<vector<int>> graph(N);
	for(int i = 0; i < N; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int u = 0; u < N; u++) {
		for(int v : graph[u]) {
			if(u < v && !isEdgeConnected(u, v, graph)) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
}