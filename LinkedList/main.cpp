#include <iostream>
#include <stdexcept>

using namespace std;

template <class T>
class Node
{
public:
	T value;
	Node<T>* next;

	Node(T value)
	{
		this->value = value;
		this->next = nullptr;
	}
	Node(const Node& node)
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
	LinkedList(T value)
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
	void pushFront(T value)
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = head;
		head = newNode;
		++size;
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
		for (size_t i = 0; i < index-1; ++i)
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

int main()
{
	srand(time(NULL));
	try
	{
		LinkedList<char> myList;
		
		for (size_t i = 0; i < 10; ++i)
		{
			myList.pushBack(rand() % 26 + 97);
		}

		myList.print();

		for (size_t i = 0; i < 10; ++i)
		{
			myList.removeAt(i);
			myList.print();
		}
	}
	catch (exception& ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}

	return 0;
}