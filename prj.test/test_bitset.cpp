#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bitset/bitset.hpp"


TEST_CASE("SIZE") {
	BitSet a(10);
	CHECK_EQ(a.Size(), 10);
}


TEST_CASE("DFLT CTOR") {
	BitSet a;
	CHECK(a.Size() == 0);
}


TEST_CASE("RESIZE") {
	BitSet a;
	a.Resize(5);
	CHECK(a.Size() == 5);
	CHECK_THROWS(a.Resize(0));
	a.Resize(10000);
	CHECK(a.Size() == 10000);
}


TEST_CASE("SET AND GET") {
	BitSet a(1);
	a.Set(28, 1);
	CHECK(a.Get(28) == 1);
	a.Resize(2);
	CHECK(a.Get(28) == 1);
	a.Set(32, 1);
	a.Set(28, 0);
	CHECK(a.Get(32) == 1);
	CHECK(a.Get(28) == 0);
	a.Set(0, 0);
	a.Set(0, 0);
	CHECK(a.Get(0) == 0);
	BitSet b(0);
	CHECK_THROWS(b.Set(0, 0));
	CHECK_THROWS(b.Get(10));
}


TEST_CASE("OPERATOR==") {
	BitSet a(10);
	BitSet b(10);
	CHECK_EQ(a == b, true);
}


TEST_CASE("OPERATOR!=") {
	
}