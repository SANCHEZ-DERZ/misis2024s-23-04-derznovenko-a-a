#include "stacklst/stacklst.hpp"


StackLst::StackLst() {
	head_ = nullptr;
	size_ = 0;
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
	if (head_ != nullptr) {
		if (head_->next != nullptr) {
			Node* new_head = head_;
			head_ = head_->next;
			delete new_head;
			size_ -= 1;
		}
		else {
			delete head_;
			head_ = nullptr;
			size_ -= 1;
		}
	}
}


void StackLst::Push(const Complex& val) {
	Node* new_head = new Node;
	new_head->item = val;
	if (head_ != nullptr) {
		new_head->next = head_;
	}
	head_ = new_head;
	size_ += 1;
}


void StackLst::Clear() noexcept {
	while (head_ != nullptr) {
		this->Pop();
	}
	size_ = 0;
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
	if (this != &lst) {
		StackLst new_lst;
		Node* new_head = lst.head_;
		for (int i = 0; i < lst.size_; i++) {
			new_lst.Push(new_head->item);
			new_head = new_head->next;
		}
		for (int i = 0; i < lst.size_; i++) {
			this->Push(new_head->item);
			new_head = new_head->next;
		}
	}
	return *this;
}

StackLst::~StackLst() {
	Clear();
}


StackLst::StackLst(const StackLst& lst) {
	size_ = lst.size_;
	Node* new_head = lst.head_;
	for (int i = 0; i < size_; i++) {
		this->Push(new_head->item);
		new_head = head_->next;
	}
}