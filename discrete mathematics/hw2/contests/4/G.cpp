#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using vv = vector<vector<ll>>;
 
using edge = tuple<ll, ll, char>;
 
ifstream in("equivalence.in");
ofstream out("equivalence.out");
 
vector<bool> visited;
vector<bool> visited1;
vector<bool> visited2;
map<ll, map<char, ll>> edges1;
map<ll, map<char, ll>> edges2;
set<ll> accept1;
set<ll> accept2;
set<char> sigma;
ll n, m, k;
ll n2, m2, k2;
bool dir = false;

bool vanilla_dfs(ll state, bool isFirst) {
    if (isFirst && visited1[state]) return false;
    if (!isFirst && visited2[state]) return false;
    if ((isFirst ? accept1 : accept2).count(state) != 0) return true;
    if (isFirst) visited1[state] = true;
    else visited2[state] = true;
    for (auto [c, new_state] : (isFirst ? edges1[state] : edges2[state])) {
        if (vanilla_dfs(new_state, isFirst))
            return true;
    }
    return false;
}

bool dfs(pair<ll, ll> state) {
    if (accept1.count(state.first) == dir && accept2.count(state.second) != dir)
        return true;
    if (visited[n * (state.first - 1) + state.second - 1]) return false;
    visited[n * (state.first - 1) + state.second - 1] = true;
    for (char c : sigma) {
        if (!dir && edges1[state.first].count(c) == 0 && edges2[state.second].count(c) != 0) {
            if (vanilla_dfs(edges2[state.second][c], false))
                return true;
        }
        else if (dir && edges2[state.second].count(c) == 0 && edges1[state.first].count(c) != 0) {
            if (vanilla_dfs(edges1[state.first][c], true))
                return true;
        }
        if (edges1[state.first].count(c) != 0 && edges2[state.second].count(c) != 0) {
            if (dfs({edges1[state.first][c], edges2[state.second][c]}))
                return true;
        }
    }
    return false;
}

int main() {
    in >> n >> m >> k;
 
    for (ll i = 0; i < k; i++) {
        ll t;
        in >> t;
        accept1.insert(t);
    }
 
    for (ll i = 0; i < m; i++) {
        ll a, b; char c;
        in >> a >> b >> c;
        edges1[a][c] = b;
        sigma.insert(c);
    }

    in >> n2 >> m2 >> k2;
 
    for (ll i = 0; i < k2; i++) {
        ll t;
        in >> t;
        accept2.insert(t);
    }
 
    for (ll i = 0; i < m2; i++) {
        ll a, b; char c;
        in >> a >> b >> c;
        edges2[a][c] = b;
        sigma.insert(c);
    }

    visited = vector<bool>(1e9, false);
    visited1 = vector<bool>(n + 1, false);
    visited2 = vector<bool>(n2 + 1, false);
    if (dfs({1, 1})) {
        out << "NO\n";
    } else {
        dir = true;
        visited = vector<bool>(1e9, false);
    visited1 = vector<bool>(n + 1, false); //? rt
    visited2 = vector<bool>(n2 + 1, false);
        if (dfs({1, 1})) {
            out << "NO\n";
        } else out << "YES\n";
    }
}