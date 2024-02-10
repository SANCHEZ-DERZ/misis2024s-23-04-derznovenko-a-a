#include "dynarr/dynarr.hpp"
#include <iostream>

Dynarr::Dynarr() {
	size_ = 0;
	data_ = nullptr;
	capacity_ = 0;
}

Dynarr::Dynarr(std::ptrdiff_t size) {
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
			data_ = 0;
			size_ = 0;
			capacity_ = 0;
		}
	}
}

Dynarr::Dynarr(const Dynarr& rhs) {
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

Dynarr::~Dynarr() {
	if (data_) {
		delete[] data_;
	}
}

void Dynarr::Resize(const std::ptrdiff_t size) {
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

float& Dynarr::operator[](std::ptrdiff_t idx) {
	if (idx >= size_ || 0 > idx) {
		throw std::out_of_range("index out of range");
	}
	return data_[idx];
}

void Dynarr::Push_back(float val) noexcept {
	Dynarr::Resize(size_ + 1);
	data_[size_ - 1] = val;
}


