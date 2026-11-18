#include <iostream>
#include <vector>

int main() {
   {
   int a = 10, b = 20;
   int *p = &a , *q = &b;
   p = q;
   ;
   std::cout << "a " << a <<' ' << "b " << b  << "p " << *p <<' '<< "q " << *q << std::endl;
   }
   {
   int a = 10, b = 20;
   int *p = &a , *q = &b;
   *p = *q;
   std::cout << "a " << a <<' ' << "b " << b  << "p " << *p <<' '<< "q " << *q << std::endl;
   }
   return 0;

}
