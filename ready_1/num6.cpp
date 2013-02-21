#include <iostream>


int main(int argc, char *argv[])
{
    char b[100], a[100];
    for (int i = 1; i <= 100; i++)
    {
        b[i] = 0; //чем заполнять массивы символов сразу после инициализации?
        a[i] = 0;
    }
    std::cout << "Enter the first string" << std::endl;
    std::cin.getline(b, 100); 
    std::cout << "Enter the second string" << std::endl;
    std::cin.getline(a, 100);
    bool k = true;
    int p = 0;
    for (int i = 0; (i <= ((strlen(b)-strlen(a)))); i++)
    {
        k = true;
        for (int j = 0; (j <= strlen(a)-1); j++)
        {
            if (b[i+j] != a[j])
            {
                k = false;
            }
        }
        if (k == true) 
        {
            p++;
        }       
    }
    std::cout << "The number of coincidences - ";
    std::cout << p << std::endl;
    std::cin >> p;	
    return 0;
}
