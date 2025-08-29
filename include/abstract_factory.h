#pragma once

#include <iostream>

/**
	抽象工厂模式（Abstract Factory Pattern）是一种创建型设计模式
*/

class Chair {
public:
	virtual void sitOn() = 0;
};

class Sofa {
public:
	virtual void lieOn() = 0;
};

class CoffeeTable {
public:
	virtual void putOn() = 0;
};

// 抽象工厂接口
class FurnitureFactory {
public:
	virtual Chair* createChair() = 0;
	virtual Sofa* createSofa() = 0;
	virtual CoffeeTable* createCoffeeTable() = 0;
};


// Victorian style furniture
class VictorianChair : public Chair {
public:
	void sitOn() override {
		std::cout << "Victorian Chair sitOn\n";
	}
};
class VictorianSofa : public Sofa {
public:
	void lieOn() override {
		std::cout << "Victorian Sofa lieOn\n";
	}
};
class VictorianCoffeeTable : public CoffeeTable {
public:
	void putOn() override {
		std::cout << "Victorian CoffeeTable putOn\n";
	}
};

class VictorianFactory : public FurnitureFactory {
public:
	Chair* createChair() override {
		return new VictorianChair();
	}
	Sofa* createSofa() override {
		return new VictorianSofa();
	}
	CoffeeTable* createCoffeeTable() override {
		return new VictorianCoffeeTable();
	}
};

// Modern style furniture
class ModernChair : public Chair {
public:
	void sitOn() override {
		std::cout << "Modern Chair sitOn\n";
	}
};
class ModernSofa : public Sofa {
public:
	void lieOn() override {
		std::cout << "Modern Sofa lieOn\n";
	}
};
class ModernCoffeeTable : public CoffeeTable {
public:
	void putOn() override {
		std::cout << "Modern CoffeeTable putOn\n";
	}
};

class ModernFactory : public FurnitureFactory {
public:
	Chair* createChair() override {
		return new ModernChair();
	}
	Sofa* createSofa() override {
		return new ModernSofa();
	}
	CoffeeTable* createCoffeeTable() override {
		return new ModernCoffeeTable();
	}
};

/**
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

*/