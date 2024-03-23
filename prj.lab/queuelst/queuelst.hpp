#pragma once
#ifndef QUEUELST_QUEUELST_HPP_20240220
#define QUEUELST_QUEUELST_HPP_20240220

#include <cstddef>
#include "complex/complex.hpp"

class QueueLst {
public:
	QueueLst();

	QueueLst(const QueueLst&);

	QueueLst(QueueLst&&) noexcept;

	~QueueLst();

	QueueLst& operator=(const QueueLst&);

	QueueLst& operator=(QueueLst&&) noexcept;

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
	Node* tail_ = nullptr;
};

#endif