#include "dynarr/dynarr.hpp"
#include <iostream>

DynArr::DynArr() {
	size_ = 0;
	data_ = nullptr;
	capacity_ = 0;
}


DynArr& DynArr::operator=(const DynArr& arr) {
	size_ = arr.size_;
	capacity_ = size_ * 2;
	delete[] data_;
	data_ = new float[capacity_] {};
	for (int i = 0; i < size_; i++) {
		data_[i] = arr.data_[i];
	}
	return *this;
}


DynArr::DynArr(std::ptrdiff_t size) {
	if (size < 0) {
		throw std::overflow_error("Error: size cannot be less than zero");
	}
	else {
		size_ = size;
		capacity_ = size_;
		if (size != 0) {
			data_ = new float[size] {};
		}
		else {
			data_ = nullptr;
			size_ = 0;
			capacity_ = 0;
		}
	}
}

DynArr::DynArr(const DynArr& rhs) {
	size_ = rhs.size_;
	capacity_ = size_;
	data_ = nullptr;
	if (size_ != 0) {
		data_ = new float[size_];
	}
	else {
		data_ = 0;
	}
	for (int i = 0; i < size_; i++) {
		data_[i] = rhs.data_[i];
	}
}

DynArr::~DynArr() {
	if (data_) {
		delete[] data_;
	}
}

void DynArr::Resize(const std::ptrdiff_t size) {
	if (capacity_ < size) {
		std::ptrdiff_t new_capacity = 0;
		if (size > size_ * 2) {
			new_capacity = size;
		}
		else {
			new_capacity = size_ * 2;
		}
		float* new_data = new float[new_capacity] {};
		for (int i = 0; i < size_; i++) {
			new_data[i] = data_[i];
		}
		delete[] data_;
		data_ = new_data;
		capacity_ = new_capacity;
	}
	size_ = size;
}

float& DynArr::operator[](std::ptrdiff_t idx) {
	if (idx >= size_ || 0 > idx) {
		throw std::out_of_range("index out of range");
	}
	return data_[idx];
}

const float& DynArr::operator[](const ptrdiff_t idx) const {
	if (idx < 0)
		throw std::invalid_argument("Index shouldn't be a negative number");
	else if (idx >= size_)
		throw std::out_of_range("Index out of range");
	return *(data_ + idx);
}

void DynArr::Push_back(float val) noexcept {
	DynArr::Resize(size_ + 1);
	data_[size_ - 1] = val;
}

DynArr::DynArr(DynArr&& rhs) noexcept {
	std::swap(data_, rhs.data_);
	std::swap(size_, rhs.size_);
	std::swap(capacity_, rhs.capacity_);
	rhs.size_ = 0;
	rhs.data_ = nullptr;
	rhs.capacity_ = 0;
}

DynArr& DynArr::operator=(DynArr&& rhs) noexcept {
	if (this != &rhs) {
		std::swap(data_, rhs.data_);
		std::swap(size_, rhs.size_);
		std::swap(capacity_, rhs.capacity_);
		rhs.size_ = 0;
		rhs.data_ = nullptr;
		rhs.capacity_ = 0;
	}
	return *this;
}



