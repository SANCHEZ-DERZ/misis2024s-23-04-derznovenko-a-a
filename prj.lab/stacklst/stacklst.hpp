#pragma once
#ifndef STACKLST_STACKLST_HPP_20240213
#define STACKLST_STACKLST_HPP_20240213

#include <cstddef>
#include "complex/complex.hpp"

class StackLst {
public:
	StackLst() = default;

	StackLst(const StackLst& lst);

	StackLst(StackLst&&) noexcept;

	~StackLst();

	StackLst& operator=(const StackLst& lst);

	StackLst& operator=(StackLst&&) noexcept;

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

#endif