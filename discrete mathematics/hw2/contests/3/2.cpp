#include<bits/stdc++.h>

using namespace std;

typedef vector<bool> vi;
typedef vector<vector<bool>> vvi;

ifstream in("gray.in");
ofstream out("gray.out");

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
    vvi t(v.rbegin(), v.rend());
    v.insert(v.end(), t.begin(), t.end());
    for (int i = 0; i < v.size(); i++) {
        if (i < v.size() / 2)
            v[i].push_back(false);
        else
            v[i].push_back(true);
    }
    gen(v, n-1);
}

int main() {
    int n;
    in >> n;
    vvi codes;
    codes.push_back({0});
    codes.push_back({1});
    gen(codes, n-1);
}