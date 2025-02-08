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

int main()
{
	try
	{
		std::thread thread1(do_work);
		std::thread thread2(do_work);
		std::thread thread3(do_work);

		thread1.join();
		thread2.join();
		thread3.join();
	}
	catch (const std::exception& ex)
	{
		std::cerr << "Exception: " << ex.what() << std::endl;
	}
	return 0;
}