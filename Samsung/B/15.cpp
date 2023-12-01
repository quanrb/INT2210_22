#include "bits/stdc++.h"
using namespace std;

vector<int> topoSort(vector<vector<int>> graph, vector<int>& indegree) {
    vector<int> result;
    queue<int> q;
    for(int u = 0; u < (int) indegree.size(); u++) {
        if(indegree[u] == 0) {
            q.push(u);
        }
    }
    while(!q.empty()) {
        char current = q.front();
        q.pop();
        result.push_back(current);
        for(int neighbor : graph[current]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    return result;
}

int main() {
    vector<vector<int>> graph = {};
    vector<int> indegree;
    for(auto u : graph) {
        for(int v : u) {
            indegree[v]++;
        }
    }
    vector<int> sortedOrder = topoSort(graph, indegree);
    return 0;
}
