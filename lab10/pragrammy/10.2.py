#include <iostream>
#include <vector>

int main() {
    double x[10];
    for (int i = 0; i < 10; i++) {
        size_t npa = reinterpret_cast <size_t>(&x[i]);
        std::cout << npa << std::endl;
    }
    return 0;
}
