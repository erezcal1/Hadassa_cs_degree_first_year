/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program gets an array with 10 rows and 15 coloms and find if and where 
there are tringles. if there are tringles it prints where they start and how 
big are they if they are inverted or not, and at the end or the program 
cheking the array it priints the biggest tringle and if there is more then 
one it prints how much tiringles like this exist.
The run time is ROWS * (COLS)^2 * base_of_triangle

input: an array with 10 rows and 15 coloms

output: The tringles that the program find and how much of the biggest 
        tringle there is.

*/
//---------include section---------
#include <iostream>
#include <cstdlib>

//----------using section----------
using std::cin;
using std::cout;
using std::endl;

//---------const section----------
const int ROWS = 10;
const int COLS = 15;

//------------function------------
void read_data(int[ROWS][COLS]);
void calling_triangles(int[ROWS][COLS]);
void cheaking_triangles(int arr[ROWS][COLS], int, int, int, bool,
                        int &, int &, bool &);
bool base_of_triangle(int[ROWS][COLS], int, int, int, int);
void biggest_tringles(int, int &, int &);

//---------main section-------
int main()
{
    //addining int in to the program to recognize
    int arr[ROWS][COLS];

    //inserting values to arry
    read_data(arr);
    //cheaking if there are triangles in the array.
    calling_triangles(arr);

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
//This function cheaks if there is a triangles in the array
void calling_triangles(int arr[ROWS][COLS])
{
    int top_value, highest_tringle = 0, sum = 0;
    bool inverted_tringles, printed = false;

    for (int i = 0; i < ROWS - 2; i++)
    {
        for (int j = 2; j < COLS - 2; j++)
        {
            top_value = arr[i][j];

            //cheaking standing triangles
            inverted_tringles = false;
            cheaking_triangles(arr, i, j, top_value, inverted_tringles, highest_tringle, sum, printed);

            //cheaking inverted trinagles
            inverted_tringles = true;
            cheaking_triangles(arr, i, j, top_value, inverted_tringles, highest_tringle, sum, printed);
        }
    }
    //printing the biggest trinagles in the array and how much there is 
    if (printed)
    {
        cout << sum << " " << highest_tringle << endl;
    }
    //if there isnt any tringles it prints 0 0
    else
    {
        cout << 0 << " " << 0 << endl;
    }
}

void cheaking_triangles(int arr[ROWS][COLS], int i, int j, int top_value, 
                       bool inverted_tringles, int &highest_tringle, 
                       int &sum, bool &printed)
{
    int top, base_size, max_size;
    bool good_tringle = false;

    for (int k = 1; k < COLS / 2; k++)
    {
        top = k;
        if (inverted_tringles)
            top *= -1;

        if (top_value != arr[i + top][j + top] || 
        top_value != arr[i + top][j - top])
        {
            break;
        }

        else if (top_value == arr[i + top][j + top] &&
                 top_value == arr[i + top][j - top] && 
                 (top >= 2 || top <= -2))
        {
            if (inverted_tringles)
            {
                top *= -1;

                base_size = ((top + 1) * 2) - 1; //size of base of 
                                                 //cheaking_triangles

                if (base_of_triangle(arr, i - top, j + top, top_value, 
                    base_size))
                {
                    good_tringle = true;
                    max_size = top + 1;
                }
            }
            else
            {
                base_size = ((top + 1) * 2) - 1; //size of base of 
                                                 //cheaking_triangles
                if (base_of_triangle(arr, i + top, j + top, top_value, 
                    base_size))
                {
                    good_tringle = true;
                    max_size = top + 1;
                }
            }
        }
    }

    //if the program found a tringle it prints it in the correct place
    if (good_tringle && inverted_tringles)
    {
        cout << i << " " << j << ": " << max_size << " inverted. Value: " << 
        top_value << endl;
        printed = true;
        biggest_tringles(max_size, highest_tringle, sum);
    }
    else if (good_tringle)
    {
        cout << i << " " << j << ": " << max_size << " standing. Value: " << 
        top_value << endl;
        printed = true;
        biggest_tringles(max_size, highest_tringle, sum);
    }
}

//cheaking the base of tringle and if it fits what we need.
bool base_of_triangle(int arr[ROWS][COLS], int i, int j, int top_value, 
                      int base_size)
{
    for (int k = 0; k < base_size; k++)
    {
        if (j - k < 0 || top_value != arr[i][j - k])
            return false;
    }
    return true;
}

//looking for the biggest array and how much there is
void biggest_tringles(int max_size, int &highest_tringle, int &sum)
{
    if (max_size > highest_tringle)
    {
        sum = 1;
        highest_tringle = max_size;
    }

    if (max_size == highest_tringle)
    {
        sum++;
    }
}