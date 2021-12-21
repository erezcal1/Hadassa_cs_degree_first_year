/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program gets 6 numbers in an arry and show how much values 
in the arry. It prtints the number that divide by the previus 
arry without a remainder left and divide the nuimber after 
them without a remainder left too.

input: 6 numbers in arry

output: number that divide the last number and the number after in order

*/
//---------include section---------
#include <iostream>
#include <cstdlib>

//----------using section----------
using std::cout;
using std::cin;

//---------const section----------
const int N = 6;

//---------main section-------
int main ()
{
    //addining int in to the program to recognize
    int arr[N], counter = 0, i;

    //inserting values to arry
    for (i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    
    //run on the arr and cheking iof the terms are valid
    for (i = 1; (i + 1) < N; i++)
    {
        if (((arr[i] % arr[i - 1] == 0)) && ((arr[i + 1] % arr[i]  == 0)))
        {
            counter++; //ading numbers if they did
        }
    }
    //cout the numbers the fit
    cout << counter;
    
    // finishing the program with success
    return EXIT_SUCCESS;
}
