#pragma once
#ifndef DYNARR_DYNARR_HPP_20231203
#define DYNARR_DYNARR_HPP_20231203

#include <cstddef>

class Dynarr {
private:
	std::ptrdiff_t size_ = 0;
	float* data_ = 0;
public:
	Dynarr() = default;
	~Dynarr() = default;
	Dynarr(const Dynarr&) = default;
	Dynarr(const std::ptrdiff_t size) {
		size_ = size;
	}
	Dynarr& operator=(const Dynarr&) = default;

	float& operator[](const std::ptrdiff_t idx);

	const float& operator[](const std::ptrdiff_t idx) const;

	std::ptrdiff_t Size() const noexcept;

	void Resize(const std::ptrdiff_t size);
};

#endif