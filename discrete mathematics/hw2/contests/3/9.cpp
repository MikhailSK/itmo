#include<bits/stdc++.h>

using namespace std;

typedef vector<char> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ofstream out("brackets.out");
ifstream in("brackets.in");

vi a;
int n;

void gen(int p, int bal) {
    if (p == 2*n) {
        for (int i = 0; i < p; i++) {
            out << a[i];
        }
        out << '\n';
        return;
    }

    if (2*n-p-1 >= bal+1) {
        a[p] = '(';
        gen(p + 1, bal + 1);
    }
    if (bal > 0) {
        a[p] = ')';
        gen(p + 1, bal - 1);
    }
}

int main() {
    in >> n;
    a = vi(2*n, ' ');
    gen(0, 0);
}