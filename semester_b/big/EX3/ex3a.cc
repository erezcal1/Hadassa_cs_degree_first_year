/*
written by: Erez Calderon, Id: 318993847, LogIn: erezca

This program builds a sorted binary tree. 
when it finishes to build the program calles a function that goes along the 
tree and finds places where the node and the left node are the same number. 
If they are the same n umebr it adds 1 to the counter and if not it move in 
order at the tree from left to right.

input: numbers to put inside a binary tree

output: how much numbers on a node and on his left node are the same
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

//------------function---------------------------------------------------------
Node *build_root(Node *root);
void insert_in_tree(Node *&root, int num);
void same_dad_son(Node *root, int& same);
void free_tree(Node *root);
Node* find_biggest(Node* root, int lefty, int righty, int max, Node* max_n);

//---------main section--------------------------------------------------------
int main()
{
    struct Node *root = NULL, *biggest = NULL;
    
    //building the tree with the number the user put in
    root = build_root(root);

    //searching how much numebrs in the node and in the left node are the same
    biggest = find_biggest(root, 0, 0, 0, NULL);
    
    

    //freeing the space I used
    free_tree(root);

    return EXIT_SUCCESS;
}
//------------------------build the tree and ask for numbers-------------------
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
//------------------------insert numbers in to the tree------------------------
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
//------------------------same dad and son-------------------------------------
//looking in a reccurssive way to find a place where the dad and the left son 
//are the same
Node* find_biggest(Node* root, int &lefty, int& righty, int max, Node* max_n)
{
	if (!root)
	{
		lefty = righty = max = 0;
		return root;
	}

	Node *subL = find_biggest(root->_left, lefty+1, 0, max, max_n);
	Node *subR = find_biggest(root->_right, 0, righty+1, max, max_n);
	
	if (lefty > max)
	{
		if (lefty == righty)
		{
			max = righty;
			max_n = root;
		}
	}
	return max_n;
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