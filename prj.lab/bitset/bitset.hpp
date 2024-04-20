#pragma once
#ifndef BITSET_MISIS_HPP
#define BITSET_MISIS_HPP

#include <cstdint>
#include <iosfwd>
#include <vector>

class BitSet {
public:
	BitSet() = default;

	BitSet(const BitSet&);

	BitSet(BitSet&&) noexcept;

	BitSet(const std::int32_t);

	BitSet& operator=(const BitSet&);

	BitSet& operator=(BitSet&&) noexcept;

	~BitSet() = default;

	[[nodiscard]] bool operator==(const BitSet& rhs) const noexcept;

	[[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept;

	int32_t Size() const noexcept { return size_; }

	void Resize(const int32_t size); // 0 < size

	[[nodiscard]] bool Get(const int32_t idx) const;

	void Set(const int32_t idx, const bool val);

	void Fill(const bool val) noexcept;

	[[nodiscard]] BitSet& operator&=(const BitSet& rhs);

	[[nodiscard]] BitSet& operator|=(const BitSet& rhs);

	[[nodiscard]] BitSet& operator^=(const BitSet& rhs);

	[[nodiscard]] BitSet operator~();

	class BIA {
	public:
		BIA() = delete;
		BIA(BitSet& bitset, const uint32_t idx) : bitset_{ bitset }, idx_{ idx } {};
		BIA operator=(const BIA);
		BIA operator=(const bool val);
		operator bool() const;
		~BIA() = default;
	private:
		BitSet& bitset_;
		uint32_t idx_ = 0;
	};

	BIA operator[](const int32_t);
	const bool operator[](const std::int32_t idx) const;
	// std::ostream& WriteTxt(std::ostream&)
	// std::ostream& WriteBinary(std::ostream&)
	// std::istream& ReadTxt(std::istream&)
	// std::istream& ReadBinary(std::istream&)
private:
	std::int32_t size_ = 0;
	std::vector<uint32_t> bits_;
};

// std::ostream& operaror<<(std::ostream&, const BitSet&);
// std::istream& operaror>>(std::istream&, BitSet&);

[[nodiscard]] BitSet operator&(const BitSet& lhs, const BitSet& rhs);

[[nodiscard]] BitSet operator|(const BitSet& lhs, const BitSet& rhs);

[[nodiscard]] BitSet operator^(const BitSet& lhs, const BitSet& rhs);

#endif
