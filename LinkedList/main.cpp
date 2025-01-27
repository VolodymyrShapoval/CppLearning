#include <iostream>
#include <stdexcept>
#include "LinkedList.h"

using namespace std;

int main()
{
	srand(time(NULL));
	try
	{
		LinkedList<string> strList;
		LinkedList<char> myList;

		cout << "String list: ";
		strList.pushBack("Hello!");
		strList.pushBack("My");
		strList.pushBack("name");
		strList.pushBack("is");
		strList.pushBack("John");
		strList.pushBack("Doe");
		strList.print();

		cout << "Char list: ";
		myList.generateList(10, 97, 122);
		myList.print();
	}
	catch (exception& ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}

	return 0;
}