/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program get numbers from the user and checks each one of them if the 
number before it is smaller then him and the number after him is bigger 
them him. only if those two options exist it adds one to the counter. 
at the end it prints the amount. to check the first number and the last on 
one of the things needs to work acordingly.

input: numbers until eof

output: how much numbers how many numbers where the condition is met
*/
//-------------------------include---------------------------------------------
#include <iostream>
#include <iomanip>
#include <cstdlib>
//-------------------------using-----------------------------------------------
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::nothrow;
//-------------------------struct----------------------------------------------
struct Node
{
    int _data;
    struct Node *_next,
                *_prev;
};
//-------------------------fuctions--------------------------------------------
Node *build_list();
int check_before_after(Node *head);
void free_places(Node *head);

//-------------------------main------------------------------------------------
int main()
{
    struct Node *head = NULL;
    int counter;

    //building the list with previus numebrs and forword
    head = build_list();

    //counts the amount of numebr that meet the condition 
    counter = check_before_after(head);

    //releasing the used data
    free_places(head);

    cout << counter << endl;

    return EXIT_SUCCESS;
}
//-------------------------build_list------------------------------------------
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
//counts the amount of numebr that meet the condition 
//-------------------------check before and after------------------------------
int check_before_after(Node *head)
{
    int counter = 0;
    
    while (head != NULL)
    {
        if ((head->_prev == NULL) || (head->_prev->_data < head->_data))
        {
            if ((head->_next == NULL) || (head->_next->_data > head->_data))
            {
                //only if those two condition is met it adds
                counter++;
            }
        }
        //checking each numebr that we built
        head = head->_next;
    }
    return counter;
}
//releasing the used data
//-------------------------free places-----------------------------------------
void free_places(Node *head)
{
    while (head != NULL)
    {
        Node *temp = head->_next;
        delete head;
        head = temp;
    }
}