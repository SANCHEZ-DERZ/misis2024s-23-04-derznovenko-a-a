#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stackarrt/stackarrt.hpp"
#include "complex/complex.hpp"

TEST_CASE("Constructor") {
    StackArrT<Complex> stack;
    CHECK(stack.IsEmpty());
}

TEST_CASE("Push") {
    StackArrT<Complex> stack;
    Complex c(1, 2);
    stack.Push(c);
    CHECK_FALSE(stack.IsEmpty());
    CHECK_EQ(stack.Top(), c);
}

TEST_CASE("Pop") {
    StackArrT<Complex> stack;
    Complex c(1, 2);
    stack.Push(c);
    stack.Pop();
    CHECK(stack.IsEmpty());
}

TEST_CASE("Copy constructor") {
    StackArrT<Complex> stack;
    Complex c{ 1, 2 };
    stack.Push(c);
    StackArrT<Complex> stack2(stack);
    CHECK_FALSE(stack.IsEmpty());
    CHECK_FALSE(stack2.IsEmpty());
    CHECK_EQ(stack.Top(), c);
    CHECK_EQ(stack2.Top(), c);
    stack.Pop();
    CHECK(stack.IsEmpty());
    CHECK_FALSE(stack2.IsEmpty());
    CHECK_EQ(stack2.Top(), c);
}

TEST_CASE("Assignment operator") {
    StackArrT<Complex> stack;
    Complex c(1, 2);
    stack.Push(c);
    StackArrT<Complex> stack2;
    stack2 = stack;
    CHECK_FALSE(stack.IsEmpty());
    CHECK_FALSE(stack2.IsEmpty());
    CHECK_EQ(stack.Top(), c);
    CHECK_EQ(stack2.Top(), c);
    stack.Pop();
    CHECK(stack.IsEmpty());
    CHECK_FALSE(stack2.IsEmpty());
    CHECK_EQ(stack2.Top(), c);
}

TEST_CASE("Clear") {
    StackArrT<Complex> stack;
    Complex c(1, 2);
    stack.Push(c);
    stack.Clear();
    CHECK(stack.IsEmpty());
}

TEST_CASE("Push and Pop") {
    StackArrT<Complex> stack;
    Complex c1(1, 2);
    Complex c2(3, 4);
    stack.Push(c1);
    stack.Push(c2);
    CHECK_EQ(stack.Top(), c2);
    stack.Pop();
    CHECK_EQ(stack.Top(), c1);
    stack.Pop();
    CHECK(stack.IsEmpty());
}

TEST_CASE("Push and Pop with resizing") {
    StackArrT<Complex> stack;
    Complex value;
    for (ptrdiff_t i = 0; i < 1000; ++i) {
        value = Complex(i, i);
        stack.Push(value);
    }
    for (ptrdiff_t i = 999; i >= 0; --i) {
        CHECK_EQ(stack.Top(), Complex(i, i));
        stack.Pop();
    }
    CHECK(stack.IsEmpty());
}

TEST_CASE("Push and Pop with resizing and copy") {
    StackArrT<Complex> stack;
    Complex value;
    for (ptrdiff_t i = 0; i < 1000; ++i) {
        value = Complex(i, i);
        stack.Push(value);
    }
    StackArrT<Complex> stack2(stack);
    for (ptrdiff_t i = 999; i >= 0; --i) {
        CHECK_EQ(stack.Top(), Complex(i, i));
        CHECK_EQ(stack2.Top(), Complex(i, i));
        stack.Pop();
        stack2.Pop();
    }
    CHECK(stack.IsEmpty());
    CHECK(stack2.IsEmpty());
}

TEST_CASE("Push and Pop with resizing and assignment") {
    StackArrT<Complex> stack;
    Complex value;
    for (ptrdiff_t i = 0; i < 1000; ++i) {
        value = Complex(i, i);
        stack.Push(value);
    }
    StackArrT<Complex> stack2;
    stack2 = stack;
    for (ptrdiff_t i = 999; i >= 0; --i) {
        CHECK_EQ(stack.Top(), Complex(i, i));
        CHECK_EQ(stack2.Top(), Complex(i, i));
        stack.Pop();
        stack2.Pop();
    }
    CHECK(stack.IsEmpty());
    CHECK(stack2.IsEmpty());
}