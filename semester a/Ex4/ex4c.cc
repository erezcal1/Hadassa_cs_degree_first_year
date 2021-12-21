/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program gets 8 numbers and finds a loop that accepet the 
following order: the first arry points at a number then this 
number points at an arry that has the same number as the one 
insert to arry one. it gose like this until it finds an arry 
for example the arry 3 that have the nu,ber 5 points at an arry
that have the number 6, this poits at an arry 6 that hve the 
number 3 and we go back to the srat and thats how we finished a loop.
If the program dosent find a loop it prints

input: 8 numbers in to an arry 

output:

*/
//---------include section---------
#include <iostream>
#include <cstdlib>

//----------using section----------
using std::cout;
using std::cin;

//---------const section----------
const int N = 8;


//---------main section-------
int main ()
{
    //addining ints in to the program to recognize
    int i, arr[N], j, index, counter;
    bool found = false; // restarrting found with false

    //inserting values to the arry
    for (i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    for (i = 0; i < N ; i++ )
    {

        index = i;
        //looking for a loop in the arry 
        for (counter = 0; index >= 0 && index < N && counter <= N; counter++)
        {
            index = arr[index]; 
            if (index == i)
            {
                for (j = 0; j <= counter; j++)
                {
                   cout << index << " ";
                   index = arr[index];
                }
                found = true; 
                break; 
            }
        }
        //if the program finds a loop it stop the program
        if (found)
            break;
        
    }

    return EXIT_SUCCESS;
}