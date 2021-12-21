/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program gets numebrs by the user and does a lot of things depending on 
what you asked her to do.
if you choose 1 it will ask for an array in a size of 10.
2 will sum all the numbers and prints
3 will sort the array from smallets to largest in bubble sort way.
4 will look for a numebr in the array only if it sorterd
5 will print 1 if there is a progress in the array
6 will print the array from start to finish
7 will print the array from finish to start
8 will print 1 if the numebr is the sum of the 2 back numbers and 0 if not 
(from place numebr 2)
9 will prrint 1 if the number put in is a palindrom
10 will print how much the array goges up and down
11 will ask for 2 numbers if the numebrs put in are not in the size of the 
array it will print the max numebr in the entire array if it is in the limit 
of the array iot will print the max number in those palces
12 will prints all the prime numebrs in the array
13 will close the program and everything else will print unknow request

input: numbers from 1 to 13 to choose what you want to do 

output: the thing you choose if the function need to print things

*/
//---------include section---------
#include <iostream>
#include <cstdlib>

//----------using section----------
using std::cin;
using std::cout;
using std::endl;
using std::swap;

//---------const section----------
const int ARR_SIZE = 10;

//------------enum------------
enum functions
{
    INPUT_ARR = 1,
    ADDING_NUMS = 2,
    BUBBLE = 3,
    B_SEARCH = 4,
    ARI_PRO = 5,
    UP_A = 6,
    DOWN_P_A = 7,
    SUM_2 = 8,
    PALI = 9,
    PRO_UP_DOWN = 10,
    MAX = 11,
    PRIME = 12,
    STOP = 13
};

//------------function------------
void menu(int arr[ARR_SIZE], int i, bool &sorted);                        //
void restarting_arr(int arr[ARR_SIZE], int i);                            //
void input_to_arr(int arr[ARR_SIZE], int i);                              //
void adding_numbers(int arr[ARR_SIZE], int i, int &sum);                  //
void b_sort(int arr[ARR_SIZE], int i);                                    //
void swap_i(int arr[ARR_SIZE], int i);                                    //
int binarySearch(int arr[ARR_SIZE], int l, int r, int wanted);            //
bool ari_progress(int arr[ARR_SIZE], int i);                              //
void up_arr(int arr[ARR_SIZE], int i);                                    //
void down_p_arr(int arr[ARR_SIZE], int i = ARR_SIZE);                     //
bool sum_back_2(int arr[ARR_SIZE], int i);                                //
bool palindrom(int arr[ARR_SIZE], int i, int ARR_SIZE);                   //
void porgression_up_down(int arr[ARR_SIZE], int i, int &counter_up_down); //
int arr_pro_up(int arr[ARR_SIZE], int i, int &counter_up_down);           //
int arr_pro_down(int arr[ARR_SIZE], int i, int &counter_up_down);         //
int max_num(int arr[ARR_SIZE], int i, int max, int &max_arr);             //
void prime_num(int arr[ARR_SIZE], int i);                                 //
bool prime_check(int arr[ARR_SIZE], int i, int div);                      //

//---------main section-------
int main()
{
    int arr[ARR_SIZE], i = 0;
    bool sorted = false; //restarting sorted to be false for the check in the
                         //main function

    //restarting the array
    restarting_arr(arr, i);
    //calling the main function
    menu(arr, i, sorted);

    return EXIT_SUCCESS;
}

