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
	MyString(const MyString& other)
	{
		int length = strlen(other.str);

		this->str = new char[length + 1];

		for (size_t i = 0; i < length; ++i)
		{
			this->str[i] = other.str[i];
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



	MyString operator + (const MyString& other)
	{
		int myStrLength = strlen(this->str);
		int otherStrLength = strlen(other.str);
		int length = myStrLength + otherStrLength;

		MyString new_str;
		new_str.str = new char[length + 1];

		for (size_t i = 0; i < myStrLength; ++i)
		{
			new_str.str[i] = this->str[i];
		}

		for (size_t i = myStrLength, j = 0; i < length; ++i, ++j)
		{
			new_str.str[i] = other.str[j];
		}

		new_str.str[length] = '\0';


		return new_str;
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
		MyString str1 = "Hello";
		MyString str2 = "World";

		MyString str = str1 + str2;

		str.print();
	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	return 0;
}