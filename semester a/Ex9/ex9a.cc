//---------include section---------
#include <iostream>
#include <cstdlib>

//----------using section----------
using std::cout;
using std::endl;

//---------const section----------
const int SIZE_OF_ARR = 9;

void biggest_num(int arr[SIZE_OF_ARR], int num);
bool exist(int arr[SIZE_OF_ARR], int num, int i);
bool divide_by_11(int arr[SIZE_OF_ARR]);
void print_arr(int arr[SIZE_OF_ARR]);
bool divide_by_121(int temp[2]);


int main()
{
    int arr[SIZE_OF_ARR] = {9};

    biggest_num(arr, SIZE_OF_ARR);


    return EXIT_SUCCESS;
}

void biggest_num(int arr[SIZE_OF_ARR], int num)
{
    if (num == 0)
    {
        return;
    }

    for (int i = 0; i < SIZE_OF_ARR; i++)
    {
        arr[i] = num;

        if (exist(arr, num, i))
        {
            biggest_num(arr, num - 1);
        }
    }

    if (divide_by_11(arr))
    {
        print_arr(arr);
    }
}

bool exist(int arr[SIZE_OF_ARR], int num, int place)
{

    //check right
    for (int i = 0; i < SIZE_OF_ARR; i++)
    {
        if (i == place)
        {
            continue;
        }

        if (arr[i] == num)
        {
            return true;
        }
    }

    return false;
}

bool divide_by_11(int arr[SIZE_OF_ARR])
{
    int sum_even = 0, sum_odd = 0;

    for (int i = 0; i < SIZE_OF_ARR; i++)
    {
        if (i % 2 == 0)
        {
            sum_even += arr[i];
        }
        else
        {
            sum_odd += arr[i];
        }
    }
    if ((sum_odd - sum_even) % 11 == 0)
    {
        return true;
    }

    return false;
}

void print_arr(int arr[SIZE_OF_ARR])
{
    for (int i = 0; i < SIZE_OF_ARR; i++)
    {
        cout << arr[i];
    }
}
