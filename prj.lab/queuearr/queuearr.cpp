#include "queuearr/queuearr.hpp"
#include <algorithm>
#include <stdexcept>


QueueArr::QueueArr() {
	head_ = -1;
	tail_ = -1;
	size_ = 0;
	data_ = nullptr;
	capacity_ = 0;
}


QueueArr::~QueueArr() {
	delete[] data_;
	data_ = nullptr;
}


void QueueArr::Clear() noexcept {
	size_ = 0;
	head_ = -1;
	tail_ = -1;
	capacity_ = 0;
}


bool QueueArr::IsEmpty() const noexcept {
	return head_ < 0;
}


Complex& QueueArr::Top() {
	if (head_ != -1) {
		return data_[head_];
	}
	else {
		throw std::logic_error("Trying to get top from empty queue.");
	}
}


void QueueArr::Push(const Complex& val) {
	if (data_ != nullptr) {
		if (capacity_ > size_) {
			size_ += 1;
			tail_ += 1;
			data_[tail_] = val;
		}
		else {
			tail_ += 1;
			size_ += 1;
			capacity_ = size_ * 2;
			Complex* new_data = new Complex[capacity_];
			for (int i = 0; i < size_; i++) {
				new_data[i] = data_[i];
			}
			delete[] data_;
			data_ = new_data;
			data_[tail_] = val;
		}
	}
	else {
		size_ = 1;
		capacity_ = size_ * 2;
		tail_ = 0;
		head_ = 0;
		data_ = new Complex[capacity_];
		data_[tail_] = val;
	}
}


void QueueArr::Pop() noexcept {
	if (data_ != nullptr) {
		if (head_ != tail_) {
			head_ += 1;
		}
		else {
			head_ = -1;
			tail_ = -1;
		}
		size_ -= 1;
	}
}


QueueArr::QueueArr(const QueueArr& que) {
	size_ = que.size_;
	tail_ = que.tail_;
	head_ = que.head_;
	capacity_ = que.capacity_;
	data_ = new Complex[capacity_];
	std::copy(que.data_, que.data_ + que.capacity_, data_);
}


QueueArr& QueueArr::operator=(const QueueArr& rhs) {
	if (this != &rhs) {
		delete[] data_;
		size_ = rhs.size_;
		capacity_ = rhs.capacity_;
		head_ = rhs.head_;
		tail_ = rhs.tail_;
		data_ = new Complex[capacity_];
		for (std::size_t i = 0; i < size_; ++i) {
			data_[i] = rhs.data_[i + head_];
		}
		tail_ = tail_ - head_;
		head_ = 0;
	}
	return *this;
}


QueueArr::QueueArr(QueueArr&& rhs) noexcept {
	std::swap(head_, rhs.head_);
	std::swap(tail_, rhs.tail_);
	std::swap(data_, rhs.data_);
	std::swap(size_, rhs.size_);
	std::swap(capacity_, rhs.capacity_);
	rhs.head_ = 0;
	rhs.tail_ = 0;
	rhs.data_ = nullptr;
	rhs.size_ = 0;
	rhs.capacity_ = 0;
}


QueueArr& QueueArr::operator=(QueueArr&& rhs) noexcept {
	if (this != &rhs) {
		std::swap(head_, rhs.head_);
		std::swap(tail_, rhs.tail_);
		std::swap(data_, rhs.data_);
		std::swap(size_, rhs.size_);
		std::swap(capacity_, rhs.capacity_);
		rhs.head_ = 0;
		rhs.tail_ = 0;
		rhs.data_ = nullptr;
		rhs.size_ = 0;
		rhs.capacity_ = 0;
	}
	return *this;
}