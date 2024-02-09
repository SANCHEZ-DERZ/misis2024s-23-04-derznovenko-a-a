#include "dynarr/dynarr.hpp"

Dynarr::Dynarr() {
	size_ = 0;
	data_ = nullptr;
}

Dynarr::Dynarr(std::ptrdiff_t size) {
	size_ = size;
	if (size != 0) {
		data_ = new float[size];
	}
	else {
		data_ = 0;
	}
}

Dynarr::Dynarr(const Dynarr& rhs) {
	size_ = rhs.size_;
	data_ = nullptr;
	if (size_ != 0) {
		data_ = new float[size_];
	}
	else {
		data_ = 0;
	}
	for (size_t i = 0; i < size_; i++) {
		data_[i] = rhs.data_[i];
	}
}

Dynarr::~Dynarr() {
	if (data_) {

	}
}