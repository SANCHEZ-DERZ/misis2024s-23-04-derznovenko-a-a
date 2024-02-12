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
	i_top_
}
