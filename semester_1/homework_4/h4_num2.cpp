#include <cstdlib>
#include <iostream>

using namespace std;

void printSpiral(int **array, int num) {
    int x1 = int(num / 2) + 1;
    int x2 = int(num / 2) + 1;
    cout << array[x1][x2] << " ";
    for (int i = 1; i <= num; i++) {
        if ((i % 2) != 0) {
            for (int j = 1; j <= i && !(x1 == num && x2 == num); j++) {
                x2++;
                cout << array[x1][x2] << " ";
            }
            for (int j = 1; j <= i && !(x1 == num && x2 == num); j++) {
                x1--;
                cout << array[x1][x2] << " ";
            }
        }
        if ((i % 2) == 0) {
            for (int j = 1; j <= i  && !(x1 == num && x2 == num); j++) {
                x2--;
                cout << array[x1][x2] << " ";
            }
            for (int j = 1; j <= i && !(x1 == num && x2 == num); j++) {
                x1++;
                cout << array[x1][x2] << " ";
            }
        }
    }
}     

int main() {
    cout << "This program print array elements at round it on a spiral, since the center" << endl;
    cout << "Array (N x N), N - odd number" << endl;
    cout << "Enter the N - ";
    int num = 0;
    cin >> num;
    
    if (!(num % 2))
    {
        cerr << "N is even" << endl;
        cin >> num;
        return 1;
    }
    int **array = new int*[num + 1]; 
    for (int i = 1; i <= num; ++i)
        array[i] = new int[num + 1];
    int p = 1;
    cout << endl << "Initial array:" << endl;
    for (int i = 1; i <= num; ++i) {
        for (int j = 1; j <= num; ++j) {
            array[i][j] = p;
            p++;
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl << "Print on a spiral:" << endl;
    printSpiral(array, num);
    for (int i = 1; i <= num; ++i) {
        delete[] array[i];
    }
    delete [] array;
    cout << endl << endl << "To exit the program enter the character ";
    cin >> num;
    return 0;
}
