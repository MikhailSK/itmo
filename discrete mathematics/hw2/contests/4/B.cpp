#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using v = vector<ll>;
 
using edge = pair<ll, char>;
 
ifstream in("problem2.in");
ofstream out("problem2.out");
 
vector<bool> accept;
vector<vector<ll>> edges;
string s;
map<pair<ll, ll>, ll> vis;
 
ll bruh(ll i, ll state) {
    if (vis.count({i, state}) != 0) return vis[{i, state}];
    ll res = 0;
    for (auto s : edges[state]) {
        res = res + bruh(i - 1, s);
    }
    vis[{i, state}] = res;
}
 
int main() {
    in >> s;
    ll n, m, k;
    in >> n >> m >> k;
 
    accept = vector<bool>(n + 1, false);
    for (int i = 0; i < k; i++) {
        ll t;
        in >> t;
        accept[t] = true;
    }
 
    edges = vector<vector<ll>>(n+1);
    for (int i = 0; i < m; i++) {
        ll a, b; char c;
        in >> a >> b >> c;
        edges[b].push_back(a);
    }
 
    bruh(0, 1);
    out << "Rejects\n";
}