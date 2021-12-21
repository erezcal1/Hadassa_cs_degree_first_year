/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program gets 12 numbers 3 for the first arry and 9 for the second.
It prints  the first number that start the wich the first arry is located in.
The first arry needs to be in the same order without any 
inturaptuins if the program dosent find arry 1 in the second arry it pronts -1.

input: arry 1: 3 numbers, arry 2: 9 numbers.

output: the nuber the program find the start of the first arry if 
it dosent find it prints  -1.

*/
//---------include section---------
#include <iostream>
#include <cstdlib>

//----------using section----------
using std::cout;
using std::cin;

//---------const section----------
const int N = 3;
const int M = 9;

//---------main section-------
int main ()
{
    //addining ints in to the program to recognize
    int short_arr[N], long_arr[M], i, j = 0;
    bool found = false; // restarrting found with false

    for (i = 0; i < N; i++)
    {
        cin >> short_arr[i];
    }

    //inserting values to long arry
    for (i = 0; i < M; i++)
    {
        cin >> long_arr[i];
    }
    //run on the arr and cheking iof the terms are valid
    for (i = 0; i < M; i++)
    {
        if ((short_arr[j] == long_arr[i]) && (short_arr[j + 1] == 
        long_arr[i + 1]) && (short_arr[j + 2] == long_arr[i + 2]))
        {
            //if the terms are valid it end the program and 
            //prits the number that i started with
            found = true;
            cout << i;
            break;
        }
    }
    //if no terms were mateched it prints -1
    if (!found)
    {
        cout << -1;
    }
    // the end of the program
    return EXIT_SUCCESS;
}
