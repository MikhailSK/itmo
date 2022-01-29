#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

ofstream out("subsets.out");
ifstream in("subsets.in");

int n;

void gen(vi v) {
    if (v.size() != 0) {
        for (int i = 0; i < v.size(); i++) {
            out << v[i] << ' ';
        }
        out << '\n';
    }
    for (int i = (v.size()==0?1:v.back() + 1); i <= n; i++) {
        vi t(v);
        t.push_back(i);
        gen(t);
    }
}

int main() {
    in >> n;
    out << '\n';
    gen({});
}