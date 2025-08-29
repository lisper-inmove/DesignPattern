#pragma once

/**
	生成器模式（Builder Pattern）是一种创建型设计模式，它通过将复杂对象的构建过程与其表示分离，

*/

#include <string>
#include <iostream>
#include <vector>

class Car {
private:
	std::string type_;

public:
	std::vector<std::string> steps_;

	Car(std::string type) : type_(type) {}
	void list() const {
		std::cout << "\n Product " << type_ << " Steps" << std::endl;
		for (const auto& s : steps_) std::cout << " - " << s << std::endl;
	}
};

class ICarBuilder {
public:
	virtual void reset() = 0;
	virtual void buildChassis() = 0;
	virtual void installEngine() = 0;
	virtual void installWheels() = 0;
	virtual void paint(const std::string color) = 0;
	virtual void installElectronics() = 0;
	virtual Car getResult() = 0;
};

class SportsCarBuilder : public ICarBuilder {
private:
	Car car_{ "Sports Car" };
public:
	void reset() override {
		car_.steps_.clear();
	}
	void buildChassis() override {
		car_.steps_.push_back("Sports Car Chassis");
	}
	void installEngine() override {
		car_.steps_.push_back("Sports Car Engine");
	}
	void installWheels() override {
		car_.steps_.push_back("Sports Car Wheels");
	}
	void paint(const std::string color) override {
		car_.steps_.push_back("Sports Car Painted " + color);
	}
	void installElectronics() override {
		car_.steps_.push_back("Sports Car Electronics");
	}
	Car getResult() override {
		return car_;
	}
};

class SUVCarBuilder : public ICarBuilder {
private:
	Car car_{ "SUV Car" };
public:
	void reset() override {
		car_.steps_.clear();
	}
	void buildChassis() override {
		car_.steps_.push_back("SUV Car Chassis");
	}
	void installEngine() override {
		car_.steps_.push_back("SUV Car Engine");
	}
	void installWheels() override {
		car_.steps_.push_back("SUV Car Wheels");
	}
	void paint(const std::string color) override {
		car_.steps_.push_back("SUV Car Painted " + color);
	}
	void installElectronics() override {
		car_.steps_.push_back("SUV Car Electronics");
	}
	Car getResult() override {
		return car_;
	}
};

class Director {
public:
	void setBuilder(ICarBuilder* builder) {
		builder_ = builder;
	}

	Car makeSportsCar() {
		builder_->reset();
		builder_->buildChassis();
		builder_->installEngine();
		builder_->installWheels();
		builder_->paint("Red");
		builder_->installElectronics();
		return builder_->getResult();
	}

	Car makeSUVCar() {
		builder_->reset();
		builder_->buildChassis();
		builder_->installEngine();
		builder_->installWheels();
		builder_->paint("Black");
		builder_->installElectronics();
		return builder_->getResult();
	}
private:
	ICarBuilder* builder_ = nullptr;
};

/**
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
*/