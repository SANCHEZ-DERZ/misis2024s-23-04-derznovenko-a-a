#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int a[n], p[n], mex = n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = n - 1; i >= 0; i--) {
            p[i] = mex - a[i];
            if (mex > p[i]) mex = p[i];
        }
        for (int i = 0; i < n; i++) cout << p[i] << " ";
        cout << endl;
    }
}