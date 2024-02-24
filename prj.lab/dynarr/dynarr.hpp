#pragma once
#ifndef DYNARR_DYNARR_HPP_20231203
#define DYNARR_DYNARR_HPP_20231203

#include <cstddef>

class Dynarr {
private:
	std::ptrdiff_t size_ = 0;
	float* data_ = 0;
	std::ptrdiff_t capacity_ = 0;
public:
	Dynarr();
	~Dynarr();
	Dynarr(const Dynarr&);
	Dynarr(const std::ptrdiff_t size);
	Dynarr& operator=(const Dynarr&);

	float& operator[](const std::ptrdiff_t idx);

	const float& operator[](const std::ptrdiff_t idx) const { 
		return data_[idx]; 
	}

	std::ptrdiff_t Size() const noexcept {
		return size_;
	}

	void Resize(const std::ptrdiff_t size);

	void Push_back(float val) noexcept;
};

#endif