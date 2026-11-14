#include <iostream>
#include <vector>

int main() {
    int a = 10, b = 20;
    int* p = &a, * q = &b;
    p = q;
    std::cout << "p: " << *p << " q: " << *q << " a: " << a << " b: " << b << std::endl;
    return 0;
}
