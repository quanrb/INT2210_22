#include "bits/stdc++.h"
using namespace std;

struct Item {
	int value;
	int weight;
};

bool cmp(const Item& a, const Item& b) {
	return a.value/a.weight > b.value/b.weight;
} 

int knapsackGreedy(vector<Item>& items, int capacity, vector<Item>& taken) {
	sort(items.begin(), items.end(), cmp);
	int res = 0;
	int i = 0;
	for(Item item : items) {
		if (!capacity) break;
		if(item.weight <= capacity) {
			res += item.value;
			capacity -= item.weight;
			taken[i++] = item;
		}
	}
	return res;
}

int main() {
	
}