#include "bits/stdc++.h"
using namespace std;

map<int, int> mp;

int C(int k, int n) {
	if (k == 0 || k == n) return 1;
	if (k == 1) return n;
	return C(k - 1, n - 1) + C(k, n - 1);
}

int main() {
	int n; cin >> n;
	int a[n];
	for(auto &i : a) {
		cin >> i;
		mp[i]++;
	}
	int numpairs = 0;
	for(auto i : mp) {
		if(i.second > 1) {
			numpairs += C(2, i.second);
		}
	}
	cout << numpairs << endl;
}