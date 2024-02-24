#include <iostream>
#include <vector>
#include <algorithm>


int main() {
	int t = 0;
	int x = 0;
	int y = 0;
	int n = 0;
	std::cin >> t;
	for (int g = 0; g < t; g++) {
		std::cin >> x >> y >> n;
		for (int i = n; i >= 0; i--) {
			if ((i % x) < y) {
				std::cout << (i - (i % x)) - (x - y) << "\n";
				break;
			}
			else {
				std::cout << i - ((i % x) - y) << "\n";
				break;
			}
		}
	}
}