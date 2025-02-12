#include <iostream>
#include <string>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <vector>
#include <iomanip>
#include <functional>

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

class Bank
{
public:
	static void make_request(const std::string& firstName, const std::string& lastName, std::function<void(int amount)> operation)
	{
		srand(time(NULL));
		auto now = std::chrono::system_clock::now();
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
		std::tm localTime{};
	#ifdef _WIN32
			localtime_s(&localTime, &now_c);  // Безпечна версія для Windows
	#else
			localtime_r(&now_c, &localTime);  // Безпечна версія для Linux/macOS
	#endif
		std::cout << std::setw(4) << std::setfill('0') << localTime.tm_year+1900 << "/"
			<< std::setw(2) << std::setfill('0') << localTime.tm_mday << "/"
			<< std::setw(2) << std::setfill('0') << localTime.tm_mon + 1 << " "
			<< std::setw(2) << std::setfill('0') << localTime.tm_hour << ":" 
			<< std::setw(2) << std::setfill('0') << localTime.tm_min << ":" 
			<< std::setw(2) << std::setfill('0') << localTime.tm_sec << ": \t"
			<< std::setw(15) << std::setfill(' ') << std::left << lastName
			<< std::setw(15) << std::left << firstName;
		operation(rand() % 100000 + 1000);
	}

	static void get_cash(const std::uint32_t amount)
	{
		std::cout << std::setw(10) << std::right << amount << " UAN"
			<< std::setw(15) << std::right << "get_cash"
			<< std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	static void deposit_cash(const std::uint32_t amount)
	{
		std::cout << std::setw(10) << std::right << amount << " UAN"
			<< std::setw(15) << std::right << "deposit_cash"
			<< std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
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

	try
	{
		srand(time(NULL));
		for (size_t i = 0; i < 2500; ++i)
		{
			std::thread th1(Bank::make_request, firstNames[rand() % firstNames.size()], 
												lastNames[rand() % lastNames.size()], 
												Bank::get_cash);
			/*std::thread th2(Bank::make_request, firstNames[rand() % firstNames.size()],
												lastNames[rand() % lastNames.size()],
												Bank::deposit_cash);*/
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