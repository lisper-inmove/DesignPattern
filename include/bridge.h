#pragma once

/**
	�Ž�ģʽ��Bridge Pattern����һ�ֽṹ�����ģʽ��ּ�ڽ����󲿷�����ʵ�ֲ��ַ��룬ʹ���ǿ��Զ����ر仯��

	�Ž�ģʽͨ������һ���Žӽӿڣ������󲿷ֺ�ʵ�ֲ��ֽ���Ӷ��������Ƕ�������չ���޸ġ�

	Remote �� Device �����������仯��ά�ȡ�

	Remote ��Ϊ������Զ�̿������������˻����Ĳ����ӿڣ��翪�ء�����������Ƶ���ȡ�
	AdvancedRemote ��Ϊ Remote ����չ�������˾������ܡ�

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