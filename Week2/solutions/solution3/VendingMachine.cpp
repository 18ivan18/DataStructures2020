#include "VendingMachine.h"

bool VendingMachine::hasEmpty() const
{
    return slotCola.empty() || slotWater.empty() || slotCroissant.empty() || slotBakeRolls.empty();
}

void VendingMachine::addItem(const short slotNumber, const Item& item)
{
	switch (slotNumber)
	{
		case 1: slotCola.push(item.clone()); break;
		case 2: slotWater.push(item.clone()); break;
		case 3: slotCroissant.push(item.clone()); break;
		case 4: slotBakeRolls.push(item.clone()); break;
	}
}

Item* VendingMachine::consume(const short slotNumber)
{
	Item* item = nullptr;
	switch (slotNumber)
	{
	case 1: item = slotCola.top(); slotCola.pop();break;
	case 2: item = slotWater.top(); slotWater.pop(); break;
	case 3: item = slotCroissant.top(); slotCroissant.pop(); break;
	case 4: item = slotBakeRolls.top(); slotBakeRolls.pop(); break;
	}
	return item;
}

VendingMachine::~VendingMachine()
{
	while(!slotCola.empty())
	{
		delete slotCola.top();
		slotCola.pop();
	}
	while(!slotWater.empty())
	{
		delete slotWater.top();
		slotWater.pop();
	}
	while(!slotCroissant.empty())
	{
		delete slotCroissant.top();
		slotCroissant.pop();
	}
	while(!slotBakeRolls.empty())
	{
		delete slotBakeRolls.top();
		slotBakeRolls.pop();
	}
}
