#include "bits/stdc++.h"
using namespace std;

const int MAXN = 1e5;
int visited[MAXN];
vector<int> graph[MAXN];
stack<int> topo;

void dfs(int u) {
	visited[u] = 1;
	for(auto v : graph[u]) {
		if(visited[v] == 1) {
			return;
		}
		if(!visited[v]) dfs(v);
	}
	topo.push(u);
	visited[u] = 2;
}

int main() {
	int n, m;
	cin >> n >> m;
	while(m--) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	for(int i = 1; i <= n; i++) {
		if(!visited[i]) dfs(i);
	}
	while(!topo.empty()) {
		int v = topo.top();
		cout << v << " ";
		topo.pop();
	}
}

