#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ifstream in("antigray.in");
ofstream out("antigray.out");

int alph = 3;

vvi gen(vi v, int n) {
    if (n == 0)
        return {v};
    vi t = v;
    vvi res;
    for (int i = 0; i < alph; i++) {
        t.push_back(i);
        vvi a = gen(t, n-1);
        t.pop_back();
        res.insert(res.end(), a.begin(), a.end());
    }
    return res;
}

int main() {
    int n;
    in >> n;
    vvi norm_codes = gen({0}, n-1);
    for (vi norm_code : norm_codes) {
        for (int i = 1; i < alph + 1; i++) {
            for (int val : norm_code) {
                out << (val + i) % alph;
            }
            out << '\n';
        }
    }
}