#include <iostream>

using namespace std;

void bubbleSort(int *a, int n)
{
    bool f = 1;
    while (f)
    {
        f = 0;
        for (int i = 0; i < n - 1; ++i)
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                f = 1;
            }
    }
}

int main() {
    cout << "Bubble Sort:" << endl;
    cout << "Enter the number of elements: ";
    int num = 0;
    cin >> num;
    int *array = new int[num];
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < num; i++) {
        cin >> array[i];
    }
    bubbleSort(array, num);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < num; i++) {
        cout << array[i] << " ";
    }
    cout << endl << "To exit the program enter the character ";
    cin >> num;
    delete[] array;
    return 0;
}
    
