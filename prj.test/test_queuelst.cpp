#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "queuelst/queuelst.hpp"



TEST_CASE("stack IsEmpty") {
	QueueLst st;
	Complex a{ 1.5, 2.0 };
	Complex b{ 2.0, 3.0 };
	CHECK_EQ(st.IsEmpty(), 1);
	st.Push(a);
	CHECK_EQ(st.Top(), a);
}

TEST_CASE("Push") {
	QueueLst st;
	Complex a{ 1.5, 2.0 };
	Complex b{ 2.0, 3.0 };
	CHECK_EQ(st.IsEmpty(), 1);
	st.Push(a);
	st.Push(b);
	CHECK_EQ(st.Top(), a);
}

TEST_CASE("Pop") {
	QueueLst st;
	Complex a{ 1.5, 2.0 };
	st.Push(a);
	CHECK_EQ(st.IsEmpty(), 0);
	st.Pop();
	CHECK_EQ(st.IsEmpty(), 1);
}

TEST_CASE("Top") {
	QueueLst st;
	Complex a{ 1.5, 2.0 };
	st.Push(a);
	CHECK_EQ(st.Top(), a);
}

TEST_CASE("Clear") {
	QueueLst st;
	Complex a{ 1.5, 2.0 };
	st.Push(a);
	st.Clear();
	CHECK_EQ(st.IsEmpty(), 1);
}

TEST_CASE("Cycle") {
	QueueLst st;
	Complex a;
	float b = 0;
	for (int i = 0; i < 1000; i++) {
		b += 1.0;
		a = { b, 0 };
		st.Push(a);
	}
	CHECK_EQ(st.Top(), Complex{ 1, 0 });
	st.Pop();
	CHECK_EQ(st.Top(), Complex{ 2, 0 });
	CHECK_EQ(st.IsEmpty(), 0);
	st.Clear();
	CHECK_EQ(st.IsEmpty(), 1);
}

/*
TEST_CASE("Copy") {
	QueueLst st;
	Complex a{ 1.5, 2.0 };
	Complex b{ 2.0, 3.0 };
	st.Push(a);
	QueueLst cpy(st);
	cpy.Top();
}
*/