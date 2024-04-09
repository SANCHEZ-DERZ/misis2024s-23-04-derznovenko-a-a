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
	std::ptrdiff_t size_ = 0;   //!< число элементов в буфере
	std::ptrdiff_t i_top_ = -1; //!< индекс top элемента
	T* data_ = nullptr;   //!< элементы стека
};

template <typename T>
StackArrT<T>::StackArrT(const StackArrT& arr) {
	i_top_ = arr.i_top_;
	size_ = arr.size_;
	data_ = new Complex[size_];
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
StackArrT<T>& StackArrT<T>::operator=(const StackArrT& arr) {
	if (this != &arr) {
		size_ = arr.size_;
		i_top_ = arr.i_top_;
		delete[] data_;
		data_ = new Complex[size_]{};
		for (int i = 0; i < size_; i++) {
			data_[i] = arr.data_[i];
		}
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
	if (data_ != nullptr) {
		if (size_ > i_top_ + 1) {
			data_[i_top_ + 1] = val;
			i_top_ += 1;
		}
		else {
			i_top_ += 1;
			size_ = i_top_ * 2;
			Complex* new_data = new Complex[size_];
			for (int i = 0; i < size_; i++) {
				new_data[i] = data_[i];
			}
			delete[] data_;
			data_ = new_data;
			data_[i_top_] = val;
		}
	}
	else {
		i_top_ += 1;
		size_ = 8;
		data_ = new Complex[size_];
		data_[i_top_] = val;
	}
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