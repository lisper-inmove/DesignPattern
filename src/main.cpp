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