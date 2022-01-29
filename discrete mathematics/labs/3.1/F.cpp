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

    v code(n - 2);
    v d(n, 1);
    set<ll> leaves;
    vp res;
    res.reserve(n);

    for (ll i = 0; i < n - 2; i++) {
        cin >> code[i];
        code[i]--;
    }

    for (auto t : code) {
        d[t]++;
    }

    for (ll i = 0; i < n; i++) {
        if (d[i] == 1) {
            leaves.insert(i);
        }
    }

    for (auto t : code) {
        ll v = *leaves.begin();
        leaves.erase(leaves.begin());
        res.push_back({v, t});
        d[t]--;
        if (d[t] == 1) {
            leaves.insert(t);
        }
    }
    res.push_back({*leaves.begin(), n - 1});

    for (auto [a, b] : res) {
        cout << a + 1 << ' ' << b + 1 << '\n';
    }
    cout << '\n';
}