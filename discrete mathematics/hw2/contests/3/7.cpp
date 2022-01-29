#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ofstream out("permutations.out");
ifstream in("permutations.in");

vb used;
vi a;
int n;

void gen(int p) {
    if (p == n) {
        for (int val : a) {
            out << val << ' ';
        }
        out << '\n';
        return;
    }
    for (int c = 1; c <= n; c++) {
        // a[p] = c;
        if (!used[c]) {
            a[p] = c;
            used[c] = true;
            gen(p + 1);
            used[c] = false;
        }
    }
}

int main() {
    in >> n;
    used = vb(n, false);
    a = vi(n, 1);
    gen(0);
}