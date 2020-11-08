#include <iostream>

template<typename T>
struct Node
{
	Node<T>* next;
	T data;
};

Node<int>* init()
{
	Node<int>* first = new Node<int>({ nullptr, 10 });
	first->next = new Node<int>({ nullptr, 20 });
	first->next->next = new Node<int>({ nullptr, 30 });
	first->next->next->next = new Node<int>({ nullptr, 40 });
	first->next->next->next->next = new Node<int>({ nullptr, 50 });
	first->next->next->next->next->next = new Node<int>({ nullptr, 60 });
	return first;
}

template<typename T>
Node<T>* rotate(Node<T>* node, int k)
{
	if(k == 0)
	{
		return node;
	}
	
	Node<T>* kThNode = node, * beforekThNode = nullptr;

	while(k != 0)
	{
		if(k == 1)
		{
			beforekThNode = kThNode;
		}
		kThNode = kThNode->next;
		k--;
	}

	Node<T>* lastNode = kThNode;
	while(lastNode->next != nullptr)
	{
		lastNode = lastNode->next;
	}

	lastNode->next = node;
	beforekThNode->next = nullptr;
	return kThNode;
}

template<typename T>
void print(Node<T>* head) {
	while (head != nullptr) {
		std::cout << head->data;
		if (head->next != nullptr) {
			std::cout << " -> ";
		}
		head = head->next;
	}
	std::cout << '\n';
}

template<typename T>
void clearMemory(Node<T>* head)
{
	while (head != nullptr) {
		Node<T>* save = head;
		head = head->next;
		delete save;
	}
}

int main()
{
	Node<int>* head = init();
	head = rotate(head, 4);
	print(head);
	clearMemory(head);
	return 0;
}