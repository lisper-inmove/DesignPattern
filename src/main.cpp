#include <vector>
#include <iostream>
#include <memory>
#include "bridge.h"

using namespace std;

int main()
{
	auto tv = std::make_shared<Tivision>();
	Remote* r = new AdvancedRemote(tv);
	r->togglePower();
	r->channelUp();
	r->volumeDown();
	return 0;
}