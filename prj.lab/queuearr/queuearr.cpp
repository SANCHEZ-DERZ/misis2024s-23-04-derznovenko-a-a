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


void QueueArr::Pop() noexcept {

}