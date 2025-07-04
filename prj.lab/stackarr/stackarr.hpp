#pragma once
#ifndef STACKARR_STACKARR_HPP_20240203
#define STACKARR_STACKARR_HPP_20240203

#include <cstddef>
#include "complex/complex.hpp"

class StackArr {
public:
	StackArr(); 

	StackArr(const StackArr&); 

	StackArr(StackArr&&) noexcept;

	~StackArr();

	StackArr& operator=(const StackArr&);

	StackArr& operator=(StackArr&&) noexcept;

	bool IsEmpty() const noexcept;

	void Pop() noexcept;

	void Push(const Complex& val);

	Complex& Top();

	const Complex& Top() const;

	void Clear() noexcept;

private:
	std::ptrdiff_t size_ = 0;   //!< ����� ��������� � ������
	std::ptrdiff_t i_top_ = -1; //!< ������ top ��������
	Complex* data_ = nullptr;   //!< �������� �����
};

#endif // !STACKARR_STACKARR_HPP_20240203