#pragma once
#ifndef _BANK_
#define _BANK_

#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>
#include <functional>
#include <vector>
#include <tuple>
#include "Stock.h"
#include "Client.h"

class Client;

class Bank
{
public:
	static void make_request(const Client& client, std::function<void(std::uint32_t amount)> operation);
	static void get_cash(const std::uint32_t amount);
	static void deposit_cash(const std::uint32_t amount);
};

#endif // !_BANK_



