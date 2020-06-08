#include <fstream>
#include <iostream>
#include <limits>
#include <strings.h>
using namespace std;
void sort(int* numbers, char** mass, int strings)
{
    char* temp = new char[100];
    int check = 0;
    for (int i = 0; i < strings; i++) {
        for (int j = 0; j < strings - 1; j++) {
            check = strcasecmp(mass[j], mass[j + 1]);
            if (check > 0) {
                temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = temp;
            }
        }
    }
}

void swap(int* numbers, char** mass, int strings)
{
    char* b = new char[100];
    int c;
    for (int i = 0; i < strings; i++) {
        for (int j = 0; j < strings - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                c = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = c;
                b = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = b;      
            }
        }
    }
}

void output(char** mass, int strings, char* argv[], int c)
{
    FILE* out = fopen(argv[c], "w");
    for (int i = 0; i < strings; i++) {
        fputs(mass[i], out);
        fputs("\n", out);
    }

    fclose(out);
}
