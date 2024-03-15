#include "queuearr/queuearr.hpp"
#include <algorithm>
#include <stdexcept>


QueueArr::QueueArr() {
	head_ = -1;
	tail_ = -1;
	size_ = 0;
	data_ = nullptr;
}


QueueArr::~QueueArr() {
	delete[] data_;
}


void QueueArr::Clear() noexcept {
	size_ = 0;
	head_ = -1;
	tail_ = -1;
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
		if (size_ > tail_ + 1) {
			data_[tail_ + 1] = val;
			tail_ += 1;
		}
		else {
			tail_ += 1;
			size_ = tail_ * 2;
			Complex* new_data = new Complex[size_];
			for (int i = 0; i < size_; i++) {
				new_data[i] = data_[i];
			}
			delete[] data_;
			data_ = new_data;
			data_[tail_] = val;
		}
	}
	else {
		size_ += 1;
		tail_ += 1;
		head_ = 0;
		data_ = new Complex[size_];
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
	}
}


QueueArr::QueueArr(const QueueArr& que) {
	size_ = que.size_;
	tail_ = que.tail_;
	head_ = que.head_;
	data_ = new Complex[size_];
	std::copy(que.data_, que.data_ + que.size_, data_);
}


QueueArr& QueueArr::operator=(const QueueArr& que) {
	if (this != &que) {
		Complex* new_data = new Complex[que.size_];
		for (int i = 0; i < que.size_; i++) {
			new_data[i] = data_[i];
		}
		data_ = new_data;
		delete[] data_;
		head_ = que.head_;
		tail_ = que.tail_;
	}
	return *this;
}