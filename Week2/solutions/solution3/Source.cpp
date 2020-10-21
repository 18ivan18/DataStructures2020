#include <iostream>
#include <vector>
#include "BakeRolls.h"
#include "Cola.h"
#include "Croissant.h"
#include "VendingMachine.h"
#include "Water.h"


int main()
{
	std::vector<Cola> colas{ Cola(1.10, Cola::flavour::CHERRY),
							 Cola(1.20, Cola::flavour::RASPBERRY),
							 Cola(1.50, Cola::flavour::ZERO) };
	std::vector<Water> waters{ Water(0.50, Water::bottleSize::HALFLITRE),
							   Water(1.20, Water::bottleSize::ONELITRE),
							   Water(1.80, Water::bottleSize::LITREANDHALF) };
	std::vector<Croissant> croissants{ Croissant(1.50, Croissant::flavour::HAZELNUT),
									   Croissant(1.50, Croissant::flavour::CHERRY),
									   Croissant(1.50, Croissant::flavour::COCONUT),
									   Croissant(1.50, Croissant::flavour::STRAWBERRY) };
	std::vector<BakeRolls> bakeRolls{ BakeRolls(1.70, BakeRolls::flavour::PIZZA),
									  BakeRolls(1.70, BakeRolls::flavour::SALT),
									  BakeRolls(1.70, BakeRolls::flavour::GARLIC),
									  BakeRolls(1.70, BakeRolls::flavour::CHEESEANDSPINACH) };

	VendingMachine vm;
	for (Cola cola : colas)
	{
		vm.addItem(1, cola);
	}
	
	for (Water water : waters)
	{
		vm.addItem(2, water);
	}
	
	for (Croissant croissant : croissants)
	{
		vm.addItem(3, croissant);
	}
	
	for (BakeRolls bakeRoll : bakeRolls)
	{
		vm.addItem(4, bakeRoll);
	}

	std::cout << "Check if there is an empty slot:" << std::boolalpha << vm.hasEmpty() << "\n";

	std::cout << "Consume: ";
	vm.consume(1)->print();
	std::cout << "Consume: ";
	vm.consume(1)->print();
	std::cout << "Consume: ";
	vm.consume(4)->print();
	std::cout << "Consume: ";
	vm.consume(4)->print();
	std::cout << "Consume: ";
	vm.consume(4)->print();
	std::cout << "Consume: ";
	vm.consume(4)->print();

	std::cout << "Check if there is an empty slot:" << std::boolalpha << vm.hasEmpty() << "\n";
	
	return 0;
}
