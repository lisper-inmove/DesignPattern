#include <vector>
#include <iostream>
#include "abstract_factory.h"

using namespace std;

int main()
{
	FurnitureFactory* factory = new VictorianFactory();
	Chair* chair = factory->createChair();
	chair->sitOn();
	Sofa* sofa = factory->createSofa();
	sofa->lieOn();
	CoffeeTable* table = factory->createCoffeeTable();
	table->putOn();

	return 0;
}