#include "bitset/bitset.hpp"
#include <stdexcept>
#define MAX 2147483648
#define BIT_32 32

bool BitSet::Get(const int32_t idx) const {
	if (size_ > 0 && idx < size_ * BIT_32 && idx * BIT_32 >= 0) {
		std::int32_t num_idx = idx / BIT_32;
		std::int32_t idx_in_num = idx - num_idx * BIT_32;
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
	if (size_ > 0 && idx < size_ * BIT_32 && idx * BIT_32 >= 0) {
		std::int32_t num_idx = idx / BIT_32;
		std::int32_t idx_in_num = idx - num_idx * BIT_32;
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


BitSet BitSet::operator~() {
	BitSet new_bs(size_);
	for (int i = 0; i < size_; i++) {
		new_bs.bits_[i] = ~bits_[i];
	}
	return new_bs;
}



BitSet& BitSet::operator&=(const BitSet& rhs) {
	if (size_ != rhs.size_) {
		throw std::invalid_argument("Bitsets must have the same sizes.");
	}
	else {
		for (int i = 0; i < size_; i++) {
			bits_[i] = bits_[i] & rhs.bits_[i];
		}
		return *this;
	}
}


BitSet& BitSet::operator|=(const BitSet& rhs) {
	if (size_ != rhs.size_) {
		throw std::invalid_argument("Bitsets must have the same sizes.");
	}
	else {
		for (int i = 0; i < size_; i++) {
			bits_[i] = bits_[i] | rhs.bits_[i];
		}
		return *this;
	}
}


BitSet& BitSet::operator^=(const BitSet& rhs) {
	if (size_ != rhs.size_) {
		throw std::invalid_argument("Bitsets must have the same sizes.");
	}
	else {
		for (int i = 0; i < size_; i++) {
			bits_[i] = bits_[i] ^ rhs.bits_[i];
		}
		return *this;
	}
}


BitSet operator&(const BitSet& lhs, const BitSet& rhs) {
	if (lhs.Size() != rhs.Size()) {
		throw std::invalid_argument("Bitsets must have the same sizes.");
	}
	else {
		BitSet result(lhs);
		return result &= rhs;
	}
}


BitSet operator|(const BitSet& lhs, const BitSet& rhs) {
	if (lhs.Size() != rhs.Size()) {
		throw std::invalid_argument("Bitsets must have the same sizes.");
	}
	else {
		BitSet result(lhs);
		return result |= rhs;
	}
}


BitSet operator^(const BitSet& lhs, const BitSet& rhs) {
	if (lhs.Size() != rhs.Size()) {
		throw std::invalid_argument("Bitsets must have the same sizes.");
	}
	else {
		BitSet result(lhs);
		return result ^= rhs;
	}
}


BitSet::BIA::operator bool() const {
	return bitset_.Get(idx_);
}


BitSet::BIA BitSet::BIA::operator=(const BIA rhs) {
	bitset_.Set(idx_, rhs.bitset_.Get(rhs.idx_));
	return *this;
}


BitSet::BIA BitSet::BIA::operator=(const bool val) {
	bitset_.Set(idx_, val);
	return *this;
}


BitSet::BIA BitSet::operator[](const std::int32_t idx) {
	if (idx >= 0 && idx < size_) {
		BIA BIA(*this, idx);
		return BIA;
	}
	else {
		throw(std::logic_error("Wrong idx\n"));
	}
}


const bool BitSet::operator[](const std::int32_t idx) const {
	if (idx >= 0 && idx < size_) {
		return Get(idx);
	}
	else {
		throw(std::logic_error("Wrong idx\n"));
	}
}