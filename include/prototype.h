#pragma once

#include <memory>
#include <string>

/**

	原型模式（Prototype Pattern）是一种创建型设计模式，它通过复制现有对象来创建新对象，避免了从头开始实例化对象的开销。
	这种模式特别适用于创建复杂对象或需要频繁创建相似对象的场景。
	主要角色：
	1. 原型接口（Prototype Interface）：定义一个克隆方法，用于复制对象。
	2. 具体原型类（Concrete Prototype Class）：实现原型接口，提供克隆方法的具体实现。
	3. 客户端（Client）：通过调用克隆方法来创建新对象，而不是直接实例化类。

	https://www.cnblogs.com/three-fighter/p/12892186.html

*/

class Shape {
public:
	virtual std::unique_ptr<Shape> clone() = 0;
	virtual std::string display() = 0;
};

class Rectangle :public Shape {
private:
	int x_;
	int y_;
public:
	Rectangle(int x, int y) :x_(x), y_(y) {}
	Rectangle(Rectangle* other) {
		x_ = other->x_;
		y_ = other->y_;
	}
	std::unique_ptr<Shape> clone() override {
		return std::make_unique<Rectangle>(*this);
	}

	std::string display() override {
		return "Rectangle: x=" + std::to_string(x_) + ", y=" + std::to_string(y_);
	}
};

/**

#include <vector>
#include <iostream>
#include "prototype.h"

using namespace std;

int main()
{
	Rectangle rect1(10, 20);
	unique_ptr<Shape> rect2 = rect1.clone();
	cout << "Original rectangle." << rect1.display() << endl;
	cout << "Cloned rectangle." << rect2->display() << endl;
	return 0;
}

*/