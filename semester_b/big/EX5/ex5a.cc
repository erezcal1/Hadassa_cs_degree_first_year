/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program ask for a numebrs for the student id and the agrade until -1. 
it reads student until the end or 0 is entered. then the progrem gets numbers 
for the courses id how much points it have and the hours of the course. after 
all that the program calculate in a generic functions the average of all the 
avarage of the grades for each student the avarege of the height the avarege 
of the points in each courses and hours. at the end it prints the id of the 
highst grade student and the cousrs with the hiest numebr of hours

input: number of the id grades until -1 and the num,ebr of course id points 
       of it and hours

output: the avareges all in on line with a space between each one
*/
/*=============================================================================
                            ־־*== include ==*־־  
=============================================================================*/
#include <iomanip>
#include <cstdlib>
#include "Stud.h"
#include "Course.h"
/*=============================================================================
                            ־־*== using ==*־־  
=============================================================================*/
using std::cout;
using std::endl;
/*=============================================================================
                            ־־*== struct ==*־־  
=============================================================================*/
struct Highest
{
    double _avg;
    int _high_id;
};

/*=============================================================================
                            ־־*== typedef ==*־־  
=============================================================================*/
typedef void *get_elem_func(const void *arr, int index);
typedef double get_avg_func(const void *arr);

/*=============================================================================
                            ־־*== function ==*־־  
=============================================================================*/

Highest avg_of_all(void *arr, get_elem_func func, const int len,
                   get_avg_func get_value);

/*=============================================================================
                            ־־*== main ==*־־  
=============================================================================*/
int main()
{
    struct Stud studs[CLASS_SIZE] = {0};
    struct Course courses[NUM_OF_COURSES] = {0};
    Highest avg;
    int high_grade_id = 0, high_hour_C = 0;

    read_students(studs);

    read_courses(courses);

    //prints the right thing each time and saves the largest

    avg = avg_of_all(studs, get_stud_elem, CLASS_SIZE, stud_avg_Grade);
    cout << avg._avg << " ";
    high_grade_id = avg._high_id;

    avg = avg_of_all(studs, get_stud_elem, CLASS_SIZE, height_avg);
    cout << avg._avg << " ";

    avg = avg_of_all(courses, get_curr_elem, NUM_OF_COURSES, point_avg);
    cout << avg._avg << " ";

    avg = avg_of_all(courses, get_curr_elem, NUM_OF_COURSES, hours_avg);
    cout << avg._avg << " ";
    high_hour_C = avg._high_id;
    cout << high_grade_id << " " << high_hour_C << endl;

    return EXIT_SUCCESS;
}

/*=============================================================================
                            ־־*== avarege of all ==*־־  
=============================================================================*/
//main function that gest each function and return the avarage
Highest avg_of_all(void *arr, get_elem_func func,
                   const int len, get_avg_func get_value)
{
    int i;
    double avg = 0, biggest_avg = 0, sum_avg = 0;
    Highest temp;

    for (i = 0; i < len; i++)
    {
        if (return_id(func(arr, i)) == 0)
        {
            break;
        }
        avg = get_value(func(arr, i));

        //change the largest stud or curse if he is bigger
        if (avg > biggest_avg)
        {
            biggest_avg = avg;
            temp._high_id = return_id(func(arr, i));
        }
        sum_avg += avg;
    }
    temp._avg = sum_avg / i;
    return temp;
}
