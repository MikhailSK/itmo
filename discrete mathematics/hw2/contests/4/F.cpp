#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using vv = vector<vector<ll>>;
 
using edge = tuple<ll, ll, char>;
 
ifstream in("isomorphism.in");
ofstream out("isomorphism.out");
 
vector<bool> visited;
map<ll, map<char, ll>> edges1;
map<ll, map<char, ll>> edges2;
set<ll> accept1;
set<ll> accept2;
vector<ll> ass;

bool dev(ll v, map<ll, map<char, ll>>& e) {
    for (auto [_, u] : e[v]) {
        if (u != v) return true;
    }
    return false;
}

bool dfs(ll u, ll v) {
    visited[u] = true;
    if (accept1.count(u) != accept2.count(v)) {
        return false;
    }

    ass[u] = v;
    for (auto [c, q] : edges1[u]) {
        ll t = edges2[v][c];
        if (dev(q, edges1) != dev(t, edges2)) {
            return false;
        }
        if (visited[q]) {
            if (t != ass[q])
                return false;
        } else if (!dfs(q, t)) return false;
    }
    return true;
}

int main() {
    ll n, m, k;
    in >> n >> m >> k;
    visited = vector<bool>(n + 1, false);
    ass = vector<ll>(n + 1);
 
    for (ll i = 0; i < k; i++) {
        ll t;
        in >> t;
        accept1.insert(t);
    }
 
    for (ll i = 0; i < m; i++) {
        ll a, b; char c;
        in >> a >> b >> c;
        edges1[a][c] = b;
    }

    in >> n >> m >> k;
 
    for (ll i = 0; i < k; i++) {
        ll t;
        in >> t;
        accept2.insert(t);
    }
 
    for (ll i = 0; i < m; i++) {
        ll a, b; char c;
        in >> a >> b >> c;
        edges2[a][c] = b;
    }

    if (dfs(1, 1))
        out << "YES\n";
    else
        out << "NO\n";
}