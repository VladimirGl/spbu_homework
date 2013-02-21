#include <iostream>

long numpower(long a, long k)
{
    long b = 1;
    while (k) 
    {
         if ((k % 2) == 0) 
         {
              k = k / 2;
              a = a * a;
         }
         else 
         {
              k--;
              b = b * a;
         }
    }
    return b;
}


int main(int argc, char *argv[])
{
    int num = 0;
    int pow = 0;
    std::cout << "a ^ n" << std::endl;
    std::cout << "Enret the a - ";
    std::cin >> num;
    std::cout << "Enter the n - ";
    std::cin >> pow;
    std::cout << "a ^ n = ";
    std::cout << numpower(num, pow) << std::endl;
    std::cin >> pow;
  
  return 0;
}
