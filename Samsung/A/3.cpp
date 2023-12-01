#include "bits/stdc++.h"
using namespace std;

int countParallelEdges(vector<pair<int, int>>& graph) {
    unordered_set<int> vertices;
    unordered_set<int> parallelEdges;
    for(auto edge : graph) {
        vertices.insert(edge.first);
        vertices.insert(edge.second);
    }
    int cnt = vertices.size();
    vector<vector<int>> edges(cnt);
    for(auto edge : graph) {
        edges[edge.first].push_back(edge.second);
        edges[edge.second].push_back(edge.first);
    }
    for(int v = 0; v < cnt; v++) {
        vector<int> neighbors = edges[v];
        unordered_set<int> visited;
        for(int neighbor : neighbors) {
            if(visited.find(neighbor) != visited.end()) {
                parallelEdges.insert(neighbor);
            } else {
                visited.insert(neighbor);
            }
        }
    }
    return parallelEdges.size();
}

int main() {
    return 0;
}
