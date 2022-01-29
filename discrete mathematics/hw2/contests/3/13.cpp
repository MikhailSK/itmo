#include<bits/stdc++.h>

using namespace std;

typedef vector<unsigned long long> vi;
typedef vector<bool> vb;
typedef unsigned long long ull;

ofstream out("num2perm.out");
ifstream in("num2perm.in");

ull n, k;

vi factorials = {
    1llu,
    1llu,
    2llu,
    6llu,
    24llu,
    120llu,
    720llu,
    5040llu,
    40320llu,
    362880llu,
    3628800llu,
    39916800llu,
    479001600llu,
    6227020800llu,
    87178291200llu,
    1307674368000llu,
    20922789888000llu,
    355687428096000llu,
    6402373705728000llu,
};

void gen() {
    vi perm(n);
    vb was(n, false);
    for (int i = 1; i <= n; i++) {
        ull alreadyWas = double(k) / factorials[n-i];
        k %= factorials[n-i];
        ull currFree = 0;
        for (int j = 1; j <= n; j++) {
            if (was[j-1] == false) {
                currFree++;
                if (currFree == alreadyWas + 1) {
                    perm[i-1] = j;
                    was[j-1] = true;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << perm[i] << ' ';
    }
    cout << '\n';
}

int main() {
    cin >> n >> k;
    gen();
}