#include<bits/stdc++.h>

using namespace std;

typedef vector<unsigned long long> vi;
typedef vector<bool> vb;
typedef unsigned long long ull;

ofstream out("perm2num.out");
ifstream in("perm2num.in");

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
    6402373705728000llu
};

int main() {
    int n;
    cin >> n;
    vi perm(n);
    for (int i = 0; i < n; i++) {
        cin >> perm[i];
    }

    vb was(n, false);
    ull res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < perm[i] - 1; j++) {
            if (was[j] == false) {
                res += factorials[n - i - 1];
            }
        }
        was[perm[i] - 1] = true;
    }
    cout << res << '\n';
}