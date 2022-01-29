#include <bits/stdc++.h>

using namespace std;

using ll  = long long;
using ull = unsigned long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vb  = vector<bool>;
using p   = pair<ll, ll>;
using vp  = vector<p>;

const ll MODULO = 1;

ll mod(ll x) { return x; }

ll gcd(ll a, ll b, ll& x, ll& y)
{
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd(b % a, a, x1, y1);
    x    = y1 - (b / a) * x1;
    y    = x1;
    return d;
}

ll modulo_inverse(ll b)
{
    ll x, y;
    ll gcd_res = gcd(b, MODULO, x, y);
    // if (gcd_res != 1) {
    //     throw "No inverse";
    // }
    x = mod(x);
    return x;
}

// perf: O(n) precompute
ll frac_mod(ll a, ll b) { return mod(a * modulo_inverse(b)); }

vector<ll> facts = { 1 };
ll fact(ll n)
{
    if (facts.size() > n) {
        return facts[n];
    }
    ll res = n * fact(n - 1);
    facts.push_back(res);
    return res;
}

vector<ll> pows = { 1 };
ll pow4_mod(ll n)
{
    if (pows.size() > n) {
        return pows[n];
    }
    ll res = mod(4 * pow4_mod(n - 1));
    pows.push_back(res);
    return res;
}

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

    Polynomial operator/(ll x) const
    {
        v res_vals;
        for (ll i = 0; i < n; i++) {
            res_vals.push_back(frac_mod((*this)[i], 2));
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

    // @see Knuth, the art of computer progarmming vol.2, sec. 4.7
    Polynomial exp(ll precision) const
    {
        v res;
        res.reserve(precision);
        res.push_back(1);
        for (ll n = 1; n < precision; n++) {
            res.push_back(0);
            for (ll k = 1; k <= n; k++) {
                res.back() = mod(res.back() + mod(mod(frac_mod(k, n) * (*this)[k]) * res[n - k]));
            }
        }
        return Polynomial(res);
    }

    Polynomial log1p(ll precision) const
    {
        v res;
        res.reserve(precision);
        res.push_back(0);
        for (ll n = 1; n < precision; n++) {
            res.push_back((*this)[n]);
            for (ll k = 1; k < n; k++) {
                res.back()
                    = mod(res.back() + mod(res[n - k] * mod((*this)[k] * mod(frac_mod(k, n) - 1))));
            }
        }
        return Polynomial(res);
    }

    Polynomial sqrt1p(ll precision) const { return (log1p(precision) / 2).exp(precision); }

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

private:
    v vals;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll r, k;
    cin >> r >> k;

    v t(k + 1);
    for (ll i = 0; i < k + 1; i++) {
        cin >> t[i];
    }
    auto T = Polynomial(t);
    v c(k + 1);
    for (ll i = k; i >= 0; i--) {
        c[i] = T[i] * fact(i);
        T    = T + Polynomial::bruh(i) * (-T[i]);
    }
    auto P = Polynomial({ 0 });
    auto Q = Polynomial({ 1 });
    for (ll i = k; i >= 0; i--) {
        P = P + Q * c[i];
        Q = Q * Polynomial({ 1, -r });
    }
    cout << P;
    cout << Q;
}