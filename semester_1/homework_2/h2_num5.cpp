#include <iostream>
#include <ctime>

void down(int a[], int k, int n) 
{
    int child = 0;
    int newelem = a[k];
    while (k <= n/2) 
    {       
        child = 2*k;
        
        if (child < n && a[child] < a[child+1])
        {
            child++;
        }
        if (newelem >= a[child])
        { 
            break;
        } 
        a[k] = a[child];
        k = child;
    }
    a[k] = newelem;
}
 
void sort(int a[], int size) 
{
    long i;
    for (i = ((size / 2) - 1); i >= 0; --i)
    { 
        down(a, i, size-1);
    } 
    for(i = (size - 1); i > 0; --i) 
    {
        int temp = a[i]; 
        a[i] = a[0]; 
        a[0] = temp;
        down(a, 0, i-1); 
    }
}
 
int main(int argc, char *argv[])
{
    int n = 0;
    srand(time(0));
    std::cout << "Enter the n - ";
    std::cin >> n;
    int m[255] = {};
    for (int i = 0; i < n; i++)
    {
        m[i] = ((std::rand() % 20) - 10);
        std::cout << m[i] << " "; 
    }
    std::cout << std::endl;
    sort(m, n);
    for (int i = 0; i < n; i++)
    {
        std::cout << m[i] << " ";
    }
    std::cout << std::endl;
    std::cin >> n;
    return 0;
}
