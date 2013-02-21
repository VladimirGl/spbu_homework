#include <iostream>

int fact1(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return (n * fact1(n - 1));
    }
} 

int fact2(int n)
{
    int a = 1;
    for (int i = 1; i <= n; i++)
        a = a * i;
    return a;
}    

int main(int argc, char *argv[])
{
    int n = 0;
    std::cout << "Enter the number - ";
    std::cin >> n;
    std::cout << "n!=";
    std::cout << (fact1(n)) << std::endl;
    std::cout << "n!=";
    std::cout << (fact2(n)) << std::endl;   
    std::cin >> n;    
    return 0;
}
