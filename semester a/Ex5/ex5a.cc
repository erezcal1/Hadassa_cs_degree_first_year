/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

THis program gets six numbers from the user and prints by order:
min value, max value, the averge of all the array, the number diversity 
(the diversity is difenined by the following formula: (x1 - avg)^2 and 
like that to all the number in the array), ho wmuch nagative, zero and 
positive nyumbers are in the array to all in the same row.

input: 6 numbers in arry

output: 7 diffrent numbers that show statistic numbers on the array.

*/
//---------include section---------
#include <iostream>
#include <cstdlib>
#include <cmath>

//----------using section----------
using std::cout;
using std::cin;
using std::endl;

//------------function------------
void data_Reader (int arr[]);
void min_Max_Finder (int arr[], int&, int&);
int avg_Cal (int arr[]);
double dif_In_arr (int arr[], int);
void positive_Neg_Zero (int arr[], int&, int&, int&);
void cout_values (int, int, int, double, int, int, int);

//---------const section----------
const int N = 6;

//---------main section-------
int main()
{
    //addining int in to the program to recognize
    int arr[N];
    int min = 0, max = 0, avg, negative = 0, zero = 0, 
        positive = 0;
    double num_diversity;

    //inserting values to arry
    data_Reader(arr);
    //finding the minimun and maximun numbers in the array
    min_Max_Finder(arr, min, max);
    //calculating the average from all the array
    avg = avg_Cal(arr);
    //finding the diversity from the array and making it a printable term
    num_diversity = dif_In_arr(arr, avg);
    //finding if the numbers that inserted to the array are negative 
    //zero or positive
    positive_Neg_Zero(arr, negative, zero, positive);
    //printing all the numbers that the program finds from the array
    cout_values (min, max, avg, num_diversity, negative, zero, positive);

    //return EXIT_SECCESS if the program did all what it takes
    return EXIT_SUCCESS;

}

//the function gets the array and put numbers in to it
void data_Reader (int arr [N])
{
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

//this function gets the array that was inserted and findes the values
//of min and man and bring it back to the main
void min_Max_Finder (int arr [N], int& min, int& max)
{
    min = arr[0];
    max = arr[0];

    for (int i = 0; i < N; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
}

//this function gets the array and return the avg number to the main for 
//the nuxt function tio read
int avg_Cal (int arr[N])
{
    int avg = 0;

    for (int i = 0; i < N; i++)
    {
        avg += arr[i];
    }
    return avg /= N;
}

//this function gets an array and the avg number form the main and using the
//include of cmath it does the calculation in the power of 2 insted writing
//it 2 times. It also returen the diversity that it found using this
//calculation.
double dif_In_arr (int arr[N],int avg)
{
    double num_diversity = 0;

    for (int i = 0; i < N; i++)
    {
        num_diversity += pow((arr[i]-avg), 2);
    }
  
    return num_diversity /= N;
}

//this function gets an array and 3 ints and finds where the numbers belong
//in the Axis of numbers.
void positive_Neg_Zero (int arr[N], int& negative, int& zero, int& positive)
{
    for (int i = 0; i < N; i++)
    {
        if (arr[i] < 0)
        {
            negative ++;
        }
        else if (arr [i] == 0)
        {
            zero ++;
        }
        else
        {
            positive ++;
        }
    }
}

//this function get all the calcultion form the priviuse functions and 
//prints it in one row with one free colom between each one
void cout_values (int min, int max, int avg, double num_diversity, int negative,
            int zero, int positive)
{
    cout << min << " " << max << " " << avg << " " << num_diversity << " " << 
         negative << " " << zero << " " << positive << endl;
}