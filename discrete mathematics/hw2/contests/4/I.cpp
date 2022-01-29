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
vb accept_new;
v accept;
vector<map<ll, vector<ll>>> g;
vector<vector<pair<ll, ll>>> gr;
ll n, m, k;

void dfs(ll state) {
    if (visited[state]) return;
    visited[state] = true;
    for (auto [c, states] : g[state]) {
        for (auto i : states) dfs(i);
    }
}

int main() {
    in >> n >> m >> k;

    accept_new = vb(n, false);
    accept = v(k);
    visited = vb(n, false);

    for (ll i = 0; i < k; i++) {
        in >> accept[i];
        accept_new[--accept[i]] = true;
    }
    ll alfa = 'z' - 'a' + 1;
    g.resize(n);
    gr.resize(n);
    for (ll i = 0; i < m; i++) {
        ll x, y;
        char c;
        in >> x >> y >> c;
        x--, y--;
        if (g[y].find(c - 'a') == g[y].end())
            g[y].insert({ c - 'a', vector<ll>(1, x) });
        else
            g[y].find(c - 'a')->second.push_back(x);
        gr[x].push_back({ y, c - 'a' });
    }
    for (ll i = 0; i < k; i++) dfs(accept[i]);
    for (ll i = 0; i < n; i++)
        visited[i] = visited[i] && visited[i];

    vector <set<ll> > P(2);
    vector <ll> Class(n);
    for (ll i = 0; i < n; i++) {
        if (visited[i]) {
            if (accept_new[i])
                P[0].insert(i), Class[i] = 0;
            else
                P[1].insert(i), Class[i] = 1;
        }
    }
    if (P[1].empty())
        P.pop_back();
    else {
        queue <pair<ll, ll> > Queue;
        for (ll i = 0; i < alfa; i++) {
            Queue.push({ 0, i });
            Queue.push({ 1, i });
        }
        while (!Queue.empty()) {
            ll C = Queue.front().first;
            ll a = Queue.front().second;
            Queue.pop();
            map <ll, vector<ll>> Involved;
            for (ll q : P[C]) {
                auto it = g[q].find(a);
                if (it == g[q].end())
                    continue;
                for (ll r : it->second) {
                    if (!visited[r])
                        continue;
                    ll i = Class[r];
                    if (Involved.find(i) == Involved.end())
                        Involved.insert({ i, vector<ll>() });
                    Involved.find(i)->second.push_back(r);
                }
            }
            for (auto it : Involved) {
                ll i = it.first;
                if (it.second.size() < P[i].size()) {
                    ll j = P.size();
                    P.push_back(set<ll>());
                    for (ll r : it.second) {
                        P[i].erase(r);
                        P[j].insert(r);
                    }
                    if (P[j].size() > P[i].size())
                        swap(P[j], P[i]);
                    for (ll r : P[j])
                        Class[r] = j;
                    for (ll c = 0; c < alfa; c++)
                        Queue.push({ j, c });
                }
            }
        }
    }


    if (Class[0] != 0) {
        ll h = Class[0];
        swap(P[0], P[h]);
        for (ll i : P[0])
            Class[i] = 0;
        for (ll i : P[h])
            Class[i] = h;
    }

    set <ll> tern;
    for (ll i = 0; i < k; i++) {
        if (visited[accept[i]])
        tern.insert(Class[accept[i]]);
    }
    ll mn = 0;
    vector <set <pair <ll, ll> > > gn(P.size());
    for (ll i = 0; i < P.size(); i++) {
        for (ll from : P[i]) {
            for (auto to : gr[from]) {
                if (visited[to.first])
                    gn[i].insert({ Class[to.first], to.second });
            }
        }
        mn += gn[i].size();
    }
    cout << P.size() << " " << mn << " " << tern.size() << "\n";
    for (ll i : tern)
        cout << i + 1 << " ";
    for (ll i = 0; i < P.size(); i++) {
        for (auto it : gn[i])
            cout << "\n" << i + 1 << " " << it.first + 1 << " " << (char)('a' + it.second);
    }
    return 0;
}