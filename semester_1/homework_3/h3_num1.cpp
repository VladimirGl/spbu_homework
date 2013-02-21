#include <cstdlib>
#include <iostream>

using namespace std;

void qSort(int *array,int first, int last) {   
    int average = array[first + (last - first)/ 2];
    int newFirst = first;
    int newLast = last;
    while (newFirst <= newLast) {
        while (array[newFirst] < average)
            newFirst++;
        while (array[newLast] > average)
            newLast--;
        if (newFirst <= newLast) {
            swap(array[newFirst], array[newLast]);
            newFirst++;
            newLast--;
        }
    }
    if (newFirst < last)
        qSort(array, newFirst, last);
    if (first < newLast)
        qSort(array, first, newLast);
}

int ununiqueMax(int *array, int size) {
    for (int i = (size - 1); i > 0; i--)
        if (array[i] == array[i - 1])
            return i;
    return -1;
}
    

int main()
{
    cout << "This program search for nonunique member of array\n"
            "Enter the nubber of elements ";
    int size = 0;
    cin >> size;
    int *array = new int[size];
    cout << "Enter the elements\n";
    for (int i = 0; i < size; i++) 
        cin >> array[i];
    qSort(array, 0, size - 1);
    int numOfMax = ununiqueMax(array, size);
    if (numOfMax != -1)
        cout << "Ununique max element - " << array[numOfMax] << endl;
    else
        cout << "No ununique max element's in array\n";

    cout << "To exit the program enter the character ";
    cin >> numOfMax;
    
    delete[] array;
        
    return 0;
}
