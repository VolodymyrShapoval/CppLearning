#include <iostream>
#include <stdexcept>
#include "LinkedList.h"

using namespace std;

int main()
{
	srand(time(NULL));
	try
	{
		LinkedList<int> myList;

		myList.generate(5, 0, 10);
		myList.print();
		myList.getHead();
		myList.getSize();
		myList.clear();
		myList.pushFront(1);
		myList.pushBack(3);
		myList.pushBack(4);
		myList.insert(2, 1);
		myList.print();
		myList.popFront();
		myList.print();
		myList.removeAt(1);
		myList.print();
		myList.popBack();
		myList.print();
	}
	catch (exception& ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}

	return 0;
}
