#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

ofstream out("choose.out");
ifstream in("choose.in");

vb used;
vi a;
int n, k;
int bruh;

void gen(int p) {
    if (p == k) {
        cout << bruh << ' ';
        bruh++;
        for (int i = 0; i < k; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int c = (p == 0? 1 : a[p-1]); c <= n; c++) {
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
    cout << "This thing generates сочетания\nOutput format is: num + соч.\n";
    cout << "Input n and k\n";
    bruh = 1;
    cin >> n >> k;
    used = vb(n, false);
    a = vi(n, 1);
    gen(0);
}