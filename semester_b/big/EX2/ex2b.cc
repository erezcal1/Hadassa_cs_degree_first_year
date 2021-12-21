/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program builds a list that goes in both ways. first iit reads and id and 
jump to each node it creates and then conting each one to the next and back 
node. the program gets numebrs to the nodes and put it it pairs the first 
num goes to the id and the second one goes to the jump. the program stops 
getting numbers when the second number is 0. the it prints the id of the first 
node and jumps the amount of numebrs that the jumps says. forword or backwords 
even a complete circel. when it jumped enoth times the program print the id on 
the node that it is corrently in and jumps again. it does that until we went 
to the node with the jump = 0 or it jumped 15 times. 

input: pairs of numebrs until the second one is 0

output: the id of the nodes after the jumps
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
    int _id;
    int _jump;
    struct Node *_next,
        *_prev;
};
//-------------------------consts----------------------------------------------
const unsigned N = 15;
//-------------------------fuctions--------------------------------------------
Node *build_list();
void print_next(Node *head);
Node *jmp_forw(Node *head);
Node *jmp_back(Node *head);
void free_plac(Node *head);
//-------------------------main------------------------------------------------
int main()
{
    struct Node *head = NULL;

    //building the list and making head equal to the list
    head = build_list();

    //printing the ids
    print_next(head);

    //releasing the used data
    free_plac(head);

    return EXIT_SUCCESS;
}
//building the two-way list 
//-------------------------build_list------------------------------------------
Node *build_list()
{
    Node *back = NULL, *head = NULL;

    int num1, num2;

    cin >> num1 >> num2;
    while (true)
    {
        //creating a nodes to put the id and the jump
        struct Node *temp = new (nothrow) Node;

        if (temp == NULL)
        {
            cerr << "Cannot allocate memory\n";
            exit(EXIT_FAILURE);
        }

        temp->_id = num1;
        temp->_jump = num2;

        if (head == NULL)
        {
            head = temp;
        }

        else
        {
            temp->_prev = back;
            back->_next = temp;
        }
        
        //concting the back and the corrent node
        back = temp;

        //exiting if the second number is equal to 0
        if (num2 == 0)
            break;

        cin >> num1 >> num2;
    }

    //concting the last with first
    //and vise versa
    back->_next = head;
    head->_prev = back;

    return head;
}
//printing the ids and sending a function to jump
//-------------------------print next------------------------------------------
void print_next(Node *head)
{
    //goes until the 15 numebr
    for (unsigned counter = 0; counter < N; counter++)
    {
        cout << head->_id << " ";
        //check if needs to jump forword or back words
        if (head->_jump > 0)
        {
            head = jmp_forw(head);
        }
        //breaking if we got 0 on the jump
        else if (head->_jump == 0)
        {
            return;
        }

        else
        {
            head = jmp_back(head);
        }
    }
}
//jumps the amount of times in the jump node forword
//-------------------------jump forword----------------------------------------
Node *jmp_forw(Node *head)
{
    int num = 0;
    num = head->_jump;
    for (int i = 0; i < num; i++)
    {
        head = head->_next;
    }
    return head;
}
//jumps the amount of times in the jump node backwords
//-------------------------hump backwords--------------------------------------
Node *jmp_back(Node *head)
{
    int num = 0;
    num = head->_jump;
    for (int i = 0; i > num; i--)
    {
        head = head->_prev;
    }
    return head;
}
//releasing the used data
//-------------------------free places-----------------------------------------
void free_plac(Node *head)
{
    while (head->_jump != 0)
    {
        Node *temp = head->_next;
        delete head;
        head = temp;
    }
    delete head;
}