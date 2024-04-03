#include "expression_tree.h"

//Constructor
//Construct a tree from a string that represents an expression
ExpressionTree::ExpressionTree(std::string expr)
{
    root_ = 0;
    std::cout << "Converting " << expr << " into ExpressionTree" << std::endl;
    for (char val: expr)
    {
        insert(val);
    }
}

//Destructor
ExpressionTree::~ExpressionTree()
{
    while(root_)
    {
        delete root_; root_ = 0;
    }
}


void ExpressionTree::insert(char data)
{

    Node * cur_node = root_;
    Node * parent_node = 0;
    //Logic to traverse tree
    while(cur_node)
    {
        parent_node = cur_node;
        cur_node = cur_node->left;

    }
    //Case: Root contains a digit and newly added data does too
    if (parent_node && isdigit(data))
    {
        parent_node->set_data(data);
    }
    //Case: Tree contains at least 1 node
    //Append to root node if it contains a number
    //Otherwise create new node containg operation
    return;
}

//Wrapper for inorder traversal
void ExpressionTree::print()
{
    if(!root_)
    {
        std::cout << "Tree is Empty!" << std::endl;
        return;
    }
    inorder(root_);
    std::cout << std::endl;
}

void ExpressionTree::inorder(Node * n)
{
    //reached leaf
    if(!n) return;
    //Move to left child
    inorder(n->left);
    //Print self
    std::cout << n->val;
    //Move to right child
    inorder(n->right);

}
