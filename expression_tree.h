#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <iostream>

class Node{
    friend class ExpressionTree;
public:
    Node(){parent=0; left=0; right=0; val="";}
    void set_data(char data){val+=data;}
private:
    Node * parent;
    Node * left;
    Node * right;
    std::string val;

};

class ExpressionTree
{
public:
    ExpressionTree(std::string);
    ~ExpressionTree();
    void insert(char);
    void print();

private:
    Node * root_;
    void inorder(Node *);
};

#endif // EXPRESSION_TREE_H
