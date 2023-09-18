#include "bits/stdc++.h"
using namespace std;

struct Node {
	int data;
	Node* next;
};

void printReverse(Node *head) {
	Node *p = head;
	if (p->next != nullptr) {
		printReverse(p->next);
	}
	cout << p->data << " ";
}

class STACK {
private:
	Node *head;
	int len = 0;
public:
	void push(int x) {
		len++;
		Node *tmp = new Node;
		tmp->data = x;
		if(len == 1) {
			head = tmp;
			head->next = nullptr;
			return;
		}
		tmp->next = head;
		head = tmp;
	}

	void pop() {
		if(len == 0) return;
		len--;
		Node* tmp = head->next;
		delete head;
		head = tmp;
	}

	void print() {
		printReverse(head);
	}
};

int main() {
	int n; cin >> n;
	STACK s;
	while(n--) {
		string operat; cin >> operat;
		if(operat == "push") {
			int x; cin >> x;
			s.push(x);
		}
		else s.pop();
	}
	s.print();
}