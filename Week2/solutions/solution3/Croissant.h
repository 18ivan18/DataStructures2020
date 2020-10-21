#pragma once
#include <string>
#include "Item.h"

class Croissant : public Item
{
public:
	enum flavour {CHERRY, COCONUT, STRAWBERRY, HAZELNUT};
private:
	flavour croissantTaste;
public:
	Croissant(const double& price, const flavour& croissantTaste);
	Item* clone() const override;
	std::string getTaste() const;
	void setTaste(const flavour& croissantTaste);
	void print() const override;
};
