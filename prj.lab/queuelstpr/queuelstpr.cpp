#include "queuelstpr/queuelstpr.hpp"
#include <stdexcept>




bool QueueLstPr::IsEmpty() const noexcept {
	if (head_ == nullptr) {
		return true;
	}
	else {
		return false;
	}
}


float& QueueLstPr::Top() {
	if (head_ != nullptr) {
		return head_->item;
	}
	else {
		throw std::logic_error("QueueLst - trying to get top from empty queue.");
	}
}


const float& QueueLstPr::Top() const {
	if (head_ != nullptr) {
		return head_->item;
	}
	else {
		throw std::logic_error("QueueLst - trying to get top from empty queue.");
	}
}


void QueueLstPr::Pop() noexcept {
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


void QueueLstPr::Clear() noexcept {
	while (!IsEmpty()) {
		Pop();
	}
	size_ = 0;
}


void QueueLstPr::Push(const float& val) {
	if (head_ == nullptr) {
		tail_ = new Node{ val };
		head_ = tail_;
	}
	else {
		if (head_->item > val) {
			Node* new_head = new Node{ val };
			new_head->next = head_;
			head_ = new_head;
		}
		else if (tail_->item < val) {
			tail_->next = new Node{ val };
			tail_ = tail_->next;
		}
		else {
			Node* current = head_;
			Node* prev = nullptr;
			while (current->item < val && current) {
					prev = current;
					current = current->next;
			}
			Node* new_node = new Node{ val, current };
			prev->next = new_node;
		}
	}
	size_ += 1;
}


QueueLstPr::~QueueLstPr() {
	Clear();
}


QueueLstPr::QueueLstPr(const QueueLstPr& other) {
	Node* current = other.head_;
	while (current) {
		Push(current->item);
		current = current->next;
	}
}


QueueLstPr& QueueLstPr::operator=(const QueueLstPr& que) {
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


QueueLstPr::QueueLstPr(QueueLstPr&& rhs) noexcept {
	head_ = rhs.head_;
	tail_ = rhs.tail_;
	rhs.head_ = nullptr;
	rhs.tail_ = nullptr;
}


QueueLstPr& QueueLstPr::operator=(QueueLstPr&& rhs) noexcept {
	if (this != &rhs) {
		head_ = rhs.head_;
		tail_ = rhs.tail_;
		rhs.head_ = nullptr;
		rhs.tail_ = nullptr;
	}
	return *this;
}