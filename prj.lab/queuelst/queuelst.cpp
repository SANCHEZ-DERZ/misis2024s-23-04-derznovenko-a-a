#include "queuelst/queuelst.hpp"
#include <stdexcept>

QueueLst::QueueLst() {
	size_ = 0;
	head_ = nullptr;
	tail_ = nullptr;
}


bool QueueLst::IsEmpty() const noexcept {
	if (head_ == nullptr) {
		return true;
	}
	else {
		return false;
	}
}


Complex& QueueLst::Top() {
	if (head_ != nullptr) {
		return head_->item;
	}
	else {
		throw std::logic_error("QueueLst - trying to get top from empty queue.");
	}
}


const Complex& QueueLst::Top() const {
	if (head_ != nullptr) {
		return head_->item;
	}
	else {
		throw std::logic_error("QueueLst - trying to get top from empty queue.");
	}
}


void QueueLst::Pop() noexcept {
	if (head_ != nullptr) {
		if (head_ != tail_) {
			Node* new_head = head_;
			head_ = head_->next;
			delete new_head;
			size_ -= 1;
		}
		else {
			delete head_;
			tail_ = nullptr;
			head_ = nullptr;
			size_ -= 1;
		}
	}
}


void QueueLst::Clear() noexcept {
	while (!IsEmpty()) {
		Pop();
	}
	size_ = 0;
}


void QueueLst::Push(const Complex& val) {
	if (head_ == nullptr) {
		tail_ = new Node{ val };
		head_ = tail_;
	}
	else {
		tail_->next = new Node{ val };
		tail_ = tail_->next;
	}
	size_ += 1;
}


QueueLst::~QueueLst() {
	Clear();
}


QueueLst::QueueLst(const QueueLst& other) {
	Node* current = other.head_;
	while (current) {
		Push(current->item);
		current = current->next;
	}
}


QueueLst& QueueLst::operator=(const QueueLst& que) {
	if (this != &que) {
		Clear();
		Node* current = que.head_;
		while (current) {
			Push(current->item);
			current = current->next;
		}
	}
	return *this;
}