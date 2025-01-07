#include<iostream>
#include<string>
#include<stdexcept>

using namespace std;

int mystrlen(const char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		++i;
	}
	return i;
}

string getDataFromWebServer()
{
	return "Data From WebServer";
}

string getDataFromDB()
{
	return "Data from DB";
}

void showInfo(string (*foo)())
{
	cout << foo() << endl;
}

void main()
{
	try
	{
		const char* str = "Hello!";
		cout << str << " = " << mystrlen(str) << endl;

		showInfo(getDataFromDB);
	}
	catch (exception& ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}
}