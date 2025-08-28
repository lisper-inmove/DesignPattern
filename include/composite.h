#pragma once

/**
	���ģʽ: ���Ӧ�õĺ���ģ��������״�ṹ��ʾ����Ӧ����ʹ�����ģʽ���м�ֵ��

*/

#include <iostream>
#include <vector>
#include <memory>
#include <string>

// �������
class FileSystemComponent {
public:
    virtual ~FileSystemComponent() = default;
    virtual void show(int depth = 0) const = 0;
};

// Ҷ�ӽڵ㣺�ļ�
class File : public FileSystemComponent {
private:
    std::string name_;
public:
    File(const std::string& name) : name_(name) {}
    void show(int depth = 0) const override {
        std::cout << std::string(depth, '-') << "File: " << name_ << "\n";
    }
};

// ��Ͻڵ㣺�ļ���
class Directory : public FileSystemComponent {
private:
    std::string name_;
    std::vector<std::shared_ptr<FileSystemComponent>> children_;
public:
    Directory(const std::string& name) : name_(name) {}
    void add(const std::shared_ptr<FileSystemComponent>& component) {
        children_.push_back(component);
    }
    void show(int depth = 0) const override {
        std::cout << std::string(depth, '-') << "Dir: " << name_ << "\n";
        for (const auto& child : children_) {
            child->show(depth + 2);
        }
    }
};

/**
#include <vector>
#include <iostream>
#include <memory>
#include "composite.h"

using namespace std;

int main()
{
    auto root = std::make_shared<Directory>("root");
    auto home = std::make_shared<Directory>("home");
    auto user = std::make_shared<Directory>("user");
    auto file1 = std::make_shared<File>("file1.txt");
    auto file2 = std::make_shared<File>("file2.txt");

    user->add(file1);
    home->add(user);
    root->add(home);
    root->add(file2);

    root->show();

    return 0;
}
*/