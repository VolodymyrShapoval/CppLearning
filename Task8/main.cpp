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
		string (*SHOW_INFO_FOO)(string(*foo)()) = [](string(*foo)()) -> string
		{
			cout << foo() << endl;
			return "WTF?";
		};
		auto s = SHOW_INFO_FOO(getDataFromDB);
		auto f = []()
		{
			return 1;
		};

		cout << f() << endl;
	}
	catch (exception& ex)
	{
		cout << "Exception: " << ex.what() << endl;
	}
}