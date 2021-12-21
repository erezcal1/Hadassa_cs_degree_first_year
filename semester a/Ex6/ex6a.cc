/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program gets an arry in the size of 4 by 5 and serching for a row where 
there biggest numbers are and after that it look at the coloms and serches for
the biggest colom there is and prints them both one at a time at this order.

input: an array in the size of 4 rows and 5 coloms

output: the biggest row and then the biggest colom

*/
//---------include section---------
#include <iostream>
#include <cstdlib>

//----------using section----------
using std::cout;
using std::cin;
using std::endl;

//---------const section----------
const int COLS = 5;
const int ROWS = 4;

//------------function------------
void read_data (int arr[ROWS][COLS]);
void ROW_COL_NUMS (int arr[ROWS][COLS]);

//---------main section-------
int main()
{
    //addining int in to the program to recognize
    int arr[ROWS][COLS];

    //inserting values to arry
    read_data (arr);

    //finding the biggest row and coloms
    ROW_COL_NUMS (arr);

    //return EXIT_SECCESS if the program did not fail
    return EXIT_SUCCESS;
}

//the function gets the array and put numbers in to it
void read_data (int arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cin >> arr[i][j];
        }
    }
}
//this function get the array and finds the biggest row in the array and 
// /then the biggest colom
void ROW_COL_NUMS (int arr[ROWS][COLS])
{
    int first_cheack = 0, second_cheack = 0, index_arr;
    for (int i = 0; i < ROWS; i++)
    {
        first_cheack  = 0;
        for (int j = 0; j < COLS; j++)
        {
            first_cheack += arr[i][j];
        }  
        if (first_cheack > second_cheack)
        {
            second_cheack = first_cheack;
            index_arr = ++i;
        }   
    }
    //printing the biggest row
    cout << index_arr << " ";
    
    index_arr =0;
    for (int i = 0; i < COLS; i++)
    {
        first_cheack = 0;
        for (int j = 0; j < ROWS; j++)
        {
            first_cheack += arr[j][i];
        }
        if (first_cheack > second_cheack)
        {
            second_cheack = first_cheack;
            index_arr = ++i;
        }   
    }
    //printing the biggest colom
    cout << index_arr << " ";
}
