#pragma once

#include <iostream>
#include <mutex>

class Singleton {
private:
    Singleton() { std::cout << "构造函数\n"; }
    ~Singleton() { std::cout << "析构函数\n"; }

    Singleton(const Singleton&) = delete;            // 禁止拷贝
    Singleton& operator=(const Singleton&) = delete; // 禁止赋值

    static Singleton* instance_;
    static std::mutex mtx_;

public:
    static Singleton* getInstance() {
        if (instance_ == nullptr) {
            std::lock_guard<std::mutex> lock(mtx_);
            if (instance_ == nullptr) { // 双重检查锁
                instance_ = new Singleton();
            }
        }
        return instance_;
    }

    void hello() { std::cout << "Hello Singleton!\n"; }
};

// 静态成员初始化
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