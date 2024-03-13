#include "queuelst/queuelst.hpp"


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


void QueueLst::Pop() noexcept {
	if (head_ != nullptr) {
		Node* new_head = head_;
		head_ = head_->next;
		delete new_head;
	}
	else {
		tail_ = nullptr;
	}
	size_ -= 1;
}


void QueueLst::Clear() noexcept {
	while (head_ != nullptr) {
		this->Pop();
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
	this->Clear();
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