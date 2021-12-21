#include <iostream>

using std::cin;

const int NUM_OF_COURSES = 10;
/*=============================================================================
                            ־־*== struct ==*־־  
=============================================================================*/
struct Course
{
    int _course_id;
    double _credit_points;
    unsigned int _hours_of_course;
};
void *get_curr_elem(const void *arr, int index);

void read_courses(Course courses[]);
double hours_avg(const void *arr);
double point_avg(const void *arr);

int return_id(const void *arr);