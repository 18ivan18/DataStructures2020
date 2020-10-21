#include "Water.h"
#include <iomanip>
#include <iostream>

Water::Water(const double& price, const bottleSize& size) : Item(price), size(size)
{
}

Item* Water::clone() const
{
	return new Water(*this);
}

std::string Water::getSize() const
{
	switch (this->size)
	{
		case HALFLITRE: return "0.5l";
		case ONELITRE: return "1l";
		case LITREANDHALF: return "1.5l";
	}
}

void Water::setSize(const bottleSize& size)
{
	this->size = size;
}

void Water::print() const
{
	std::cout << "Water price: " << std::fixed << std::setprecision(PRICEPRECISION) << this->getPrice() << "   bottleSize: " << this->getSize() << '\n';
}
