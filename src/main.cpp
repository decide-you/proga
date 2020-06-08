#include <fstream>
#include <iostream>
#include <limits>
#include <strings.h>
#include <sort.h>
#include <work_with_array.h>
using namespace std;

int main(int argc, char* argv[])
{
    const int len = 100, strings = number_of_strings(argv);
    const char ch = '\n';
    char** mass = new char*[strings];
    for (int i = 0; i < strings; i++)
        mass[i] = new char[len];

    ifstream work(argv[1]);

    for (int r = 0; r < strings; r++)
        work.getline(mass[r], len - 1, ch);
    work.close();
    int* numbers = new int[strings];
    check(numbers, mass, strings);
    swap(numbers, mass, strings);
    output(mass, strings, argv, 2);
    sort(numbers, mass, strings);
    output(mass, strings, argv, 3);
    for (int i = 0; i < strings; i++)
        delete (mass[i]);
    delete (mass);
    delete (numbers);
    return 0;
}
