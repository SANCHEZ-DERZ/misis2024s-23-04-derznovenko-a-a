#pragma once
#ifndef STACKARR_STACKARR_HPP_20240203
#define STACKARR_STACKARR_HPP_20240203

#include <cstddef>
#include "complex/complex.hpp"

class StackLst {
public:
	StackLst();

	StackLst(const StackLst& lst);

	~StackLst();

	StackLst& operator=(const StackLst& lst);

	bool IsEmpty() const noexcept;

	void Pop() noexcept;

	void Push(const Complex& val);

	Complex& Top();

	const Complex& Top() const;

	void Clear() noexcept;

private:
	struct Node {
		Complex item;
		Node* next = nullptr;
	};
	Node* head_ = nullptr;
	std::ptrdiff_t size_ = 0;
};

#endif // !STACKARR_STACKARR_HPP_20240203