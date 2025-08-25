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