#pragma once
#include <string>
#include "Item.h"

class Water : public Item
{
public:
	enum bottleSize {HALFLITRE, ONELITRE, LITREANDHALF};
private:
	bottleSize size;
public:
	Water(const double& price, const bottleSize& size);
	Item* clone() const override;
	std::string getSize() const;
	void setSize(const bottleSize& size);
	void print() const override;
};
