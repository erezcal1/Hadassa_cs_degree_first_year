/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program ask for a numebr 1 or 0 to find oyut what the user want to do. 
and then there are a few options initializing the array print the arr sorting 
the array with bubler sort read another or exut the frogram. each one does 
different things. the initializing gets numebrs Date or Time until -1 is 
put to him. print prints all the data put in to him. sort is sorting the 
array by numebr from small to big. read another gets anothe time or date. 
and exit realsing the array that has been used and exit the program 

input: at the begginng 1 or 0 for date or time, and the number from 1-4 for 
       the programs that i wrote above

output: only the print has an put put of the artray that the user put in
*/
#include "ex4c_given.h"

void my_exit(int line, const char *msg)
{
  cerr << "internal error in line " << line
       << " ; " << msg << endl;
  exit(1);
}

// ***  Generic functions and types  ***
typedef bool (*read_item)(void *);                     //
typedef void (*print_item)(void *);                    //
typedef int (*comp_items)(const void *, const void *); //
typedef void (*swap_items)(void *, void *);            //
typedef void (*copy_item)(void *, const void *);       // first arg is destination
typedef void *(*alloc_arr)(int size);                  //
typedef void *(*alloc_item)();                         //
typedef void (*delete_arr)(void *&);
typedef void (*delete_item)(void *&);           //
typedef void *(*item_at)(void *ptr, int index); //

//*** Struct declarations ***

// structure to hold generic functions
struct Functions
{
  read_item _read_item;
  print_item _print_item;
  comp_items _comp_item;
  swap_items _swap_item;
  copy_item _copy_item;
  alloc_arr _alloc_arr;
  alloc_item _alloc_item;
  delete_arr _delete_arr;
  delete_item _delete_item;
  item_at _item_at;
};

struct Arr_Struct
{
  int _size,
      _capacity;
  void *_array;
};

/*===================================================
==  Date functions and Date Wrap Functions        ==*  
===================================================*/
bool read_date(void *date)
{
  return read_date(*((Date *)date));
}
//----------------------------------------------
void print_date(void *date)
{
  return print_date(*((Date *)date));
}
//----------------------------------------------
int comp_date(const void *d1, const void *d2)
{
  return comp_date(*((Date *)d1), *((Date *)d2));
}
//----------------------------------------------
void swap_date(void *d1, void *d2)
{
  return swap_date(*((Date *)d1), *((Date *)d2));
}
//----------------------------------------------
void copy_date(void *date, const void *date2)
{
  copy_date(*((Date *)date), *((Date *)date2));
}
//----------------------------------------------
void *alloc_date_arr(int size)
{
  Date *date_arr = new (nothrow) Date[size];
  if (!date_arr)
  {
    cerr << "Cannot allocate array";
    exit(EXIT_FAILURE);
  }
  return date_arr;
}
//----------------------------------------------
void *alloc_date_item()
{
  void *date = new (nothrow) Date;
  if (date == NULL)
  {
    cerr << "Cannot allocate array";
    exit(EXIT_FAILURE);
  }
  return date;
}
//----------------------------------------------
void delete_date_arr(void *&date)
{
  Date *temp = ((Date *)date);
  delete[] temp;
  temp = nullptr;
}
//----------------------------------------------
void delete_date_item(void *&date)
{
  Date *temp = ((Date *)date);
  delete temp;
  temp = nullptr;
}
//----------------------------------------------
void *item_date_at(void *ptr, int index)
{
  return ((Date *)ptr + index);
}

/*===================================================
==  Time functions and Time Wrap Functions        ==*  
===================================================*/
bool read_time(void *time)
{
  return read_time(*((Time *)time));
}
//----------------------------------------------
void print_time(void *time)
{
  return print_time(*((Time *)time));
}
//----------------------------------------------
int comp_time(const void *t1, const void *t2)
{
  return comp_time(*((Time *)t1), *((Time *)t2));
}
//----------------------------------------------
void swap_time(void *t1, void *t2)
{
  return swap_time(*((Time *)t1), *((Time *)t2));
}
//----------------------------------------------
void copy_time(void *time, const void *time2)
{
  return copy_time(*((Time *)time), *((Time *)time2));
}
//----------------------------------------------
void *alloc_time_arr(int size)
{
  Time *time_arr = new (nothrow) Time[size];
  if (!time_arr)
  {
    cerr << "Cannot allocate array";
    exit(EXIT_FAILURE);
  }
  return time_arr;
}
//----------------------------------------------
void *alloc_time_item()
{
  void *time = new (nothrow) Time;
  if (time == NULL)
  {
    cerr << "Cannot allocate array";
    exit(EXIT_FAILURE);
  }
  return time;
}
//----------------------------------------------
void delete_time_arr(void *&time)
{
  Time *temp = ((Time *)time);
  delete[] temp;
  temp = nullptr;
}
//----------------------------------------------
void delete_time_item(void *&time)
{
  Time *temp = ((Time *)time);
  delete temp;
  temp = nullptr;
}
//----------------------------------------------
void *item_time_at(void *ptr, int index)
{
  return ((Time *)ptr + index);
}
/*===================================================
==         ex4c generic functions                 ==*  
===================================================*/

