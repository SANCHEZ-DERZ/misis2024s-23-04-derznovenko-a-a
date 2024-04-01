#include <iostream>


int main() {
	int a = 0;
	int t = 0;
	std::cin >> a >> t;
	for (int i = 0; i < t; i++) {
		if (a % 10 != 0) {
			--a;
		}
		else {
			a /= 10;
		}
	}
	std::cout << a;
}