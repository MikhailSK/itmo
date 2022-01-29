#include<bits/stdc++.h>

using namespace std;

typedef vector<bool> vi;

ofstream out("allvectors.out");

void gen(vi v, int n) {
    if (n == 0) {
        for (bool b : v) {
            out << b;
        }
        out << '\n';
        return;
    }
    vi t = v;
    t.push_back(false);
    v.push_back(true);
    gen(t, n-1);
    gen(v, n-1);
}

int main() {
    int n;
    ifstream in("allvectors.in");
    in >> n;
    gen({}, n);
}