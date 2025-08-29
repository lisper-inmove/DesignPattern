#pragma once

/**
	工厂方法模式（Factory Method Pattern）是一种创建型设计模式，它定义了一个用于创建对象的接口，

	以下例子中:
	Logistics 类是一个抽象类，定义了一个工厂方法 createTransport()，用于创建 Transport 对象。

	RoadLogistics 和 SeaLogistics 是 Logistics 的具体子类，实现了 createTransport() 方法，分别创建 Truck 和 Ship 对象。
	SeaLogistics 负责海运，RoadLogistics 负责陆运。

*/

#include <iostream>
#include <memory>

class Transport {
public:
	virtual void deliver() = 0;
};

class Truck : public Transport {
public:
	void deliver() override {
		std::cout << "Truck transport\n";
	}
};

class Ship : public Transport {
public:
	void deliver() override {
		std::cout << "Ship transport\n";
	}
};

class Logistics {
public:
	void planDelivery() {
		auto t = createTransport();
		t->deliver();
	}
	virtual std::unique_ptr<Transport> createTransport() = 0;
};

class RoadLogistics : public Logistics {
public:
	std::unique_ptr<Transport> createTransport() override {
		return std::make_unique<Truck>();
	}
};

class SeaLogistics : public Logistics {
public:
	std::unique_ptr<Transport> createTransport() override {
		return std::make_unique<Ship>();
	}
};

/**

#include <vector>
#include <iostream>
#include "factory_method.h"

using namespace std;

int main()
{
	Logistics *l1 = new RoadLogistics();
	l1->planDelivery();

	Logistics* l2 = new SeaLogistics();
	l2->planDelivery();
	return 0;
}

*/