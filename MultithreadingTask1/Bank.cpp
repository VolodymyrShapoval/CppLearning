#include "Bank.h"

std::mutex mtx;

void Bank::make_request(const Client& client, std::function<void(std::uint32_t amount)> operation)
{
	std::lock_guard<std::mutex> guard(mtx);
	auto now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::tm localTime{};
#ifdef _WIN32
	localtime_s(&localTime, &now_c);  // Безпечна версія для Windows
#else
	localtime_r(&now_c, &localTime);  // Безпечна версія для Linux/macOS
#endif
	std::cout << std::setw(4) << std::setfill('0') << localTime.tm_year + 1900 << "/"
		<< std::setw(2) << std::setfill('0') << localTime.tm_mday << "/"
		<< std::setw(2) << std::setfill('0') << localTime.tm_mon + 1 << " "
		<< std::setw(2) << std::setfill('0') << localTime.tm_hour << ":"
		<< std::setw(2) << std::setfill('0') << localTime.tm_min << ":"
		<< std::setw(2) << std::setfill('0') << localTime.tm_sec << ": \t"
		<< std::setw(15) << std::setfill(' ') << std::left << client.lastName()
		<< std::setw(15) << std::left << client.firstName();
	
	auto get_rand_amount = [&now_c]() -> int
	{
		srand(time(&now_c));
		return rand() % 100000 + 1000;
	};
	operation(get_rand_amount());
}

void Bank::get_cash(const std::uint32_t amount)
{
	std::cout << std::setw(10) << std::right << amount << " UAN"
		<< std::setw(15) << std::right << "get_cash"
		<< std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void Bank::deposit_cash(const std::uint32_t amount)
{
	std::cout << std::setw(10) << std::right << amount << " UAN"
		<< std::setw(15) << std::right << "deposit_cash"
		<< std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}