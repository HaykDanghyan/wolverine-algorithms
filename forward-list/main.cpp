#include <iostream>

#include "forward-list.h"

int main() {
    forward_list<int> f1{1, 2, 3, 4, 5};
    forward_list<int> f2{4, 5, 6, 7, 8};
    f1.insert(2, 99);
    f1.insert(3, 77);
    f1.insert(1, 1);
    f1.erase(1);
    std::cout << f1 << std::endl;
    return 0;
}