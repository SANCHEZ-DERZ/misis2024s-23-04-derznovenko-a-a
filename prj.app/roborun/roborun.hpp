#include <vector>
#include <map>
#include <string>
#include <iostream>


class Roborun {
private:
	std::map<std::string, std::vector<double>> commands_;
	std::pair<double, double> point_;
public:
	Roborun() = default;

	void Set(std::string command_name, double dir);

	std::pair<double, double> GOR(double x) noexcept;
};

std::istream& operator>>(std::istream& in, Roborun command);