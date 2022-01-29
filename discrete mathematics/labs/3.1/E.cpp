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

    vv edges(n);
    vb bans(n, false);
    v res(n - 2);
    v degree(n, 0);
    set<ll> leaves;

    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[v].push_back(u);
        edges[u].push_back(v);
        degree[v]++;
        degree[u]++;
    }

    for (ll i = 0; i < n; i++) {
        if (degree[i] == 1) {
            leaves.insert(i);
        }
    }

    for (ll i = 0; i < res.size(); i++) {
        ll v = *leaves.begin();
        leaves.erase(leaves.begin());

        ll u;
        bans[v] = true;
        for (ll w : edges[v]) {
            if (!bans[w]) {
                u = w;
            }
        }

        res[i] = u;
        degree[u]--;
        if (degree[u] == 1) {
            leaves.insert(u);
        }
    }

    for (auto t : res) {
        cout << t + 1 << ' ';
    }
    cout << '\n';
}