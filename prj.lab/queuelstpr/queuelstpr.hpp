#pragma once
#ifndef QUEUELSTPR_MISIS
#define QUEUELSTPR_MISIS

#include <cstddef>

class QueueLstPr {
public:
	QueueLstPr() = default;

	QueueLstPr(const QueueLstPr&);

	QueueLstPr(QueueLstPr&& rhs) noexcept;

	~QueueLstPr();

	QueueLstPr& operator=(const QueueLstPr&);

	QueueLstPr& operator=(QueueLstPr&&) noexcept;

	bool IsEmpty() const noexcept;

	void Pop() noexcept;

	void Push(const float& val);

	float& Top();

	const float& Top() const;

	void Clear() noexcept;

private:
	struct Node {
		float item;
		Node* next = nullptr;
	};
	Node* head_ = nullptr;
	std::ptrdiff_t size_ = 0;
	Node* tail_ = nullptr;
};

#endif