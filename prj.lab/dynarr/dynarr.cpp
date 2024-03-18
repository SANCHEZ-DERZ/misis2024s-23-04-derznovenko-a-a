#include "dynarr/dynarr.hpp"
#include <algorithm>
#include <stdexcept>

DynArr::DynArr() {
	size_ = 0;
	data_ = nullptr;
	capacity_ = 0;
}


DynArr& DynArr::operator=(const DynArr& arr) {
	if (this != &arr) {
		size_ = arr.size_;
		capacity_ = arr.capacity_;
		std::copy(arr.data_, arr.data_ + arr.size_, data_);
	}
	return *this;
}


DynArr::DynArr(std::ptrdiff_t size) {
	if (size <= 0) {
		throw std::invalid_argument("Error: size cannot be less than zero");
	}
	else {
		size_ = size;
		capacity_ = size_ * 2;
		data_ = new float[size_] {};
	}
}

DynArr::DynArr(const DynArr& rhs) {
	size_ = rhs.size_;
	capacity_ = rhs.size_;
	data_ = nullptr;
	data_ = new float[rhs.size_];
	std::copy(rhs.data_, rhs.data_ + size_, data_);
}

DynArr::~DynArr() {
	if (data_) {
		delete[] data_;
		data_ = nullptr;
	}
}

void DynArr::Resize(const std::ptrdiff_t size) {
	if (size <= 0) {
		throw std::invalid_argument("Size should be positive number");
	}
	if (size < size_) {
		size_ = size;
	}
	else {
		float* buf = new float[size];
		std::copy(data_, data_ + size_, buf);
		std::swap(data_, buf);
		capacity_ = size;
		size_ = capacity_;
	}
}

float& DynArr::operator[](std::ptrdiff_t idx) {
	if (idx >= size_ || 0 > idx) {
		throw std::out_of_range("index out of range");
	}
	return data_[idx];
}

const float& DynArr::operator[](const ptrdiff_t idx) const {
	if (idx >= size_ || 0 > idx) {
		throw std::out_of_range("index out of range");
	}
	return data_[idx];
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



