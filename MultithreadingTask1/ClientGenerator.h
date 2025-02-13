#pragma once
#ifndef _CLIENT_GENERATOR_
#define _CLIENT_GENERATOR_

#include <iostream>
#include <vector>
#include "Client.h"

class ClientGenerator
{
public:
	std::vector<Client> operator ()(const std::vector<std::string>& firstNames, const std::vector<std::string>& lastNames) noexcept;
};

#endif // !_CLIENT_GENERATOR_


