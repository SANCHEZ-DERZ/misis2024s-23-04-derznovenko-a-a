#include <complex/complex.hpp>

double Complex::getRe() const{
	return re;
}

double Complex::getIm() const{
	return im;
}

Complex& Complex::operator-() {
	re *= -1;
	im *= -1;
	return *this;
}

Complex& Complex::operator=(const Complex& num) {
	re = num.re;
	im = num.im;
	return* this;
}

Complex& Complex::operator=(const double& num) {
	return operator=(Complex(num));
}

Complex& Complex::operator*=(const double& num) {
	return operator=(Complex(num));
}

Complex& Complex::operator+=(const double& num) {
	return operator+=(Complex(num));
}

Complex& Complex::operator-=(const double& num) {
	return operator-=(Complex(num));
}

Complex& Complex::operator/=(const double& num) {
	return operator/=(Complex(num));
}

Complex& Complex::operator+=(const Complex& num) {
	re += num.re;
	im += num.im;
	return *this;
}

Complex& Complex::operator-=(const Complex& num) {
	re -= num.re;
	im -= num.im;
	return *this;
}

Complex& Complex::operator*=(const Complex& num) {
	double k, e;
	k = re;
	e = im;
	re *= num.re;
	im *= num.im;
	re -= im;
	im = k * num.im + e * num.re;
	return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
	double k;
	k = re;
	if ((rhs.im * rhs.im + rhs.re * rhs.re) != 0) {
		re = (re * rhs.re + im * rhs.im) / (rhs.im * rhs.im + rhs.re * rhs.re);
		im = (im * rhs.re - k * rhs.im) / (rhs.im * rhs.im + rhs.re * rhs.re);
		return *this;
	}
	throw std::overflow_error("Error: Division by zero");
}

Complex operator+(const Complex& num, const Complex& num2) {
	Complex sum(num);
	sum += num2;
	return sum;
}

Complex operator+(const Complex& num, const double& num2) {
	Complex sum(num);
	sum.re += num2;
	return sum;
}

Complex operator+(const double& num, const Complex& num2) {
	Complex sum(num2);
	sum.re += num;
	return sum;
}

Complex operator-(const Complex& num, const Complex& num2) {
	Complex minus(num);
	minus -= num2;
	return minus;
}

Complex operator-(const Complex& num, const double& num2) {
	Complex minus(num);
	minus -= num2;
	return minus;
}

Complex operator-(const double& num, const Complex& num2) {
	Complex minus(num2);
	minus.re -= num;
	minus.re *= -1;
	minus.im *= -1;
	return minus;
}

Complex operator*(const Complex& num, const Complex& num2) {
	Complex umn(num);
	umn *= num2;
	return umn;
}

Complex operator*(const Complex& num, const double& num2) {
	Complex umn(num);
	umn *= num2;
	return umn;
}

Complex operator*(const double& num, const Complex& num2) {
	Complex umn(num2);
	umn.re *= num;
	umn.im *= num;
	return umn;
}

Complex operator/(const Complex& num, const Complex& num2)
{
	Complex raz(num);
	raz /= num2;
	return raz;
}

Complex operator/(const Complex& num, const double& num2)
{
	Complex raz(num);
	raz /= num2;
	return raz;
}

Complex operator/(const double& num, const Complex& num2)
{
	Complex raz(num);
	raz /= num2;
	return raz;
}

bool operator==(const Complex& num, const double& num2)
{
	if (num.im == 0 && std::abs(num.re - num2) < 4 * std::numeric_limits<double>::epsilon()) {
		return true;
	}
	return false;
}

bool operator==(const double& num, const Complex& num2)
{
	if (num2.im == 0 && std::abs(num2.re - num) < 4 * std::numeric_limits<double>::epsilon()) {
		return true;
	}
	return false;
}

bool operator!=(const Complex& num, const double& num2)
{
	return !(num == num2);
}

bool operator!=(const double& num, const Complex& num2)
{
	return !(num == num2);
}

std::ostream& operator<<(std::ostream& out, const Complex& num) {
	out << "{" << num.getRe() << ", " << num.getIm() << "}";
	return out;
}

std::istream& operator>>(std::istream& in, Complex& num) {
	double r = 0.0;
	double i = 0.0;
	char sep{};
	in >> r >> sep;
	in >> i >> sep;
	num = Complex(r, i);
	return in;
}

Complex::Complex(const double real)
	: Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
	: re(real)
	, im(imaginary)
{
}