//  ****  global variables ***
const Functions DATE_FUNCS = {
    read_date,
    print_date,
    comp_date,
    swap_date,
    copy_date,
    alloc_date_arr,
    alloc_date_item,
    delete_date_arr,
    delete_date_item,
    item_date_at,
};

const Functions TIME_FUNCS = {
    read_time,
    print_time,
    comp_time,
    swap_time,
    copy_time,
    alloc_time_arr,
    alloc_time_item,
    delete_time_arr,
    delete_time_item,
    item_time_at,
};

//==================================================
void free_memory(Arr_Struct &arr, const Functions *functions)
{
  //realesing the momory that we used
  functions->_delete_arr(arr._array);
}
//==================================================
void copy_time(Time &dest, const Time &src)
{
  //copy the time struct from the sorce to the destantion
  dest._hour = src._hour;
  dest._minute = src._minute;
  dest._second = src._second;
}
//==================================================
void copy_date(Date &dest, const Date &src)
{
  //copy the date struct from the sorce to the destantion
  dest._day = src._day;
  dest._month = src._month;
  dest._year = src._year;
}
//==================================================
void resize_arr(Arr_Struct &arr, const Functions *functions)
{
  arr._capacity *= 2;
  void *temp, *temp_arr;
  //creatin an alocation for the new item to be places at
  void *new_arr = functions->_alloc_arr(arr._capacity);
  for (int i = 0; i < arr._size; i++)
  {
    temp_arr = functions->_item_at(new_arr, i);
    temp = functions->_item_at(arr._array, i);
    functions->_copy_item(temp_arr, temp);
  }
  //delete the last array after the resize
  functions->_delete_arr(arr._array);
  arr._array = new_arr;
}
//==================================================
void add_item(Arr_Struct &arr, const Functions *functions)
{
  //add new item to the array
  if (arr._size == arr._capacity)
  {
    //making the size twice as big
    resize_arr(arr, functions);
  }
  void *temp;
  while (true)
  {
    //reads the date or time until the end
    temp = functions->_item_at(arr._array, arr._size);
    if (!functions->_read_item(temp))
    {
      return;
    }
    arr._size++;
    //dose a resize if needed
  }
}
//==================================================
void init_arr(Arr_Struct &arr, const Functions *functions)
{
  arr._size = 0;
  arr._capacity = 2;
  free_memory(arr, functions);
  arr._array = functions->_alloc_arr(arr._capacity);
  add_item(arr, functions);
}
//==================================================
void print_arr(const Arr_Struct &arr, const Functions *functions)
{
  //prints the array
  cout << "Size = " << arr._size
       << " Capacity = " << arr._capacity << endl;

  void *temp;

  for (int j = 0; j < arr._size; j++)
  {
    temp = functions->_item_at(arr._array, j);
    functions->_print_item(temp);
    cout << endl;
  }
}
//==================================================
void sort_arr(Arr_Struct &arr, const Functions *functions)
{
  //sorting the array with bubble sort
  void *temp1, *temp2;

  for (int i = 0; i < arr._size - 1; i++)
  {
    for (int j = 0; j < arr._size - 1 - i; j++)
    {
      temp1 = functions->_item_at(arr._array, j);
      temp2 = functions->_item_at(arr._array, j + 1);
      if (functions->_comp_item(temp1, temp2) > 0)
      {
        functions->_swap_item(temp1, temp2);
      }
    }
  }
}
//==================================================
int main(int argc, char **argv)
{
  const Functions *func_ptr = nullptr;
  Arr_Struct arr;
  //initializing the array
  arr._capacity = arr._size = 0;
  arr._array = nullptr;

  Type type = select_type();

  //asking for the DATE or TIME
  switch (type)
  {
  case DATE:
    func_ptr = &DATE_FUNCS;
    break;
  case TIME:
    func_ptr = &TIME_FUNCS;
    break;
  default:
    my_exit(__LINE__, "bad Type");
  };

  while (true)
  {
    //asking each time what to do
    Action act = select_action();

    switch (act)
    {
    case INIT:
      init_arr(arr, func_ptr);
      break;
    case PRINT:
      print_arr(arr, func_ptr);
      break;
    case SORT:
      sort_arr(arr, func_ptr);
      break;
    case ADD:
      add_item(arr, func_ptr);
      break;
    case EXIT:
      free_memory(arr, func_ptr);
      exit(0);
    default:
      my_exit(__LINE__, "bad action code");
    }
  }
}
