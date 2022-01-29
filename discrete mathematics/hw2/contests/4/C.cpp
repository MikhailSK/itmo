#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using v = vector<ll>;

ifstream in("problem3.in");
ofstream out("problem3.out");

vector<v> edges;
vector<v> edges_inv;
vector<short> state;
vector<bool> visited;
vector<bool> unvisited;
map<ll, ll> cache;
ll n, m, k;
set<ll> accept;
// set<ll> cycles;

void dfs(ll pos)
{
    if (visited[pos]) {
        return;
    }
    visited[pos] = true;
    for (ll i : edges_inv[pos]) {
        dfs(i);
    }
}

void undfs(ll pos = 0)
{
    if (unvisited[pos]) {
        return;
    }
    unvisited[pos] = true;
    for (ll i : edges[pos]) {
        undfs(i);
    }
}

void detect(ll pos = 0)
{
    state[pos] = 1;
    for (ll i : edges[pos]) {
        if (state[i] == 0)
            detect(i);
        else if (state[i] == 1) {
            if (visited[i]) {
                out << "-1" << endl;
                exit(0);
            }
        }
    }
    state[pos] = 2;
}

ll bruh(ll pos)
{
    if (!unvisited[pos]) return 0;
    // cout << pos << "\n";
    if (pos == 0) return 1;
    // if (cycles.count(pos) != 0) return 0; // ultra garbage
    if (cache.count(pos) != 0) {
        return cache[pos];
    }
    ll res = 0;
    for (ll i : edges_inv[pos]) {
        res = (res + bruh(i)) % (1000000007LL);
    }
    cache[pos] = res;
    return res;
}

int main()
{
    in >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        ll t;
        in >> t;
        accept.insert(t);
    }

    edges = vector<v>(n);
    edges_inv = vector<v>(n);
    for (int i = 0; i < m; i++) {
        ll a, b;
        char c;
        in >> a >> b >> c;
        edges[a - 1].push_back(b - 1);
        edges_inv[b - 1].push_back(a - 1);
    }

    visited = vector<bool>(n, false);
    unvisited = vector<bool>(n, false);
    undfs();
    for (ll i : accept) {
        dfs(i - 1);
    }

    state = vector<short>(n, 0);
    detect();

    cache[0] = 1;
    ll res = 0;
    for (ll i : accept) {
        // visited = vector<bool>(n, false);
        // if (undfs(i - 1)) {
        res = (res + bruh(i - 1)) % (1000000007LL);
        // }
    }
    out << res << "\n";
    return 0;
}