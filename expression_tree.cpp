#include "expression_tree.h"
#include <iostream>
void Node::print()
{
    std::cout << "Val: " << val << " Parent: ";
    if(!parent)
    {
        std::cout << "None ";
    }
    else
        std::cout << parent->val;
    std::cout << "L: ";
    if(!left)
    {
        std::cout << "None ";
    }
    else
        std::cout << left->val;
    std::cout << "R: ";
    if(!right)
    {
        std::cout << "None ";
    }
    else
        std::cout << right->val;
    std::cout << std::endl;
}

//Constructor
//Construct a tree from a string that represents an expression
ExpressionTree::ExpressionTree(std::string expr)
{
    root_ = 0;
    expr_ = expr;
    eval_expr_(expr_);
    // std::cout << "Converting " << expr << " into ExpressionTree" << std::endl;
}

//Destructor
ExpressionTree::~ExpressionTree()
{
    std::cout << "Destroying ExpressionTree" << std::endl;
    while(root_)
    {
        delete root_; root_ = 0;
    }
}

void ExpressionTree::eval_expr()
{
    eval_expr_(expr_);
}

Node * ExpressionTree::eval_expr_(std::string expr)
{
    if (expr.empty()) return 0;

    //Try to build a tree
    for (char val: expr)
    {
        insert(val);
    }
    //Calculate the result
    double res = calculate(root_);
    std::cout << "Answer is: " << res << std::endl;
    return 0;
}

bool ExpressionTree::is_ordered_op(std::string op)
{
    return (op == "*" || op == "/");
}

void ExpressionTree::insert(char data)
{
    //Case: Tree is Empty
    if (!root_)
    {
        root_ = new Node();
        root_->set_data(data);
        return;
    }
    Node * cur_node = root_;
    Node * parent_node = 0;
    Node * n = new Node();
    n->set_data(data);
    //Logic to traverse tree
    while(cur_node)
    {
        if(is_ordered_op(cur_node->val) && !isdigit(data))
        {
            double val_a = stod(cur_node->left->val);
            double val_b = stod(cur_node->right->val);
            if (cur_node->val == "*")
            {
                cur_node->val = val_a * val_b;
            }
            else
            {
                cur_node->val = val_a / val_b;
            }
            cur_node->is_number = true;
            Node * to_rmv = cur_node->left;
            delete to_rmv;

            to_rmv = cur_node->right;
            delete to_rmv;
        }

        //Operator
        if (cur_node->is_number && !isdigit(data))
        {
            //make operator(Node n) the parent of current node
            n->parent = parent_node;
            n->left = cur_node;
            //Update root if need to
            if (cur_node == root_)
                root_ = n;
            cur_node->parent = n;
            if (parent_node)
                parent_node->right = n;
            return;

        }
        //Building number
        if (cur_node->is_number && isdigit(data))
        {
            cur_node->set_data(data);
            return;
        }

        //Traverse tree
        parent_node = cur_node;
        //All data goes to the right of an operator
        cur_node = cur_node->right;


    }
    //Set number to right sight of operator
    if (!cur_node && !parent_node->is_number && isdigit(data))
    {
        n->parent = parent_node;
        parent_node->right = n;
    }
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

double ExpressionTree::calculate(Node * n)
{
    if(!n->left && !n->right) return stod(n->val);
    double left_val = calculate(n->left);
    double right_val = calculate(n->right);


    if (n->val == "+")
    {
        return left_val + right_val;
    }
    else if (n->val == "-")
    {
        return left_val - right_val;
    }
    else if (n->val == "/")
    {
        return left_val / right_val;
    }
    else
        return left_val * right_val;

}
