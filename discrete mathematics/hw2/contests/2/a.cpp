#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    // ifstream in("huffman.in");
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll res = 0;
    vector<ll> codes;
    sort(v.begin(), v.end());
    for (ll i = 0; i < n - 1; i++) {
        vector<pair<ll, ll>> uhh;
        if (codes.size() >= 2) {
            uhh.push_back(make_pair(codes[0] + codes[1], 2));
        }
        if (codes.size() >= 1 && v.size() >= 1) {
            uhh.push_back(make_pair(codes[0] + v[0], 1));
        }
        if (v.size() >= 2) {
            uhh.push_back(make_pair(v[0] + v[1], 0));
        }
        sort(uhh.begin(), uhh.end());
        auto bruh = uhh[0];
        if (bruh.second == 0) {
            v.erase(v.begin());
            v.erase(v.begin());
        } else if (bruh.second == 1) {
            v.erase(v.begin());
            codes.erase(codes.begin());
        } else {
            codes.erase(codes.begin());
            codes.erase(codes.begin());
        }
        codes.push_back(bruh.first);
        res += bruh.first;
    }
    /* for (ll i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
    for (ll i = 0; i < n; i++) {
        cout << codes[i] << " ";
    }
    cout << "\n"; */
    // ofstream out("huffman.out");
    cout << res << "\n";
    return 0;
}