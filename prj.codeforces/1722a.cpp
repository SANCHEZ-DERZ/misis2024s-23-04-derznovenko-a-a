#include <iostream>
#include <vector>
#include <algorithm>


int main() {
	std::vector<char> symb = { 'T', 'i', 'm', 'u', 'r' };
	int t = 0;
	int n = 0;
	int count = 0;
	std::vector<char> s(n);
	std::cin >> t;
	for (int g = 0; g < t; g++) {
		count = 0;
		std::cin >> n;
		s.resize(n);
		for (int i = 0; i < n; i++) {
			std::cin >> s[i];
		}
		if (n == 5) {
			std::sort(s.begin(), s.end());
			std::sort(symb.begin(), symb.end());
			for (int i = 0; i < n; i++) {
				if (symb[i] == s[i]) {
					count += 1;
				}
				//std::cout << s[i] << "\t" << symb[i] << "\t" << count << "\n";
			}
			if (count == n) {
				std::cout << "YES" << "\n";
			}
			else {
				std::cout << "NO" << "\n";
			}
		}
		else {
			std::cout << "NO" << "\n";
		}
	}
}