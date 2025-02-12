#pragma once
#ifndef _BANK_
#define _BANK_

#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <functional>

class Bank
{
public:
	static void make_request(const std::string& firstName, const std::string& lastName, std::function<void(int amount)> operation);
	static void get_cash(const std::uint32_t amount);
	static void deposit_cash(const std::uint32_t amount);
};

#endif // !_BANK_



