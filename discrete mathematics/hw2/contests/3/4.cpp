#include<bits/stdc++.h>
 
using namespace std;
 
typedef vector<bool> vi;
typedef vector<vector<bool>> vvi;
 
ifstream in("chaincode.in");
ofstream out("chaincode.out");
 
int main() {
    int n;
    in >> n;
    vvi result;
    vi current(n, 0);
    while (true) {
        vi prefix(current.begin() + 1, current.end());
        prefix.push_back(true);
        if (find(result.begin(), result.end(), prefix) == result.end()) {
            current = prefix;
        } else {
            prefix.pop_back();
            prefix.push_back(false);
            if (find(result.begin(), result.end(), prefix) == result.end()) {
                current = prefix;
            } else {
                break;
            }
        }
        result.push_back(current);
    }
    for (vi code : result) {
        for (bool val : code) {
            out << val;
        }
        out << '\n';
    }
}