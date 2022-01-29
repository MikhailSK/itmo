#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

ofstream out("partition.out");
ifstream in("partition.in");

vi a;
int n;

void gen(int p, int sum) {
    if (sum == 0) {
        for (int i = p-1; i > 0; i--) {
            cout << a[i] << '+';
        }
        cout << a[0];
        cout << '\n';
    }
    else {
        for (int c = 1; c <= min(p==0?n:a[p-1], sum); c++) {
            a[p]=c;
            gen(p+1, sum-c);
        }
    }
}

int main() {
    cerr << "This finds ways to represent a number as a sum.\nTo get the number, use wc -l\nEnter it.\n";
    cin >> n;
    a = vi(n);
    gen(0, n);
}