#pragma once
#ifndef _CLIENT_
#define _CLIENT_

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>
#include <thread>
#include <iomanip>
#include "Stock.h"
#include "Bank.h"

class Client
{
public:
	Client(const std::string& firstName, const std::string& lastName);
	const std::string firstName() const;
	const std::string lastName() const;

private:
	const std::string m_firstName;
	const std::string m_lastName;
};

#endif // !_CLIENT_



