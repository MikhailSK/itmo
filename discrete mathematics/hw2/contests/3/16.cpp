#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

ifstream in("choose2num.in");
ofstream out("choose2num.out");

int main() {
    int n, k;
    in >> n >> k;
    vi choose(k);
    for (int i = 0; i < k; i++) in >> choose[i];
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
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    ll res = 0;
    for (int i = 0; i < k; i++) {
        for (int j = choose[i] - 1; j >= (i == 0 ? 1 : choose[i-1] + 1); j--) {
            res += dp[i][j - 1];
            // cout << res << '\n';
        }
    }
    out << res << '\n';
}