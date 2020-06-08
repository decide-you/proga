#include <fstream>
#include <iostream>
#include <limits>
#include <strings.h>
using namespace std;
int number_of_strings(char* argv[])
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


