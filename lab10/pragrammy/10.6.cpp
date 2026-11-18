#include <iostream>
#include <vector>

int main() {
   {
   double x = 0;
   double *d = &x;

   std::cout << reinterpret_cast<size_t>(d)<< std::endl;
   std::cout << reinterpret_cast<size_t>(d + 4)<< std::endl;
   std::cout << reinterpret_cast<size_t>(d - 4)<< std::endl;
   }
   {
   int x= 0;
   int *d = &x;

   std::cout << reinterpret_cast<size_t>(d)<< std::endl;
   std::cout << reinterpret_cast<size_t>(d + 4)<< std::endl;
   std::cout << reinterpret_cast<size_t>(d - 4)<< std::endl;
   }
   {
   char x = 0;
   char *d = &x;

   std::cout << reinterpret_cast<size_t>(d)<< std::endl;
   std::cout << reinterpret_cast<size_t>(d + 4)<< std::endl;
   std::cout << reinterpret_cast<size_t>(d - 4)<< std::endl;
   }
   {
   std::pair<int,double>x={0,0.};
   std::pair<int,double>*d=&x;

   std::cout << reinterpret_cast<size_t>(d)<< std::endl;
   std::cout << reinterpret_cast<size_t>(d + 4)<< std::endl;
   std::cout << reinterpret_cast<size_t>(d - 4)<< std::endl;
   }                      
   return 0;

} 
