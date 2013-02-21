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
    int c = strlen(b);
    bool a = true;
    for (int i = 0; i < int(c/2); i++) 
    {
        if (b[i] != b[c-i-1])
        {
                a = false;
        }
    }
    if (a == true)
    {
        std::cout << "This string is a palindrome" << std::endl;
    }
    else
    {
        std::cout << "This string is not a palindrome" <<std::endl;
    }
        std::cin >> c;	
    return 0;
}
