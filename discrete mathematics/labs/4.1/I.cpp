#include <bits/stdc++.h>

using namespace std;

using ll  = long long;
using ull = unsigned long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vb  = vector<bool>;
using p   = pair<ll, ll>;
using vp  = vector<p>;

const ll MODULO = 104857601LL;

ll mod(ll x) { return (x + MODULO) % MODULO; }

class Polynomial {
public:
    Polynomial(const v& vals_)
    // : vals(vals_)
    // , n(vals_.size())
    {
        if (vals_.size() == 0) {
            n    = 0;
            vals = v();
            return;
        }
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

    Polynomial operator+(ll x) const
    {
        v res_vals(vals);
        if (res_vals.size() == 0) {
            res_vals.push_back(0);
        }
        res_vals[0] += x;
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

    Polynomial operator*(ll x) const
    {
        v res_vals(vals);
        for (ll i = 0; i < n; i++) {
            res_vals[i] *= x;
        }
        return Polynomial(res_vals);
    }

    static Polynomial bruh(ll precision)
    {
        auto res = Polynomial({ 1 });
        for (ll i = 1; i <= precision; i++) {
            res = res * Polynomial({ i, 1 });
        }
        return res;
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

    void shift()
    {
        vals.insert(vals.begin(), 0);
        n++;
    }

    void write(ll precision, ostream& stream = cout) const
    {
        for (ll i = 0; i < precision; i++) {
            cout << (*this)[i] << ' ';
        }
        cout << '\n';
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

    void neg()
    {
        for (ll i = 0; i < n; i++) {
            vals[i] *= (-1);
        }
    }

    void add(const Polynomial& poly)
    {
        for (ll i = 0; i < n; i++) {
            vals[i] += poly[i];
        }
    }

    ll shiftprod(Polynomial other, ll shift) const
    {
        ll res = 0;
        for (ll j = 0; j <= shift; j++) {
            res = mod(res + (*this)[j] * other[shift - j]);
        }
        return res;
    }

private:
    v vals;
};

int main()
{
    ll k, n;
    cin >> k >> n;
    n--;
    v r(k + 1);

    v A(2 * k);
    for (ll i = 0; i < k; i++) {
        cin >> A[i];
    }

    v tmp(k + 1);
    for (ll i = 1; i <= k; i++) {
        cin >> tmp[i];
    }
    tmp[0] = -1;
    Polynomial C(tmp);

    while (n >= k) {
        for (ll i = 0; i < k; i++) {
            ll t = 0;
            for (ll j = 1; j <= k; j++) {
                t = mod(t + C[j] * A[i + k - j]);
            }
            A[i + k] = t;
        }

        for (ll i = 0; i <= k; i++) {
            ll t = 0;
            for (ll j = 0; j <= 2 * i; j++) {
                t = mod(t + C[j] * C[2 * i - j] * (j % 2 == 0 ? 1 : -1));
            }
            r[i] = -t;
        }

        C = Polynomial(r);

        ll filt = 0;
        for (ll i = 0; i < 2 * k; i++) {
            if (n % 2 == i % 2) {
                A[filt] = A[i];
                filt++;
            }
        }

        n /= 2;
    }

    cout << mod(A[n]) << '\n';
}