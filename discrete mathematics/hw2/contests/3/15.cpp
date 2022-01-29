#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

ifstream in("num2choose.in");
ofstream out("num2choose.out");

int main() {
    int n, k, m;
    in >> n >> k >> m;
    vvi dp(k, vi(n, 0));
    for (int i = k - 1; i >= 0; i--) {
        for (int j = n - 1 - (k - 1 - i); j >= 0; j--) {
            if (i == k - 1) dp[i][j] = 1;
            else if (j == n - 1 - (k - 1 - i)) dp[i][j] = 1;
            else dp[i][j] = dp[i][j+1] + dp[i+1][j+1];
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            // cout << dp[i][j] << ' ';
        }
        // cout << '\n';
    }

    vi choose;
    for (int i = 0; i < k; i++) {
        int j;
        for (j = (i == 0 ? 1 : choose.back() + 1); m >= dp[i][j - 1]; j++) {m -= dp[i][j-1];}
        choose.push_back(j);
        out << j << ' ';
    }
    out << '\n';
}