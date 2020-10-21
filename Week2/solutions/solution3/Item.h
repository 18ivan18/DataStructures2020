#pragma once
#define PRICEPRECISION 2

class Item
{
private:
	double price;
public:
	Item();
	Item(const double& price);

	virtual Item* clone() const = 0;

	double getPrice() const;
	void setPrice(const double& price);
	virtual void print() const = 0;
};