#include "Stud.h"
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
                            ־־*== get stud elem ==*־־  
=============================================================================*/
void *get_stud_elem(const void *arr, int index)
{
    return (Stud *)arr + index;
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