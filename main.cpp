#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

int number_of_strings(int argc, char* argv[])
{
    ifstream start(argv[1], ios::in | ios::binary);
    if (!start) {
        cout << "Import file not found, maybe you renamed it" << endl;
        return 0;
    }

    int count = 0;
    while (start.ignore(numeric_limits<streamsize>::max(), '\n')) {
        if (!start.eof())
            count++;
    }

    start.close();
    return count;
}

void swap(int* numbers, char** mass, int strings)
{
    char* temp = new char[100];
    for (int i = 0; i < strings; i++) {
        for (int j = 0; j < strings - 1; j++) {
            if (numbers[i] > numbers[j]) {
                temp = mass[i];
                mass[i] = mass[j];
                mass[j] = temp;
            }
        }
    }
}

void check(int* numbers, char** mass, int strings)
{
    int chitayu = 0, j = 0;
    for (int i = 0; i < strings; i++) {
        chitayu = 0, j = 0;
        while (mass[i][j] != '\0') {
            chitayu++;
            j++;
        }
        numbers[i] = chitayu;
    }
}

int main(int argc, char* argv[])
{
    const int len = 100, strings = number_of_strings(argc, argv);
    const char ch = '\n';
    char** mass = new char*[strings];
    for (int i = 0; i < strings; i++)
        mass[i] = new char[len];

    ifstream work(argv[1], ios::in | ios::binary);

    for (int r = 0; r < strings; r++) {
        work.getline(mass[r], len - 1, ch);
        cout << "String " << r + 1 << " = " << mass[r] << endl;
    }
    work.close();
    int* numbers = new int[strings];
    check(numbers, mass, strings);
    for (int i = 0; i < strings; i++) {
        cout << numbers[i] << endl;
    }
    for (int i = 0; i < strings; i++)
        delete (mass[i]);
    delete (mass);
    delete (numbers);
    return 0;
}
