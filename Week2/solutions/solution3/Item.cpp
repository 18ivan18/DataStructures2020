#include "Item.h"

Item::Item()
{
	price = 0;
}

Item::Item(const double& price)
{
	this->price = price;
}

double Item::getPrice() const
{
	return price;
}

void Item::setPrice(const double& price)
{
	this->price = price;
}
