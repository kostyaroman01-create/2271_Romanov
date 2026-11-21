#include <iostream>
#include <vector>

int main() {
    unsigned a = 8, b = 3, c = 17;
    unsigned* p = &a;
    unsigned* q = &b;
    *p += *q + c;
    std::cout << "a=" << a << " " << "b=" << b << " " << "c=" << c << " " << "p=" << *p << " " << "q=" << *q << std::endl;
    c = *q;
    std::cout << "a=" << a << " " << "b=" << b << " " << "c=" << c << " " << "p=" << *p << " " << "q=" << *q << std::endl;
    p = &c;
    std::cout << "a=" << a << " " << "c=" << c << " " << "p=" << *p  << std::endl;
    c += a;
    std::cout << "a=" << a << " " << "c=" << c  << " " << "p=" << *p <<std::endl;
    *p += 10;
    std::cout << "a=" << a << " " << "c=" << c << " " << "p=" << *p << std::endl;
    *q = *p;
    std::cout << "a=" << a << " " << "b=" << b << " " << "p=" << *p << " " << "q=" << *q << std::endl;
    q = p;
    std::cout << "a=" << a << " " << "b=" << b << " " << "p=" << *p << " " << "q=" << *q << std::endl;
    *q += 10;
    std::cout << "b=" << b << " " << "c=" << c << " " << "q=" << *q << std::endl;
    return 0;
} 
