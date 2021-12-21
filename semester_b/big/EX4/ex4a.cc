/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program get numbers from the user and checks each one and print each time 
the first positive from left, then the first positive from right, the first 
prime form the left and the the right, and at the end it prints the first 
palindrom from the start and then the first palindrom for the last place. 
if the program didnt found a match it prints the numer 0 in each place 

input: numbers until eof

output: each time the correct numebr or 0 if the numebr isn't exist
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
/*=============================================================================
                            ־־*== struct ==*־־
=============================================================================*/
struct Node
{
    int _data;
    struct Node *_next,
        *_prev;
};
enum
{
    POS_LEFT,
    POS_RIGHT,
    PRIME_LEFT,
    PRIME_RIGHT,
    PALI_LEFT,
    PALI_RIGHT
};
/*=============================================================================
                            ־־*== functions ==*־־  
=============================================================================*/
Node *build_list();
int function_caller(bool (*func)(int), Node *first, int num);
void main_caller(Node *first, Node *last);
void free_places(Node *head);
Node *last_place(Node *first);
bool positive_num(int num);
bool prime_num(int num);
bool num_is_polindrom(int num);

/*=============================================================================
                            ־־*== main ==*־־  
=============================================================================*/
int main()
{
    struct Node *first = NULL, *last;

    //building the list with previus numebrs and forword
    first = build_list();
    last = last_place(first);

    main_caller(first, last);

    //releasing the used data
    free_places(first);

    return EXIT_SUCCESS;
}
/*=============================================================================
                           ־־*== build list ==*־־  
=============================================================================*/
Node *build_list()
{
    Node *tail = NULL, *head = NULL;

    int num;

    cin >> num;
    //goes until end of file or ctrl D in linux
    while (!cin.eof())
    {
        //creating a new place for the number
        struct Node *temp = new (nothrow) Node;

        if (temp == NULL)
        {
            cerr << "Cannot allocate memory\n";
            exit(EXIT_FAILURE);
        }

        //conting the back and next numebrs to the data that its recived
        temp->_prev = tail;
        temp->_data = num;
        temp->_next = NULL;

        if (head == NULL)
        {
            head = tail = temp;
        }

        else
        {
            tail->_next = temp;
            tail = temp;
        }
        cin >> num;
    }

    return head;
}
/*=============================================================================
                            ־־*== last build ==*־־  
=============================================================================*/
Node *last_place(Node *first)
{
    if (first == NULL)
    {
        return first;
    }

    while (first->_next != NULL)
    {
        first = first->_next;
    }
    return first;
}
/*=============================================================================
                        ־־*== main function caller ==*־־  
=============================================================================*/
void main_caller(Node *first, Node *last)
{
    cout << function_caller(positive_num, first, POS_LEFT) << " ";
    cout << function_caller(positive_num, last, POS_RIGHT) << " ";
    cout << function_caller(prime_num, first, PRIME_LEFT) << " ";
    cout << function_caller(prime_num, last, PRIME_RIGHT) << " ";
    cout << function_caller(num_is_polindrom, first, PALI_LEFT) << " ";
    cout << function_caller(num_is_polindrom, last, PALI_RIGHT) << " ";
    cout << endl;
}
/*=============================================================================
                        ־־*== function caller ==*־־  
=============================================================================*/
int function_caller(bool (*func)(int), Node *first, int num)
{
    while (first)
    {
        //runs on the Node each time it calls a new functiuon
        if (func(first->_data))
            return first->_data;

        if (num % 2 == 0)
        {
            first = first->_next;
        }
        else
            first = first->_prev;
    }
    return 0;
}
/*=============================================================================
                            ־־*== positive ==*־־  
=============================================================================*/
bool positive_num(int num)
{
    return (num > 0);
}
/*=============================================================================
                            ־־*== prime ==*־־  
=============================================================================*/
bool prime_num(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i < num / 2; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    //return true if the numebr is a prime
    return true;
}
/*=============================================================================
                            ־־*== palindrom ==*־־  
=============================================================================*/
bool num_is_polindrom(int num)
{
    int digit, reverse = 0, number;

    number = num;

    while (number != 0)
    {
        digit = number % 10;
        reverse = (reverse * 10) + digit;
        number = number / 10;
    }

    if (reverse == num)
    {
        return true;
    }
    return false;
}
//releasing the used data
/*=============================================================================
                            ־־*== free places ==*־־  
=============================================================================*/
void free_places(Node *head)
{
    while (head != NULL)
    {
        Node *temp = head->_next;
        delete head;
        head = temp;
    }
}