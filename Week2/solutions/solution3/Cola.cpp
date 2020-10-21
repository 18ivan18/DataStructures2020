#include "Cola.h"
#include <iomanip>
#include <iostream>

Cola::Cola(const double& price, const flavour& colaTaste) : Item(price), colaTaste(colaTaste)
{
}

Item* Cola::clone() const
{
	return new Cola(*this);
}

std::string Cola::getTaste() const
{
	switch (this->colaTaste)
	{
		case ZERO: return "zero";
		case CHERRY: return "cherry";
		case LEMON: return "lemon";
		case VANILLA: return "vanilla";
		case RASPBERRY: return "raspberry";
		case GINGER: return "ginger";
	}
}

void Cola::setTaste(const flavour& colaTaste)
{
	this->colaTaste = colaTaste;
}

void Cola::print() const
{
	std::cout << "Cola price: " << std::fixed << std::setprecision(PRICEPRECISION) << this->getPrice() << "  taste: " << this->getTaste() << "\n";
}
