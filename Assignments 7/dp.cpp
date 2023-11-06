#include "bits/stdc++.h"
using namespace std;

int main() {
	int W, N;
	cin >> W >> N;
	int weights[N+1];
	int values[N+1];
	for(int i = 1; i <= N; i++) {
		cin >> weights[i] >> values[i];
	}
	int dp[N+1][W+1];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= W; j++) {
			dp[i][j] = dp[i-1][j];
			if(weights[i] <= j) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-weights[i]] + values[i]);
			}
		}
	}
	cout << dp[N][W];
}

// 40 5
// 6 20
// 2 8
// 4 14
// 3 13
// 11 35