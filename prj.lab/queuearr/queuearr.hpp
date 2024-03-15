#pragma once
#ifndef QUEUEARR_QUEUEARR_HPP_20240227
#define QUEUEARR_QUEUEARR_HPP_20240227

#include <cstddef>
#include "complex/complex.hpp"

class QueueArr {
public:
	QueueArr();

	QueueArr(const QueueArr&);

	~QueueArr();

	QueueArr& operator=(const QueueArr&);

	bool IsEmpty() const noexcept;

	void Pop() noexcept;

	void Push(const Complex& val);

	Complex& Top();

	void Clear() noexcept;

private:
	std::ptrdiff_t size_ = 0;
	std::ptrdiff_t head_ = -1;
	Complex* data_ = nullptr;
	std::ptrdiff_t tail_ = -1;
	std::ptrdiff_t capacity_ = 0;
};

#endif