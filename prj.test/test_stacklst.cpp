
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stacklst/stacklst.hpp"


TEST_CASE("stack IsEmpty") {
	StackLst st;
	Complex a{ 1.5, 2.0 };
	Complex b{ 2.0, 3.0 };
	CHECK_EQ(st.IsEmpty(), 1);
	st.Push(a);
	CHECK_EQ(st.Top(), a);
}

TEST_CASE("Pop") {
	StackLst st;
	Complex a{ 1.5, 2.0 };
	st.Push(a);
	CHECK_EQ(st.IsEmpty(), 0);
	st.Pop();
	CHECK_EQ(st.IsEmpty(), 1);
}

TEST_CASE("Top") {
	StackLst st;
	Complex a{ 1.5, 2.0 };
	st.Push(a);
	CHECK_EQ(st.Top(), a);
}

TEST_CASE("Clear") {
	StackLst st;
	Complex a{ 1.5, 2.0 };
	st.Push(a);
	st.Clear();
	CHECK_EQ(st.IsEmpty(), 1);
}

TEST_CASE("Cycle") {
	StackLst st;
	Complex a;
	float b = 0;
	for (int i = 0; i < 1000; i++) {
		b += 1.0;
		a = { b, 0 };
		st.Push(a);
	}
	CHECK_EQ(st.Top(), Complex{ b, 0 });
	st.Pop();
	CHECK_EQ(st.Top(), Complex{ 999.0, 0 });
	CHECK_EQ(st.IsEmpty(), 0);
	st.Clear();
	CHECK_EQ(st.IsEmpty(), 1);
}


TEST_CASE("Copy") {
	StackLst st;
	Complex a{ 1.5, 2.0 };
	Complex b{ 2.0, 3.0 };
	st.Push(a);
	StackLst cpy(st);
	cpy.Top();
}
