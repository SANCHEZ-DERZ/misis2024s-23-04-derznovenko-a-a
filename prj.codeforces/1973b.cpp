#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n, ans = 1;
	cin >> n;
	vector<int>a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= 20; i++) {
		int p = 0;
		for (int j = 1; j <= n; j++) {
			if ((a[j] >> i) & 1)ans = max(ans, j - p), p = j;
		}
		if (p)ans = max(ans, n + 1 - p);
	}
	cout << ans << endl;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}