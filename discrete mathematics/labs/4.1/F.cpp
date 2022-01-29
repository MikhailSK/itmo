#include <bits/stdc++.h>

using namespace std;

using ll  = long long;
using ull = unsigned long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vb  = vector<bool>;
using p   = pair<ll, ll>;
using vp  = vector<p>;

const ll MODULO = 1000000007LL;

ll mod(ll x) { return (x + MODULO) % MODULO; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll k, m;
    cin >> k >> m;

    v C(m + 1, 0);
    for (ll i = 0; i < k; i++) {
        ll t;
        cin >> t;
        C[t]++;
    }

    v T(m + 1, 0);
    T[0] = 1;
    v ps(m + 1, 0);
    ps[0] = 1;
    for (int i = 1; i < T.size(); i++) {
        for (int j = 1; j <= i; j++) {
            T[i] += ps[i - j] * C[j];
            T[i] = mod(T[i]);
        }

        for (int j = 0; j <= i; j++) {
            ps[i] = mod(ps[i] + mod(T[j] * T[i - j]));
        }
    }

    for (ll i = 1; i < T.size(); i++) {
        cout << T[i] << ' ';
    }
    cout << '\n';
}