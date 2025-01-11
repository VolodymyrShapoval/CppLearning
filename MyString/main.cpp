#include <iostream>
#include <stdexcept>

class MyString
{
public:
	MyString() : str(nullptr) {}
	MyString(const char* const str)
	{
		int length = strlen(str);
		this->str = new char[length + 1];

		for (size_t i = 0; i < length; ++i)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';
	}
	~MyString()
	{
		delete[] this->str;
	}

	MyString& operator = (const MyString& other)
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}

		int length = strlen(other.str);

		this->str = new char[length + 1];

		for (size_t i = 0; i < length; ++i)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;
	}

	MyString& operator + (const MyString& other)
	{
		
	}

	void print()
	{
		std::cout << str << std::endl;
	}

private:
	char* str;

};

int main()
{
	try
	{
		MyString str = "Hello";
		str.print();
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	return 0;
}