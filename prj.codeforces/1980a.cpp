#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    while (q--) {
        int n, m, r(0); string s; cin >> n >> m >> s;
        for (char i('A'); i < 'H'; ++i) r += max((int)(m - count(s.begin(), s.end(), i)), 0);
        cout << r << endl;
    }
}