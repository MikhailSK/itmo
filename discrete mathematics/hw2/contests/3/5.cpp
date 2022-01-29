#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ifstream in("telemetry.in");
ofstream out("telemetry.out");

int n, k;

void gen(vvi v, int n) {
    if (n == 0) {
        for (vi code : v) {
            for (int i = code.size() - 1; i >= 0; i--) {
                out << code[i];
            }
            out << '\n';
        }
        return;
    }
    vvi tmp;
    for (int i = 0; i < k - 1; i++) {
        vvi t;
        if (i % 2 == 0)
            t = vvi(v.rbegin(), v.rend());
        else
            t = vvi(v.begin(), v.end());
        tmp.insert(tmp.end(), t.begin(), t.end());
    }
    v.insert(v.end(), tmp.begin(), tmp.end());
    for (int i = 0; i < v.size(); i++) {
        v[i].push_back((int)((float)i / v.size() * k));
    }
    gen(v, n-1);
}

int main() {
    in >> n >> k;
    vvi codes;
    for (int i = 0; i < k; i++) {
        codes.push_back({i});
    }
    gen(codes, n-1);
}