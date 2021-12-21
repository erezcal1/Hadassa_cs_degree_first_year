#include <iostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

const int INPUT = 10;

void read_data(char str[]);
void change_inputs(char str[]);
void print_str(char str[]);

int main()
{
    char str[INPUT];

    read_data(str);
    change_inputs(str);
    print_str(str);

    return EXIT_SUCCESS;
}

void read_data(char str[])
{
    cin >> setw(11) >> str;
}
void change_inputs(char str[])
{
    for (int i = 0; i < INPUT; i++)
    {
        if (isdigit(str[i]))
        {
            str[i] = '0';
        }
        else if (islower(str[i]))
        {
            str[i] = 'a';
        }
        else if (isupper(str[i]))
        {
            str[i] = 'A';
        }
        else
        {
            str[i] = ' ';
        }
    }
}
void print_str(char str[])
{
    cout << str << " ";
    cout << endl;
}