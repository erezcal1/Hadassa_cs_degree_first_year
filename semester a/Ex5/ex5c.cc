/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program prints a histogram of how much random numbers are divided 
numbers from 2 and 6 and how much prime numebrs are int the array.
Displays a histogram of number occurrences in the array

input: 2 numbers min and max for the random numbers to choose from

output: histogram 

*/
//---------include section---------
#include <iostream>
#include <cstdlib>
#include "histogram.h"

//----------using section----------
using std::cin;
using std::cout;
using std::srand;

//--------const section-----------
const int N = 200;
const int DIVIDE_BY = 6;
char col_title[10];

//------------function------------
void col_add(int arr[]);
int array_cal(int arr[], int);
void counter_prime(int arr[]);

int main()
{
    //addining int in to the program to recognize
    int lo, hi, arr[N];

    //the user adds number to the num and max of the random function 
    //to choose from
    cin >> lo >> hi;
    cout << endl;

     
    srand(101); //randomly assign values to the array
    for (int i = 0; i <= N; i++)
    {
        arr[i] = rand() % (hi - lo + 1) + lo;
    }

    //creating the histogram
    create_hist(30,
                DIVIDE_BY * (COL_MIN_WIDTH + COL_MIN_SPACE),
                DIVIDE_BY,
                "primes and divide-by histogram");

    //counting the prime numbers
    counter_prime(arr);
    //counting how much numebrs divide between 2 and 6
    col_add(arr);

    //drawing the histogram
    draw_hist();
    cout << endl;

    //returning success if the program worked well
    return EXIT_SUCCESS;
}
void col_add(int arr[]) // adding coloms for the histogram to print
{
    for (int n = 2; n <= DIVIDE_BY; n++)
    {
        sprintf(col_title, "div-by-%d", n);
        add_col(n - 1, array_cal(arr, n), 0, 0, col_title, '#');
    }
}

int array_cal(int arr[], int n)//counting how much numbers divide 
                                //in the main numbers from 2 to 6
{
    int counter = 0;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] % n == 0)
            counter++;
    }
    return counter;
}

void counter_prime(int arr[])// serching for primes in the random 
//numbers in the array
{
    int counter = 0;
    bool found = true;
    for (int i = 0; i < N; i++)
    {
        found = true;
        if (arr[i] < 2)
        {
            found = false;
        }
        for (int j = 2; j <= arr[i] / 2; j++)
        {
            if (arr[i] % j == 0)
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            counter++;
        }
    }
    //adding col to the histogram after finding all the prime number 
    //that exiset in the array
    add_col(0, counter, 0, 0, "primes", '#');
}