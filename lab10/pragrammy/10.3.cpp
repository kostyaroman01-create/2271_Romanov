#include <iostream>
#include <vector>

int main() {
    int a = 10, b = 20,y=30;
    int *p = &a, *q = &b, &s=y;
    *p = *q * 2;
    y = *q;
    if (y & *q) {
        std::cout << "y " << y << ' ' << "s " << s << std::endl;
    }
    std::cout << "a " << a << ' ' << "b " << b<< ' ' << "y " << y << " p " << *p << ' ' << "q " << *q<< ' ' << "s " << s << std::endl;
    return 0;
}
