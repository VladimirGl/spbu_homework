#include <iostream>

int main(int argc, char *argv[])
{   
    const int w = 27;
    const int n = 9;
    int a[w];
    for (int i = 0; i <= w; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
          {
               for (int k = 0; k <= n; k++)
                 {
                     a[i + j + k]++;
                 }
          }
    }
    int s = 0;
    for (int i = 0; i <= w; i++)
    {
        s = s + a[i] * a[i];
    }
    std::cout << "The number of happy tickets is ";
    std::cout << s << std::endl;
    std::cin >> s;
    return 0;
}
