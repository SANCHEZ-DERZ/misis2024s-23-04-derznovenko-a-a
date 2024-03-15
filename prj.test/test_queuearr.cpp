#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "queuearr/queuearr.hpp"

TEST_CASE("IsEmpty") {
	QueueArr a;
	Complex b{ 1, 2 };
	CHECK_EQ(a.IsEmpty(), 1);
	a.Push(b);
	CHECK_EQ(a.IsEmpty(), 0);
}

TEST_CASE("Clear") {
	QueueArr a;
	Complex b{ 1, 2 };
	Complex c{ 2, 3 };
	a.Push(b);
	a.Push(c);
	CHECK_EQ(a.IsEmpty(), 0);
	a.Clear();
	CHECK_EQ(a.IsEmpty(), 1);
}

TEST_CASE("Push") {
	QueueArr a;
	Complex b{ 1, 2 };
	float c = 0;
	for (int i = 0; i < 5; i++) {
		c += 1;
		b = { c, 0 };
		a.Push(b);
	}
	CHECK_EQ(a.IsEmpty(), 0);
}

TEST_CASE("Top") {
	QueueArr a;
	Complex b{ 1, 2 };
	Complex c{ 2, 3 };
	a.Push(b);
	a.Push(c);
	CHECK_EQ(a.Top(), b);
	a.Pop();
	CHECK_EQ(a.Top(), c);
	a.Pop();
	CHECK_EQ(a.IsEmpty(), 1);
}

TEST_CASE("Pop") {
	QueueArr a;
	Complex b{ 1, 2 };
	float c = 0;
	for (int i = 0; i < 10; i++) {
		c += 1;
		b = { c, 0 };
		a.Push(b);
	}
	b = { 1, 0 };
	c = 1;
	for (int i = 0; i < 10; i++) {
		CHECK_EQ(a.Top(), b);
		c += 1;
		b = { c, 0 };
		a.Pop();
	}
}

TEST_CASE("Copy constructor") {
	QueueArr queue;
	queue.Push(Complex(1, 1));
	queue.Push(Complex(0, 0));
	QueueArr queue1(queue);
	CHECK_EQ(queue.Top(), queue1.Top());
}

TEST_CASE("Operator=") {
	QueueArr queue;
	queue.Push(Complex(1, 1));
	queue.Push(Complex(0, 0));
	QueueArr queue1 = queue;
	CHECK_EQ(queue.Top(), queue1.Top());
}