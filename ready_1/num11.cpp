#include <iostream>


void sort(int x[],int a, int b)
{   
    int q = x[a + (b - a)/ 2];
    int i = a;
    int j = b;
    while (i <= j)
    {
        while (x[i] < q) 
        { 
            i++;
        }
        while (x[j] > q) 
        {
            j--;
        }
        if (i <= j)
        {
            std::swap(x[i], x[j]);
            i++;
            j--;
        }
    }
    if (i < b)
    {
        sort(x, i, b);
    }
    if (a < j)
    {
        sort(x, a, j);
    }
}
            
        
int main()
{
    int x[256];
    int r = 0;
    int n = 0;
    std::cout << "Enter the random number" << std::endl; 
    std::cin >> r;
    srand(r);
    std::cout << "Enter the number of elements";
    std::cin >> n;
    for (int i = 0; i <= n-1; i++)
    {
        x[i]=rand() % 100;
        std::cout << x[i] << " ";
    }
    sort(x, 0, n - 1);
    std::cout << "\n";
    for (int i = 0; i <= n-1; i++)
    {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;
    std::cin >> n;	
  return 0;
}
