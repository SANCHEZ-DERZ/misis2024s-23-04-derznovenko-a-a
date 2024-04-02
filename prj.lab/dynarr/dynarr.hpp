#pragma once
#ifndef DYNARR_DYNARR_HPP_20231203
#define DYNARR_DYNARR_HPP_20231203

#include <cstddef>

class DynArr {

private:
	std::ptrdiff_t size_ = 0;
	float* data_ = nullptr;
	std::ptrdiff_t capacity_ = 0;

public:
	DynArr() = default;
	~DynArr();
	DynArr(const DynArr&);
	DynArr(const std::ptrdiff_t size);
	DynArr(DynArr&&) noexcept;
	DynArr& operator=(const DynArr&);
	DynArr& operator=(DynArr&&) noexcept;

	float& operator[](const std::ptrdiff_t idx);

	const float& operator[](const std::ptrdiff_t idx) const;

	std::ptrdiff_t Size() const noexcept {
		return size_;
	}

	void Resize(const std::ptrdiff_t size);
};

#endif