/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program does two things 1 is fro encription and 2 is for decription. 
the origram gets what you want to do encrip or decript and then gets a string
from the user. at first it randomize a number from 1 to 3 and then acoordin 
to the number she doose a couple of things 1. is to move every letter random 
number of steps(acording to what it randomize at the begining) steps forword 
in the abc 2. mirror the word again according to the number for example if it 
randomize the number 4 it mirror the letter every 3 values in the string. 3. 
adding a random latters in the string. if you chose to decrip it does al the 
thing but in backword order: removing the random added letters, mirroring the 
letters back and the at the end it moves back the letter to they supose to be.
when you decript the number that is used to do all then thing is the last 
digit you put in the string.

input: a number to encrip or to decript and the sentece

output: the sentece after the encription or decription

*/
//---------include section---------
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>
#include <cstring>

//----------using section----------
using std::cin;
using std::cout;
using std::endl;

//---------const section----------
const int MAIN_LINE = 1000;

//------------function------------
void data_reader(char str[], int &);
void encription(char str[], int);
void solve(char str[], int);
void changing_letters(char str[], int);
void word_mirror(char str[], int);
void adding_random_letters(char str[], int);
void removing_random_letters(char str[], int);
void replacing_bad_letters(char str[], int);
void remove_last_digit(char str[], int &n);
int random(int);

//---------main section-------
int main()
{
    //addining int and chars for the program to recognize
    int wanted, n;
    char str[MAIN_LINE];
    
    //inserting values to string
    data_reader(str, wanted);

    //encription
    if (wanted == 1)
    {
        n = random(1); //randoomize the numerb for 2 - 4
        encription(str, n);
    }
    //decription
    else if (wanted == 2)
    {
        remove_last_digit(str, n); //removing the last digit and making the 
                                   //number for the program to work with
        solve(str, n);
    }
    return EXIT_SUCCESS;
}

//inserting values to string
void data_reader(char str[], int &wanted)
{
    cin >> wanted;
    cin.ignore();
    cin.getline(str, MAIN_LINE);
}

//the main encription function that changes the string
void encription(char str[], int n)
{
    changing_letters(str, n);
    word_mirror(str, n);
    adding_random_letters(str, n);
}

//the main decription function that changes the string
void solve(char str[], int n)
{
    removing_random_letters(str, n);
    word_mirror(str, n);
    replacing_bad_letters(str, n);
}

//This function changing the letters the number of steps that the 
//program ranzomized
void changing_letters(char str[], int n)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            if (isalpha(str[i] + n))
            {
                str[i] += n;
            }
            else if (isalpha(str[i]) != isalpha(str[i] + n))
            {
                str[i] = str[i] - 26 + n;
            }
        }
    }
    cout << str << endl;
}

//This function reversing the letters again acording to the number it 
//randomized (n)
void word_mirror(char str[], int n)
{
    int len = strlen(str), place = 0;
    char temp;

    for (int i = 0; i + n - 1 < len; i = i + n)
    {
        place = i;
        for (int j = n + i - 1; j - place > 0; j--)
        {
            temp = str[j];
            str[j] = str[place];
            str[place] = temp;
            place++;
        }
    }
    cout << str << endl;
}

//This program pronting random latters every number of n that exist 
//in the string
void adding_random_letters(char str[], int n)
{
    int add_rand = random(2);

    for (int i = 0; str[i] != '\0'; i++)
    {
        cout << str[i];

        if ((i + 1) % n == 0)
        {
            cout << (char)add_rand;
        }
    }
    cout << n << endl;
}

//This function does the oppesite of what the last dunction did. 
//so removing the letters that have been added.
//This is the first function of the decription
void removing_random_letters(char str[], int n)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (i % n == 0 && i != 0)
        {
            for (int j = i; str[j] != '\0'; j++)
            {
                str[j] = str[j + 1];
            }
        }
    }
    cout << str << endl;
}

//returning the letters that have been changed in the enecription
void replacing_bad_letters(char str[], int n)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        {
            if (isalpha(str[i] - n))
            {
                str[i] -= n;
            }
            else if (isalpha(str[i]) != isalpha(str[i] - n))
            {
                str[i] = str[i] + 26 - n;
            }
        }
    }
    cout << str << endl;
}

//removes the last digit from the sentece(this is also making 
//the n number for the rest of the program) this is the first 
//thing that the decription do with out starting to decrip
void remove_last_digit(char str[], int &n)
{
    int length = strlen(str);
    n = str[length - 1] - 48;
    str[length - 1] = '\0';
}

//sending the random letters and numbers for the program
int random(int x)
{
    srand(17);

    if (x == 1)
    {
        return rand() % 3 + 2;
    }
    else
    {
        return 'a' + rand() % 26;
    }

    return 0;
}
