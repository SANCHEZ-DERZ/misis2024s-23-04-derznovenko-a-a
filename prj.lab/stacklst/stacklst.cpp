#include "stacklst/stacklst.hpp"


StackLst::StackLst() {
	head_ = nullptr;
	size_ = 0
}


bool StackLst::IsEmpty() const noexcept {
	if (head_ == nullptr) {
		return true;
	}
	else {
		return false;
	}
}


Complex& StackLst::Top() {
	if (head_ != nullptr) {
		return head_->item;
	}
	else {
		throw std::out_of_range("Stack is empty");
	}
}


void StackLst::Pop() noexcept {
	if (head_ != nullptr && next_ != nullptr) {
		Node* new_head = head_;
		head_ = head_ -> next_;
		delete[] new_head;
		size_ -= 1;
	}
	else if (head_ != nullptr && next_ == nullptr) {
		delete[] head_;
		head_ = nullptr;
	}
}


void StackLst::Push(const Complex& val) {
	Node* head = new Complex[];
	head->value = val;
	if (head_ != nullptr) {
		head->next = head_;
	}
	head_ = head;
	size_ += 1;
}


void StackLst::Clear() noexcept {
	if (next_ != nullptr) {
		for (int i = 0; i < size_; i++) {
			*this->Pop();
		}
	}
}


const Complex& StackLst::Top() const {
	if (head_ != nullptr) {
		return head_->item;
	}
	else {
		throw std::out_of_range("Stack is empty");
	}
}


StackLst& StackLst::operator=(const StackLst& lst) {
	StackLst new_lst;
	Node* new_head = lst.head_;
	for (int i = 0; i < lst.size_; i++) {
		new_lst.Push(new_head->item);
		new_head = new_head->next;
	}
	for (int i = 0; i < lst.size_; i++) {
		*this->Push(new_head->item);
		new_head = new_head->next;
	}
	return *this;
}

StackLst::~StackLst() {
	Clear();
}


StackLst::StackLst(const StackLst& lst) {
	StackLst new_lst;
	Node* new_head = lst.head_;
	for (int i = 0; i < lst.size_; i++) {
		new_lst.Push(new_head->item);
		new_head = new_head->next;
	}
	for (int i = 0; i < lst.size_; i++) {
		*this->Push(new_head->item);
		new_head = new_head->next;
	}
}