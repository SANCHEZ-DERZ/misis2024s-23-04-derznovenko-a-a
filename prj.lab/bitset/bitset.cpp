#include "bitset/bitset.hpp"
#include <stdexcept>
#define MAX 2147483648

bool BitSet::Get(const int32_t idx) const {
	if (size_ > 0 && idx < size_ * 32 && idx * 32 >= 0) {
		std::int32_t num_idx = idx / 32;
		std::int32_t idx_in_num = idx - num_idx * 32;
		std::uint32_t finder = MAX >> idx_in_num;
		bool bit = false;
		bit = bits_[num_idx] & finder;
		return bit;
	}
	else {
		throw std::out_of_range("List index out of range.");
	}
}


BitSet::BitSet(const std::int32_t size) {
	size_ = size;
	bits_.resize(size_);
}


void BitSet::Resize(const std::int32_t size) {
	if (size > 0) {
		size_ = size;
		bits_.resize(size_);
	}
	else {
		throw std::invalid_argument("Argument cannot be less than zero");
	}
}


BitSet::BitSet(const BitSet& bs) {
	size_ = bs.size_;
	bits_ = bs.bits_;
}


BitSet::BitSet(BitSet&& bs) noexcept {
	size_ = bs.size_;
	bits_ = bs.bits_;
	bs.size_ = 0;
	bs.bits_.resize(0);
}


BitSet& BitSet::operator=(const BitSet& bs) {
	if (this != &bs) {
		size_ = bs.size_;
		bits_ = bs.bits_;
	}
	return *this;
}


BitSet& BitSet::operator=(BitSet&& bs) noexcept {
	if (this != &bs) {
		size_ = bs.size_;
		bits_ = bs.bits_;
		bs.size_ = 0;
		bs.bits_.resize(0);
	}
	return *this;
}


bool BitSet::operator==(const BitSet& rhs) const noexcept {
	return bits_ == rhs.bits_;
}


bool BitSet::operator!=(const BitSet& rhs) const noexcept {
	return bits_ != rhs.bits_;
}


void BitSet::Set(const int32_t idx, const bool val) {
	if (size_ > 0 && idx < size_ * 32 && idx * 32 >= 0) {
		std::int32_t num_idx = idx / 32;
		std::int32_t idx_in_num = idx - num_idx * 32;
		std::uint32_t finder = MAX >> idx_in_num;;
		if (val == true) {
			finder = MAX >> idx_in_num;
			bits_[num_idx] = bits_[num_idx] | finder;
		}
		else {
			bits_[num_idx] = bits_[num_idx] & ~finder;
		}
	}
	else {
		throw std::out_of_range("List index out of range.");
	}
}


void BitSet::Fill(const bool val) noexcept {
	if (val == 1) {
		for (int i = 0; i < size_; i++) {
			bits_[i] = 4294967295;
		}
	}
	else {
		for (int i = 0; i < size_; i++) {
			bits_[i] = 0;
		}
	}
}


/*BitSet BitSet::operator~() {
	if (size_ == 0) {
		throw std::invalid_argument("Operator~ is not usable for empty bitset.");
	}
	else {
		for (int i = 0; i < size_ * 32; i++) {
			if (Get(i) == 1) {
				Set(i, 0);
			}
			else {
				Set(i, 1);
			}
		}
	}
}
*/


/*BitSet& BitSet::operator&=(const BitSet& rhs) {
	for (int i)
}
*/