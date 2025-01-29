#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList()
{
	this->head = nullptr;
	this->size = 0;
}

template <class T>
LinkedList<T>::LinkedList(const T& value)
{
	this->head = new Node<T>(value);
	this->size = 1;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList& linkedList)
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

template <class T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template <class T>
T& LinkedList<T>::operator [] (const size_t index) const
{
	if (index >= this->size)
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

template <class T>
bool LinkedList<T>::operator == (const LinkedList<T>& other) const
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

template <class T>
bool LinkedList<T>::operator != (const LinkedList<T>& other) const
{
	return !(*this == other);
}

template <class T>
int LinkedList<T>::getSize() const
{
	return this->size;
}

template <class T>
T& LinkedList<T>::getHead()
{
	if (this->head == nullptr)
	{
		cout << "Empty linked list" << endl;
		return;
	}

	return this->head->value;
}

template <class T>
void LinkedList<T>::pushFront(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	newNode->next = head;
	head = newNode;
	++size;
}

template <class T>
void LinkedList<T>::pushBack(const T& value)
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

template <class T>
void LinkedList<T>::popFront()
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

template <class T>
void LinkedList<T>::insertAt(int index, const T& value)
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

template <class T>
void LinkedList<T>::removeAt(int index)
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

template <class T>
void LinkedList<T>::generateList(int size, int start, int end)
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

template <class T>
void LinkedList<T>::print()
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

template <class T>
void LinkedList<T>::clear()
{
	while(size)
	{
		popFront();
	}
}