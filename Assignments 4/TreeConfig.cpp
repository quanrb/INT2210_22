#include "bits/stdc++.h"
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};


Node *buildTree(map<int, vector<int>> edges, int value) {
    Node *newNode = new Node(value);

    if(edges.find(value) == edges.end()) {
        return newNode;
    }

    for(auto child : edges[value]) {
        Node *childNode = buildTree(edges, child);
        if(newNode->left == NULL) {
            newNode->left = childNode;
        }
        else {
            newNode->right = childNode;
        }
    }

    return newNode;
}

int calculateHeight(Node* root) {
    if(!root) {
        return 0;
    }

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

void preorder(Node* root) {
    if(root) {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(Node* root) {
    if(root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
}

bool isBinaryTree(map<int, vector<int>> edges) {
    for(auto child : edges) {
        if(child.second.size() > 2) {
            return false;
        }
    }
    return true;
}

void inorder(Node* root) {
    if(root) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    map<int, vector<int>> edges;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }

    Node* root = buildTree(edges, 1);
    int height = calculateHeight(root);
    cout << height << " " << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    if(isBinaryTree(edges)) {
        inorder(root);
    }
    else {
        cout << "NOT BINARY TREE\n";
    }
    return 0;
}

