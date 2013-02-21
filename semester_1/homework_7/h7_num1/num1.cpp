#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout << "This program defines, what student handed over\nwhat solution, and who should be exclude\n\n";
    ifstream text("input.txt");
    if (!text)
    {
        cerr << "Error reading a file" << endl;
        getchar();
        return 1;
    }
    cout << "first column - number of student\nsecond column - number of solution\n\n";
    cout << "0 - student should be exclude\n\n";
    int num = 0;
    text >> num;
    int copiedFrom = 0;
    int studentNum = 0;
    num++;
    int *student = new int[num];
    while (!text.eof()) {
        text >> studentNum;
        text >> copiedFrom;
        student[studentNum] = copiedFrom;
    }
    for (int i = 1; i < num; i++) {
        while (student[i] > 3) {
            student[i] = student[student[i]];
        }
    }
    for (int i = 1; i < num; i++) {
        cout << i << " " << student[i] << endl;
    }
    cout << "\nTo exit the program enter the character ";
    cin >> copiedFrom;
    return 0;
}
