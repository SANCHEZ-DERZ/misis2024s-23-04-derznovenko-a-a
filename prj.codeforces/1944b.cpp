#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, k, a[50005], b[50005], i;
		cin >> n >> k;
		for (int j = 0; j < 2; j++) {
			vector<int> o, t;
			int tem = k * 2;
			for (i = 1; i <= n; i++) b[i] = 0;
			for (i = 0; i < n; i++) {
				cin >> a[i];
				b[a[i]]++;
			}
			for (i = 1; i <= n; i++) {
				if (b[i] == 1) o.push_back(i);
				else if (b[i] == 2) t.push_back(i);
			}
			for (auto x : t) {
				cout << x << ' ' << x << ' ';
				tem -= 2;
				if (tem == 0) break;
			}
			if (tem != 0) {
				for (auto x : o) {
					cout << x << ' ';
					tem--;
					if (tem == 0) break;
				}
			}
			cout << endl;
		}
	}
}