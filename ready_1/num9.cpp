#include <iostream>
 
int main(int argc, char *argv[])
{
    int n = 0;
    int a = 0;
    int b = 0;
    std::cout << "a^n" << std::endl;
    std::cout << "Enter the a - ";
    std::cin >> a;
    std::cout << "enter the n - ";
    std::cin >> n;
    b = a;
    for (int i = 1; i < n; i++)
        a = a * b;
    std::cout<<"a^n=";
    std::cout << a << std::endl;
    std::cin >> a;

}
