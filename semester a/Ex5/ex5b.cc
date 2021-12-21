/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program find a Locating a cell in an array whose value is divided by
those to our right, and divides those to its left.


input: Two numbers 

output: arry number that uphold the program.
        if the program didnt find any number it return -1.

*/
//---------include section---------
#include <iostream>
#include <cstdlib>

//----------using section----------
using std::cout;
using std::cin;
using std::endl;

//--------const section-----------
const int N = 6;

//------------function------------
void data_Reader (int arr[]);
int first_Num(int arr[]);
bool back_divide(int arr[], int i);
bool next_divide(int arr[], int i);

//---------main section-------
int main()
{
    //addining integers in to the program to recognize
    int arr [N], result;

    //inserting values to arry
    data_Reader(arr);

    result = first_Num(arr); 
    cout << result << endl; //printing the number that the program find

    return EXIT_SUCCESS;
}

void data_Reader (int arr [N])
{
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

int first_Num(int arr[N]) //finding the right number that it looks for
{
    for (int i = 0; i < N; i++)
    {
        //calling for other function to look in the number in the 
        //back of the array and in the front
        if (back_divide(arr ,i) && next_divide(arr ,i))
        {
        return i;
        }
    }
    return -1;
}

bool back_divide(int arr[N], int i) //cheking the back dividers 
{
    for (int j = 0; j < i; j++)
    {
        if ((arr[j] == 0) || (arr[i] % arr[j] != 0))
            return false;
    }
    return true; // if found a divedider returning true
}

bool next_divide(int arr[N], int i) // checking the next dividers on the array
{
    for (int j = N - 1; j > i; j--)
    {
        if ((arr[i] == 0) || (arr[j] % arr[i] != 0))
            return false;
    }
    return true;
}