#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using v = vector<ll>;
using vv = vector<v>;

ifstream in("problem4.in");
ofstream out("problem4.out");

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

    v accept(k);
    for (int i = 0; i < k; i++) {
        in >> accept[i];
    }

    vv mat(n, v(n, 0));
    for (int i = 0; i < m; i++) {
        ll a, b;
        char c;
        in >> a >> b >> c;
        mat[a - 1][b - 1]++;
    }

    mat = pow(mat, l);

    ll res = 0;
    for (ll i : accept) {
        res = (res + mat[0][i - 1]) % (1000000007LL);
    }

    out << res << '\n';
}