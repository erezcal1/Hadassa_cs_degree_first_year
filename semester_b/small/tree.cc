#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

struct Node 
{
    int _data;
    struct Node *_left,
                *_right;
};

Node *build_root(Node *root);
void insert_in_tree(Node *&root, int num);
void print_tree(Node *root);
int small(Node *root);
void free_tree(Node *root);

int main()
{
    struct Node *root = NULL;
    

    root = build_root(root);

    int smallest_num = small(root);
    cout << smallest_num << endl;

    print_tree(root);
    free_tree(root);

    return EXIT_SUCCESS;
}
Node *build_root(Node *root)
{
    int num;
    cin >> num;
    while (!cin.eof())
    {
        insert_in_tree(root, num);
        cin >> num;
    }
    return root;
}

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
    else if (num <= root->_data)
    {
        insert_in_tree(root->_left, num);
    }
    else
    {
        insert_in_tree(root->_right, num);
    }
}

int small(Node *root)
{
    if (root->_left == NULL)
    {
        return root->_data;
    }
    return small(root->_left);
}



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
