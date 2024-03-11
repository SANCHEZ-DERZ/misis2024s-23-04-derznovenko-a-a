#pragma once
#ifndef QUEUELST_QUEUELST_HPP_20240220
#define QUEUELST_QUEUELST_HPP_20240220

#include <cstddef>
#include "complex/complex.hpp"
#include <vector>
#include <algorithm>

class QueueLst {
public:
	QueueLst();

	QueueLst(const QueueLst& que);

	~QueueLst();

	QueueLst& operator=(const QueueLst& que);

	bool IsEmpty() const noexcept;

	void Pop() noexcept;

	void Push(const Complex& val);

	Complex& Top();

	void Clear() noexcept;

private:
	struct Node {
		Complex item;
		Node* next = nullptr;
	};
	Node* head_ = nullptr;
	std::ptrdiff_t size_ = 0;
	Node* tail_ = nullptr;
};

#endif // !STACKARR_STACKARR_HPP_20240203