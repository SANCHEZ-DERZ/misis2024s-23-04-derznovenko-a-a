#include <iostream>
#include <vector>
#include <algorithm>


int main() {
	int t = 0;
	int x = 0;
	int n = 0;
	std::cin >> t;
	for (int g = 0; g < t; g++) {
		std::cin >> n >> x;
		if (n == 1 || n == 2) {
			std::cout << 1 << "\n";
		}
		else {
			if ((n - 2) % x != 0) {
				std::cout << (n - 2) / x + 2 << "\n";
			}
			else {
				std::cout << (n - 2) / x + 1 << "\n";
			}
		}
	}
}