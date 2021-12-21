/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program builds to list and concting between them. the first list is a 
prime numbers list it gets the numebrs to therte or by the user or if the user 
puts a number that is not prime it find its smalles dividened (that is a prime)
and put it in order of smallest to biggest. the second list is a numebr the 
the user put in. each numebr is conctted to its prime number on the left. it 
out it in the right line near the prime numebr that it belong to at the end. 
for example the numebr 15 is not a prime but the smallest dividened of him is 
the numebr 3. so it build the prime number node 3 and concets the numebr 15 
in the right side of him. 

input: number bigger the 2 until the number 0

output: the main prime number and then all the numebr that the user put in
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
struct Prime_Node
{
    int _prime;
    struct Prime_Node *_next_prime;
    struct Node *_right;
};

struct Node
{
    int _data;
    struct Node *_next;
};
//-------------------------fuctions--------------------------------------------
Node *build_list(Prime_Node *&prime_head);
bool is_prime(int num);
void print_list(Prime_Node *prime_head, Node *head);
void put_in_Pos(const int num, Prime_Node **prime_head);
int smallest_divider(const int num);
void put_next(const int num, int dividend, Prime_Node *head);
Node *creat_node(int num);
void free_places(Prime_Node *prime_head, Node *head);
//-------------------------main------------------------------------------------
int main()
{
    struct Node *head = NULL;
    struct Prime_Node *prime_head = NULL;

    //building the list with previus numebrs and forword
    head = build_list(prime_head);
    //printning the numbers in the correct order
    print_list(prime_head, head);
    //releasing the used data
    free_places(prime_head, head);

    return EXIT_SUCCESS;
}
//-------------------------build list------------------------------------------
Node *build_list(Prime_Node *&prime_head)
{
    Node *head = NULL;

    int num, dividend;

    cin >> num;

    while (num != 0)
    {
        //checks if the numebr is a prime one
        if (is_prime(num))
        {
            //put the prime numebr in the correct order.(sorted)
            put_in_Pos(num, &prime_head);
            //puts the numebr that the user put in the right place
            put_next(num, num, prime_head);
        }
        else
        {
            //finding the smallest dividend
            dividend = smallest_divider(num);

            //puting him as a prime numebr in the correct place
            put_in_Pos(dividend, &prime_head);
            //put in the number that the user put in in the correct place
            put_next(num, dividend, prime_head);
        }

        cin >> num;
    }

    return head;
}
//checks if the numebr is a prime one
//-------------------------check if the num is prime---------------------------
bool is_prime(const int num)
{
    int n = 2;
    while (n <= num / 2)
    {
        if (num % n == 0)
            return false;
        n++;
    }
    return true;
}
//printning the numbers in the correct order
//-------------------------print the list--------------------------------------
void print_list(Prime_Node *prime_head, Node *head)
{
    //printning each line sparatly
    while (prime_head)
    {
        cout << prime_head->_prime << " ";
        head = prime_head->_right;
        while (head)
        {
            cout << head->_data << " ";
            head = head->_next;
        }
        cout << "\n";
        prime_head = prime_head->_next_prime;
    }
}
//put the prime numebr in the correct order.(sorted)
//using pointer to pointer
//-------------------------put the primes in the right postion-----------------
void put_in_Pos(const int num, Prime_Node **prime_head)
{
    //puting the numebr or creating a new node in the right place with pointer 
    //to pointer
    Prime_Node *temp;

    temp = new (nothrow) Prime_Node;
    if (temp == NULL)
    {
        cerr << "Cannot allocate memory\n";
        exit(EXIT_FAILURE);
    }

    temp->_prime = num;

    while (*prime_head != NULL && (*prime_head)->_prime <= num)
    {
        if ((*prime_head)->_prime == num)
        {
            delete temp;
            return;
        }
        prime_head = &((*prime_head)->_next_prime);
    }

    temp->_next_prime = *prime_head;
    *prime_head = temp;
    (*prime_head)->_right = NULL;
    
}
//finding the smallest dividend
//-------------------------checks what the smallest dividend is----------------
int smallest_divider(const int num)
{
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return i;
        }
    }
    return num;
}
//puts the numebr that the user put in the right place
//-------------------------put the number in the right place-------------------
void put_next(const int num, int dividend, Prime_Node *head)
{
    while (head != NULL)
    {
        //next to what we need to put the number
        if (head->_prime == dividend)
        {
            //creates a new node next to the prime number
            Node *next = creat_node(num);

            if (!head->_right)
            {
                head->_right = next;
                next->_next = NULL;
                break;
            }

            
            Node *temp = head->_right;

            while (temp && temp->_next != NULL)
            {
                temp = temp->_next;
            }

            //puts it in the correct spot
            temp->_next = next;
            next->_next = NULL;
        }
        
        head = head->_next_prime;
    }
}
//creating a new node for the numebr that the user puts in
//-------------------------creats a node to put the nums in--------------------
Node *creat_node(int num)
{
    struct Node *temp = new (nothrow) Node;
    if (temp == NULL)
    {
        cerr << "Cannot allocate memory\n";
        exit(EXIT_FAILURE);
    }
    temp->_data = num;
    return temp;
}
//releasing the used data
//-------------------------free all the places that the program used-----------
void free_places(Prime_Node *prime_head, Node *head)
{
    //releasing each line sparatly
    Prime_Node *temp;
    Node *temp1;
    while (prime_head)
    {
        head = prime_head->_right;
        while (head)
        {
            temp1 = head->_next;
            delete head;
            head = temp1;
        }
        delete head;
        temp = prime_head->_next_prime;
        delete prime_head;
        prime_head = temp;
    }
    delete prime_head;
}