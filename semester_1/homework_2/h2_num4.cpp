#include <iostream>

int nod(int x, int y)
    { 
        if (y == 0)
        {  
            return x; 
        } 
        return nod(y, x % y);
    }
    
void sort(int n, int m[][2], int k)
{
    for (int i = 1; i < k; i++) 
    {
        int j = i;
        while (j > 0 && ((m[j - 1][0] * m[j][1]) > (m[j][0] * m[j-1][1]))) 
        {
            std::swap(m[j][0], m[j-1][0]);
            std::swap(m[j][1], m[j-1][1]);
            j--;
        }
    }
}

void write(int n, int m[][2], int k)
{
    for (int i = 1; i < k; i++)
    {
        std::cout << m[i][0] << "/" << m[i][1] << std::endl;
    } 
}
    
void work(int n)
{
    int m[255][2] = {};
    int k = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {   
            if (nod(i,j) == 1)
            {
                m[k][0] = j;
                m[k][1] = i;
                k++; 

            }
        }  
    }
    sort(n, m, k);
    write(n, m, k);    
}    


int main(int argc, char *argv[])
{
    int n = 0;
    std::cout << "Enter the n - ";
    std::cin >> n;
    work(n);
    std::cin >> n;
    return 0;
}
