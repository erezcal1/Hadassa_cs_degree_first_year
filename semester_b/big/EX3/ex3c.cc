/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This function gets numebr form the user and return the biggets node with the 
most even numebrs. the program checks each node to see if its even or odd and 
adds to the sum. itgoes from left to right on order. if it found a node with 
most even nodes in it saves the node until it founds a new one and saving him.

input: number to build a tree until EOF

output: the biggest tree that most f its number are even
*/
//---------include section-----------------------------------------------------
#include <iostream>
#include <cstdlib>
//---------using section-------------------------------------------------------
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
//------------struct-----------------------------------------------------------
struct Node 
{
    int _data;
    struct Node *_left,
                *_right;
};

struct Node_stats
{
    int _even,
        _odd;
    struct Node *_tree;
};
//------------function---------------------------------------------------------
Node *build_root(Node *root);
void insert_in_tree(Node *&root, int num);
Node *biggest_even_tree(Node *root, Node_stats &curr);
bool is_even(Node *root);
void free_tree(Node *root);
//---------main section--------------------------------------------------------
int main()
{
    struct Node_stats current;
    struct Node *root = NULL, *subtree;
    
    //building the tree with the number the user put in
    root = build_root(root);

    //searching how much numebrs in the node and in the left node are the same
    
    subtree = biggest_even_tree(root, current);
    
    //if it didnt foudn a biggest tree it print out NOT FOUND 
    if (!subtree)
    {
        cout << "NOT FOUND" << endl;
    }
    else
    //if it found it print the node 
    {
        cout << subtree->_data  << endl;
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
        root = new(std::nothrow) Node;
        if (root == NULL)
        {
            cerr << "Cannot alocate memory\n";
            exit(EXIT_FAILURE);
        }
        root ->_data = num;
        root->_left = root->_right = NULL;
    }
    //puting a smaller numebr and the same numebr on the left
    else if (num <= root->_data)
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
//the main funtion the checks the biggest node the finds the node
Node *biggest_even_tree(Node *root, Node_stats &curr)
{
    Node_stats left, right;
    Node *bigl, *bigr;

    //if root is null it resart the secondry struct with 0;
    if (root == NULL)
    {
        curr = {0, 0, NULL};
        return root;
    }
    //calling the same function in recurssive to the left and then to the right
    bigl = biggest_even_tree(root->_left, left);
    bigr = biggest_even_tree(root->_right, right);
    
    //adds the numebr of even and odds
    curr._even = left._even + right._even;
    curr._odd = right._odd + left._odd;

    //check the current node if its even
    if (is_even(root))
    {
        curr._even++;
    }
    else
        curr._odd++;
    
    //checks if even is bigger then odd
    if (curr._even > curr._odd)
    {
        return root;
    }
    else if (left._even > left._odd)
    {
        return bigl;
    }
    
    return bigr;
}
//-----------------------------------------------------------------------
//checks if the number is even
bool is_even(Node *root)
{
    return(root->_data % 2 == 0);
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
    delete root;
}