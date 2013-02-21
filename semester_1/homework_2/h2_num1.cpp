#include <iostream>

long fiban(int n)
{
    int n1 = 1;
    int n2 = 1;
    for (int i = 2; i <= n; ++i)
    {
        int temp = n1 + n2;
        n1 = n2;
        n2 = temp;
    }
    return n2;
}
    
int main(int argc, char *argv[])
{
    int n = 0;
    std::cout << "Enter then number - ";
    std::cin >> n;
    std::cout << "The Fibonacci number - ";
    std::cout << (fiban2(n));
    std::cout << std::endl;
    std::cin >> n;
    return 0;
}
