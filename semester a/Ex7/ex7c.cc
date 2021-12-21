/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program checks if the password you enter are good acording to 
the mandatory things you says that need to be in them

input: the numebr of password you want to check and then the passwords
       then the number of mandatory things that need to be in then the 
       madatory strings

output: the passwords that are good

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
using std::setw;

//---------const section----------
const int MAX_STRS = 10;
const int MAX_STR_LEN = 100;

//------------function------------
void read_passwords(char inp_passwd[MAX_STRS][MAX_STR_LEN], int &);
void parameter_to_password(char mandatory[MAX_STRS][MAX_STR_LEN], int &);
void cheaking_passwords(char mandatory[MAX_STRS][MAX_STR_LEN],
                        char inp_passwd[MAX_STRS][MAX_STR_LEN],
                        char out_passwd[MAX_STRS][MAX_STR_LEN], int, int);
void inp_checker(int i, int j, char inp_passwd[MAX_STRS][MAX_STR_LEN],
                 char mandatory[MAX_STRS][MAX_STR_LEN], bool &, int n);
void print_good_passwd(char inp_passwd[MAX_STRS][MAX_STR_LEN],
                       char out_passwd[MAX_STRS][MAX_STR_LEN], int, int);

//---------main section-------
int main()
{
    //addining int and chars for the program to recognize
    char inp_passwd[MAX_STRS][MAX_STR_LEN], out_passwd[MAX_STRS][MAX_STR_LEN],
        mandatory[MAX_STRS][MAX_STR_LEN];

    int wanted_check, wanted_passwords;

    //reading the passwords
    read_passwords(inp_passwd, wanted_passwords);
    //reading the mandatory thing that need to be
    parameter_to_password(mandatory, wanted_check);
    //the main function that checks all the things
    // the running time of this fuction is  
    //(wanted_passwrod * wanted_check * the size of madatory * 
    //the size of the password) so n ^ 4
    cheaking_passwords(mandatory, inp_passwd, out_passwd, wanted_check,
                       wanted_passwords);

    return EXIT_SUCCESS;
}

//inserting values to string (reading the number of password that the user 
//want to put in and the passwords)
void read_passwords(char inp_passwd[MAX_STRS][MAX_STR_LEN],
                    int &wanted_passwords)
{
    cin >> wanted_passwords;

    for (int i = 0; i < wanted_passwords; i++)
    {
        cin >> setw(MAX_STR_LEN + 1) >> inp_passwd[i];
    }
}

//inserting values to string (reading the number of madatory things that the 
//user want to put in and the mandatory things)
void parameter_to_password(char mandatory[MAX_STRS][MAX_STR_LEN],
                           int &wanted_check)
{
    cin >> wanted_check;

    for (int i = 0; i < wanted_check; i++)
    {
        cin >> setw(MAX_STR_LEN + 1) >> mandatory[i];
    }
}

//the main function that checks if one of the mandatory chars exist in the 
//password. like that to each row of the mandatory checks
void cheaking_passwords(char mandatory[MAX_STRS][MAX_STR_LEN],
                        char inp_passwd[MAX_STRS][MAX_STR_LEN],
                        char out_passwd[MAX_STRS][MAX_STR_LEN],
                        int wanted_check, int wanted_passwords)
{
    bool found = false;
    int counter = 0, n = 0, num_of_valid_passwd = 0;

    while (n < wanted_passwords)
    {
        counter = 0;

        for (int i = 0; i < wanted_check; i++)
        {
            found = false;

            for (int j = 0; mandatory[i][j] != '\0'; j++)
            {
                //calling a function to check the password if the mandatory 
                //place is exist password
                inp_checker(i, j, inp_passwd, mandatory, found, n);
                if (found)
                {
                    counter++;
                    break;
                }
                if (!found)
                {
                    break;
                }
            }
            if (counter == wanted_check)
            {
                //sending the good passwords to a function and putting them 
                //in a 2 dimentions array called out_passwd
                print_good_passwd(inp_passwd, out_passwd, n, 
                                  num_of_valid_passwd);
                num_of_valid_passwd++;
            }
            if (!found)
            {
                break;
            }
        }
        n++;
    }
}

//check is the m,andotory place exist if so return true if not it stays false
void inp_checker(int i, int j, char inp_passwd[MAX_STRS][MAX_STR_LEN],
                 char mandatory[MAX_STRS][MAX_STR_LEN], bool &found, int n)
{
    for (int inp_cheak = 0; inp_cheak < int(strlen(inp_passwd[n])); inp_cheak++)
    {
        if (strchr(mandatory[i], inp_passwd[n][inp_cheak]))
        {
            found = true;
        }
    }
}

//copying the good password to the 2 dimetions array calls out_passwd
void print_good_passwd(char inp_passwd[MAX_STRS][MAX_STR_LEN],
                       char out_passwd[MAX_STRS][MAX_STR_LEN], int n,
                       int num_of_valid_passwd)
{
    strcpy(out_passwd[num_of_valid_passwd], inp_passwd[n]);
    //printing the good passwords
    cout << out_passwd[num_of_valid_passwd] << endl;
}