#pragma once
#include <string>
#include "Item.h"

class BakeRolls : public Item
{
public:
	enum flavour {SALT, PIZZA, GARLIC, TOMATO, CHEESEANDSPINACH};
private:
	flavour bakeRollsTaste;
public:
	BakeRolls(const double& price, const flavour& bakeRollsTaste);
	Item* clone() const override;
	std::string getTaste() const;
	void setTaste(const flavour& bakeRollsTaste);
	void print() const override;
};
