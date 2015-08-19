
#include <iostream>
using namespace std;

class Node
{
protected:
    Node* left;
    Node* right;
public:
    Node(){}
    Node(Node* left, Node* right)
    {
        this->left = left;
        this->right = right;
    }
    virtual float eval() = 0;
};

class NumberNode : public Node
{
protected:
    float value = 0;
public:
    NumberNode(){}
    NumberNode(float value)
    {
        this->value = value;
    }
    float eval()
    {
        return value;
    }
};

class PlusNode : public Node
{
public:
    PlusNode(Node* left, Node* right) : Node(left, right)
    {
    }
    PlusNode(){}
    float eval()
    {
        return left->eval() + right->eval();
    }
};

class MinusNode : public Node
{
public:
    MinusNode(Node* left, Node* right) : Node(left, right)
    {
    }
    MinusNode(){}
    float eval()
    {
        return left->eval() - right->eval();
    }
};

class TimesNode : public Node
{
public:
    TimesNode(Node* left, Node* right) : Node(left, right)
    {
    }
    TimesNode(){}

    float eval()
    {
        return left->eval() * right->eval();
    }
};

class DivisionNode : public Node
{
public:
    DivisionNode(Node* left, Node* right) : Node(left, right)
    {
    }
    DivisionNode(){}
    float eval()
    {
        return left->eval() / right->eval();
    }
};

int main(int argc, const char * argv[])
{
    NumberNode* one = new NumberNode(1.0);
    NumberNode* two = new NumberNode(2.0);
    NumberNode* three = new NumberNode(3.0);
    NumberNode* four = new NumberNode(4.0);
    
    TimesNode* times = new TimesNode(one, two);
    MinusNode* minus = new MinusNode(three, four);
    PlusNode* plus = new PlusNode(times, minus);
    
    cout << plus->eval() << endl;
}
