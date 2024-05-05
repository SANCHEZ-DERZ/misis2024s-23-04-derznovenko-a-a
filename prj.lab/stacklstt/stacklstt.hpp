#pragma once
#ifndef STACKLST_STACKLSTT_HPP_20240213
#define STACKLST_STACKLSTT_HPP_20240213

#include <cstddef>
template<class T>
class StackLstT {
public:
	StackLstT() = default;

	StackLstT(const StackLstT& lst);

	StackLstT(StackLstT&&) noexcept;

	~StackLstT();

	StackLstT& operator=(const StackLstT& lst);

	StackLstT& operator=(StackLstT&&) noexcept;

	bool IsEmpty() const noexcept;

	void Pop() noexcept;

	void Push(const T& val);

	T& Top();

	const T& Top() const;

	void Clear() noexcept;

private:
	struct Node {
		T item;
		Node* next = nullptr;
	};
	Node* head_ = nullptr;
	std::ptrdiff_t size_ = 0;
};

template <typename T>
bool StackLstT<T>::IsEmpty() const noexcept {
	return head_ == nullptr;
}

template <typename T>
T& StackLstT<T>::Top() {
	if (head_ != nullptr) {
		return head_->item;
	}
	else {
		throw std::out_of_range("Stack is empty");
	}
}

template <typename T>
void StackLstT<T>::Pop() noexcept {
	if (head_ != nullptr) {
		Node* new_head = head_;
		head_ = head_->next;
		delete new_head;
		size_ -= 1;
	}
}

template <typename T>
void StackLstT<T>::Push(const T& val) {
	Node* new_head = new Node;
	new_head->item = val;
	new_head->next = head_;
	head_ = new_head;
	size_ += 1;
}

template <typename T>
void StackLstT<T>::Clear() noexcept {
	while (head_ != nullptr) {
		this->Pop();
	}
	size_ = 0;
}

template <typename T>
const T& StackLstT<T>::Top() const {
	if (head_ != nullptr) {
		return head_->item;
	}
	else {
		throw std::out_of_range("Stack is empty");
	}
}

template <typename T>
StackLstT<T>& StackLstT<T>::operator=(const StackLstT& other) {
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
template <typename T>
StackLstT<T>::~StackLstT() {
	Clear();
}

template <typename T>
StackLstT<T>::StackLstT(const StackLstT& other) {
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

template <typename T>
StackLstT<T>::StackLstT(StackLstT&& rhs) noexcept {
	head_ = rhs.head_;
	rhs.head_ = nullptr;
}

template <typename T>
StackLstT<T>& StackLstT<T>::operator=(StackLstT&& rhs) noexcept {
	if (this != &rhs) {
		Clear();
		head_ = rhs.head_;
		rhs.head_ = nullptr;
	}
	return *this;
}

#endif