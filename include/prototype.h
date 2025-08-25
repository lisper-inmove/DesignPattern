#pragma once

#include <memory>
#include <string>

/**

	ԭ��ģʽ��Prototype Pattern����һ�ִ��������ģʽ����ͨ���������ж����������¶��󣬱����˴�ͷ��ʼʵ��������Ŀ�����
	����ģʽ�ر������ڴ������Ӷ������ҪƵ���������ƶ���ĳ�����
	��Ҫ��ɫ��
	1. ԭ�ͽӿڣ�Prototype Interface��������һ����¡���������ڸ��ƶ���
	2. ����ԭ���ࣨConcrete Prototype Class����ʵ��ԭ�ͽӿڣ��ṩ��¡�����ľ���ʵ�֡�
	3. �ͻ��ˣ�Client����ͨ�����ÿ�¡�����������¶��󣬶�����ֱ��ʵ�����ࡣ

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