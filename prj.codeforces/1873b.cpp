#include <iostream>
#include <vector>
#include <algorithm>


int main() {
	int t = 0;
	int n = 0;
	int min = 10;
	int sum = 1;
	std::vector<int> s;
	std::cin >> t;
	for (int g = 0; g < t; g++) {
		min = 10;
		sum = 1;
		std::cin >> n;
		s.resize(n);
		for (int i = 0; i < n; i++) {
			std::cin >> s[i];
		}
		for (int i = 0; i < n; i++) {
			if (min > s[i]) {
				min = s[i];
			}
		}
		for (int i = 0; i < n; i++) {
			if (s[i] == min) {
				s[i] += 1;
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			sum *= s[i];
		}
		std::cout << sum << "\n";
	}
}