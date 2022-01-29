#include<bits/stdc++.h>

using namespace std;

typedef vector<bool> vi;
typedef vector<vector<bool>> vvi;

ofstream out("vectors.out");
ifstream in("vectors.in");

vvi gen(vi v, int n, int one_cnt) {
    if (n == 0) {
        return {v};
    }
    v.push_back(false);
    vvi res = gen(v, n-1, 0);
    if (one_cnt == 0) {
        vi t = v;
        t.pop_back();
        t.push_back(true);
        vvi a = gen(t, n-1, one_cnt + 1);
        res.insert(res.end(), a.begin(), a.end());
    }
    return res;
}

int main() {
    int n;
    in >> n;
    vvi res = gen({}, n, 0);
    out << res.size() << '\n';
    for (vi code : res) {
        for (bool val : code) {
            out << val;
        }
        out << '\n';
    }
}