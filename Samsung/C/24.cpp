#include "bits/stdc++.h"
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int _data) : data(_data), next(nullptr), prev(nullptr) {}
};

class BoruvkaForest {
public:
    vector<Node*> roots;
    BoruvkaForest(int V) {
        roots.resize(V, nullptr);
        for (int i = 0; i < V; ++i) {
            roots[i] = new Node(i);
            roots[i]->next = roots[i];
            roots[i]->prev = roots[i];
        }
    }
    Node* findRoot(Node* node) {
        return node->next;
    }
    void mergeTrees(Node* root1, Node* root2) {
        Node* tail1 = root1->prev;
        Node* tail2 = root2->prev;
        tail1->next = root2;
        root2->prev = tail1;
        tail2->next = root1;
        root1->prev = tail2;
    }
};

struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

vector<Edge> boruvkaMST(vector<Edge>& graph, int V) {
    vector<Edge> mstEdges;
    BoruvkaForest forest(V);
    while(mstEdges.size() < V - 1) {
        vector<Edge> cheapestEdge(V, Edge(-1, -1, INT_MAX));
        for(const Edge& edge : graph) {
            Node* rootU = forest.findRoot(forest.roots[edge.u]);
            Node* rootV = forest.findRoot(forest.roots[edge.v]);
            if(rootU != rootV && edge.weight < cheapestEdge[rootU->data].weight) {
                cheapestEdge[rootU->data] = edge;
            }
        }
        for (int i = 0; i < V; ++i) {
            if (cheapestEdge[i].u != -1) {
                Node* rootU = forest.findRoot(forest.roots[cheapestEdge[i].u]);
                Node* rootV = forest.findRoot(forest.roots[cheapestEdge[i].v]);
                if (rootU != rootV) {
                    forest.mergeTrees(rootU, rootV);
                    mstEdges.push_back(cheapestEdge[i]);
                }
            }
        }
    }
    return mstEdges;
}

 int main() {
    
 }
