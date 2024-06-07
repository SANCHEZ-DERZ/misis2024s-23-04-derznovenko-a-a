#include<bits/stdc++.h>
using namespace std;
int main() {
	int T, n, m;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		cout << ((m <= n && (n - m) % 2 == 0) ? "Yes" : "No") << endl;
	}
	return 0;
}