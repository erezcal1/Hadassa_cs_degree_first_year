#include <iostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <cstring>
#include <string.h>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

const int ROWS = 5;
const int COLS = 10;

void read_data(char str[ROWS][COLS]);
void bubble_sort(char str[ROWS][COLS]);
void printing(char str[ROWS][COLS]);

int main()
{
    char str[ROWS][COLS];

    read_data(str);
    bubble_sort(str);
    printing(str);

    return EXIT_SUCCESS;
}

void read_data(char str[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        cin >> setw(COLS + 1) >> str[i];
    }
}

void bubble_sort(char str[ROWS][COLS])
{
    char temp[COLS];

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = i+1; j < ROWS; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[i]);
                strcpy(str[i], temp);
            }
        }
    }
}

void printing(char str[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        cout << str[i] << endl;
    }
}
