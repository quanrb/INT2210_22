#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
  	Node* next;
};

class QUEUE {
private:
    Node *head, *tail;
    int len = 0;
public:
    void enqueue(int x) {
    	Node* tmp = new Node;
      	tmp->data = x;
      	tmp->next = NULL;
      	len++;
      	if (len == 1) {
        	head = tmp;
        	tail = tmp;
        	return;
      	}
      	tail->next = tmp;
      	tail = tmp;
    }

    void dequeue() {
    	if (len == 0) return;
    	len--;
      	Node* tmp = head->next;
      	delete head;
     	head = tmp;
    }

    void print() {
      	Node* p = head;
      	while(p != NULL) {
        	cout << p->data << " ";
        	p = p->next;
        }
    }
};

int main() {
	int n; cin >> n;
	QUEUE q;
	while(n--) {
		string operat; cin >> operat;
		if(operat == "enqueue") {
			int x; cin >> x;
			q.enqueue(x);
		}
		else {
			q.dequeue();
		}
	}
	q.print();
}