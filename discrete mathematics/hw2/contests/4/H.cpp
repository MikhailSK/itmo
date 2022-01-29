#include <bits/stdc++.h>
  
using namespace std;
using ll = long long;
using v = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vv = vector<vector<ll>>;
  
using edge = tuple<ll, ll, char>;
  
ifstream in("minimization.in");
ofstream out("minimization.out");
  
vb visited;
map<ll, map<char, ll>> edges;
map<ll, map<char, v>> edges_inv;
set<ll> accept;
set<char> sigma;
ll n, m, k;
 
void dfs(ll state) {
    if (visited[state]) return;
    visited[state] = true;
    for (auto [c, new_state] : edges[state]) {
        dfs(new_state);
    }
}
 
int main() {
    in >> n >> m >> k;
  
    for (ll i = 0; i < k; i++) {
        ll t;
        in >> t;
        accept.insert(t);
    }
  
    for (ll i = 0; i < m; i++) {
        ll a, b; char c;
        in >> a >> b >> c;
        edges[a][c] = b;
        edges_inv[b][c].push_back(a);
        sigma.insert(c);
    }
 
    for (ll i = 1; i <= n; i++) {
        for (char c : sigma) {
            if (edges[i].count(c) == 0) {
                edges[i][c] = 0;
                edges_inv[0][c].push_back(i);
            }
            // if (edges_inv[i].count(c) == 0) {
            //     edges_inv[i][c] = {0};
            // }
        }
    }
    for (char c : sigma) {
        edges[0][c] = 0; //? inv
        edges_inv[0][c].push_back(0);
    }
 
    visited = vb(n + 1, false);
    dfs(1);
 
    queue<pair<ll, ll>> q;
    vvb table(n + 1, vb(n + 1, false)); //? mem
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= n; j++) {
            if (!table[i][j] && accept.count(i) != accept.count(j)) {
                table[i][j] = true;
                table[j][i] = true;
                q.push({i, j});
                q.push({j, i});
            }
        }
    }
 
    while (!q.empty()) {
        auto [u, v] = q.front(); q.pop();
        for (char c : sigma) {
            for (ll r : edges_inv[u][c]) {
                for (ll s : edges_inv[v][c]) {
                    if (!table[r][s]) {
                        table[r][s] = true;
                        table[s][r] = true;
                        q.push({r, s});
                        q.push({s, r});
                    }
                }
            }
        }
    }

    // for (ll i = 0; i <= n; i++) {
    //     for (ll j = 0; j <= n; j++) {
    //         cout << (table[i][j] ? "O" : " ");
    //     }
    //     cout << "\n";
    // }
 
    v comps(n+1, -1);
    for (ll i = 0; i <= n; i++) {
        if (!table[0][i]) comps[i] = 0;
    }
    comps[0] = 0;
 
    ll cnt = 0;
    for (ll i = 0; i <= n; i++) {
        if (!visited[i]) continue;
        if (comps[i] == -1) {
            cnt++;
            comps[i] = cnt;
            for (ll j = i + 1; j <= n; j++) {
                if (!table[i][j])
                    comps[j] = cnt;
            }
        }
    }

    // for (ll i : comps) {
    //     cout << i << " ";
    // }
    // cout << '\n';
 
    set<ll> accept_new;
    map<ll, map<char, ll>> edges_new;
    ll edge_cnt = 0;
 
    for (ll i = 1; i <= n; i++) {
        if (comps[i] == -1) continue;
        if (accept.count(i) != 0) { //? rt
            accept_new.insert(comps[i]);
        }
        for (auto [c, q] : edges[i]) {
            if (edges_new[comps[i]].count(c) == 0) {
                if (comps[i] == 0 || comps[q] == 0) continue;
                edges_new[comps[i]][c] = comps[q];
                edge_cnt++;
            }
        }
    }

    if (accept_new.size() == 0) {
        out << "2 1 1\n2\n1 1 a\n";
        return 0;
    }
 
    out << cnt << " " << edge_cnt << " " << accept_new.size() << "\n";
 
    for (ll node : accept_new) {
        out << node << " ";
    }
    out << "\n";
    for (auto [a, b] : edges_new) {
        for (auto [c, d] : b) {
            if (a == 0 || d == 0) continue;
            out << a << " " << d << " " << c << "\n";
        }
    }
}