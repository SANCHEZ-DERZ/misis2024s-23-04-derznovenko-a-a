#include<bits/stdc++.h>
using namespace std;
int main() {
	int test;
	cin >> test;
	while (test--) {
		int n, a, mn = 10000005, sum = 0; cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a, mn = min(mn, a), sum += a;
		cout << sum - mn * n << "\n";
	}
	return 0;
}