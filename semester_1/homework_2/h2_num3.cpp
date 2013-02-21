
#include <iostream>
void permutation(int left, int sum[], int const &n, int min = 0, int i = 0)
{
    if ((left < 0) || (min == n))
    {
        return;
    }
    sum[i] = min;
    if (min != 0)
    {
        permutation(left - min, sum, n, min, i + 1);
    }
    permutation(left - 1, sum, n, min + 1, i);
    if (left == 0)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j != i)
            {
                std::cout << sum[j] << '+';
            }
            else
            {
                std::cout << sum[j] << std::endl;
            }
        }
    }
}
int main(int argc, char *argv[])
{
    int n = 0;
    int sum[255] = {};
    std::cout << "Enter the number - ";
    std::cin >> n; 
    permutation(n, sum, n);
    std::cout << "To exit the program enter a character ";
    std::cin >> n;
    return 0;
}
