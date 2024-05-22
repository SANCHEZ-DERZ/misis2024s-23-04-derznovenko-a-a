#include "roborun/roborun.hpp"

void Roborun::Set(std::string command_name, double dir) {
	commands_[command_name].push_back(dir);
}


std::istream& operator>>(std::istream& in, Roborun command) {
	std::string command_name{};
	double dir{};
	in >> command_name >> dir;
	command.Set(command_name, dir);
	return in;
}


//std::pair<double, double> Roborun::GOR(double x) noexcept {
//	point_.first = x;
//}
