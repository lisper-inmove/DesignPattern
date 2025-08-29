#include <vector>
#include <iostream>
#include <memory>
#include "decorator.h"

using namespace std;

int main()
{
	DataSource* source = new FileDataSource("file.txt");
	source = new EncryptionDecorator(source);
	source = new DecompressionDecorator(source);
	source->writeData("Hello, World!");
    return 0;
}