#pragma once
#ifndef DYNARR_DYNARR_HPP_20231203
#define DYNARR_DYNARR_HPP_20231203

#include <cstddef>
#include <memory>

class DynArr {

private:
	std::ptrdiff_t size_ = 0;
	float* data_ = 0;
	std::ptrdiff_t capacity_ = 0;

public:
	DynArr();
	~DynArr();
	DynArr(const DynArr&);
	DynArr(const std::ptrdiff_t size);
	DynArr& operator=(const DynArr&);

	float& operator[](const std::ptrdiff_t idx);

	const float& operator[](const std::ptrdiff_t idx) const;

	std::ptrdiff_t Size() const noexcept {
		return size_;
	}

	void Resize(const std::ptrdiff_t size);

	void Push_back(float val) noexcept;
};

#endif