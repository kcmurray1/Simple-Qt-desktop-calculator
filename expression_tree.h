#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <iostream>

class Node{
    friend class ExpressionTree;
public:
    Node(){parent=0; left=0; right=0; val="";}
    void set_data(char data){val+=data; is_number = isdigit(data);}
    void print();
private:
    Node * parent;
    Node * left;
    Node * right;
    std::string val;
    bool is_number;

};

class ExpressionTree
{
public:
    ExpressionTree(std::string);
    ~ExpressionTree();
    void insert(char);
    void print();
    void eval_expr();

private:
    std::string expr_;
    Node * root_;
    void inorder(Node *);
    Node * eval_expr_(std::string);
    double calculate(Node *);
    bool is_ordered_op(std::string);
};

#endif // EXPRESSION_TREE_H
