#include <iostream>
#include <cstdlib>
#include <iomanip>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::nothrow;
using std::setw;

const int MAX_LINE_LEN = 1000;

struct Sentences 
{
    char **_data ;
    int _num_of_sentences;
}; 

void allocate_array();
void read_array(Sentences& lines, int i);


int main()
{
    allocate_array();
    
    return EXIT_SUCCESS;
}

void allocate_array()
{
    Sentences lines;

    cin >> lines._num_of_sentences;

    Sentences *lines_size[lines._num_of_sentences];

    for (int i = 0; i < lines._num_of_sentences; i++)
    {
        lines_size[i] = new(nothrow) Sentences;

        if (lines_size[i] == NULL)
        {
            cerr << "problem" << endl;
            exit(EXIT_FAILURE);
        }
    }
}

