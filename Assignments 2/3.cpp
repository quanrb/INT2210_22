#include "bits/stdc++.h"
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
	Node() {

	}
	Node(int d, Node* p = nullptr) {
		data = d;
		next = p;
	}
};

Node* makeNode(int x) {
	Node *newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void print(Node* head) {
	while(head != nullptr) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int size(Node *head) {
	int cnt = 0;
	while(head != nullptr) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

void insert(Node *&head, int x) {
	Node *newNode = makeNode(x);
	if(head == nullptr) {
		head = newNode;
		return;
	}
	Node *p = head;
	while(p->next != NULL) {
		p = p->next;
	}
	p->next = newNode;
	newNode->prev = p;
}

int main() {
	int n; cin >> n;
	Node *head = NULL;
	while(n--) {
		int x; cin >> x;
		insert(head, x);
	}
	int triplets = 0;
	if(size(head) > 2) {
		Node *p = head->next;
		while(p->next != nullptr) {
			if(p->prev->data + p->next->data + p->data == 0) ++triplets;
			p = p->next;
		}
	}
	cout << triplets << endl;
	// print(head);
}	