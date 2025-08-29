#pragma once

/**
	������ģʽ��Adapter Pattern����һ�ֽṹ�����ģʽ��ּ�ڽ�һ����Ľӿ�ת���ɿͻ�����������һ���ӿڡ�
	������ģʽʹ��ԭ�����ڽӿڲ����ݶ�����һ�����������Эͬ������

	����X������Ҫʹ��A�ࡣ��ʱ�������һ��B�࣬B��Ľӿں�A�಻���ݣ�
	��B����X��������Ҫ�Ĺ��ܣ���ʱ�Ϳ���ʹ��������ģʽ��
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