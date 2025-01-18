#include <iostream>
#include <stdexcept>

class MyString
{
public:
	MyString() : str(nullptr), length(0) {}
	MyString(const char* const str)
	{
		this->length = strlen(str);
		this->str = new char[this->length + 1];

		for (size_t i = 0; i < this->length; ++i)
		{
			this->str[i] = str[i];
		}

		this->str[this->length] = '\0';
	}
	MyString(const MyString& other)
	{
		this->length = strlen(other.str);
		this->str = new char[this->length + 1];

		for (size_t i = 0; i < this->length; ++i)
		{
			this->str[i] = other.str[i];
		}

		this->str[this->length] = '\0';
	}
	MyString(MyString&& other)
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}
	~MyString()
	{
		delete[] this->str;
		this->length = 0;
	}

	MyString& operator = (const MyString& other)
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}

		this->length = strlen(other.str);

		this->str = new char[this->length + 1];

		for (size_t i = 0; i < this->length; ++i)
		{
			this->str[i] = other.str[i];
		}

		this->str[this->length] = '\0';

		return *this;
	}

	MyString operator + (const MyString& other)
	{
		int myStrLength = strlen(this->str);
		int otherStrLength = strlen(other.str);
		int length = myStrLength + otherStrLength;

		MyString new_str;
		new_str.str = new char[length + 1];
		new_str.length = length;

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

	bool operator ==(const MyString& other)
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (size_t i = 0; i < this->length; ++i)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}

		return true;
	}

	bool operator !=(const MyString& other)
	{
		return !(this->str == other.str);
	}

	char& operator [](size_t index)
	{
		if (this->length == 0 || index > this->length)
		{
			throw std::out_of_range("Index out of range!");
		}
		return this->str[index];
	}

	void print()
	{
		std::cout << this->str << std::endl;
	}

	int getLength()
	{
		return this->length;
	}

private:
	char* str;
	int length;

};

int main()
{
	try
	{
		MyString str1 = "Hello";
		MyString str2 = "World";
		MyString str3;

		std::cout << "str1: " << str1.getLength() << std::endl;
		std::cout << "str2: " << str2.getLength() << std::endl;
		MyString str = str1 + str2;
		std::cout << "str: " << str.getLength() << std::endl;
		str.print();
		std::cout << "str1 == str2 -> " << std::boolalpha << (str1 == str2) << std::endl;
		std::cout << "str1 != str2 -> " << std::boolalpha << (str1 != str2) << std::endl;
		std::cout << "str(before replacement) -> ";
		str.print();
		str[0] = 'h';
		str[4] = '0';
		std::cout << "str(after replacement) -> ";
		str.print();
		std::cout << "str3 -> " << str3[10] << std::endl;

	}
	catch (std::exception& ex)
	{
		std::cout << "Exception: " << ex.what() << std::endl;
	}

	return 0;
}