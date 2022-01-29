#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

ifstream in("nextsetpartition.in");
ofstream out("nextsetpartition.out");

int main() {
    int n, k;
    in >> n >> k;
    while (n != 0 || k != 0) {
        vvi test;
        { string tmp; getline(in, tmp); }
        for (int i = 0; i < k; i++) {
            string setstr;
            getline(in, setstr);
            istringstream setstrstr(setstr);
            vi set;
            int t;
            while (setstrstr >> t) set.push_back(t); 
            test.push_back(set);
        }
        vi used;
        bool fl = false;
        for (int i = test.size() - 1; i >= 0; i--) {
            if (used.size() != 0 && (used.back() > test[i].back())) {
                test[i].push_back(used.back());
                used.pop_back();
                break;
            }
            int j;
            for (j = test[i].size() - 1; j >= 0; j--) {
                if (used.size() != 0 && j != 0 && used.back() > test[i][j]) {
                    test[i][j] = used.back();
                    fl = true;
                    break;
                }
            }
            if (fl) break;
            used.push_back(test[i][j]);
            test[i].erase(test[i].begin() + j);
        }
        sort(used.begin(), used.end());
        for (int i : used) test.push_back({i});
        for (auto t : test) {
            for (auto i : t) {
                cout << i << ' ';
            }
            cout << '\n';
        } 
        { string tmp; getline(in, tmp); }
        in >> n >> k;
    }
}