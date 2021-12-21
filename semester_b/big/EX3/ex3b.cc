/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program get numebrs to build the tree and for each number it gets it 
also get x and y to go in the same place. the progrem then calculate and 
return the larggest Node with his kids and him are in the same querter. 
for example if the node and his kids are in the 2 quarter it will add them 
and the size of the node is 3. the program returnthe larggest node that it 
found with this method. if 2 nodes are the same it returns the node that he 
saw first . that means that the left nodewill come first. at the end when it 
found the biggest node it prints the valus of x and y that he holds.

run time of main function: O(n)

input: number and valuse for x and y

output: the x and y that the biggest Node holds
*/
//---------include section-----------------------------------------------------
#include <iostream>
#include <cstdlib>
//---------using section-------------------------------------------------------
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
//------------struct-----------------------------------------------------------
struct Point
{
    int _x,
        _y;
};

struct Node
{
    int _id;
    struct Point *_data;
    struct Node *_left,
        *_right;
};

struct Node_Stats
{
    int _size,
        _quart,
        _max_place;
    struct Node *_max_tree;
};
//------------Enum----------------------------------------------------------- 
enum quart_place
{
    FIRST = 1,
    SECOND = 2,
    THIRD = 3,
    FORTH = 4
};
//------------function---------------------------------------------------------
Node *build_root(Node *root);
void insert_in_tree(Node *&root, int num);
void insert_point(Node *root);
void free_tree(Node *root);
Node *same_place(Node *root);
Node *same_place(Node *root, Node_Stats &curr, int &max_place, 
                Node *&max_size_tree);
int quarter_place(Node *root, Node_Stats &curr);
//---------main section--------------------------------------------------------
int main()
{
    struct Node *root = NULL, *subtree;

    //building the tree with the number the user put in
    root = build_root(root);

    if (!root)
    {
        //pritns 0 0 if the node it got is empty
        cout << "0 0" << endl;
    }

    else
    {
        //if the node isnt empty it checks the larggest node
        subtree = same_place(root);
        //prints his x and y valus
        cout << subtree->_data->_x << " " << subtree->_data->_y << endl;
    }
    //freeing the space I used
    free_tree(root);

    return EXIT_SUCCESS;
}
//-----------------------------------------------------------------------
//building the tree with the number the user put in
//asking for nunmbers and calling the other function
Node *build_root(Node *root)
{
    int num;
    cin >> num;
    //ask for nummbers until end of file
    while (!cin.eof())
    {
        insert_in_tree(root, num);
        cin >> num;
    }
    return root;
}
//-----------------------------------------------------------------------
//puting the numbers in the right place
void insert_in_tree(Node *&root, int num)
{
    if (root == NULL)
    {
        root = new (std::nothrow) Node;
        if (root == NULL)
        {
            cerr << "Cannot alocate memory\n";
            exit(EXIT_FAILURE);
        }
        root->_id = num;
        insert_point(root);
        root->_left = root->_right = NULL;
        return;
    }
    //puting a smaller numebr and the same numebr on the left
    else if (num <= root->_id)
    {
        insert_in_tree(root->_left, num);
    }
    //puting bigger numebrs in the right place
    else
    {
        insert_in_tree(root->_right, num);
    }
}
//-----------------------------------------------------------------------
//adding the x and y to each node 
void insert_point(Node *root)
{
    Point *new_point = new (std::nothrow) Point;
    if (new_point == NULL)
    {
        cerr << "Cannot alocate memory\n";
        exit(EXIT_FAILURE);
    }
    cin >> new_point->_x >> new_point->_y;
    root->_data = new_point;
}
//-----------------------------------------------------------------------
//rapping function to the main function that calls her
Node *same_place(Node *root)
{
    int max_place = 0;
    Node_Stats curr;
    Node *max_size_tree = NULL;
    return same_place(root, curr, max_place, max_size_tree);
}
//-----------------------------------------------------------------------
//recurrsive function to go over the tree and find the biggest node that 
//coperatis with what the qustion needed
//run time of main function: O(n)
Node *same_place(Node *root, Node_Stats &curr, int &max_place, 
                 Node *&max_size_tree)
{
    Node_Stats left, right;

    //if rrot is null it resart the secondry struct with 0;
    if (!root)
    {
        curr = {0, 0, 0, NULL};
        return root;
    }

    //calling the same function in recurssive to the left and then to the right
    left._max_tree = same_place(root->_left, left, left._max_place, 
                     max_size_tree);
    right._max_tree = same_place(root->_right, right, right._max_place, 
                      max_size_tree);

    //finding the quarter of the place we are right now
    curr._quart = quarter_place(root, curr);

    //checks if the same qurter or NULL for right and left
    if (root->_left == NULL || curr._quart == left._quart)
    {
        if (root->_right == NULL || curr._quart == right._quart)
        {
            //adding the size
            curr._size = left._size + right._size + 1;
            //if they are the same it check if its the biggets node
            if (max_place < curr._size)
            {
                //if found to be the biggest it saaves it as the biggest Node
                max_place = curr._size;
                max_size_tree = root;
                return root;
            }
        }
    }

    //return the biggest node
    if (left._max_place >= right._max_place)
    {
        return left._max_tree;
    }
    
    return right._max_tree;
}
//-----------------------------------------------------------------------
//this function returns the querter of the node that sent to her
int quarter_place(Node *root, Node_Stats &curr)
{
    if (!root)
    {
        //return 0 if the node is null
        return 0;
    }

    //adding the size and returning the right place
    curr._size++;

    if (root->_data->_x > 0 && root->_data->_y > 0)
    {
        return FIRST;
    }

    else if (root->_data->_x < 0 && root->_data->_y > 0)
    {
        return SECOND;
    }

    else if (root->_data->_x < 0 && root->_data->_y < 0)
    {
        return THIRD;
    }

    return FORTH;
}
//------------------------realsing the tree we built and used------------------
void free_tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root->_left);
    free_tree(root->_right);
    delete root->_data;
    delete root;
}