#include "expression_tree.h"
#include <iostream>
#include <unordered_set>
#include <map>
#include <cmath>
//Offers quick lookups https://cplusplus.com/reference/unordered_set/unordered_set/find/
const std::unordered_set<char> ExpressionTree::kValidOperations = {'+', '-', '*', '/'};
const std::unordered_set<char> ExpressionTree::kOrderedOperations = {'*', '/'};
std::map<std::string, char> ExpressionTree::kTrigFunctions = {{"sin", 's'},
                                                                    {"cos", 'c'},
                                                                    {"tan", 't'}};

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

Node * ExpressionTree::eval_expr_(std::string expr)
{
    if (expr.empty()) return 0;
    //Used to build special functions such as trig functions
    std::string special_func = "";
    //Try to build a tree
    for (char val: expr)
    {
        char inserted_val = val;
        if(!isdigit(val) && !is_operation(val) && !is_special_func(special_func))
        {
            special_func += val;
            continue;
        }
        if(is_special_func(special_func))
        {
            inserted_val = kTrigFunctions[special_func];
        }
        if (!insert(inserted_val))
        {
            return NULL;
        }

    }
    //Calculate the result
    double res = calculate(root_);
    std::string res_str = std::to_string(res);

    //Format result
    //Remove trailing zeros
    while(res_str.back() == '0')
    {
        res_str.pop_back();
    }
    if(res_str.back() == '.')
    {
        res_str.pop_back();
    }
    expr_ = res_str;
    return 0;
}

bool ExpressionTree::is_special_func(std::string func)
{
    return kTrigFunctions.find(func) != kTrigFunctions.end();
}

bool ExpressionTree::is_ordered_op(char op)
{
    if (!is_operation(op)) return false;

    std::unordered_set<char>::const_iterator res = kOrderedOperations.find(op);

    return (res != kOrderedOperations.end());
}

bool ExpressionTree::is_operation(char data)
{
    if (isdigit(data)) return false;

    std::unordered_set<char>::const_iterator res = kValidOperations.find(data);

    return (res != kValidOperations.end());

}

bool ExpressionTree::insert(char data)
{
    std::cout << "inserting " << data << std::endl;
    //Case: Tree is Empty
    if (!root_)
    {
        root_ = new Node();
        root_->set_data(data);
        return true;
    }

    Node * n = new Node();
    n->set_data(data);

    //Case: operation, set root_ as left child of operation
    if((!isdigit(data) && !is_ordered_op(data)) || (root_->is_number && is_ordered_op(data)))
    {
        n->left = root_;
        root_->parent = n;
        root_ = n;
        return true;
    }

    Node * cur_node = root_;
    Node * parent_node = 0;

    //Traverse until we reach a leaf
    while(cur_node->right)
    {
        parent_node = cur_node;
        cur_node = cur_node->right;
    }
    //Case: number after number
    if(cur_node->is_number && isdigit(data))
    {
        cur_node->set_data(data);
    }
    //Case: number after operation
    if(!cur_node->is_number && isdigit(data))
    {
        cur_node->right = n;
        n->parent = cur_node;
    }
    //Case: ordered_operation after number
    if(cur_node->is_number && is_ordered_op(data))
    {
        //make cur_node the left child of the ordered operation
        n->left = cur_node;
        cur_node->parent = n;

        //Attach to tree
        n->parent = parent_node;
        parent_node->right = n;
    }

    return true;

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
    if(!n) return 0.0;
    if(!n->left && !n->right) return stod(n->val);
    double left_val = calculate(n->left);
    double right_val = calculate(n->right);

    //Basic operations
    if (n->val == "+")
    {
        return left_val + right_val;
    }
    if (n->val == "-")
    {
        return left_val - right_val;
    }
    if (n->val == "/")
    {
        return left_val / right_val;
    }
    if (n->val == "*")
    {
        return left_val * right_val;
    }
}
