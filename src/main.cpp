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