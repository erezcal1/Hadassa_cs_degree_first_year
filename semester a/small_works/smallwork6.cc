#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

const int M = 5;
const int S = 3;

//-----prototype ---
void reset_arry (int arr[]);
void read_data (int arr[]);
void print_fun (int arr[]);

int main()
{
    int arr[M];

    reset_arry (arr);
    read_data (arr);
    print_fun (arr);

    return EXIT_SUCCESS;
}

void reset_arry (int arr[M])
{
    for (int i = 0; i < M; i++)
    {
        arr[i] = 0;
    }
}
void read_data (int arr[M])
{
    int index, value;
    for (int i = 0; i < S; i++)
    {
        cin >> index >> value;
        arr[index] = value;
    }
}
void print_fun (int arr[M])
{
    for (int i = 0; i < M; i++)
    {
        cout << arr[i] << " ";
    }
}