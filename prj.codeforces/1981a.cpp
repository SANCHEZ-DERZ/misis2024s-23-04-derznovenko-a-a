#include<bits/stdc++.h>
using namespace std; 
int main() { 
	int t; cin >> t; 
	while (t--) { 
		int l, r; cin >> l >> r; 
		cout << (63 - __builtin_clzll(r)) << "\n"; 
	} 
}