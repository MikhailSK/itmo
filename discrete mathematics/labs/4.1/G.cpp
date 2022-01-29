#include <bits/stdc++.h>

using namespace std;
using ll = long long;

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

using ull = unsigned long long;
using v   = vector<Frac>;
using vv  = vector<v>;
using vb  = vector<bool>;
using p   = pair<ll, ll>;
using vp  = vector<p>;

const ll PRECISION = 7;

class Polynomial {
public:
    Polynomial(const v& vals_)
    {
        if (vals_.size() == 0) {
            n    = 0;
            vals = v();
            return;
        }
        ll offset;
        for (offset = vals_.size() - 1; offset >= 0; offset--) {
            if (vals_[offset].t != 0) {
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
            if (vals_[offset].t != 0) {
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
            res_vals[i] = (*this)[i] + other[i];
        }
        return Polynomial(res_vals);
    }

    Polynomial operator+(Frac x) const
    {
        v res_vals(vals);
        if (res_vals.size() == 0) {
            res_vals.push_back(Frac(0, 1));
        }
        res_vals[0] = res_vals[0] + x;
        return Polynomial(res_vals);
    }

    Polynomial operator*(const Polynomial& other) const
    {
        v res_vals(2 * max(n, other.n), Frac(0, 1));
        for (ll i = 0; i < 2 * max(n, other.n); i++) {
            for (ll j = 0; j <= i; j++) {
                res_vals[i] = res_vals[i] + (*this)[j] * other[i - j];
            }
        }
        return Polynomial(res_vals);
    }

    Polynomial operator*(ll x) const
    {
        v res_vals(vals);
        for (ll i = 0; i < n; i++) {
            res_vals[i] = res_vals[i] * Frac(x, 1);
        }
        return Polynomial(res_vals);
    }

    Polynomial operator/(ll x) const
    {
        v res_vals;
        for (ll i = 0; i < n; i++) {
            res_vals.push_back((*this)[i] * Frac(1, x));
        }
        return Polynomial(res_vals);
    }

    Polynomial inverse(ll precision) const
    {
        v res;
        res.reserve(precision);
        res.push_back(Frac((*this)[0].b, (*this)[0].t));
        for (ll i = 1; i <= precision; i++) {
            Frac t = Frac(0, 1);
            for (ll j = 1; j <= i; j++) {
                t = t + (*this)[j] * res[i - j];
            }
            res.push_back(t * Frac(-1, 1) * Frac((*this)[0].b, (*this)[0].t));
        }
        return Polynomial(res);
    }

    // @see Knuth, the art of computer progarmming vol.2, sec. 4.7
    Polynomial exp(ll precision) const
    {
        v res;
        res.reserve(precision);
        res.push_back(Frac(1, 1));
        for (ll n = 1; n < precision; n++) {
            res.push_back(Frac(0, 1));
            for (ll k = 1; k <= n; k++) {
                res.back() = res.back() + Frac(k, n) * (*this)[k] * res[n - k];
            }
        }
        return Polynomial(res);
    }

    Polynomial log1p(ll precision) const
    {
        v res;
        res.reserve(precision);
        res.push_back(Frac(0, 1));
        for (ll n = 1; n < precision; n++) {
            res.push_back((*this)[n]);
            for (ll k = 1; k < n; k++) {
                res.back() = res.back() + res[n - k] * (*this)[k] * (Frac(k, n) + Frac(-1, 1));
            }
        }
        return Polynomial(res);
    }

    Polynomial sqrt1p(ll precision) const { return (log1p(precision) / 2).exp(precision); }

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
        v vals(n + 1);
        for (ll i = 0; i <= n; i++) {
            stream >> vals[i].t;
            vals[i].b = 1;
        }
        return Polynomial(std::move(vals));
    }

    void shift()
    {
        vals.insert(vals.begin(), Frac(0, 1));
        n++;
    }

    void write(ll precision, ostream& stream = cout) const
    {
        for (ll i = 0; i < precision; i++) {
            cout << (*this)[i].t << ' ';
        }
        cout << '\n';
    }

    friend ostream& operator<<(ostream& stream, const Polynomial& poly)
    {
        stream << poly.n - 1 << '\n';
        for (ll i = 0; i < poly.n; i++) {
            stream << poly[i].t << '/' << poly[i].b << ' ';
        }
        stream << '\n';
        return stream;
    }

    void neg()
    {
        for (ll i = 0; i < n; i++) {
            vals[i].t *= (-1);
        }
    }

    Polynomial comppow(ll n) const
    {
        v res_vals(PRECISION + 1, Frac(0, 1));
        for (ll i = 0; i <= PRECISION; i += n) {
            res_vals[i] = (*this)[i / n];
        }
        return Polynomial(res_vals);
    }

private:
    v vals;
};

Polynomial work(const string& s, ll& pos)
{
    switch (s[pos]) {
    case 'B': {
        pos++;
        return Polynomial({ Frac(0, 1), Frac(1, 1) });
    }
    case 'S': {
        pos += 2;
        Polynomial operand = work(s, pos);
        operand            = operand + (operand[0] * (-1));
        Polynomial res({});
        for (ll k = 1; k <= PRECISION; k++) {
            // cout << k;
            // cout << operand.comppow(k) / k;
            // cout << '\n';
            res = res + operand.comppow(k) / k;
        }
        pos++;
        return res.exp(PRECISION);
    }
    case 'L': {
        pos += 2;
        Polynomial operand = work(s, pos);
        operand.neg();
        operand = operand + (operand[0] * (-1)) + Frac(1, 1);
        pos++;
        return operand.inverse(PRECISION);
    }
    case 'P': {
        pos += 2;
        Polynomial lhs = work(s, pos);
        pos++;
        Polynomial rhs = work(s, pos);
        pos++;
        return lhs * rhs;
    }
    }
    throw "Bruh";
}

int main()
{
    string s;
    cin >> s;
    ll pos = 0;
    work(s, pos).write(PRECISION);
}