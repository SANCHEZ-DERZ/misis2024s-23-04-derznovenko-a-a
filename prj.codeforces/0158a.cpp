#include <iostream>
#include <vector>
#include <math.h>


int main() {
	std::vector<int> a;
	int n = 0;
	int k = 0;
	int b = 0;
	int count = 0;
	std::cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	b = a[k - 1];
	for (int i = 0; i < n; i++) {
		if (a[i] >= b && a[i] != 0) {
			count += 1;
		}
	}
	std::cout << count;
}