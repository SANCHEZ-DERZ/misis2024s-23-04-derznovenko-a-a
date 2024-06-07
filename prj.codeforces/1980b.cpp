#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d[110] = { 0 };
		cin >> a >> b >> c;
		for (int i = 1; i <= a; i++)cin >> d[i];
		int ans = d[b];
		sort(d + 1, d + a + 1, greater<int>());
		if (d[c + 1] < ans)cout << "yes" << endl;
		else if (d[c + 1] == ans && d[c] == ans)cout << "maybe" << endl;
		else cout << "no" << endl;
	}
	return 0;
}