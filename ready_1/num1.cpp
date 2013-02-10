#include <iostream>

int main(int argc, char *argv[])
{
    int x = 0;
    std::cout << "Enter the x  " <<std::endl;
    std::cout << "x:=";
    std::cin >> x;
    int y = x * x;
    int g = (y + 1) * (y + x) + 1;
    std::cout << "x^4+x^3+x^2+x+1=";
    std::cout << g << std::endl;
    std::cin >> x;
}
