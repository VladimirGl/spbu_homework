#include <iostream>


int main(int argc, char *argv[])
{
    char b[100];
    for (int i = 1; i <= 100; i++)
    {
        b[i] = 0;
    }
    std::cout << "Enter the string" << std::endl;
    std::cin.getline(b, 100); 
    int a = 0;
    for (int i = 0; ((a >= 0) && (i <= strlen(b))); i++)
    {
        if (b[i] == '(')
        {
            a++;
        }
        if (b[i] == ')')
        {
            a--;
        }
    }
    if (a == 0)
    {
        std::cout << "The parentheses placed correctly" << std::endl;
    }
    else
    {
        std::cout << "The parentheses placed incorrectly" << std::endl;
    }
    std::cin >> a;	
    return 0;
}
