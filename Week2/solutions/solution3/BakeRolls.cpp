#include "BakeRolls.h"
#include <iomanip>
#include <iostream>

BakeRolls::BakeRolls(const double& price, const flavour& bakeRollsTaste) : Item(price), bakeRollsTaste(bakeRollsTaste)
{
}

Item* BakeRolls::clone() const
{
	return new BakeRolls(*this);
}

std::string BakeRolls::getTaste() const
{
	switch (this->bakeRollsTaste)
	{
		case SALT: return "salt";
		case PIZZA: return "pizza";
		case GARLIC: return "garlic";
		case TOMATO: return "tomato";
		case CHEESEANDSPINACH: return "cheese & spinach";
	}
}

void BakeRolls::setTaste(const flavour& bakeRollsTaste)
{
	this->bakeRollsTaste = bakeRollsTaste;
}

void BakeRolls::print() const
{
	std::cout << "BakeRolls price: " << std::fixed << std::setprecision(PRICEPRECISION) << this->getPrice() << "  taste: " << this->getTaste() << '\n';
}
