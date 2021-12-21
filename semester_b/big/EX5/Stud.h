#include <iostream>

using std::cin;

const int NUM_OF_GRADES = 7;
const int CLASS_SIZE = 10;
/*=============================================================================
                            ־־*== struct ==*־־  
=============================================================================*/
struct Stud
{
    int _stud_id;
    int _grades[NUM_OF_GRADES];
    double _height;
};


void read_students(Stud studs[]);
void read_greades(Stud &student);

void *get_stud_elem(const void *arr, int index);

double stud_avg_Grade(const void *arr);

double height_avg(const void *arr);