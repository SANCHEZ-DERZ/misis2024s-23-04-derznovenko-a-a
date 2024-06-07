#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        if (is_sorted(s.begin(), s.end())) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}