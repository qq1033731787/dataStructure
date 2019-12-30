//
// Created by lzk on 2019-12-18.
//

#include "stack.h"

int main() {
    auto ds = new doubleStack<int>(5);
    ds->S1.push(1);
    ds->S1.push(2);
    ds->S1.push(3);
    ds->S2.push(1);
    ds->S2.push(2);
    std::cout << std::boolalpha <<(ds->S1.isFull() && ds->S2.isFull()) << std::endl;

    std::cout << (ds->S1.push(1) || ds->S2.push(1)) << std::endl;

    int tmp;
    ds->S1.pop(tmp);
    std::cout << "S1 pop "  << tmp << std::endl;
    ds->S1.pop(tmp);
    std::cout << "S1 pop "  << tmp << std::endl;
    ds->S1.pop(tmp);
    std::cout << "S1 pop "  << tmp << std::endl;
    ds->S2.pop(tmp);
    std::cout << "S2 pop "  << tmp << std::endl;
    ds->S2.pop(tmp);
    std::cout << "S2 pop "  << tmp << std::endl;

    std::cout << (ds->S1.isEmpty() && ds->S2.isEmpty()) << std::endl;

    std::cout << (ds->S1.pop(tmp) || ds->S2.pop(tmp)) << std::endl;


}