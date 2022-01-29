// ICIE v0.7.26

#include <bits/stdc++.h>

using namespace std;

using ll  = long long;
using ull = unsigned long long;
using v   = vector<ll>;
using vv  = vector<v>;
using vb  = vector<bool>;
using vvb = vector<vb>;
using p   = pair<ll, ll>;
using vp  = vector<p>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    v res = {1};
    for (ll i = 0; i < n - 1; i++) {
        ll l = -1;
        ll r = i + 1;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            cout << 1 << ' ' << res[m] << ' ' << i + 2 << endl; // ew flush
            string ans;
            cin >> ans;
            if (ans == "NO")
                r = m;
            else
                l = m;
        }
        res.insert(res.begin() + r, i + 2);
    }

    cout << 0 << ' ';
    for (auto t : res) {
        cout << t << ' ';
    }
    cout << '\n';
}