#pragma once
#include <vector>

template<typename T>
class Iterator
{
private:
	std::vector<T> data;
	int position;

	void initData(const T* _data, const int& size);
public:
	Iterator(T* _data, const int& _size, const int& _pos);
	Iterator(const Iterator& other);
	Iterator& operator=(const Iterator& other);
	T operator*() const;
	void operator++();
	bool operator==(const Iterator& other);
	bool operator!=(const Iterator& other);
};

