#ifndef RATIONAL_RATIONAL_HPP_20231113
#define RATIONAL_RATIONAL_HPP_20231113

#include <iostream>
#include <sstream>

class Rational {
private:
	std::int64_t num_ = 0;
	std::int64_t den_ = 1;

	std::int64_t NOD(std::int64_t den, std::int64_t num);
	void simplify();

public:
	Rational() = default;
	Rational(const Rational&) = default;
	explicit Rational(const std::int64_t num) noexcept : num_(num) { }
	Rational(const std::int64_t num, const std::int64_t den);
	~Rational() = default;

	Rational& operator=(Rational&&) = default;
	Rational& operator=(const Rational&);
	Rational& operator=(const int64_t rhs);


	std::int64_t num() const noexcept { return num_; }
	std::int64_t den() const noexcept { return den_; }

	bool operator==(const Rational& rhs) const;
	bool operator!=(const Rational& rhs) const;
	bool operator>=(const Rational& rhs) const;
	bool operator<=(const Rational& rhs) const;
	bool operator<(const Rational& rhs) const;
	bool operator>(const Rational& rhs) const;

	Rational& operator++();
	Rational& operator--();

	Rational operator-() const noexcept { return { -num_, den_ }; }

	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);

	Rational& operator+=(const std::int64_t rhs);
	Rational& operator-=(const std::int64_t rhs);
	Rational& operator*=(const std::int64_t rhs);
	Rational& operator/=(const std::int64_t rhs);


};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

Rational operator+(const Rational& lhs, const std::int64_t rhs);
Rational operator-(const Rational& lhs, const std::int64_t rhs);
Rational operator*(const Rational& lhs, const std::int64_t rhs);
Rational operator/(const Rational& lhs, const std::int64_t rhs);

Rational operator+(const std::int64_t lhs, const Rational& rhs);
Rational operator-(const std::int64_t lhs, const Rational& rhs);
Rational operator*(const std::int64_t lhs, const Rational& rhs);
Rational operator/(const std::int64_t lhs, const Rational& rhs);

bool operator==(const Rational& lhs, const int64_t& rhs);
bool operator==(const int64_t& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const int64_t& rhs);
bool operator!=(const int64_t& lhs, const Rational& rhs);

bool operator>=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const int64_t& rhs);
bool operator>=(const int64_t& lhs, const Rational& rhs);

bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const int64_t& rhs);
bool operator>(const int64_t& lhs, const Rational& rhs);

bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const int64_t& rhs);
bool operator<=(const int64_t& lhs, const Rational& rhs);

bool operator<(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const int64_t& rhs);
bool operator<(const int64_t& lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& out, const Rational& rhs);
std::istream& operator>>(std::istream& in, Rational& rhs);

#endif