#include "Stock.h"

Stock::Stock(const std::string& title, const double basePrice) : m_title(title), m_price(basePrice) {};

const std::string Stock::Title() const
{
	return m_title;
}