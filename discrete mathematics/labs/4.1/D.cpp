#include <bits/stdc++.h>

using namespace std;

using ll  = long long;
using ull = unsigned long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vb  = vector<bool>;
using p   = pair<ll, ll>;
using vp  = vector<p>;

class Frac {
public:
    Frac(ll t, ll b)
        : t(t)
        , b(b)
    {
    }

    Frac(const Frac& f)
        : Frac(f.t, f.b)
    {
    }

    Frac()
        : Frac(0, 1)
    {
    }

    Frac operator*(ll x) const
    {
        ll a = gcd(x, b);
        return Frac(t * (x / a), b / a);
    }

    Frac operator+(Frac other) const
    {
        ll new_b = b / gcd(b, other.b) * other.b;
        ll new_t = t * (other.b / gcd(b, other.b)) + other.t * (b / gcd(b, other.b));
        return Frac(new_t / gcd(new_b, new_t), new_b / gcd(new_b, new_t));
    }

    Frac operator*(Frac other) const
    {
        ll new_b = b * other.b;
        ll new_t = t * other.t;
        return Frac(new_t / gcd(new_b, new_t), new_b / gcd(new_b, new_t));
    }

    ll t, b;
};

class Polynomial {
public:
    Polynomial(const vector<Frac>& vals_)
        : vals(vals_)
        , n(vals_.size())
    {
    }

    Polynomial operator+(const Polynomial& other) const
    {
        vector<Frac> res_vals(max(n, other.n));
        for (ll i = 0; i < max(n, other.n); i++) {
            res_vals[i] = (*this)[i] + other[i];
        }
        return Polynomial(res_vals);
    }

    Polynomial operator*(const Polynomial& other) const
    {
        vector<Frac> res_vals(2 * max(n, other.n) - 1, Frac(0, 1));
        for (ll i = 0; i < 2 * max(n, other.n) - 1; i++) {
            for (ll j = 0; j <= i; j++) {
                res_vals[i] = res_vals[i] + (*this)[j] * other[i - j];
            }
        }
        return Polynomial(res_vals);
    }

    Polynomial operator*(Frac x) const
    {
        vector<Frac> res_vals(vals);
        for (ll i = 0; i < res_vals.size(); i++) {
            res_vals[i] = res_vals[i] * x;
        }
        return Polynomial(res_vals);
    }

    // Polynomial inverse(ll precision) const
    // {
    //     v res;
    //     res.reserve(precision);
    //     res.push_back(1 / (*this)[0]);
    //     for (ll i = 1; i <= precision; i++) {
    //         ll t = 0;
    //         for (ll j = 1; j <= i; j++) {
    //             t += (*this)[j] * res[i - j];
    //         }
    //         res.push_back(-t / (*this)[0]);
    //     }
    //     return Polynomial(res);
    // }

    ll n;

    Frac operator[](ll idx) const
    {
        if (idx < n) {
            return vals[idx];
        }
        return Frac(0, 1);
    }

    static Polynomial read(ll n, istream& stream = cin)
    {
        vector<Frac> vals(n + 1);
        for (ll i = 0; i <= n; i++) {
            stream >> vals[i].t;
            vals[i].b = 1;
        }
        return Polynomial(vals);
    }

    void write(ll precision, ostream& stream = cout) const
    {
        for (ll i = 0; i < precision; i++) {
            cout << (*this)[i].t << '/' << (*this)[i].b << ' ';
        }
        cout << '\n';
    }

    // friend ostream& operator<<(ostream& stream, const Polynomial& poly)
    // {
    //     stream << poly.n - 1 << '\n';
    //     for (ll i = 0; i < poly.n; i++) {
    //         stream << poly[i] << ' ';
    //     }
    //     stream << '\n';
    //     return stream;
    // }

private:
    vector<Frac> vals;
};

int main()
{
    ll r, k;
    cin >> r >> k;

    auto P = Polynomial::read(k);
    // P.write(k + 1);

    ll k_fact = 1;
    for (ll i = 1; i <= k; i++) {
        k_fact *= i;
    }

    vector<Polynomial> u;
    for (ll i = 0; i <= k; i++) {
        u.push_back(Polynomial({ Frac(1, k_fact * pow(r, i)) }));
        for (ll off = 1; off <= k; off++) {
            u.back() = u.back() * Polynomial({ Frac(off - i, 1), Frac(1, 1) });
            // cout << "n " << off - i << '\n';
        }
        // cout << "-----\n";
    }

    // for (auto p : u) {
    //     p.write(3);
    // }

    auto res = Polynomial({ Frac(0, 1) });
    for (ll i = 0; i <= k; i++) {
        res = res + u[i] * P[i];
    }

    res.write(k + 1);

    // Polynomial(u).write(k + 1);

    // (P * Polynomial(u)).write(k + 1);
}