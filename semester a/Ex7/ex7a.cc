/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program gets 2 arrays one after the other and does with them two things.
one is to taker the first array and  print the small letter in caps and big 
and keep the like they are the program dosent print any other things like ! 
and @.
after the program prints all those things it moves to its second task witch 
is to eliminate all the letters and symbols found in the first array for 
example if the first array was 123abc and the second array was 123ab the print
 will only be c

input: 2 differet arrays 

output: only big latters from the first array
        the letters and symbols that found in the first array but not in the 
        second

*/
//---------include section---------
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>

//----------using section----------
using std::cin;
using std::cout;
using std::endl;
using std::setw;

//---------const section----------
const int MAX_STR_LEN = 100;
const int DIFFERENCE = 100;

//------------function------------
void read_data(char str[]);
void second_read_data(char str2[]);
void change_small_letters_and_remove_other_chars(char str[]);
void first_minus_second(char str[], char str2[]);

//---------main section-------
int main()
{
    //addining chars in for the program to recognize
    char str[MAX_STR_LEN], str2[DIFFERENCE];

    //inserting values to the first arry
    read_data(str);
    //inserting values to the second arry
    second_read_data(str2);
    //changing the small letters and ignoring all the other symbols that 
    //are not letters
    change_small_letters_and_remove_other_chars(str);
    cout << endl;
    //removing the second array from the first and then printing the first 
    //array without the value from the second one
    first_minus_second(str, str2);

    return EXIT_SUCCESS;
}
//inserting values to the first arry
void read_data(char str[])
{
    cin >> setw(MAX_STR_LEN + 1) >> str;
}
//changing the small letters and ignoring all the other symbols that 
//are not letters
void change_small_letters_and_remove_other_chars(char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isupper(str[i]))
        {
            cout << str[i];
        }
        else if (islower(str[i]))
        {
            cout << (char)toupper(str[i]);
        }
    }
}
//inserting values to the second arry
void second_read_data(char str2[])
{
    cin >> setw(DIFFERENCE + 1) >> str2;
}
//removing the second array from the first and then printing the first 
//array without the value from the second one
void first_minus_second(char str[], char str2[])
{
    bool is_found = true;

    //running through the first and second array t ofind if there are 
    //value to eliminate
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = 0; str[j] != '\0'; j++)
        {
            if (str[i] == str2[j])
            {
                is_found = false;
            }
        }
        //it didnet find something like that in the second array it prints 
        //the letter
        if (is_found)
        {
            cout << str[i];
        }
        is_found = true;
    }
    cout << endl;
}