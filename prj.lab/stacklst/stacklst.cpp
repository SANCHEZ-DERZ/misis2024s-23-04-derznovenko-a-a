	#include "stacklst/stacklst.hpp"


bool StackLst::IsEmpty() const noexcept {
	return head_ == nullptr;
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
		Node* new_head = head_;
		head_ = head_->next;
		delete new_head;
		size_ -= 1;
	}
}


void StackLst::Push(const Complex& val) {
	Node* new_head = new Node;
	new_head->item = val;
	new_head->next = head_;
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


StackLst& StackLst::operator=(const StackLst& other) {
	if (this != &other) {
		Clear();
		if (!other.IsEmpty()) {
			head_ = new Node;
			head_->item = other.head_->item;
			Node* temp = other.head_;
			Node* prev = head_;
			while (temp->next != nullptr) {
				temp = temp->next;
				Node* curr = new Node;
				prev->next = curr;
				curr->item = temp->item;
				prev = curr;
			}
		}
	}
	return *this;
}

StackLst::~StackLst() {
	Clear();
}


StackLst::StackLst(const StackLst& other) {
	if (!other.IsEmpty()) {
		head_ = new Node;
		head_->item = other.head_->item;
		Node* temp = other.head_;
		Node* prev = head_;
		while (temp->next != nullptr) {
			temp = temp->next;
			Node* curr = new Node;
			prev->next = curr;
			curr->item = temp->item;
			prev = curr;
		}
	}
}


StackLst::StackLst(StackLst&& rhs) noexcept {
	head_ = rhs.head_;
	rhs.head_ = nullptr;
}


StackLst& StackLst::operator=(StackLst&& rhs) noexcept {
	if (this != &rhs) {
		Clear();
		head_ = rhs.head_;
		rhs.head_ = nullptr;
	}
	return *this;
}