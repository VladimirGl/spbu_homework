#include <iostream>

int main(int argc, char *argv[])
{
    int n = 0;
    std::cout << "Enter the number - ";
    std::cin >> n;
    bool a = false;
    for (int i = 1; i <= n; i++)
    {  
        a = false;
        for (int j = 2; (j < int(sqrt(i)) + 1); j++)
        {
            if ((i % j) == 0 )
            a = true;
        }
        if (a == false) {
            std::cout << i;
            std::cout << " ";
        }
    }        
    std::cin >> a;        
    return 0;
}
