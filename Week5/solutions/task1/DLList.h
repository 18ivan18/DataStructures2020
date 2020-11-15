#pragma once

template<typename T>
class DLListIterator;

template<typename T>
class DLList
{
private:
	struct node
	{
		T data;
		node* next, * prev;
	};
	node* first, * last;
public:
	class DLListIterator
	{
	private:
		node* currentPosition;
	public:
		DLListIterator(node* pos);
		void operator++();
		T operator*() const;
		bool operator==(const DLListIterator& other) const;
		bool operator!=(const DLListIterator& other) const;
	};
	
	DLList();
	bool isEmpty() const;
	size_t size() const;
	T front() const;
	T back() const;
	void assign(const size_t& n, const T& element);
	void pushFront(const T& element);
	void pushBack(const T& element);
	void popFront();
	void popBack();
	void insert(const size_t& position, const T& element);
	void erase(const size_t& position);
	void clear();
	void unique();
	void reverse();
	void removeIf(bool (*predicate)(T element));
	void map(T (*function)(T element));
	void print() const;
	void printReverse() const;

	DLListIterator begin();
	DLListIterator end();
};