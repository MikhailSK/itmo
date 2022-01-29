#include <bits/stdc++.h>

using namespace std;

using ll  = long long;
using ull = unsigned long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vb  = vector<bool>;
using p   = pair<ll, ll>;
using vp  = vector<p>;

const ll MODULO = 998244353;

ll mod(ll x) { return (x + MODULO) % MODULO; }

class Polynomial {
public:
    Polynomial(const v& vals_)
    {
        ll offset;
        for (offset = vals_.size() - 1; offset >= 0; offset--) {
            if (vals_[offset] != 0) {
                break;
            }
        }
        vals = v(vals_.begin(), vals_.begin() + offset + 1);
        n    = vals.size();
    }
    Polynomial(v&& vals_)
    {
        ll offset;
        for (offset = vals_.size() - 1; offset >= 0; offset--) {
            if (vals_[offset] != 0) {
                break;
            }
        }
        vals = v(vals_.begin(), vals_.begin() + offset + 1);
        n    = vals.size();
    }

    Polynomial operator+(const Polynomial& other) const
    {
        v res_vals(max(n, other.n));
        for (ll i = 0; i < max(n, other.n); i++) {
            res_vals[i] = mod((*this)[i] + other[i]);
        }
        return Polynomial(res_vals);
    }

    Polynomial operator*(const Polynomial& other) const
    {
        v res_vals(2 * max(n, other.n), 0);
        for (ll i = 0; i < 2 * max(n, other.n); i++) {
            for (ll j = 0; j <= i; j++) {
                res_vals[i] = mod(res_vals[i] + (*this)[j] * other[i - j]);
            }
        }
        return Polynomial(res_vals);
    }

    Polynomial inverse(ll precision) const
    {
        v res;
        res.reserve(precision);
        res.push_back(1 / (*this)[0]);
        for (ll i = 1; i <= precision; i++) {
            ll t = 0;
            for (ll j = 1; j <= i; j++) {
                t = mod(t + (*this)[j] * res[i - j]);
            }
            res.push_back(mod(-t / (*this)[0]));
        }
        return Polynomial(res);
    }

    ll n;

    ll operator[](ll idx) const
    {
        if (idx < n) {
            return vals[idx];
        }
        return 0;
    }

    static Polynomial read(ll n, istream& stream = cin)
    {
        v vals(n + 1);
        for (ll i = 0; i <= n; i++) {
            stream >> vals[i];
        }
        return Polynomial(std::move(vals));
    }

    friend ostream& operator<<(ostream& stream, const Polynomial& poly)
    {
        stream << poly.n - 1 << '\n';
        for (ll i = 0; i < poly.n; i++) {
            stream << poly[i] << ' ';
        }
        stream << '\n';
        return stream;
    }

private:
    v vals;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    Polynomial P = Polynomial::read(n);
    Polynomial Q = Polynomial::read(m);
    cout << P + Q;
    cout << P * Q;

    Polynomial div = P * Q.inverse(1000);
    for (ll i = 0; i < 1000; i++) {
        cout << div[i] << ' ';
    }
    cout << '\n';
}