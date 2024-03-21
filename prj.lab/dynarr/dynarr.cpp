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
		if (capacity_ > arr.size_) {
			size_ = arr.size_;
			for (int i = 0; i < size_; i++) {
				data_[i] = arr.data_[i];
			}
		}
		else {
			capacity_ = arr.size_ * 2;
			size_ = arr.size_;
			delete[] data_;
			data_ = new float[capacity_];
			for (int i = 0; i < size_; i++) {
				data_[i] = arr.data_[i];
			}
		}
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
		data_ = new float[capacity_] {};
	}
}

DynArr::DynArr(const DynArr& rhs) {
	data_ = nullptr;
	capacity_ = rhs.capacity_;
	size_ = rhs.size_;
	data_ = new float[capacity_];
	std::copy(rhs.data_, rhs.data_ + rhs.capacity_, data_);
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
		float* buf = new float[size * 2] {};
		std::copy(data_, data_ + capacity_, buf);
		std::swap(data_, buf);
		capacity_ = size * 2;
		size_ = size;
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



