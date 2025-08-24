#include <vector>
#include <iostream>
#include "builder.h"

using namespace std;

int main()
{
	Director director;
	SportsCarBuilder sportsBuilder;
	director.setBuilder(&sportsBuilder);
	director.makeSportsCar();
	Car car = sportsBuilder.getResult();
	car.list();
	return 0;
}