#include<iostream>
using namespace std;

const int MAX = 1e5;

class heapTree {
private:
	int length = 0;
	int heap[MAX];
public:
	heapTree() {
		for(int i = 0; i < MAX; i++) {
			heap[i] = -MAX;
		}
		heap[0] = MAX;
	}

	void swim(int cur) {
		while(heap[cur] > heap[cur/2]) {
			swap(heap[cur], heap[cur/2]);
			cur /= 2;
		}
	}

	void insert(int num) {
		heap[++length] = num;
		swim(length);
	}

	void sink(int cur) {
		while(heap[cur] < max(heap[cur*2], heap[cur*2+1])) {
			if(heap[cur*2+1] > heap[cur*2]) {
				swap(heap[cur], heap[cur*2+1]);
				cur = cur*2 + 1;
			}
			else {
				swap(heap[cur], heap[cur*2]);
				cur = cur*2;
			}
		}
	}

	void remove(int cur) {
		if(!length || !cur) return;
		heap[cur] = heap[length];
		heap[length] = -MAX;
		--length;
		sink(cur);
	}

	int maxElement() {
		return heap[1];
	}
};

int main() {
	heapTree tree;
	tree.insert(1);
	tree.insert(10);
	tree.insert(12);
	tree.insert(4);
	tree.insert(5);
	tree.remove(2);
	cout << tree.maxElement();
}