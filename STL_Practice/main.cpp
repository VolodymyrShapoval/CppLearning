#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <forward_list>
#include <array>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <stdexcept>
#include "VectorDisplay.h"
#include "ListDisplay.h"
#include "ForwardListDisplay.h"
#include "ArrayDisplay.h"
#include "VectorGenerator.h"
#include "ListGenerator.h"
#include "ForwardListGenerator.h"

class Person
{
public:
	std::string name;
	std::int16_t age;

	Person(const std::string& name, const std::int16_t age)
	{
		this->name = name;
		this->age = age;
	}

	std::string& operator <<(const Person& person)
	{
		std::cout << "Name: " << person.name << "\n"
			<< "Age: " << person.age << std::endl;
	}
};

void menu()
{
	std::cout << "1. Vector \n"
			<< "2. List \n"
			<< "3. Forward list \n"
			<< "4. Array \n"
			<< "5. Deque \n"
			<< "6. Set \n"
			<< "7. Multiset \n"
			<< "8. Map \n"
			<< "9. Multimap \n"
			<< "10. Stack \n"
			<< "11. Queue \n"
			<< "12. Priority queue \n"
			<< "13. Sorting \n"
			<< "14. Searching \n"
			<< "15. Copying \n"
			<< "0. Exit \n";
}

void clearConsole() {
#ifdef _WIN32
	system("cls");  // Windows
#else
	system("clear");  // Linux/macOS
#endif
}

