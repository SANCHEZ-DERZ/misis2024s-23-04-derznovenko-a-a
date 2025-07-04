#pragma once
#ifndef StackArrT_StackArrT_HPP_20240203
#define StackArrT_StackArrT_HPP_20240203

#include <cstddef>

template <class T>
class StackArrT {
public:
	StackArrT() = default;

	StackArrT(const StackArrT&);

	StackArrT(StackArrT&&) noexcept;

	~StackArrT();

	StackArrT& operator=(const StackArrT&);

	StackArrT& operator=(StackArrT&&) noexcept;

	bool IsEmpty() const noexcept;

	void Pop() noexcept;

	void Push(const T& val);

	T& Top();

	const T& Top() const;

	void Clear() noexcept;

private:
	std::ptrdiff_t size_ = 0;   //!< ����� ��������� � ������
	std::ptrdiff_t i_top_ = -1; //!< ������ top ��������
	T* data_ = nullptr;   //!< �������� �����
};

template <typename T>
StackArrT<T>::StackArrT(const StackArrT& arr) {
	i_top_ = arr.i_top_;
	size_ = arr.size_;
	data_ = new T[size_];
	std::copy(arr.data_, arr.data_ + arr.size_, data_);
}

template <typename T>
StackArrT<T>::StackArrT(StackArrT&& rhs) noexcept {
	std::swap(i_top_, rhs.i_top_);
	std::swap(size_, rhs.size_);
	std::swap(data_, rhs.data_);
}

template <typename T>
StackArrT<T>::~StackArrT() {
	delete[] data_;
}

template <typename T>
StackArrT<T>& StackArrT<T>::operator=(const StackArrT& st) {
	if (this != &st) {
		if (st.IsEmpty()) {
			Clear();
		}
		if (size_ <= st.i_top_) {
			size_ = (st.i_top_ + 4) / 4 * 4;
			T* buf = new T[size_];
			std::swap(data_, buf);
			delete[] buf;
		}
		i_top_ = st.i_top_;
		std::copy(st.data_, st.data_ + i_top_ + 1, data_);
	}
	return *this;
}

template <typename T>
StackArrT<T>& StackArrT<T>::operator=(StackArrT&& rhs) noexcept {
	if (this != &rhs) {
		std::swap(i_top_, rhs.i_top_);
		std::swap(size_, rhs.size_);
		std::swap(data_, rhs.data_);
	}
	return *this;
}

template <typename T>
bool StackArrT<T>::IsEmpty() const noexcept {
	return i_top_ < 0;
}

template <typename T>
T& StackArrT<T>::Top() {
	if (i_top_ == -1) {
		throw std::out_of_range("Stack is empty");
	}
	else {
		return data_[i_top_];
	}
}

template <typename T>
void StackArrT<T>::Push(const T& val) {
	if (nullptr == data_) {
		size_ = 1;
		data_ = new T[size_];
	}
	else if (size_ == i_top_ + 1) {
		auto buf = new T[size_ * 2];
		std::copy(data_, data_ + size_, buf);
		std::swap(data_, buf);
		delete[] buf;
		size_ *= 2;
	}
	data_[++i_top_] = val;
}

template <typename T>
void StackArrT<T>::Pop() noexcept {
	if (!IsEmpty()) {
		i_top_ -= 1;
	}
}

template <typename T>
void StackArrT<T>::Clear() noexcept {
	i_top_ = -1;
}

template <typename T>
const T& StackArrT<T>::Top() const {
	if (i_top_ == -1) {
		throw std::out_of_range("Stack is empty");
	}
	else {
		return data_[i_top_];
	}
}


#endif // !StackArrT_StackArrT_HPP_2024020