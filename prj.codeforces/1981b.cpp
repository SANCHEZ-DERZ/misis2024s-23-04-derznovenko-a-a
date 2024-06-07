#include<bits/stdc++.h>
using namespace std;
int t, n, m;
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int l = max(0, n - m), r = n + m, s = 0;
		while (l != r && r) { r >>= 1; l >>= 1; ++s; }
		cout << ((n + m) | ((1 << s) - 1)) << '\n';
	}
	return 0;
}