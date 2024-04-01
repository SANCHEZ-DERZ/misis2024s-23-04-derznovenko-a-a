#include <string>
#include <iostream>


int main() {
	std::string sml = { "qwertyuiopasdfghjklzxcvbnm" };
	std::string caps = { "QWERTYUIOPASDFGHJKLZXCVBNM" };
	std::string s;
	std::cin >> s;
	for (int i = 0; i < sml.size(); i++) {
		if (s[0] == sml[i]) {
			s[0] = caps[i];
			break;
		}
	}
	for (int i = 0; i < s.size(); i++) {
		std::cout << s[i];
	}
}