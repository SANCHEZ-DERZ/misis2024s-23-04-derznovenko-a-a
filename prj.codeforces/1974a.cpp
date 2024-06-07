#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		cout << max((y + 1) / 2, (4 * y + x + 14) / 15) << "\n";
	}
}