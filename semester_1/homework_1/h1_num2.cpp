#include <iostream>

int main(int argc, char *argv[])
{
    int a = 0;
    int b = 0;
    std::cout << "Enter the a  " <<std::endl;
    std::cout << "a:=";
    std::cin >> a;
    std::cout << "Enter the b  " <<std::endl;
    std::cout << "b:=";
    std::cin >> b;
    int i = 0;
    while (a >= b)
    {
        a = a - b;
        i++;
    }
    std::cout << "Partial quotient - ";
    std::cout << i << std::endl;
    std::cin >> a;
}
