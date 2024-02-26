#include <iostream>
#include <vector>
#include <math.h>
#include <string>


int main() {
	int n = 0;
	std::string a;
	int count = 0;
	std::cin >> n;
	for (int j = 0; j < n; j++) {
		std::cin >> a;
		if (a[0] == '+' || a[2] == '+') {
			count += 1;
		}
		else {
			count -= 1;
		}
	}
	std::cout << count << "\n";
}