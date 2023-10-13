#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5;

int shortestPath(vector<vector<int>> graph, int X, int Y) {
	int n = graph.size();
	vector<int> dsc(n, -1);
	queue<int> q;
	q.push(X);
	dsc[X] = 0;

	while(!q.empty()) {
		int p = q.front();
		q.pop();
		if(p == Y) return dsc[p];
		for(int adj : graph[p]) {
			if(dsc[adj] == -1) {
				dsc[adj] = dsc[p] + 1;
				q.push(adj);
			}
		}
	}

	return -1;
}

int main() {
	int n, m; cin >> n >> m;
	int X, Y; cin >> X >> Y;
	vector<vector<int>> graph(n+1);
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		graph[a].push_back(b);
	}
	cout << shortestPath(graph, X, Y);
}