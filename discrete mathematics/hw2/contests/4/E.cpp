#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using v = vector<ll>;
using vv = vector<v>;
 
using edge = tuple<ll, ll, char>;
 
ifstream in("problem5.in");
ofstream out("problem5.out");

vv operator*(vv &A, vv &B) {
    assert(A[0].size() == B.size());
    vv res(A.size(), v(B[0].size(), 0));
    for (ll i = 0; i < A.size(); i++) {
        for (ll j = 0; j < B[0].size(); j++) {
            for (ll k = 0; k < B.size(); k++) {
                res[i][j] = (res[i][j] + (A[i][k] * B[k][j]) % (1000000007LL)) % (1000000007LL);
            }
        }
    }
    return res;
}

vv pow(vv &m, ll p) {
    if (p == 1)
        return m;
    if (p % 2 == 0) {
        vv t = m * m;
        return pow(t, p / 2);
    }
    vv t = pow(m, p - 1);
    return m * t;
}

int main() {
    ll n, m, k, l;
    in >> n >> m >> k >> l;
 
    set<ll> accept;
    for (ll i = 0; i < k; i++) {
        ll t;
        in >> t;
        accept.insert(t);
    }
 
    set<char> sigma;
    map<pair<ll, char>, v> edges;
    for (ll i = 0; i < m; i++) {
        ll a, b; char c;
        in >> a >> b >> c;
        edges[make_pair(a, c)].push_back(b);
        sigma.insert(c);
    }
 
    queue<v> p;
    p.push({1});
    set<v> q;
    q.insert({1});
    map<pair<v, char>, v> edgesd;
    while (p.size() != 0) {
        v pd = p.front(); p.pop();
        for (char c : sigma) {
            set<ll> qdnotqd;
            for (auto pp : pd) {
                for (auto t : edges[make_pair(pp, c)]) {
                    qdnotqd.insert(t);
                }
            }
            v qd(qdnotqd.begin(), qdnotqd.end());
            if (qd.size() == 0) continue;
            edgesd[make_pair(pd, c)] = qd;
            if (q.count(qd) == 0) {
                p.push(qd);
                q.insert(qd);
            }
        }
    }
    set<v> acceptd;
    for (auto& qd : q) {
        for (auto& st : qd) {
            if (accept.count(st) != 0) {
                acceptd.insert(qd);
                break;
            }
        }
    }

    vector<v> q_vec(q.begin(), q.end()); //? mem
    map<v, ll> bruh;
    for (ll i = 0; i < q_vec.size(); i++) {
        bruh[q_vec[i]] = i;
    }
    vector<vector<vector<char>>> mat(q.size(), vector<vector<char>>(q.size()));
    for (auto [p, q] : edgesd) {
        auto [a, c] = p;
        mat[bruh[a]][bruh[q]].push_back(c);
    }
    for (ll i = 0; i < q.size(); i++) {
        for (ll j = 0; j < q.size(); j++) {
            if (mat[i][j].size() == 0) cout << "___ ";
            else
            if (mat[i][j].size() == 1) cout << "_ ";
            for (char c : mat[i][j]) {
                cout << c << ' ';
            }
        }
        cout << '\n';
    }

    // mat = pow(mat, l);

    // ll res = 0;
    // for (v i : acceptd) {
    //     res = (res + mat[0][bruh[i]]) % (1000000007LL);
    // }

    // out << res << '\n';
    // return 0;
}