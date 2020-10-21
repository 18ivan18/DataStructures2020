#pragma once
#include <string>
#include "Item.h"

class Cola : public Item
{
public:
	enum flavour { CHERRY, LEMON, VANILLA, ZERO, RASPBERRY, GINGER };
private:
	flavour colaTaste;
public:
	Cola(const double& price, const flavour& colaTaste);
	Item* clone() const override;
	std::string getTaste() const;
	void setTaste(const flavour& colaTaste);
	void print() const override;
};
