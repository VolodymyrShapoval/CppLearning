#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class Node
{
public:
	T value;
	Node<T>* next;

	Node() = default;
	Node(T value)
	{
		this->value = value;
		this->next = nullptr;
	}
	Node(const Node<T>& node)
	{
		this->value = node.value;
		this->next = node.next;
	}
};

template <class T>
class LinkedList
{
private:
	Node<T>* head;
	int size;

public:
	LinkedList()
	{
		this->head = nullptr;
		this->size = 0;
	}
	LinkedList(const T& value)
	{
		this->head = new Node<T>(value);
		this->size = 1;
	}
	LinkedList(const LinkedList& linkedList)
	{
		if (linkedList.head == nullptr)
		{
			this->head = nullptr;
			this->size = 0;
			return;
		}
		Node<T>* current = linkedList.head;
		while (current != nullptr)
		{
			pushBack(current->value);
			current = current->next;
		}
	}
	~LinkedList()
	{
		if (head == nullptr)
			return;

		clear();
	}
	T& operator [](size_t index)
	{
		if (index < 0 && index >= this->size)
		{
			throw invalid_argument("Invalid index!");
		}

		Node<T>* current = head;
		while (index > 0)
		{
			current = current->next;
			--index;
		}

		return current->value;
	}
	bool operator == (const LinkedList<T>& other)
	{
		if (this->size != other.size)
			return false;

		Node<T>* currentNode = head;
		Node<T>* otherNode = other.head;
		for (size_t i = 0; i < size; ++i)
		{
			if (currentNode->value != otherNode->value)
				return false;
			currentNode = currentNode->next;
			otherNode = otherNode->next;
		}
		return true;
	}

	bool operator != (const LinkedList<T>& other)
	{
		return !(*this == other);
	}
	int getSize()
	{
		return this->size;
	}
	void pushFront(T value)
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head;
		head = newNode;
		++size;
	}
	T& getFront()
	{
		if (this->head == nullptr)
		{
			cout << "Empty linked list" << endl;
			return;
		}

		return this->head->value;
	}
	void popFront()
	{
		if (head == nullptr)
		{
			cout << "Empty linked list" << endl;
			return;
		}

		Node<T>* current = head;
		head = head->next;
		delete current;
		--size;
	}
	void insertAt(int index, T value)
	{
		if (index > size)
		{
			throw exception("You cannot insert node to non-existent position");
		}
		else if (index < 0)
		{
			throw exception("Index cannot be less than 0");
		}
		else if (index == 0)
		{
			pushFront(value);
			return;
		}

		Node<T>* current = head;
		for (size_t i = 0; i < index - 1; ++i)
		{
			current = current->next;
		}
		Node<T>* newNode = new Node<T>(value);
		newNode->next = current->next;
		current->next = newNode;
		++size;
	}
	void removeAt(int index)
	{
		if (index >= size)
		{
			throw exception("You cannot remove node from non-existent position");
		}
		else if (index < 0)
		{
			throw exception("Index cannot be less than 0");
		}
		else if (index == 0)
		{
			popFront();
			return;
		}

		Node<T>* current = head;
		for (size_t i = 0; i < index - 1; ++i)
		{
			current = current->next;
		}
		Node<T>* deleteNode = current->next;
		current->next = deleteNode->next;
		delete deleteNode;
		--size;
	}
	void pushBack(T value)
	{
		if (head == nullptr)
		{
			head = new Node<T>(value);
			++size;
			return;
		}

		Node<T>* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new Node<T>(value);
		++size;
	}
	void generateList(int size, int start, int end)
	{
		if (size < 0)
		{
			throw exception("Size of linked list cannot be less than 0");
		}
		else if (size == 0)
		{
			return;
		}
		if (this->head != nullptr)
		{
			clear();
		}

		for (size_t i = 0; i < size; ++i)
		{
			pushFront(rand() % (end - start + 1) + start);
		}
	}
	void print()
	{
		if (head == nullptr)
		{
			cout << "Empty linked list" << endl;
			return;
		}

		Node<T>* current = head;
		while (current != nullptr)
		{
			cout << current->value << "->";
			current = current->next;
		}
		cout << "nullptr" << endl;
	}
	void clear()
	{
		for (size_t i = 0; i < size; ++i)
		{
			popFront();
		}
	}
};