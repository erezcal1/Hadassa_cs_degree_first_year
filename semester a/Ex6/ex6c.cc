/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program serches for the most common number in a row and looks if there 
are more number it skips it and if there isnt it prints the row the number 
and how much time it showed it the row.
The run time is (ROW * COLS) to the power of 2

input: an array in the size of 4 rows and 7 coloms

output: The rows where you have the biggest time 
        the amount of the number that is the most common in that row

*/
//---------include section---------
#include <iostream>
#include <cstdlib>

//----------using section----------
using std::cin;
using std::cout;
using std::endl;

//---------const section----------
const int ROWS = 4;
const int COLS = 7;

//------------function------------
void read_data(int[ROWS][COLS]);
void cheacking_biggest_num_in_row (int arr[ROWS][COLS]);
int highest_num_in_row (int arr[ROWS][COLS], int, int&, int&);
bool checking_other_rows (int arr[ROWS][COLS], int, int);

//---------main section-------
int main()
{
    //addining int in to the program to recognize
    int arr[ROWS][COLS];

    //inserting values to arry
    read_data(arr);
    //cheaks for the biggest number in each row 
    cheacking_biggest_num_in_row(arr);

    //return EXIT_SECCESS if the program did not fail
    return EXIT_SUCCESS;
}
//the function gets the array and put numbers in to it
void read_data(int arr[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            cin >> arr[i][j];
    }
}

//This function gets the array and looks for thew biggest numebr.
//This function is the one that calls all the other funtion to 
//look if this is the number that it nees to print 
void cheacking_biggest_num_in_row (int arr[ROWS][COLS])
{
    int max_nums = 0, top_counter = 0;
    for (int i = 0; i < ROWS; i++)
    {
        top_counter = highest_num_in_row (arr, i, max_nums, top_counter);
    }
}

//cheaking the highest number in each row
int highest_num_in_row (int arr[ROWS][COLS], int i, int& max_nums, 
                        int& top_counter)
{
    int counter = 0, corrent_value = 0;
        corrent_value = arr[i][0];
        for (int k = 0; k < COLS; k++)
        {
            if (corrent_value == arr[i][k])
            {
                counter++;
            }
        }
        if (top_counter < counter)
        {
            top_counter = counter;
            max_nums = corrent_value;
        }
        if (checking_other_rows(arr, top_counter, max_nums))
        {
            cout << i << " " << max_nums << " " << top_counter << endl;
        }
        max_nums = 0;
        top_counter = 0;

    return top_counter;
}
//cheaking other rows to look if the number uit dound is the most common 
//in the array
bool checking_other_rows (int arr[ROWS][COLS], int top_counter, int max_nums)
{
    int mid_counter = 0;
    for (int r = 0; r < ROWS; r++)
    {
        mid_counter = 0;
        for (int col = 0; col < COLS; col++)
        {
            if (arr[r][col] == max_nums)
            {
                mid_counter++;
            }
        }
        if (mid_counter > top_counter)
        {
            //if there is more numbers like the one that the program finds 
            //it returens false
            return false;
        }
    }
    //if there isnt any bigger it return true and prints it the in array 
    //that called him
    return true;
}