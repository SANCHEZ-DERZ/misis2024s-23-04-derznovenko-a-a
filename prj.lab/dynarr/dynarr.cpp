#include "dynarr/dynarr.hpp"
#include <algorithm>
#include <stdexcept>



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
		capacity_ = (capacity_ > 2 * size_ ? capacity_ : 2 * size_);
		data_ = new float[capacity_];
		for (int i = 0; i < size_; i++) {
			data_[i] = 0;
		}
	}
}

DynArr::DynArr(const DynArr& rhs) {
	if (rhs.size_ <= 0) {
		throw std::invalid_argument("It is impossible to create an array of this size");
	}
	else {
		data_ = nullptr;
		capacity_ = rhs.capacity_;
		size_ = rhs.size_;
		data_ = new float[capacity_];
		std::copy(rhs.data_, rhs.data_ + rhs.capacity_, data_);
	}
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
	else {
		if (size <= size_) {
			size_ = size;
		}
		else {
			if (size <= capacity_) {
				for (std::ptrdiff_t i = size_; i < size; i++) {
					data_[i] = 0;
				}
				size_ = size;
			}
			else {
				capacity_ = size * 2;
				float* new_data = new float[capacity_];
				for (std::ptrdiff_t i = 0; i < size; i++) {
					new_data[i] = 0;
				}
				for (std::ptrdiff_t i = 0; i < size_; i++) {
					new_data[i] = data_[i];
				}
				size_ = size;
				delete[] data_;
				data_ = new_data;
			}
		}
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



