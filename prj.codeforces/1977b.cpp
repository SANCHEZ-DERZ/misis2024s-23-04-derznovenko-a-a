#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int m; cin >> m;
		cout << 32 << endl;
		for (int j = 0; j < 32; ++j, m >>= 1) {
			//			cout << '(' << m << ')';
			if (m & 1) {
				if (m & 2) ++m, cout << -1 << ' ';
				else cout << 1 << ' ';
			}
			else cout << 0 << ' ';
		}
		cout << endl;
	}
	return 0;
}