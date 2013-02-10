#include <iostream>


int main(int argc, char *argv[])
{
    int r = 0;
    int m = 0;
    int n = 0;
    std::cout << "Enter the random number" << std::endl; //что-бы вручную не заполнять массив, и что-бы ничего не подключать. или лучше подключать, чем так?
    std::cin >> r;
    srand(r);
    std::cout << "Enter the m - ";
    std::cin >> m;
    std::cout << "Enter the n - ";
    std::cin >> n;
    int x[m+n];
    for (int i = 1; (i <= (m + n)); i++)
    {
        x[i]=rand() % 100;
        std::cout << x[i];
        std::cout << " ";
    }
    int b = 0;
    for (int i = 1; i <= (m / 2); i++)
    {
        b = x[i];
        x[i] = x[m - i + 1];
        x[m - i + 1] = b;
    }
    for (int i = m + 1; i <= (m + (n / 2)); i++)
    {
        b = x[i];
        x[i] = x[n + (2 * m) - i+1];
        x[n + (2 * m) - i+1] = b;
    }
    std::cout << "\n";
    for (int i = 1; (i <= ((m + n) / 2)); i++)
    {
        b = x[i];
        x[i] = x[m + n - i + 1];
        x[m + n - i + 1] = b;
    }
    for (int i = 1; i <= (m + n); i++)
    {
        std::cout << x[i];
        std::cout << " ";
    }
    std::cin >> n;	
  return 0;
}
