#pragma once

template<typename T>
class SkipList
{
private:
	struct node
	{
		T data;
		node* next, * skip;
	};
	node* head;
	size_t length;
	void copy(const SkipList& other);
	void erase();
public:
	SkipList();
	SkipList(const SkipList& other);
	SkipList& operator=(const SkipList& other);
	size_t size() const;
	void insertSorted(const T& element);
	void speedUp() const;
	int find(const T& element, bool (*comparator)(T a, T b));
};

