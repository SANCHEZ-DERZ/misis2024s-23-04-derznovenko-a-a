#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "rational/rational.hpp"
#include "doctest.h" 

TEST_CASE("rational ctor") {
	Rational r_def;
	CHECK(0 == r_def.num());
	CHECK(1 == r_def.den());

	Rational r_int(3);
	CHECK(3 == r_int.num());
	CHECK(1 == r_int.den());

	CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("=") {
	CHECK(Rational(2, 1) == (Rational(4, 3) = int64_t(2)));
	CHECK(Rational(5, 3) == (Rational(9, 7) = Rational(10, 6)));
}

TEST_CASE("+") {
	CHECK(Rational(41, 21) == (Rational(2, 7) + Rational(5, 3)));
	CHECK(Rational(22, 1) == (Rational(11, 2) + Rational(33, 2)));
	CHECK(Rational(10, 3) == (Rational(4, 3) += Rational(2, 1)));
	CHECK(Rational(11, 3) == (Rational(2, 3) += int64_t(3)));
	CHECK(Rational(7, 2) == (Rational(9, 6) + int64_t(2)));
}

TEST_CASE("-") {
	CHECK(Rational(1, 1) == (Rational(3, 2) -= Rational(1, 2)));
	CHECK(Rational(17, 12) == (Rational(8, 3) -= Rational(5, 4)));
	CHECK(Rational(-9, 20) == (Rational(4, 5) - Rational(5, 4)));
	CHECK(Rational(-1, 9) == (Rational(8, 9) - int64_t(1)));
	CHECK(Rational(1, 9) == (int64_t(1) - Rational(8, 9)));
	CHECK(Rational(-2, 1) == (Rational(4, 2) -= int64_t(4)));
}

TEST_CASE("*") {
	CHECK(Rational(11, 5) == (Rational(2, 5) *= Rational(11, 2)));
	CHECK(Rational(13, 12) == (Rational(13, 4) * Rational(1, 3)));
	CHECK(Rational(1, 1) == (Rational(7, 21) * int64_t(3)));
	CHECK(Rational() == (int64_t(0) * Rational(9, 6)));
}

TEST_CASE("/") {
	CHECK(Rational(4, 55) == (Rational(2, 5) /= Rational(11, 2)));
	CHECK(Rational(25, 16) == (Rational(5, 2) / Rational(8, 5)));
	CHECK(Rational(11, 20) == (Rational(11, 2) / int64_t(10)));
	CHECK(Rational(20, 11) == (int64_t(10) / Rational(11, 2)));
	CHECK(Rational() == (int64_t(0) / Rational(4, 6)));
	CHECK_THROWS(Rational(4, 6) / int64_t(0));
}

TEST_CASE("inc_dec") {
	CHECK(Rational(13, 5) == (++Rational(8, 5)));
	CHECK(Rational(8, 5) == (--Rational(13, 5)));
}

TEST_CASE("cut_back") {
	CHECK(Rational(-1, 20) == Rational(-5, 100));
	CHECK(Rational(4, 1) == Rational(64, 16));
}

TEST_CASE("minus") {
	CHECK(Rational(-3, 1) == Rational(3, -1));
	CHECK(Rational(3, 1) == Rational(-3, -1));
}

TEST_CASE("num_den") {
	CHECK(int64_t(4) == (Rational(4, 3).num()));
	CHECK(int64_t(3) == (Rational(4, 3).den()));
}

TEST_CASE("equality") {
	CHECK(Rational(12, 13) == Rational(24, 26));
	CHECK(Rational(8, 2) == int64_t(4));
	CHECK(Rational(86, 58) != Rational(87, 58));
	CHECK(int64_t(3) != Rational(3, 9));
	CHECK(Rational() == Rational(0));
}

TEST_CASE("more") {
	CHECK(Rational(13, 5) > Rational(10, 4));
	CHECK(Rational(7, 2) > int64_t(3));
	CHECK(Rational(33, 4) >= Rational(66, 8));
	CHECK(int64_t(2) >= Rational(82, 41));
}

TEST_CASE("less") {
	CHECK(Rational(19, 2) < Rational(10, 1));
	CHECK(Rational(11, 3) < int64_t(4));
	CHECK(Rational(4, 5) <= Rational(5, 4));
	CHECK(int64_t(17) <= Rational(187, 11));
}
