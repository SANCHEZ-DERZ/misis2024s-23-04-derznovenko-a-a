#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stackarrt/stackarrt.hpp"
#include "complex/complex.hpp"
#include <string>
#include <vector>

template <typename T>
void appender(std::vector<T>& vec, int size) {
    T obj{ 1 };
    for (int i = 0; i < size; i++) {
        vec.push_back(obj + i);
    }
}

template<>
void appender(std::vector<std::string>& vec, int size) {
    for (int i = 0; i < size; i++) {
        vec.push_back(std::to_string(i));
    }
}

TEST_CASE_TEMPLATE("Constructor", T, int, double, std::string, Complex) {
    StackArrT<T> stack;
    CHECK(stack.IsEmpty());
}

TEST_CASE_TEMPLATE("Push", T, int, double, std::string, Complex) {
    StackArrT<T> stack;
    std::vector<T> vec;
    appender(vec, 3);
    //T c(1);
    for (int i = 0; i < vec.size(); i++) {
        stack.Push(vec[i]);
    }
    CHECK_FALSE(stack.IsEmpty());
    for (int i = 0; i < vec.size(); i++) {
        CHECK_EQ(stack.Top(), vec[vec.size() - 1 - i]);
        stack.Pop();
    }
}

TEST_CASE_TEMPLATE("Pop", T, int, double, std::string, Complex) {
    StackArrT<T> stack;
    std::vector<T> vec;
    appender(vec, 3);
    stack.Push(c);
    stack.Pop();
    CHECK(stack.IsEmpty());
}

TEST_CASE_TEMPLATE("Copy constructor", T, int, double, std::string, Complex) {
    StackArrT<T> stack;
    T c{ 1 };
    stack.Push(c);
    StackArrT<T> stack2(stack);
    CHECK_FALSE(stack.IsEmpty());
    CHECK_FALSE(stack2.IsEmpty());
    CHECK_EQ(stack.Top(), c);
    CHECK_EQ(stack2.Top(), c);
    stack.Pop();
    CHECK(stack.IsEmpty());
    CHECK_FALSE(stack2.IsEmpty());
    CHECK_EQ(stack2.Top(), c);
}

TEST_CASE_TEMPLATE("Assignment operator", T, int, double, std::string, Complex) {
    StackArrT<T> stack;
    T c(1);
    stack.Push(c);
    StackArrT<T> stack2;
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

TEST_CASE_TEMPLATE("Clear", T, int, double, std::string, Complex) {
    StackArrT<T> stack;
    T c(1);
    stack.Push(c);
    stack.Clear();
    CHECK(stack.IsEmpty());
}

TEST_CASE_TEMPLATE("Push and Pop", T, int, double, std::string, Complex) {
    StackArrT<T> stack;
    T c1(1);
    T c2(3);
    stack.Push(c1);
    stack.Push(c2);
    CHECK_EQ(stack.Top(), c2);
    stack.Pop();
    CHECK_EQ(stack.Top(), c1);
    stack.Pop();
    CHECK(stack.IsEmpty());
}

TEST_CASE_TEMPLATE("Push and Pop with resizing", T, int, double, std::string, Complex) {
    StackArrT<T> stack;
    T value;
    for (int i = 0; i < 1000; ++i) {
        value = T(i);
        stack.Push(value);
    }
    for (ptrdiff_t i = 999; i >= 0; --i) {
        CHECK_EQ(stack.Top(), T(i));
        stack.Pop();
    }
    CHECK(stack.IsEmpty());
}

TEST_CASE_TEMPLATE("Push and Pop with resizing and copy", T, int, double, std::string, Complex) {
    StackArrT<T> stack;
    T value;
    for (int i = 0; i < 1000; ++i) {
        value = T(i);
        stack.Push(value);
    }
    StackArrT<T> stack2(stack);
    for (int i = 999; i >= 0; --i) {
        CHECK_EQ(stack.Top(), T(i));
        CHECK_EQ(stack2.Top(), T(i));
        stack.Pop();
        stack2.Pop();
    }
    CHECK(stack.IsEmpty());
    CHECK(stack2.IsEmpty());
}

TEST_CASE_TEMPLATE("Push and Pop with resizing and assignment", T, int, double, std::string, Complex) {
    StackArrT<T> stack;
    T value;
    for (int i = 0; i < 1000; ++i) {
        value = T(i);
        stack.Push(value);
    }
    StackArrT<T> stack2;
    stack2 = stack;
    for (int i = 999; i >= 0; --i) {
        CHECK_EQ(stack.Top(), T(i));
        CHECK_EQ(stack2.Top(), T(i));
        stack.Pop();
        stack2.Pop();
    }
    CHECK(stack.IsEmpty());
    CHECK(stack2.IsEmpty());
}
