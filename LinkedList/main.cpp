#include <iostream>
#include <stdexcept>
#include "LinkedList.h"

using namespace std;

int main()
{
	srand(time(NULL));
	try
	{
		LinkedList<char> myList;
		LinkedList<char> newList;

		LinkedList<string> strList;
		
		strList.pushBack("Doe");
		strList.pushBack("John");
		strList.pushBack("is");
		strList.pushBack("name");
		strList.pushBack("My");
		strList.pushBack("Hello!");
		strList.print();

		/*myList.generateList(10, 97, 122);
		myList.print();*/
	}
	catch (exception& ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}

	return 0;
}