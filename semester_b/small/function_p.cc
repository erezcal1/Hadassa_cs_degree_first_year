#include <iostream>
#include <cstdlib>
#include <algorithm> 

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

const int HIGH = 3;
const int LOW = 4;

void read_data(int arr[HIGH][LOW]);
int min (int arr[LOW]);
int max (int arr[LOW]);
void start(int (*func)(int row[]), int arr[HIGH][LOW]);

int main()
{
    int arr[HIGH][LOW];

    read_data(arr);

    int(*func)(int row[LOW]);
    func = min;
    start(func, arr);
    cout << "\n";
    func = max;
    start(func, arr);
    cout << "\n";

    return EXIT_SUCCESS;
}

void read_data(int arr[HIGH][LOW])
{
    for (int i = 0; i < HIGH; i++)
    {
        for (int j = 0; j < LOW; j++)
        {
            cin >> arr[i][j];
        }
    }
}

int min (int arr[])
{
    int min_num = arr[0];

    for (int i = 0; i < LOW; i++)
    {
        if (arr[i] < min_num)
        {
            min_num = arr[i];
        }
    }
    return min_num;
}

int max (int arr[])
{
    int max_num = arr[0];

    for (int i = 0; i < LOW; i++)
    {
        if (arr[i] > max_num)
        {
            max_num = arr[i];
        }
    }
    return max_num;
}

void start(int (*func)(int row[]), int arr[HIGH][LOW])
{
    for (int i = 0; i < HIGH; i++)
    {
        cout << func(arr[i]) << " ";
    }
}