#pragma once

/**
	适配器模式（Adapter Pattern）是一种结构型设计模式，旨在将一个类的接口转换成客户端期望的另一个接口。
	适配器模式使得原本由于接口不兼容而不能一起工作的类可以协同工作。

	调用X函数，要使用A类。这时，如果有一个B类，B类的接口和A类不兼容，
	但B类有X函数所需要的功能，这时就可以使用适配器模式。
*/

#include <math.h>

class IRoundShape {
public:
	virtual ~IRoundShape() = default;
	virtual double getRadius() const = 0;
};

class RoundPeg final :public IRoundShape {
private:
	double radius_;
public:
	RoundPeg(double radius) : radius_(radius) {}
	double getRadius() const override {
		return radius_;
	}
};

class RoundHole {
private:
	double radius_;
public:
	RoundHole(double radius) : radius_(radius) {};
	bool fit(const IRoundShape& shape) {
		return shape.getRadius() <= radius_;
	}
};

class SquarePeg {
private:
	double width_;
public:
	SquarePeg(double width) : width_(width) {}
	double getWidth() {
		return width_;
	}
};

class SquarePegAdapter final : public IRoundShape {
private:
	SquarePeg* peg_{nullptr};
public:
	SquarePegAdapter(SquarePeg* peg) : peg_(peg) {}
	double getRadius() const override {
		return peg_->getWidth() * sqrt(2) / 2;
	}
};

/**
#include <vector>
#include <iostream>
#include "adapter.h"

using namespace std;

int main()
{
	RoundHole hole(5);
	RoundPeg rpeg(5);
	cout << hole.fit(rpeg) << endl;

	SquarePeg speg(5);
	// cout << hole.fit(speg) << endl;  // Error

	SquarePegAdapter adapter(&speg);
	cout << hole.fit(adapter) << endl;

	SquarePeg speg2(10);
	SquarePegAdapter adapter2(&speg2);
	cout << hole.fit(adapter2) << endl;

	return 0;
}

*/