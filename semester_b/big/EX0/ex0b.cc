/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program gets to files. To each one of them it countes how many latters 
are in the file and puts it with the letter in 2 diffrent arrays. Then it 
sorts them with a buble sort. each time it move the number it moves the letter 
to to keep the letter with the number it shoed in the array. For example the 
most letter in the file will be at place number one in the array and so on. 
Then The program need to switch the letters fore one file to another. 
The letter with the most appereances in one file will switch with the letter 
with th e most appereance letter in the other file. If 2 letters have the 
same amount of appereances it prints the letters acording to the abc.

input: 2 files one to chage and one to count the letters

output: print of the decript file to the terminal

*/
//---------include section---------------------------------------
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>

//----------using section----------------------------------------
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::swap;

//---------const section----------------------------------------
const int MAX_FILE_LEN = 100;
const int ENG_ABC = 26;

//------------function------------------------------------------
void open_files(ifstream &if1, ifstream &if2);
void close_files(ifstream &if1, ifstream &if2);
void potting_in_arry_1(ifstream &if1, char arr_1[ENG_ABC], int arr_2[ENG_ABC]);
void sorting_arr_1(ifstream &if1, char arr_1[ENG_ABC], int arr_2[ENG_ABC]);
void printing_new_text(ifstream &if1, char arr_1[ENG_ABC], char arr_3[ENG_ABC]);
void switch_letter(char ch, char arr_1[ENG_ABC], char arr_3[ENG_ABC]);                     

//---------main section---------------------------------------------
int main()
{
    char arr_1[ENG_ABC], arr_3[ENG_ABC];
    int arr_2[ENG_ABC], arr_4[ENG_ABC];

    ifstream inp1, inp2;

    open_files(inp1, inp2);

    //This functions puts the numbers and the chars in 2 diffrent arrays
    potting_in_arry_1(inp1, arr_1, arr_2);
    potting_in_arry_1(inp2, arr_3, arr_4);

    //This function sort the numbers from largest at the begining to the 
    //smalles at the end
    //It moves the chars acordingly
    sorting_arr_1(inp1, arr_1, arr_2);
    sorting_arr_1(inp2, arr_3, arr_4);

    //This function prints the text after the switch
    printing_new_text(inp1, arr_1, arr_3);

    close_files(inp1, inp2);

    return EXIT_SUCCESS;
}

//---------------------------------------------------------------------
//The function to open the files to work with
void open_files(ifstream &if1, ifstream &if2)
{
    char file_name[MAX_FILE_LEN];

    cin >> setw(MAX_FILE_LEN) >> file_name;
    if1.open(file_name);
    cin >> setw(MAX_FILE_LEN) >> file_name;
    if2.open(file_name);

    if (!if1.is_open() || !if2.is_open())
    {
        cerr << "Cannot opne one of te files" << endl;
        exit(EXIT_FAILURE);
    }
}

//---------------------------------------------------------------------
//This function works 2 times one for each input file
//It put the numbers (how mcuh time it showed up in the file) in one array 
//and the letter that showed in another
void potting_in_arry_1(ifstream &if1, char arr_char[], int arr_int[])
{
    int counter = 0;
    char ch, j;

    j = 'a';
    for (int i = 0; j <= 'z'; i++, j++)
    {
        if1.seekg(0, std::ios::beg);
        ch = if1.get();
        while (!if1.eof())
        {
            if (ch == j)
            {
                counter++;
            }
            ch = if1.get();
        }

        arr_char[i] = j;
        arr_int[i] = counter;

        if1.clear();

        counter = 0;
    }
}

//---------------------------------------------------------------------
// This function sort the number in buble sort way and mover the letters with
//it so they will still "be with each other"
void sorting_arr_1(ifstream &if1, char arr_char[ENG_ABC], int arr_int[ENG_ABC])
{
    int n = ENG_ABC;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr_int[j] < arr_int[j + 1])
            {
                swap(arr_int[j], arr_int[j + 1]);
                swap(arr_char[j], arr_char[j + 1]);
            }
        }
    }

}

//---------------------------------------------------------------------
//This function prints all the non letters and send it to another funtion 
//to prints the letter that need to be printed
void printing_new_text(ifstream &if1, char arr_1[ENG_ABC], char arr_3[ENG_ABC])
{
    if1.seekg(0, std::ios::beg);
    char ch = if1.get();
    
    while (!if1.eof())
    {
        if (isalpha(ch))
        {
            switch_letter(ch, arr_1, arr_3);
        }
        else
        {
            cout << ch;
        }
        ch = if1.get();
    }
}

//---------------------------------------------------------------------
//This function gets the current place of what need to be printed and 
//print the letters from the other funtion that fit with its place
void switch_letter(char ch, char arr_1[ENG_ABC], char arr_3[ENG_ABC])
{
    for (int i = 0; i < ENG_ABC; i++)
    {
        if (arr_1[i] == ch)
        {
            cout << arr_3[i];
        }
    }
}                     

//---------------------------------------------------------------------
//closing all the file
void close_files(ifstream &if1, ifstream &if2)
{
    if1.close();
    if2.close();
}