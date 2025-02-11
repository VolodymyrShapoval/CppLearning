#include <iostream>
#include <string>
#include <stdexcept>
#include <thread>
#include <chrono>
#include <vector>
#include <iomanip>

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
	static void get_cash(const std::string& firstName, const std::string& lastName, const std::uint32_t amount)
	{
		check_data();
		std::cout << std::setw(4) << std::setfill('0') << m_sYear << "/"
			<< std::setw(2) << std::setfill('0') << m_sMonth << "/"
			<< std::setw(2) << std::setfill('0') << m_sDay << ": \t"
			<< std::setw(15) << std::setfill(' ') << std::left << lastName
			<< std::setw(15) << std::left << firstName
			<< std::setw(10) << std::right << amount << " UAN"
			<< std::setw(15) << std::right << "get_cash"
			<< std::endl; 
		++m_sOperationsCount;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	static void deposit_cash(const std::string& firstName, const std::string& lastName, const std::uint32_t amount)
	{
		check_data();
		std::cout << std::setw(4) << std::setfill('0') << m_sYear << "/"
			<< std::setw(2) << std::setfill('0') << m_sMonth << "/"
			<< std::setw(2) << std::setfill('0') << m_sDay << ": \t"
			<< std::setw(15) << std::setfill(' ') << std::left << lastName
			<< std::setw(15) << std::left << firstName
			<< std::setw(10) << std::right << amount << " UAN"
			<< std::setw(15) << std::right << "deposit_cash"
			<< std::endl; 
		++m_sOperationsCount;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

private:
	static void check_data()
	{
		const std::uint16_t februaryDays = (m_sYear % 4 && m_sYear % 100 != 0) || (m_sYear % 400 == 0) ? 29 : 28;
		static const int daysInMonth[] = { 31, februaryDays, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (m_sOperationsCount > 1000)
		{
			m_sOperationsCount = 0;
			if (m_sDay == daysInMonth[m_sMonth - 1])
			{
				m_sDay = 1;
				++m_sMonth;

				if (m_sMonth > 12)
				{
					m_sMonth = 1;
					++m_sYear;
				}
			}
			else
			{
				++m_sDay;
			}
		}
	}

	static std::uint16_t m_sOperationsCount;
	static std::uint16_t m_sYear;
	static std::uint16_t m_sMonth;
	static std::uint16_t m_sDay;
};

std::uint16_t Bank::m_sOperationsCount = 0;
std::uint16_t Bank::m_sYear = 2025;
std::uint16_t Bank::m_sMonth = 1;
std::uint16_t Bank::m_sDay = 1;

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
			std::thread th1(Bank::get_cash, firstNames[rand() % firstNames.size()], 
											lastNames[rand() % lastNames.size()], 
											rand() % 100000 + 1000);
			std::thread th2(Bank::get_cash, firstNames[rand() % firstNames.size()],
											lastNames[rand() % lastNames.size()],
											rand() % 100000 + 1000);
			th1.join();
			th2.join();
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}