#include <iostream>
#include <string>
#include <math.h>


int main() {
	int n = 0;
	int len = 0;
	std::string a;
	std::cin >> n;
	for (int g = 0; g < n; g++) {
		std::cin >> a;
		len = a.size();
		if (len > 10) {
			std::cout << a.front() << len - 2 << a.back() << "\n";
		}
		else {
			std::cout << a << "\n";
		}
	}
}