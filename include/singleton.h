#pragma once

#include <iostream>
#include <mutex>

class Singleton {
private:
    Singleton() { std::cout << "���캯��\n"; }
    ~Singleton() { std::cout << "��������\n"; }

    Singleton(const Singleton&) = delete;            // ��ֹ����
    Singleton& operator=(const Singleton&) = delete; // ��ֹ��ֵ

    static Singleton* instance_;
    static std::mutex mtx_;

public:
    static Singleton* getInstance() {
        if (instance_ == nullptr) {
            std::lock_guard<std::mutex> lock(mtx_);
            if (instance_ == nullptr) { // ˫�ؼ����
                instance_ = new Singleton();
            }
        }
        return instance_;
    }

    void hello() { std::cout << "Hello Singleton!\n"; }
};

// ��̬��Ա��ʼ��
Singleton* Singleton::instance_ = nullptr;
std::mutex Singleton::mtx_;

/**
#include <vector>
#include <iostream>
#include "singleton.h"

using namespace std;

int main()
{
    Singleton* s1 = Singleton::getInstance();
    return 0;
}

*/