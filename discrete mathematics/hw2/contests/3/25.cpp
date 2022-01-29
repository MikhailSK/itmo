#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

ifstream in("nextchoose.in");
ofstream out("nextchoose.out");

int main() {
    int n, k;
    in >> n >> k;
    vi choose(k);
    for (int i = 0; i < k; i++) in >> choose[i];

    vi next(choose.begin(), choose.end());
    next.push_back(n);
    ll i = k - 1;
    while (next[i + 1] - next[i] < 2 && i >= 0) i--;
    if (i == -1) {
        cout << string(k, '0') << '\n';
        return 0;
    }

    next[i]++;
    for (int j = i + 1; i < k; i++) {
        cout << next[j-1] << ' ';
        next[j] = next[j-1]+1;
    }
    cout << '\n';
    
}