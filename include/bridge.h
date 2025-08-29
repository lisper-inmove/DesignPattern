#pragma once

/**
	桥接模式（Bridge Pattern）是一种结构型设计模式，旨在将抽象部分与其实现部分分离，使它们可以独立地变化。

	桥接模式通过引入一个桥接接口，将抽象部分和实现部分解耦，从而允许它们独立地扩展和修改。

	Remote 和 Device 是两个独立变化的维度。

	Remote 作为基础的远程控制器，定义了基本的操作接口，如开关、调节音量和频道等。
	AdvancedRemote 作为 Remote 的扩展，增加了静音功能。

	https://www.cnblogs.com/coodream2009/p/17714431.html
*/

#include <string>
#include <iostream>
#include <memory>

class Device {
public:
	virtual ~Device() = default;
	virtual bool enable() = 0;
	virtual bool disable() = 0;
	virtual bool isEnabled() const = 0;
	virtual int getVolume() const = 0;
	virtual void setVolume(int volume) = 0;
	virtual int getChannel() const = 0;
	virtual void setChannel(int channel) = 0;
protected:
	bool on_{ false };
	int volume_{ 0 };
	int channel_{ 0 };
};

class Remote {
protected:
	std::shared_ptr<Device> device_;
	void requireOn() const {
		if (!device_->isEnabled())
			std::cout << "[warn] device is off; turn it on first.\n";
	}
public:
	explicit Remote(std::shared_ptr<Device> d) : device_(std::move(d)) {}
	virtual ~Remote() = default;
	virtual void togglePower() {
		device_->isEnabled() ? device_->disable() : device_->enable();
	}
	virtual void volumeDown() {
		requireOn();
		device_->setVolume(device_->getVolume() - 1);
	}
	virtual void volumeUp() {
		requireOn();
		device_->setVolume(device_->getVolume() + 1);
	}
	virtual void channelDown() {
		requireOn();
		device_->setChannel(device_->getChannel() - 1);
	}
	virtual void channelUp() {
		requireOn();
		device_->setChannel(device_->getChannel() + 1);
	}
};

class AdvancedRemote : public Remote {
public:
	using Remote::Remote;
	void mute() {
		requireOn();
		device_->setVolume(0);
		std::cout << "Muted\n";
	}
};

class Radio : public Device {
public:
	bool enable() override {
		on_ = true;
		std::cout << "Radio is enabled\n";
		return true;
	}
	bool disable() override {
		on_ = false;
		std::cout << "Radio is disabled\n";
		return true;
	}
	int getVolume() const override {
		std::cout << "Radio volume is " << volume_ << "\n";
		return volume_;
	}
	void setVolume(int volume) override {
		std::cout << "Radio volume set to " << volume << "\n";
		volume_ = volume;
	}
	int getChannel() const override {
		std::cout << "Radio channel is " << channel_ << "\n";
		return channel_;
	}
	void setChannel(int channel) override {
		std::cout << "Radio channel set to " << channel << "\n";
		channel_ = channel;
	}
	bool isEnabled() const override {
		std::cout << "Radio is " << (on_ ? "enabled" : "disabled") << "\n";
		return on_;
	}
};

class Tivision : public Device {
public:
	bool enable() override {
		std::cout << "Tivision is enabled\n";
		on_ = true;
		return true;
	}
	bool disable() override {
		std::cout << "Tivision is disabled\n";
		on_ = false;
		return true;
	}
	int getVolume() const override {
		std::cout << "Tivision volume is " << volume_ << "\n";
		return volume_;
	}
	void setVolume(int volume) override {
		std::cout << "Tivision volume set to " << volume << "\n";
		volume_ = volume;
	}
	int getChannel() const override {
		std::cout << "Tivision channel is " << channel_ << "\n";
		return channel_;
	}
	void setChannel(int channel) override {
		std::cout << "Tivision channel set to " << channel << "\n";
		channel_ = channel;
	}
	bool isEnabled() const override {
		std::cout << "Tivision is " << (on_ ? "enabled" : "disabled") << "\n";
		return on_;
	}
};


/**
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
*/