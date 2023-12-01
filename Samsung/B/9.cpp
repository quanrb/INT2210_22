#include "bits/stdc++.h"
using namespace std;

int N;

void DFS(int u, vector<vector<int>> graph, vector<bool>& visited) {
	visited[u] = true;
	for(int v : graph[u]) {
		if(!visited[v]) {
			DFS(v, graph, visited);
		}
	}
}

bool isConnected(vector<vector<int>> graph) {
	vector<bool> visited(N, false);
	DFS(0, graph, visited);
	return count(visited.begin(), visited.end(), false) == 0;
}

bool checkDegree(vector<vector<int>> graph) {
	int in[N];
	int out[N];
	for(int u = 0; u < N; u++) {
		for(int v : graph[u]) {
			in[v]++;
			out[u]++;
		}
	}
	for(int u = 0; u < N; u++) {
		if(in[u] != out[u]) return false;
	}
	return true;
}

int main() {
	cin >> N;
	vector<vector<int>> graph(N);
	for(int i = 0; i < N; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	if(isConnected(graph) && checkDegree(graph)) {
		cout << "YES";
	}
	else cout << "NO";
}