#include "Croissant.h"
#include <iomanip>
#include <iostream>

Croissant::Croissant(const double& price, const flavour& croissantTaste) : Item(price), croissantTaste(croissantTaste)
{
}

Item* Croissant::clone() const
{
	return new Croissant(*this);
}

std::string Croissant::getTaste() const
{
	switch (this->croissantTaste)
	{
		case CHERRY: return "cherry";
		case COCONUT: return "coconut";
		case STRAWBERRY: return "strawberry";
		case HAZELNUT: return "hazelnut";
	}
}

void Croissant::setTaste(const flavour& croissantTaste)
{
	this->croissantTaste = croissantTaste;
}

void Croissant::print() const
{
	std::cout << "Croissant price: " << std::fixed << std::setprecision(PRICEPRECISION) << this->getPrice() << "   taste: " << this->getTaste() << '\n';
}
