/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program gets 2 files and printing the the people with thire grades
acording to the abc. First of all the program compares the name of the
students if there names are similar it prints the name and the grade
from the first file and then skips the name in the second file and prints
only it grades. if the names are not similar it prints the line which goes
first on the abc. When it finishes one of the files it prints all the other
file.

input: 2 files with students name and grades sorted by the abc

output: 1 file and printing to the terminal 2 files combined with the abc

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

//---------const section----------------------------------------
const int MAX_FILE_LEN = 100;

//------------function------------------------------------------
void open_files(ifstream& if1, ifstream& if2, ofstream& out);
void merge_files(ifstream& if1, ifstream& if2, ofstream& out);
void close_files(ifstream& if1, ifstream& if2, ofstream& out);
bool compare_names(ifstream& if1, ifstream& if2);
void print_line(ifstream& if1, ifstream& if2, ofstream& out);
void print_right_line(ifstream& if1, ifstream& if2, char& ch, char& ch2, ofstream& out);

//---------main section---------------------------------------------
int main()
{
    ifstream inp1, inp2;
    ofstream out;

    open_files(inp1, inp2, out);

    //mail function that does most of the things
    merge_files(inp1, inp2, out);

    close_files(inp1, inp2, out);

    return EXIT_SUCCESS;
}

//---------------------------------------------------------------------
//The function to open the files to work with
void open_files(ifstream& if1, ifstream& if2, ofstream& out)
{
    char file_name[MAX_FILE_LEN];

    cin >> setw(MAX_FILE_LEN) >> file_name;
    if1.open(file_name);

    if (!if1.is_open())
    {
        cerr << "Key file not found" << endl;
        exit(EXIT_FAILURE);
    }

    cin >> setw(MAX_FILE_LEN) >> file_name;
    if2.open(file_name);

    if (!if2.is_open())
    {
        cerr << "input file to encrypt was not found" << endl;
        exit(EXIT_FAILURE);
    }

    cin >> setw(MAX_FILE_LEN) >> file_name;
    out.open(file_name);
}

//---------------------------------------------------------------------
//This is the main funtion that calls other functions and prints the right line
void merge_files(ifstream& if1, ifstream& if2, ofstream& out)
{
    char ch = if1.get(), ch2 = if2.get();

    if (!if1.eof() && !if2.eof())
    {
        //restarting the files to the beginning of the line
        if2.seekg(-1, std::ios::cur);
        if1.seekg(-1, std::ios::cur);

        while (!if1.eof() && !if2.eof())
        {
            
            ch = if1.get(), ch2 = if2.get();

            //Checking if there was a fail in one of the files
            if (if1.fail() || if2.fail())
                break;
            else
            {
                if2.seekg(-1, std::ios::cur);
                if1.seekg(-1, std::ios::cur);
            }
            //Check if the names are similar
            if (compare_names(if1, if2))
            {
                //If they are it prints the name and the grades from both files
                print_line(if1, if2, out);
            }

            //If the names are not the same it prints the right line according to the abc
            else
            {
                print_right_line(if1, if2, ch, ch2, out);
            }
        }
        //cout << endl;
        //out << endl;
    }

    //When one of the files ends it prints the other file
    while (!if2.fail())
    {
        cout << ch2;
        out << ch2;
        ch2 = if2.get();
    }
    while (!if1.fail())
    {
        cout << ch;
        out << ch;
        ch = if1.get();
    }
    cout << endl;
    out << endl;
}

//---------------------------------------------------------------------
//This function gets both files and check what line needs to be printed 
//It know that duo to finding what name comes first in the abc and then it prints it
void print_right_line(ifstream& if1, ifstream& if2, char& ch, char& ch2, ofstream& out)
{
    ch = if1.get(), ch2 = if2.get();
    int counter = 1;

    while (isalpha(ch))
    {
        //cout << endl;
        //out << endl;

        //when the names are similar it cheack how much of them are similar
        if (ch == ch2)
        {
            ch = if1.get();
            ch2 = if2.get();
            counter++;
        }

        //when it find a non similar letter it goes in the right if
        if (ch > ch2)
        {
            //goes to the start of the line
            if2.seekg(-counter, std::ios::cur);
            if1.seekg(-counter, std::ios::cur);
            ch2 = if2.get();
            //prints to the end of the file or to the end of the road
            while (ch2 != '\n' && !if2.eof())
            {
                cout << ch2;
                out << ch2;
                ch2 = if2.get();
            }
            if (if2.eof())
            {
                if2.seekg(-1, std::ios::cur);
            }
            break;
        }

        if (ch < ch2)
        {
            if1.seekg(-counter, std::ios::cur);
            if2.seekg(-counter, std::ios::cur);
            ch = if1.get();
            while (ch != '\n' &&  !if1.eof())
            {
                cout << ch;
                out << ch;
                ch = if1.get();
            }
            if (if1.eof())
            {
                if1.seekg(-1, std::ios::cur);
            }
            break;
        }
    }
}

//---------------------------------------------------------------------
//This function gets the 2 files and compare the name at the start of each line
//it reterns true if the names are the same and false if not
bool compare_names(ifstream& if1, ifstream& if2)
{
    char ch = if1.get(), ch2 = if2.get();
    int counter = 1;

    while (isalpha(ch))
    {
        //as long as we are in letters we keep ckeking for the same letters
        if (ch == ch2)
        {
            //moves on each time to find a worng letter
            ch = if1.get();
            ch2 = if2.get();
            counter++;
        }
        else
        {
            //returning to the start of the line for both of the files
            if1.seekg(-counter, std::ios::cur);
            if2.seekg(-counter, std::ios::cur);
            return false;
        }
    }
    //returning to the start of the line for both of the files
    if1.seekg(-counter, std::ios::cur);
    if2.seekg(-counter, std::ios::cur);
    return true;
}

//---------------------------------------------------------------------
//This function get 2 files and print the name and then the grades
//This function comes to work if the names are similar
void print_line(ifstream& if1, ifstream& if2, ofstream& out)
{
    char ch, ch2;
    ch = if1.get(), ch2 = if2.get();
    cout << endl;
    out << endl;

    //printing the entire line from the first file
    while (ch != '\n' && !if1.eof())
    {
        cout << ch;
        out << ch;
        ch = if1.get();
    }
    //skiping the name
    while (isalpha(ch2))
    {
        ch2 = if2.get();
    }

    //printing the grades from the second file
    while (ch2 != '\n' && !if2.eof())
    {
        cout << ch2;
        out << ch2;
        ch2 = if2.get();
    }
    cout << ch2;
    out << ch2;

    if (if1.eof())
    {
        if1.seekg(-1, std::ios::cur);
    }
    if (if2.eof())
    {
        if2.seekg(-1, std::ios::cur);
    }
}

//---------------------------------------------------------------------
//closing all the file
void close_files(ifstream& if1, ifstream& if2, ofstream& out)
{
    if1.close();
    if2.close();
    out.close();
}

