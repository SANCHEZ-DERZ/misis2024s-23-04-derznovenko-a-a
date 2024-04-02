#include "stackarr/stackarr.hpp"
#include <algorithm>


StackArr::StackArr() {
	size_ = 0;
	i_top_ = -1;
	data_ = nullptr;
}


StackArr::StackArr(const StackArr& arr) {
	i_top_ = arr.i_top_;
	size_ = arr.size_;
	data_ = new Complex[size_];
	std::copy(arr.data_, arr.data_ + arr.size_, data_);
}


StackArr::StackArr(StackArr&& rhs) noexcept {
	std::swap(i_top_, rhs.i_top_);
	std::swap(size_, rhs.size_);
	std::swap(data_, rhs.data_);
}


StackArr::~StackArr() {
	delete[] data_;
}


StackArr& StackArr::operator=(const StackArr& arr) {
	if (this != &arr) {
		size_ = arr.size_;
		i_top_ = arr.i_top_;
		delete[] data_;
		data_ = new Complex[size_]{};
		for (int i = 0; i < size_; i++) {
			data_[i] = arr.data_[i];
		}
	}
	return *this;
}


StackArr& StackArr::operator=(StackArr&& rhs) noexcept {
	if (this != &rhs) {
		std::swap(i_top_, rhs.i_top_);
		std::swap(size_, rhs.size_);
		std::swap(data_, rhs.data_);
	}
	return *this;
}


bool StackArr::IsEmpty() const noexcept {
	return i_top_ < 0;
}


Complex& StackArr::Top() {
	if (i_top_ == -1) {
		throw std::out_of_range("Stack is empty");
	}
	else {
		return data_[i_top_];
	}
}


void StackArr::Push(const Complex& val) {
	if (data_ != nullptr) {
		if (size_ > i_top_ + 1) {
			data_[i_top_ + 1] = val;
			i_top_ += 1;
		}
		else {
			i_top_ += 1;
			size_ = i_top_ * 2;
			Complex* new_data = new Complex[size_];
			for (int i = 0; i < size_; i++) {
				new_data[i] = data_[i];
			}
			delete[] data_;
			data_ = new_data;
			data_[i_top_] = val;
		}
	}
	else {
		i_top_ += 1;
		size_ = 8;
		data_ = new Complex[size_];
		data_[i_top_] = val;
	}
}


void StackArr::Pop() noexcept {
	if (!IsEmpty()) {
		i_top_ -= 1;
	}
}


void StackArr::Clear() noexcept {
	i_top_ = -1;
}


const Complex& StackArr::Top() const {
	if (i_top_ == -1) {
		throw std::out_of_range("Stack is empty");
	}
	else {
		return data_[i_top_];
	}
}