#include "bits/stdc++.h"
using namespace std;

struct Node {
	int data;
	Node* next;
	Node() {}
	Node(int d, Node* p = nullptr) {
		data = d;
		next = p;
	}
};

int size(Node* head) {
	int cnt = 0;
	while(head != nullptr) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

Node* makeNode(int x) {
	Node *newNode = new Node();
	newNode->data = x;
	newNode->next = nullptr;
	return newNode;
}

void insert(Node *&head, int p, int x) {
	if(p == 0) {
		Node *tmp = makeNode(x);
		tmp->next = head;
		head = tmp;
		return;
	}
	if(p > size(head)) return;
	Node *newNode = head;
	while(p > 1) {
		newNode = newNode->next;
		p--;
	}
	Node *tmp = makeNode(x);
	tmp->next = newNode->next;
	newNode->next = tmp;
}

void popNode(Node *&head, int p) {
	if(p == 0) {
		Node *tmp = head;
		tmp = tmp->next;
		head = tmp;
		return;
	}
	if(p > size(head)) return;
	Node *newNode = head;
	while(p > 1) {
		newNode = newNode->next;
		p--;
	}
	newNode->next = newNode->next->next;
}

void print(Node *head) {
	while(head != nullptr) {
		cout << head->data << " ";
		head = head->next;
	}
}

int main() {
	queue<string> q;
	Node *head = NULL;
	int n; cin >> n;
	cin.ignore();
	while(n) {
		string s;
		getline(cin, s);
		q.push(s);
		n--;
	}
	while(!q.empty()) {
		string operat = q.front();
		string a;
		int p, x;
		stringstream ss(operat);
		ss >> a >> p >> x;
		if(a[0] == 'i') {
			insert(head, p, x);
		}
		else {
			popNode(head, p);
		}
		q.pop();
	}
	print(head);
}
