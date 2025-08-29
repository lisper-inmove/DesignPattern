#pragma once

/**
	装饰器模式（Decorator Pattern）是一种结构型设计模式，旨在动态地为对象添加额外的职责或行为，

*/

#include <string>
#include <iostream>

class DataSource {
protected:
	std::string data_;
public:
	virtual ~DataSource() = default;
	virtual void writeData(const std::string& data) = 0;
	virtual std::string readData() = 0;
};

class FileDataSource : public DataSource {
private:
	std::string filename_;
public:
	explicit FileDataSource(const std::string& filename) : filename_(filename) {}
	void writeData(const std::string& data) override {
		data_ = data; 
		std::cout << "Write data to file: " << data_ << std::endl;
	}
	std::string readData() override {
		std::cout << "Read data from file: " << data_ << std::endl;
		return data_; 
	}
};

class DataSourceDecorator : public DataSource {
private:
	DataSource* wrappee_{nullptr};
public:
	DataSourceDecorator(DataSource* source) : wrappee_(source) {}
	void writeData(const std::string& data) override {
		wrappee_->writeData(data);
	}
	std::string readData() override {
		return wrappee_->readData();
	}
};

class EncryptionDecorator : public DataSourceDecorator {
public:
	EncryptionDecorator(DataSource* source) : DataSourceDecorator(source) {}
	void writeData(const std::string& data) override {
		std::string encrypted = "encrypted(" + data + ")";
		// 直接调用父类的writeData方法，从而达到转发的目地，也能将子类与wrappee_解耦
		DataSourceDecorator::writeData(encrypted);
	}
	std::string readData() override {
		std::string data = DataSourceDecorator::readData();
		if (data.find("encrypted(") == 0 && data.back() == ')') {
			return data.substr(10, data.size() - 11); // remove "encrypted(" and ")"
		}
		return data;
	}
};

class DecompressionDecorator : public DataSourceDecorator {
public:
	DecompressionDecorator(DataSource* source) : DataSourceDecorator(source) {}
	void writeData(const std::string& data) override {
		std::string compressed = "compressed(" + data + ")";
		DataSourceDecorator::writeData(compressed);
	}
	std::string readData() override {
		std::string data = DataSourceDecorator::readData();
		if (data.find("compressed(") == 0 && data.back() == ')') {
			return data.substr(11, data.size() - 12); // remove "compressed(" and ")"
		}
		return data;
	}
};

/**
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
*/