#include <iostream>
using namespace std;
int t, n, a[100010];
bool f;
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		f = 1;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = n - 1; i > 0 && f; i--) if (a[i] > a[i + 1]) if (a[i] / 10 > a[i] % 10 || a[i] % 10 > a[i + 1]) f = 0; else a[i] /= 10;
		if (f) cout << "YES\n"; else cout << "NO\n";
	}
}