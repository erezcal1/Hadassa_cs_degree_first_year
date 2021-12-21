#include "Course.h"

/*=============================================================================
                            ־־*== read courses ==*־־  
=============================================================================*/
void read_courses(Course courses[])
{
    Course new_course;

    for (int i = 0; i < NUM_OF_COURSES; i++)
    {
        cin >> new_course._course_id;
        //read courses ustil 0 is enterd
        if (new_course._course_id == 0)
        {
            return;
        }
        cin >> new_course._credit_points;
        cin >> new_course._hours_of_course;

        courses[i] = new_course;
    }
}
/*=============================================================================
                            ־־*== get curr elem ==*־־  
=============================================================================*/
void *get_curr_elem(const void *arr, int index)
{
    return (Course *)arr + index;
}
/*=============================================================================
                            ־־*== hours avg ==*־־  
=============================================================================*/
double hours_avg(const void *arr)
{
    Course *cour = ((Course *)arr);
    return (cour->_hours_of_course);
}
/*=============================================================================
                            ־־*== point avg ==*־־  
=============================================================================*/
double point_avg(const void *arr)
{
    Course *cour = ((Course *)arr);
    return (cour->_credit_points);
}