#include <iostream>
#include <vector>
#include <algorithm>


std::vector<char> symb = { 'T', 'i', 'm', 'u', 'r' };
int t = 0;
int n = 0;
std::vector<char> s(n);
std::cin >> t;
for (int g = 0; g < t; g++) {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
	}
	if (n == 5) {
		s.sort()
	}
}