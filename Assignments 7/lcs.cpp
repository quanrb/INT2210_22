#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int m = a.length();
    int n = b.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    a = "." + a;
    b = "." + b;

    for(int i = 0; i <= m; i++) dp[i][0] = 0;
    for(int i = 0; i <= n; i++) dp[0][i] = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else if(dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }

    cout << dp[m][n];
}