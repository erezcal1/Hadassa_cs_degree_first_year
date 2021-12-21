/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program gets from the user how much line of numebr does he want to sum
and build the amount of lines like he asked. then it asks for a numebrs to 
put in the lines and evetually it sums all the lines and prints the sum.

input: number of lines and numbers to put in them

output: the sum opf all the numebrs
*/
//---------include section---------------------------------------
#include <iostream>
#include <cstdlib>
#include <iomanip>
//----------using section----------------------------------------
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::nothrow;
//----------struct section----------------------------------------
struct size
{
    int *_nums;
};
//------------function------------------------------------------
void sum_of_rows();
void allocate_array();
void read_nums(size *num, int &second_arr_S);
void print_nums(size *num, int &counter, int second_arr_S);
//---------main section---------------------------------------------
int main()
{
    sum_of_rows();


    return EXIT_SUCCESS;
}
//---------------------------------------------------------------------
//This is the main function that build the lines and ask for the other 
//function to put nums and print
void sum_of_rows()
{
    int first_arr_S, counter = 0, second_arr_S;
    cin >> first_arr_S;

    size *nums_size[first_arr_S];

    for (int i = 0; i < first_arr_S; i++)
    {
        //builds a new array in the size that the preson asked
        nums_size[i] = new (nothrow) size;
        if (nums_size[i] == NULL)
        {
            cerr << "Cnnot allocate new string" << endl;
            exit(EXIT_FAILURE);
        }

        //calls the read nums function
        read_nums(nums_size[i], second_arr_S);

        print_nums(nums_size[i], counter, second_arr_S);
    }
    
    cout << counter;

    for (int i = 0; i < first_arr_S; i++)
    {
        free(nums_size[i]);
    }
}
//---------------------------------------------------------------------
//This function gets the numebrs from the user and puts them in the lines
void read_nums(size *num, int &second_arr_S)
{
    int second_arr_N;
    cin >> second_arr_S;

    //build the size of the line and put the numebrs in to it
    num->_nums = new (nothrow) int[second_arr_S];
    if (num->_nums == NULL)
        exit(EXIT_FAILURE);

    //asks for the numbers
    for (int i = 0; i < second_arr_S; i++)
    {
        cin >> second_arr_N;
        num->_nums[i] = second_arr_N;
    }
}
//---------------------------------------------------------------------
//This fuction sums all the numebrs in the arrays
void print_nums(size *num, int &counter, int second_arr_S)
{
    for (int i = 0; i < second_arr_S; i++)
    {
        counter += num->_nums[i];
    }
}
//---------------------------------------------------------------------
//This function frees the space that it used
void free(size *num)
{
    delete[] num->_nums;

    delete[] num;
}