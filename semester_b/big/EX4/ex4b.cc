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
#include <iostream>
#include <iomanip>
#include <cstdlib>
/*=============================================================================
                            ־־*== using ==*־־  
=============================================================================*/
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::nothrow;

const int NUM_OF_GRADES = 7;
const int CLASS_SIZE = 10;
const int NUM_OF_COURSES = 10;
/*=============================================================================
                            ־־*== struct ==*־־  
=============================================================================*/
struct Stud
{
    int _stud_id;
    int _grades[NUM_OF_GRADES];
    double _height;
};

struct Course
{
    int _course_id;
    double _credit_points;
    unsigned int _hours_of_course;
};

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
void read_students(Stud studs[]);
void read_greades(Stud &student);
void read_courses(Course courses[]);

Highest avg_of_all(void *arr, get_elem_func func, const int len, 
                   get_avg_func get_value);

void *get_stud_elem(const void *arr, int index);
void *get_curr_elem(const void *arr, int index);

double stud_avg_Grade(const void *arr);
double hours_avg(const void *arr);
double point_avg(const void *arr);
double height_avg(const void *arr);

int return_id(const void *arr);

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
                            ־־*== read students ==*־־  
=============================================================================*/
void read_students(Stud studs[])
{
    Stud new_student;

    for (int i = 0; i < CLASS_SIZE; i++)
    {
        cin >> new_student._stud_id;
        //read until id is 0
        if (new_student._stud_id == 0)
        {
            return;
        }

        read_greades(new_student);
        cin >> new_student._height;
        studs[i] = new_student;
    }
}
/*=============================================================================
                            ־־*== read greades ==*־־  
=============================================================================*/
void read_greades(Stud &student)
{
    for (int i = 0; i < NUM_OF_GRADES; i++)
    {
        cin >> student._grades[i];
        //gets grade until -1 is enter
        if (student._grades[i] == -1)
        {
            return;
        }
    }
}
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
/*=============================================================================
                            ־־*== get stud elem ==*־־  
=============================================================================*/
void *get_stud_elem(const void *arr, int index)
{
    return (Stud *)arr + index;
}
/*=============================================================================
                            ־־*== get curr elem ==*־־  
=============================================================================*/
void *get_curr_elem(const void *arr, int index)
{
    return (Course *)arr + index;
}
/*=============================================================================
                            ־־*== stud avg Grade ==*־־  
=============================================================================*/
double stud_avg_Grade(const void *arr)
{
    //return the student avarage
    //and later return the avarge of avarge of all the greades
    int avg_summery = 0;
    Stud *student = ((Stud *)arr);
    int j;
    if (student->_stud_id == 0)
    {
        return 0;
    }

    for (j = 0; j < NUM_OF_GRADES; j++)
    {
        if (student->_grades[j] == -1)
        {
            break;
        }
        avg_summery += student->_grades[j];
    }
    return (avg_summery / j);
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
/*=============================================================================
                            ־־*== height avg ==*־־  
=============================================================================*/
double height_avg(const void *arr)
{
    Stud *student = ((Stud *)arr);
    return (student->_height);
}
/*=============================================================================
                            ־־*== return id ==*־־  
=============================================================================*/
int return_id(const void *arr)
{
    Stud *student = ((Stud *)arr);
    return(student->_stud_id);
}