int main()
{
	try
	{
		while (true)
		{
			menu();
			std::size_t choice;
			std::cout << "Input: ";
			std::cin >> choice;

			std::cout << std::string(20, '>') << std::endl;
			clearConsole();

			switch (choice)
			{
			case 1:
			{
				std::vector<int> templateVec;
				VectorGenerator<int>::generate_vector(templateVec, 10);
				VectorDisplay<int>::vector_work(templateVec, 15);
				templateVec.resize(15);
				VectorDisplay<int>::print(templateVec);
				VectorGenerator<int>::redefine_vector(templateVec);
				VectorDisplay<int>::print(templateVec);
				break;
			}
			case 2:
			{
				std::list<int> intList = IntListGenerator().generate(10);
				std::list<double> doubleList = DoubleListGenerator().generate(10);
				std::cout << "List<int>: ";
				ListDisplay<int>::print(intList);
				std::cout << "List<double>: ";
				ListDisplay<double>::print(doubleList);
				break;
			}
			case 3:
			{
				std::forward_list<int> int_flist = IntForwardListGenerator().generate(10);
				std::cout << "Forward list: ";
				ForwardListDisplay<int>::print(int_flist);
				break;
			}
			case 4:
			{
				srand(time(NULL));
				std::array<int, 10> arr;
				for (auto& elem : arr)
				{
					elem = rand() % 100;
				}
				ArrayDisplay::print(arr);
				break;
			}
			case 5:
			{
				srand(time(NULL));
				std::deque<int> dq(10);

				for (auto& elem : dq)
				{
					elem = rand() % 100;
				}

				for (const auto& elem : dq)
				{
					std::cout << elem << " ";
				}
				std::cout << std::endl;
				break;
			}
			case 6:
			{
				srand(time(NULL));
				std::size_t size = 10;
				std::set<int> tree;
				for (size_t i = 0; i < size; ++i)
				{
					tree.insert(rand() % 100);
				}
				for (const auto& elem : tree)
				{
					std::cout << elem << " -> ";
				}
				std::cout << "null" << std::endl;
				break;
			}
			case 7:
			{
				srand(time(NULL));
				std::size_t size = 10;
				std::multiset<int> mtree;
				for (size_t i = 0; i < size; ++i)
				{
					mtree.insert(rand() % 25);
				}
				for (const auto& elem : mtree)
				{
					std::cout << elem << " -> ";
				}
				std::cout << "null" << std::endl;
				break;
			}
			case 8:
			{
				std::map<int, std::string> employees;
				employees.emplace(41, "John Doe - CEO");
				employees.emplace(38, "Anna Bee - Finance Director");
				employees.emplace(36, "Max Ford - Tech Lead");
				employees.emplace(25, "Frank Stark - Senior Developer");
				employees.emplace(23, "Kate Johnson - Middle Developer");
				employees.emplace(21, "Jane Moon - Project Manager");
				employees.emplace(20, "Fill Peterson - Junior Developer");

				std::multimap<int, std::string>::const_reverse_iterator it = employees.crbegin();
				for (it; it != employees.crend(); ++it)
				{
					std::cout << (*it).second << " - " << (*it).first << " y.o." << std::endl;
				}
				break;
			}
			case 9:
			{
				std::multimap<int, std::string> employees;
				employees.emplace(41, "John Doe - CEO");
				employees.emplace(38, "Anna Bee - Finance Director");
				employees.emplace(36, "Max Ford - Tech Lead");
				employees.emplace(36, "Lia Chin - Business analyst");
				employees.emplace(25, "Frank Stark - Senior Developer");
				employees.emplace(23, "Kate Johnson - Middle Developer");
				employees.emplace(21, "Jane Moon - Project Manager");
				employees.emplace(20, "Fill Peterson - Junior Developer");

				std::multimap<int, std::string>::const_reverse_iterator it = employees.crbegin();
				for (it; it != employees.crend(); ++it)
				{
					std::cout << (*it).second << " - "  << (*it).first << " y.o." << std::endl;
				}
				break;
			}
			case 10:
			{
				srand(time(NULL));
				std::size_t size = 10;
				std::stack<int> st;
				for (size_t i = 0; i < size; ++i)
				{
					st.push(i);
				}
				for (size_t i = 0; !st.empty(); i++)
				{
					std::cout << "->Pop #" << i+1 << ": " << st.top() << std::endl;
					st.pop();
				}
				break;
			}
			case 11:
			{
				std::size_t size = 10;
				std::queue<int> q;
				for (size_t i = 0; i < size; ++i)
				{
					q.emplace(i+1);
				}
				std::cout << "Exit <- ";
				while(!q.empty())
				{
					std::cout << q.front() << " <- ";
					q.pop();
				}
				std::cout << "new clients" << std::endl;
				break;
			}
			case 12:
			{
				srand(time(NULL));
				std::size_t size = 10;
				std::priority_queue<int> q;
				
				for (size_t i = 0; i < size; ++i)
				{
					q.emplace(rand() % 100);
				}
				std::cout << "Exit <- ";
				while (!q.empty())
				{
					std::cout << q.top() << " <- ";
					q.pop();
				}
				std::cout << "new clients" << std::endl;
				break;
			}
			case 13:
			{
				std::cout << "=========== Sorting ===========" << std::endl;
				std::vector<int> vec;
				VectorGenerator<int>::generate_vector(vec, 10);
				VectorDisplay<int>::print(vec);
				std::sort(vec.begin(), vec.end(), [](int a, int b)
				{
					return a < b;
				});
				VectorDisplay<int>::print(vec);
				break;
			}
			case 14:
			{
				std::vector<int> vec{ 6, 254, 53, 233, 66, 23, 677, 134, 11 };
				auto findRes = std::find(vec.begin(), vec.end(), 11);
				if (findRes == vec.end())
				{
					std::cout << "There is no such element!" << std::endl;
				}
				else
				{
					std::cout << "Result(find): " << *findRes << std::endl;
				}

				auto findIfRes = std::find_if(vec.begin(), vec.end(), [](int a)
				{
					return a > 100;
				});
				if (findIfRes == vec.end())
				{
					std::cout << "There is no such element!" << std::endl;
				}
				else
				{
					std::cout << "Result(find_if): " << *findIfRes << std::endl;
				}

				auto findIfNotRes = std::find_if_not(vec.begin(), vec.end(), [](int a)
					{
						return a > 100;
					});
				if (findIfNotRes == vec.end())
				{
					std::cout << "There is no such element!" << std::endl;
				}
				else
				{
					std::cout << "Result(find_if_not): " << *findIfNotRes << std::endl;
				}
				
				break;
			}
			case 15:
			{
				std::vector<Person>	people
				{
					Person("Kate", 19),
					Person("John", 21),
					Person("Fred", 20),
					Person("Mark", 41),
					Person("Lusy", 27),
					Person("Sara", 17)
				};
				std::vector<Person> result;

				std::copy_if(people.begin(), people.end(), std::back_inserter(result), [](const Person& person)
				{
					return person.age >= 20;
				});

				std::sort(result.begin(), result.end(), [](const Person& person1, const Person& person2)
				{
					return person1.age < person2.age;
				});

				for (const auto& person : result)
				{
					std::cout << person.name << " - " << person.age << std::endl;
				}
				break;
			}
			case 0:
				std::cout << "Thank you for using our program!" << std::endl;
				return 0;
			default:
				std::cout << "There is no such option!" << std::endl;
				break;
			}
			std::cout << std::string(20, '>') << std::endl;
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}