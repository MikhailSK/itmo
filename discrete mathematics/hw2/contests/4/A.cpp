#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using v = vector<ll>;

using edge = tuple<ll, ll, char>;

ifstream in("problem1.in");
ofstream out("problem1.out");

int main() {
    string s;
    in >> s;
    ll n, m, k;
    in >> n >> m >> k;

    v accept(k);
    for (int i = 0; i < k; i++) {
        in >> accept[i];
    }

    vector<edge> edges(m);
    for (int i = 0; i < m; i++) {
        ll a, b; char c;
        in >> a >> b >> c;
        edges[i] = edge(a, b, c);
    }

    ll state = 1;
    for (char c : s) {
        bool d = false;
        for (auto& [a, b, cc] : edges) {
            if (a == state && cc == c) {
                state = b;
                d = true;
                break;
            }
        }
        if (!d) {
            out << "Rejects\n";
            exit(0);
        }
    }
    if (find(accept.begin(), accept.end(), state) != accept.end())
        out << "Accepts\n";
    else
        out << "Rejects\n";
}