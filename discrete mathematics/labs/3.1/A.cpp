// ICIE v0.7.26

#include <bits/stdc++.h>

using namespace std;

using ll  = long long;
using ull = unsigned long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vb  = vector<bool>;
using vvb = vector<vb>;
using p   = pair<ll, ll>;
using vp  = vector<p>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vvb adj(n, vb(n, false));

    for (ll i = 1; i < n; i++) {
        string line;
        cin >> line;
        for (ll j = 0; j < line.size(); j++) {
            adj[i][j] = line[j] == '1';
            adj[j][i] = adj[i][j];
        }
    }

    deque<ll> res(n);
    iota(res.begin(), res.end(), 0);
    for (ll i = 0; i < n * (n - 1) / 2; i++) {
        ll st = 1;
        if (!adj[res[0]][res[1]]) {
            do {
                st++;
            } while (!adj[res[0]][res[st]] || !adj[res[1]][res[st + 1]]);
        }
        reverse(res.begin() + 1, res.begin() + st + 1);
        res.push_back(res[0]);
        res.pop_front();
    }

    for (auto t : res) {
        cout << t + 1 << ' ';
    }
    cout << '\n';
}