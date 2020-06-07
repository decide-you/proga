#include <fstream>
#include <iostream>
#include <limits>
using namespace std;

int number_of_strings(int argc, char* argv[])
{
    ifstream start(argv[1]);
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
    char* b = new char[100];
    for (int i = 0; i < strings; i++) {
        for (int j = 0; j < strings - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                cout << "numbers[j]=" << numbers[j]
                     << " numbers[j+1]=" << numbers[j + 1] << endl;
                b = mass[j]; // создали дополнительную переменную
                cout << "b = " << b << " mass[j]=" << mass[j] << endl;
                mass[j] = mass[j + 1]; // меняем местами
                mass[j + 1] = b;       // значения элементов
            }
        }
    }
}

void output(char** mass, int strings)
{
    FILE* out = fopen("out.txt", "w");
    for (int i = 0; i < strings; i++) {
        fputs(mass[i], out);
        fputs("\n", out);
    }

    fclose(out);
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

    ifstream work(argv[1]);

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
    swap(numbers, mass, strings);
    output(mass, strings);
    for (int i = 0; i < strings; i++) {
        cout << endl << endl << mass[i] << endl;
    }
    for (int i = 0; i < strings; i++)
        delete (mass[i]);
    delete (mass);
    delete (numbers);
    return 0;
}