void menu(int arr[ARR_SIZE], int i, bool &sorted)
{
    int sum = 0, chosen_num = 0;

    cin >> chosen_num;

    if (chosen_num == INPUT_ARR)
    {
        input_to_arr(arr, i);
    }
    else if (chosen_num == ADDING_NUMS)
    {
        adding_numbers(arr, i, sum);
    }
    else if (chosen_num == BUBBLE)
    {
        b_sort(arr, i);
        sorted = true; //making the sorted bool true after the array was sorted
    }
    else if (chosen_num == B_SEARCH)
    {
        if (sorted) //checking if the array is sorted if not prints Error
        {
            int wanted = 0, n = ARR_SIZE;
            //asking for a num,ber to find in ther array
            cin >> wanted;
            int result = binarySearch(arr, 0, n - 1, wanted);
            (result == -1) ? cout << 0 << endl
                           : cout << 1 << endl;
        }
        else
            fprintf(stderr, "Error\n");
    }
    else if (chosen_num == ARI_PRO)
    {
        if (ari_progress(arr, i))
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    else if (chosen_num == UP_A)
    {
        up_arr(arr, i);
    }
    else if (chosen_num == DOWN_P_A)
    {
        down_p_arr(arr, ARR_SIZE - 1);
    }
    else if (chosen_num == SUM_2)
    {
        if (sum_back_2(arr, i + 2))
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "0" << endl;
        }
    }
    else if (chosen_num == PALI)
    {
        if (palindrom(arr, i, ARR_SIZE - 1))
        {
            cout << 1 << endl; //printing 1 if the array is a palindrom
        }
        else
        {
            cout << 0 << endl; //printing 0 if the array is not a palindrom
        }
    }
    else if (chosen_num == PRO_UP_DOWN)
    {
        int counter_up_down = 0;
        porgression_up_down(arr, 0, counter_up_down);

    }
    else if (chosen_num == MAX)
    {
        int start_u = 0, finish_u = 0, max_arr = 0;

        //asking for a start and finish of the places to check the max numerb
        cin >> start_u >> finish_u;

        //if the boundris are in the size of the array sends thoes bounderis
        if ((start_u >= 0 && finish_u <= ARR_SIZE) && (start_u <= finish_u))
        {
            cout << max_num(arr, start_u, finish_u, max_arr) << endl;
        }
        //if they are not sends the entire array to find the biggest number
        else
        {
            cout << max_num(arr, i, ARR_SIZE - 1, max_arr) << endl;
        }
    }
    else if (chosen_num == PRIME)
    {
        prime_num(arr, i);
    }
    else if (chosen_num == STOP)
    {
        //ends the program and return it to the main to finish
        return;
    }
    else
    {
        //printing this if the user asked for something that doesent exist
        cout << "Unknow request" << endl;
    }

    //calling the function again to ask for more numbers
    menu(arr, i, sorted);
}
//----------------------------------------------------------------
//restarting the array
void restarting_arr(int arr[ARR_SIZE], int i)
{
    if (i >= ARR_SIZE)
    {
        return;
    }

    arr[i] = 0;
    restarting_arr(arr, i + 1);
}
//---------------------------------------------------------
//inserting values to the first arry
void input_to_arr(int arr[ARR_SIZE], int i)
{
    if (i == ARR_SIZE)
    {
        return;
    }
    cin >> arr[i];
    input_to_arr(arr, i + 1);
}
//-------------------------------------------------
//printing the sum of the array
void adding_numbers(int arr[ARR_SIZE], int i, int &sum)
{
    if (i == ARR_SIZE)
    {
        cout << sum << endl;
        return;
    }
    sum += arr[i];
    adding_numbers(arr, i + 1, sum);
}
//------------------------------------------------------------
//printing the array form start to finish
void up_arr(int arr[ARR_SIZE], int i)
{
    if (i == ARR_SIZE)
    {
        cout << endl;
        return;
    }
    cout << arr[i] << " ";
    up_arr(arr, i + 1);
}
//--------------------------------------------------------------
//printing the array form start to finish
void down_p_arr(int arr[ARR_SIZE], int i)
{
    if (i < 0)
    {
        cout << endl;
        return;
    }
    cout << arr[i] << " ";
    down_p_arr(arr, i - 1);
}
//--------------------------------------------------------------
//sorting the array from smallest to largest using the bubble sort method
void b_sort(int arr[ARR_SIZE], int i)
{
    if (i == ARR_SIZE)
    {
        return;
    }
    swap_i(arr, 0);

    b_sort(arr, i + 1);
}
//---------------------------------------------------------
//swaping betwen places of the array countine the bubble sortg function
void swap_i(int arr[ARR_SIZE], int i)
{
    if (i == ARR_SIZE)
    {
        return;
    }

    if (arr[i] > arr[i + 1])
    {
        swap(arr[i], arr[i + 1]);
    }

    swap_i(arr, i + 1);
}
//--------------------------------------------------------------------
//looking for a number in the array using the binary search method
int binarySearch(int arr[ARR_SIZE], int l, int r, int wanted) //
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == wanted)
            return mid;

        if (arr[mid] > wanted)
            return binarySearch(arr, l, mid - 1, wanted);

        return binarySearch(arr, mid + 1, r, wanted);
    }
    return -1;
}
//-----------------------------------------------------------------
//finiding if the program is aritmetic or not return false if not true if
//it does
bool ari_progress(int arr[ARR_SIZE], int i)
{
    if (i >= ARR_SIZE - 2)
    {
        return true;
    }
    int diff = arr[i] - arr[i + 1];

    if (diff != (arr[i + 1] - arr[i + 2]))
    {
        return false;
    }
    return ari_progress(arr, i + 1);
}
//------------------------------------------------------------------
//searching if the numebr from the 3 spot is the sum of the 2 that was before
//him printing 1 if yes 0 if not
bool sum_back_2(int arr[ARR_SIZE], int i)
{
    if (i == ARR_SIZE)
    {
        return true;
    }
    if (arr[i] == (arr[i - 1] + arr[i - 2]))
    {
        return sum_back_2(arr, i + 1);
    }
    else
    {
        return false;
    }
    return sum_back_2(arr, i + 1);
}
//-----------------------------------------------------------------
//finiding if the array is a polodrom if yes return true
bool palindrom(int arr[ARR_SIZE], int i, int ARR_SIZE)
{
    if (i >= ARR_SIZE)
    {
        return true;
    }
    if (arr[i] != arr[ARR_SIZE])
    {
        return false;
    }
    return palindrom(arr, i + 1, ARR_SIZE - 1);
}
//-----------------------------------------------------------------
//finding how much aritmetic progressing exist in the array and retrun
//the number
void porgression_up_down(int arr[ARR_SIZE], int arr_place, int &counter_up_down)
{

    if (arr_place >= ARR_SIZE)
    {
        //printing how much the array goes up and down
        cout << counter_up_down << endl;
        return;
    }
    if (arr[arr_place] < arr[arr_place + 1])
    {
        arr_place = arr_pro_up(arr, arr_place, counter_up_down);
    }
    else
    {
        arr_place = arr_pro_down(arr, arr_place, counter_up_down);
    }
    
    porgression_up_down(arr, arr_place, counter_up_down);
}
//-------------------------------------------------------------------
//cheacking if the array goes up
int arr_pro_up(int arr[ARR_SIZE], int i, int &counter_up_down)
{
    if ((i == ARR_SIZE - 1) || (arr[i] > arr[i + 1]))
    {
        counter_up_down++;
        return i + 1;
    }
    //if (arr[i] <= arr[i + 1])
    //{
    //   counter++;
    //}

    return arr_pro_up(arr, i + 1, counter_up_down);
}
//-----------------------------------------------------------------
//checking if the array goes down
int arr_pro_down(int arr[ARR_SIZE], int i, int &counter_up_down)
{
    if ((i == ARR_SIZE - 1) || (arr[i] < arr[i + 1]))
    {
        counter_up_down++;
        return i + 1;
    }
    //if (arr[i] >= arr[i + 1])
    //{
    //    counter++;
    //}

    return arr_pro_down(arr, i + 1, counter_up_down);
}
//-----------------------------------------------------------------
//finiding the max number in the array in the giving bounderis
int max_num(int arr[ARR_SIZE], int start_u, int finish_u, int &max_arr)
{
    if (start_u == finish_u)
    {
        return arr[start_u];
    }
    if (arr[start_u + 1] > arr[start_u])
    {
        max_arr = arr[start_u + 1];
    }
    return max_num(arr, start_u + 1, finish_u, max_arr);
}
//--------------------------------------------------------------
//finiding and printing all the priome numbers that exist in the array
void prime_num(int arr[ARR_SIZE], int i)
{
    if (i == ARR_SIZE)
    {
        cout << endl;
        return;
    }
    if (prime_check(arr, i, 2))
    {
        cout << arr[i] << " ";
    }
    prime_num(arr, i + 1);
}
//ther countinue ogf the last function to see if the numebr dived by
//any other numebr
bool prime_check(int arr[ARR_SIZE], int i, int div)
{
    if (arr[i] == 1 || arr[i] == 0)
    {
        return false;
    }
    if (div >= arr[i])
    {
        return true;
    }
    if (arr[i] % div == 0)
    {
        return false;
    }
    return prime_check(arr, i, div + 1);
}
