#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <iostream>
#include <unordered_set>
#include <cmath>
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
    bool insert(char);
    std::string get_expr(){return expr_;}
    void print();
    static const std::unordered_set<char> kValidOperations;
    static const std::unordered_set<char> kOrderedOperations;
private:
    std::string expr_;
    Node * root_;
    void inorder(Node *);
    Node * eval_expr_(std::string);
    double calculate(Node *);
    bool is_ordered_op(char);
    bool is_operation(char);

};

#endif // EXPRESSION_TREE_H
