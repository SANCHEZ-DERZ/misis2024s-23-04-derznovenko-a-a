#ifndef COMPLEX_COMPLEX_HPP
#define COMPLEX_COMPLEX_HPP

#include <iostream>
#include <sstream>
#include <limits>


struct Complex {
	Complex() {}
	~Complex() {}
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);
	bool operator==(const Complex& num) const { return (std::abs(re - num.re) < 4 * std::numeric_limits<double>::epsilon()) && (std::abs(im - num.im) < 4 * std::numeric_limits<double>::epsilon()); }
	bool operator!=(const Complex& num) const { return !operator==(num); }
	Complex& operator+=(const Complex& num);
	Complex& operator-=(const Complex& num);
	Complex& operator*=(const Complex& num);
	Complex& operator/=(const Complex& num);
	Complex& operator=(const Complex& num);
	Complex& operator-();

	Complex& operator=(const double& num);
	Complex& operator+=(const double& num);
	Complex& operator-=(const double& num);
	Complex& operator*=(const double& num);
	Complex& operator/=(const double& num);

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };

	double getRe() const;
	double getIm() const;
};


std::ostream& operator<<(std::ostream& out, const Complex& num);
std::istream& operator>>(std::istream& in, Complex& num);

Complex operator+(const Complex& num, const Complex& num2);
Complex operator+(const Complex& num, const double& num2);
Complex operator+(const double& num, const Complex& num2);

Complex operator-(const Complex& num, const Complex& num2);
Complex operator-(const Complex& num, const double& num2);
Complex operator-(const double& num, const Complex& num2);

Complex operator*(const Complex& num, const Complex& num2);
Complex operator*(const Complex& num, const double& num2);
Complex operator*(const double& num, const Complex& num2);

Complex operator/(const Complex& num, const Complex& num2);
Complex operator/(const Complex& num, const double& num2);
Complex operator/(const double& num, const Complex& num2);

bool operator==(const Complex& num, const double& num2);
bool operator==(const double& num, const Complex& num2);

bool operator!=(const Complex& num, const double& num2);
bool operator!=(const double& num, const Complex& num2);

#endif