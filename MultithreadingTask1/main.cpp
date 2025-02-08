#include <iostream>
#include <string>
#include <stdexcept>
#include <thread>
#include <chrono>

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
		std::cout << m_sYear << "/" << m_sDay << "/" << m_sMonth << ": " << lastName << " " << firstName << " -> " << amount << "UAN" << std::endl;
		++m_sOperationsCount;
	}

private:
	static void check_data()
	{
		const std::uint16_t februaryDays = (m_sYear % 4 && m_sYear % 100 != 0) || (m_sYear % 400 == 0) ? 29 : 28;
		static const int daysInMonth[] = { 31, februaryDays, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (m_sOperationsCount > 1000)
		{
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

static std::uint16_t m_sOperationsCount = 0;
std::uint16_t Bank::m_sYear = 2025;
std::uint16_t Bank::m_sMonth = 1;
std::uint16_t Bank::m_sDay = 1;

int main()
{
	const std::string firstNames[]{ "Viktor, Max, Oleh, Dmutro, Anatoliy, Volodymyr" };
	const std::string lastNames[]{ "Petrenko", "Dmutryk", "Omelnuk", "Cherednichenko", "Honchar"};
	try
	{
		srand(time(NULL));
		for (size_t i = 0; i < 1000; ++i)
		{
			std::int16_t fNameInd = rand() % firstNames->size();
			std::int16_t lNameInd = rand() % lastNames->size();
			do_work(firstNames[fNameInd], lastNames[lNameInd], rand() % 100000 + 1000);
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}