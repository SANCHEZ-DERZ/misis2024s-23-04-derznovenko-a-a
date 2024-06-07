#include<bits/stdc++.h>
using namespace std;
string s;
int k;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		cin >> k;
		cin >> s;
		string r = s;
		sort(r.begin(), r.end());
		r.erase(unique(r.begin(), r.end()), r.end());
		for (auto i : s)
		{
			int t = r.find(i);
			cout << r[r.size() - 1 - t];
		}
		cout << endl;
	}
}