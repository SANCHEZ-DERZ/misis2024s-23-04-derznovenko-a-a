#include "rational.hpp"
#include <stdexcept>


std::int64_t Rational::NOD(std::int64_t den, std::int64_t num) {
	while (num != 0) {
		std::int64_t temp = den % num;
		den = num;
		num = temp;
	}
	return den;
}

void Rational::simplify() {
	std::int64_t gcd = Rational::NOD(num_, den_);
	if (gcd != 0) {
		num_ /= gcd;
		den_ /= gcd;
	}
}

Rational::Rational(const std::int64_t num, const std::int64_t den) {
	if (den_ == 0) {
		throw std::invalid_argument("Zero denumenator in Rational ctor");
	}
	if ((den_ < 0 && num_ > 0) || (den_ > 0 && num_ < 0)) {
		den_ = -den;
		num_ = -num;
	}
	else {
		num_ = num;
		den_ = den;
	}
	simplify();
}

Rational& Rational::operator=(const Rational& rhs) {
	num_ = rhs.num_;
	den_ = rhs.den_;
	return *this;
}

Rational& Rational::operator=(const int64_t rhs) { return operator=(Rational(rhs)); }

bool Rational::operator==(const Rational& rhs) const { return num_ == rhs.num_ && den_ == rhs.den_; }

bool Rational::operator!=(const Rational& rhs) const { return !operator==(rhs); }

bool Rational::operator<(const Rational& rhs) const { return num_ * rhs.den_ < rhs.num_ * den_; }

bool Rational::operator>(const Rational& rhs) const { return num_ * rhs.den_ > rhs.num_ * den_; }

bool Rational::operator<=(const Rational& rhs) const { return operator<(rhs) || operator==(rhs);}

bool Rational::operator>=(const Rational& rhs) const { return operator>(rhs) || operator==(rhs); }

Rational& Rational::operator+=(const Rational& rhs) {
	num_ = num_ * rhs.den_ + den_ * rhs.num_;
	den_ = den_ * rhs.den_;
	simplify();
	return *this;
}

Rational& Rational::operator-=(const Rational& rhs) {
	num_ = num_ * rhs.den_ - den_ * rhs.num_;
	den_ = den_ * rhs.den_;
	simplify();
	return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
	num_ *= rhs.num_;
	den_ *= rhs.den_;
	simplify();
	return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
	num_ *= rhs.den_;
	den_ *= rhs.num_;
	simplify();
	return *this;
}

Rational& Rational::operator+=(const std::int64_t rhs) {
	num_ += rhs * den_;
	simplify();
	return *this;
}

Rational& Rational::operator-=(const std::int64_t rhs) {
	num_ -= rhs * den_;
	simplify();
	return *this;
}

Rational& Rational::operator*=(const std::int64_t rhs) {
	num_ *= rhs;
	simplify();
	return *this;
}

Rational& Rational::operator/=(const std::int64_t rhs) {
	den_ *= rhs;
	simplify();
	return *this;
}

Rational& Rational::operator++() {
	num_ += 1;
	den_ += 1;
	simplify();
	return *this;
}

Rational& Rational::operator--() {
	num_ -= 1;
	den_ -= 1;
	simplify();
	return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
	Rational sum(lhs);
	sum += rhs;
	return sum;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
	Rational sum(lhs);
	sum -= rhs;
	return sum;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
	Rational sum(lhs);
	sum *= rhs;
	return sum;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
	Rational sum(lhs);
	sum /= rhs;
	return sum;
}

Rational operator+(const Rational& lhs, const std::int64_t rhs) {
	Rational sum(lhs);
	sum += rhs;
	return sum;
}

Rational operator-(const Rational& lhs, const std::int64_t rhs) {
	Rational sum(lhs);
	sum -= rhs;
	return sum;
}

Rational operator*(const Rational& lhs, const std::int64_t rhs) {
	Rational sum(lhs);
	sum *= rhs;
	return sum;
}

Rational operator/(const Rational& lhs, const std::int64_t rhs) {
	Rational sum(lhs);
	sum /= rhs;
	return sum;
}

Rational operator+(const std::int64_t lhs, const Rational& rhs) {
	Rational sum(rhs);
	sum += lhs;
	return sum;
}

Rational operator-(const std::int64_t lhs, const Rational& rhs) {
	Rational sum(rhs);
	sum -= lhs;
	return sum;
}

Rational operator*(const std::int64_t lhs, const Rational& rhs) {
	Rational sum(rhs);
	sum *= lhs;
	return sum;
}

Rational operator/(const std::int64_t lhs, const Rational& rhs) {
	Rational sum(rhs);
	sum /= lhs;
	return sum;
}

bool operator==(const Rational& lhs, const int64_t& rhs) {
	if ((lhs.num() == rhs && lhs.den() == 1) || (lhs.num() == 0 && rhs == 0)) {
		return true;
	}
	return false;
}

bool operator==(const int64_t& lhs, const Rational& rhs) {
	if ((rhs.num() == lhs && rhs.den() == 1) || (rhs.num() == 0 && lhs == 0)) {
		return true;
	}
	return false;
}

bool operator!=(const Rational& lhs, const int64_t& rhs) {
	if (lhs.num() == rhs && lhs.den() == 1) {
		return false;
	}
	return true;
}

bool operator!=(const int64_t& lhs, const Rational& rhs) {
	if (rhs.num() == lhs && rhs.den() == 1) {
		return false;
	}
	return true;
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.num() >= 0);
}

bool operator>=(const Rational& lhs, const int64_t& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.num() >= 0);
}

bool operator>=(const int64_t& lhs, const Rational& rhs) {
	Rational a;
	a = lhs - rhs;
	return (a.num() >= 0);
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.num() <= 0);
}

bool operator<=(const Rational& lhs, const int64_t& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.num() <= 0);
}

bool operator<=(const int64_t& lhs, const Rational& rhs) {
	Rational a;
	a = lhs - rhs;
	return (a.num() <= 0);
}

bool operator>(const Rational& lhs, const Rational& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.num() > 0);
}

bool operator>(const Rational& lhs, const int64_t& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.num() > 0);
}

bool operator>(const int64_t& lhs, const Rational& rhs) {
	Rational a;
	a = lhs - rhs;
	return (a.num() > 0);
}

bool operator<(const Rational& lhs, const Rational& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.num() < 0);
}

bool operator<(const Rational& lhs, const int64_t& rhs) {
	Rational a(lhs);
	a -= rhs;
	return (a.num() < 0);
}

bool operator<(const int64_t& lhs, const Rational& rhs) {
	Rational a;
	a = lhs - rhs;
	return (a.num() < 0);
}

std::ostream& operator<<(std::ostream& out, const Rational& rhs) {
	out << rhs.num() << " / " << rhs.den();
	return out;
}

std::istream& operator>>(std::istream& in, Rational& rhs) {
	std::int64_t num = 0;
	std::int64_t den = 0;
	char sep{};
	in >> num >> sep;
	in >> den >> sep;
	rhs = Rational(num, den);
	return in;
}