#include <iostream>
#include <string>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <vector>
#include <iomanip>
#include <functional>
#include "Bank.h"
#include "OperationTimer.h"

void do_work()
{
	std::thread::id thisId = std::this_thread::get_id();
	std::cout << "START THREAD " << thisId << std::endl;
	for (size_t i = 0; i < 10; ++i)
	{
		std::cout << "THREAD " << thisId << " WORKING \tdo_work" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	std::cout << "END THREAD " << thisId << std::endl;
}

class ClientGenerator
{
public:
	std::vector<Client> operator ()(const std::vector<std::string>& firstNames, const std::vector<std::string>& lastNames) noexcept
	{
		std::vector<Client> clients;
		for (const auto& firstName : firstNames) 
		{
			for (const auto& lastName : lastNames) 
			{
				clients.emplace_back(firstName, lastName);
			}
		}
		return clients;
	}
};

int main()
{
	const std::vector<std::string> firstNames {
	"Viktor", "Max", "Oleh", "Dmutro", "Anatoliy", "Volodymyr", "Andriy", "Serhiy", "Oleksandr", "Mykola",
	"Bohdan", "Yaroslav", "Roman", "Ihor", "Artem", "Pavlo", "Denys", "Taras", "Stepan", "Hryhoriy",
	"Yevhen", "Valentyn", "Mykhailo", "Stanislav", "Ruslan"	};

	const std::vector<std::string> lastNames {
		"Petrenko", "Dmutryk", "Omelnuk", "Cherednichenko", "Honchar", "Shevchenko", "Kovalenko", "Moroz", "Savchenko", "Tkachenko",
		"Kryvonos", "Khomenko", "Perebyinis", "Zakharchenko", "Khmelnitsky", "Shapoval", "Bondarenko", "Mazurenko", "Vasylenko", "Melnyk",
		"Lysenko", "Rudenko", "Havryliuk", "Zelenko", "Yakovenko" };

	ClientGenerator clientGen;
	std::vector<Client> clients = clientGen(firstNames, lastNames);

	const std::vector<Stock> stocks
	{
		Stock("Coca-Cola", 15),
		Stock("Microsoft", 235),
		Stock("Apple", 150)
	};

	try
	{
		srand(time(NULL));
		for (size_t i = 0; i < 2500; ++i)
		{
#ifdef _DEBUG
			OperationTimer timer;
#endif
			std::thread th1(Bank::make_request, clients[rand() % clients.size()], Bank::get_cash);
			/*std::thread th2(Bank::make_request, clients[rand() % clients.size()], Bank::get_cash);*/
			th1.join();
			//th2.join();
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}