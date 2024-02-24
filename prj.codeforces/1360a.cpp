#include <iostream>
#include <vector>
#include <math.h>


int main() {
	int t = 0;
	int a = 0;
	int b = 0;
	int sqr = 0;
	std::cin >> t;
	for (int g = 0; g < t; g++) {
		std::cin >> a >> b;
		for (int i = 0; i < 40001; i++) {
			if (i * i >= a * b * 2) {
				std::cout << i * i << "\n";
				break;
			}
		}
	}
}