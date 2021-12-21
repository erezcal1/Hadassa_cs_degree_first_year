/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program gets to files from the user and does only one this with it. 
It take the file that needs to be encrypted and cheks every single char in 
it to see if it needs to be replaced (The chars that need to be replaced 
are only letters and letetrs that are found in pairs in the key file that 
program got from the user). each letter is cheked in the key file if it found
his pair it print the other letter of the pair if not it prints the current 
one.
It does that to the entire file.
Every time the program prints it print it to the terminal as well as the file

input: 2 files, one key and one file to encrypt

output: and output file with the encription
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
void open_files(ifstream &if1, ifstream &if2, ofstream &out);
void read_main_text(ifstream &if1, ifstream &if2, ofstream &out);
bool find_letter(ifstream &if1, ifstream &if2, char &letter, char ch);
void close_files(ifstream &if1, ifstream &if2, ofstream &out);

//---------main section---------------------------------------------
int main()
{
    ifstream inp1, inp2;
    ofstream out;

    open_files(inp1, inp2, out);

    //The main function that takes all the inputs and print what it needs to 
    read_main_text(inp1, inp2, out);

    close_files(inp1, inp2, out);

    return EXIT_SUCCESS;
}

//---------------------------------------------------------------------
//The function to open the files to work with
void open_files (ifstream &if1, ifstream &if2, ofstream &out)
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
//This funtion reads the main file to encript.
//It takes every single letter and compares it to the encription key file
void read_main_text (ifstream &if1, ifstream &if2, ofstream &out)
{
    char ch, letter;

    ch = if2.get();
    while (!if2.eof())
    {
        if (isalpha(ch))
        {
            //Find out if the letter exist in the ecription key file
            if (find_letter(if1, if2, letter, ch))
            {
                //If exist it prints the encription letter
                out << letter;
                cout << letter;
            }
            else
            {
                //If it didnt find it prints the lettter that it took
                out << ch;
                cout << ch;
            }
        }
        else
        {
            //Prints here if the char it took is not a letter
            out << ch;
            cout << ch;
        }

        ch = if2.get();
    }
}

//---------------------------------------------------------------------
//This function finds the letter it need to print instad of the currnet one
bool find_letter (ifstream &if1, ifstream &if2, char &letter, char ch)
{
    //reseting the file every time to start and serching from the begining
    if1.seekg(0, std::ios::beg);
    letter = if1.get();
    while (!if1.eof())
    {
        if (isalpha(letter))
        {
            if (ch == letter)
            {
                //If it found it takes the letter after that (the one that needs to print)
                letter = if1.get();
                return true;
            }
            //If the currnet letter is not the one we are serching it moves 2 spots to the right of the key
            if1.seekg(2, std::ios::cur);
            letter = if1.get();
        }
        else
        {
            if1.seekg(1, std::ios::cur);
            letter = if1.get();
        }
        
    }
    if1.clear();
    //reseting the file for it next search
    return false;
}

//---------------------------------------------------------------------
//closing all the file
void close_files (ifstream &if1, ifstream &if2, ofstream &out)
{
    if1.close();
    if2.close();
    out.close();
}