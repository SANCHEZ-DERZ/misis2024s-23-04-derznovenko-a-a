#include "stackarr/stackarr.hpp"


StackArr::StackArr() {
	size_ = 0;
	i_top_ = -1;
	data_ = nullptr;
}


StackArr::StackArr(const StackArr& arr) {
	size_ = arr.size_;
	i_top_ = arr.i_top_;
	data_ = nullptr;
	if (size_ != 0) {
		data_ = new Complex[size_];
	}
	else {
		data_ = 0;
	}
	for (int i = 0; i < size_; i++) {
		data_[i] = arr.data_[i];
	}
}


StackArr::~StackArr() {
	if (data_) {
		delete[] data_;
	}
}


StackArr& StackArr::operator=(const StackArr& arr) {
	size_ = arr.size_;
	i_top_ = arr.i_top_;
	delete[] data_;
	data_ = new Complex[size_]{};
	for (int i = 0; i < size_; i++) {
		data_[i] = arr.data_[i];
	}
	return *this;
}


bool StackArr::IsEmpty() const noexcept {
	if (size_ == 0) {
		return true;
	}
	else {
		return false;
	}
}


Complex& StackArr::Top() {
	if (IsEmpty) {
		throw std::out_of_range("Stack is empty");
	}
	else {
		i_top_ = size_ - 1;
		return data_[i_top_];
	}
}


void StackArr::Push(const Complex& val) {
	if (size_ != 0) {
		size_ += 1;
		Complex* new_data = new Complex[size_]{};
		for (int i = 0; i < size_; i++) {
			new_data[i] = data_[i];
		}
		delete[] data_;
		data_ = new_data;
		data_[size_ - 1] = val;
	}
	else {
		size_ += 1;
		data_ = new Complex[size_];
		data_[0] = val;
	}
}


void StackArr::Pop() noexcept {
}


