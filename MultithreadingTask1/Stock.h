#pragma once
#ifndef _STOCK_
#define _STOCK_

#include <iostream>
#include <string>

struct Stock
{
public:
	Stock(const std::string& title, const double basePrice);
	const std::string Title() const;

private:
	const std::string	m_title;
	double				m_price = 0;
};


#endif // !_STOCK_



