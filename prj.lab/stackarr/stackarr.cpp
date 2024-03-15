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


StackArr::~StackArr() {
	if (data_) {
		delete[] data_;
	}
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


bool StackArr::IsEmpty() const noexcept {
	if (i_top_ == -1) {
		return true;
	}
	else {
		return false;
	}
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
		size_ += 1;
		i_top_ += 1;
		data_ = new Complex[size_];
		data_[i_top_] = val;
	}
}


void StackArr::Pop() noexcept {
	if (size_ != 0) {
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