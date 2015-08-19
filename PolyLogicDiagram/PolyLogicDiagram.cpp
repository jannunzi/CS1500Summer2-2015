
#include <iostream>
using namespace std;

class GateNode
{
protected:
    GateNode * input1 = NULL;
    GateNode * input2 = NULL;
public:
    GateNode(){}
    GateNode(GateNode * input)
    {
        input1 = input;
    }
    GateNode(GateNode * input1, GateNode * input2)
    {
        this->input1 = input1;
        this->input2 = input2;
    }
    virtual bool eval() = 0; // pure virtual
//    bool eval()
//    {
//        return false;
//    }
};

class AndGate : public GateNode
{
public:
    AndGate(){}
    AndGate(GateNode * i1, GateNode * i2) : GateNode(i1, i2)
    {}
    bool eval()
    {
        return input1->eval() && input2->eval();
    }
};

class OrGate : public GateNode
{
public:
    OrGate(){}
    OrGate(GateNode * i1, GateNode * i2) : GateNode(i1, i2)
    {}
    bool eval()
    {
        return input1->eval() || input2->eval();
    }
};

class Input : public GateNode
{
protected:
    bool value = false;
    string label = "";
public:
    Input(){}
    Input(bool value)
    {
        this->value = value;
    }
    Input(bool value, string label)
    {
        this->value = value;
        this->label = label;
    }
    bool eval()
    {
        return value;
    }
};

class NotGate : public GateNode
{
public:
    NotGate(GateNode * i1) : GateNode(i1)
    {}
    bool eval()
    {
        return !input1->eval();
    }
};

class XOrGate : public GateNode
{
public:
    XOrGate(GateNode * i1, GateNode * i2) : GateNode(i1, i2)
    {}
    bool eval()
    {
        bool x = input1->eval();
        bool y = input2->eval();
        if(x == y) return false;
        return true;
    }
};

int main(int argc, const char * argv[])
{
    Input * A = new Input(true, "A");
    Input * B = new Input(false, "B");
    Input * C = new Input(false, "C");
    Input * D = new Input(true, "D");
    
    OrGate  * AorB = new OrGate(A, B);
    XOrGate * CxorD = new XOrGate(C, D);
    NotGate * NotCxorD = new NotGate(CxorD);
    AndGate * result = new AndGate(AorB, NotCxorD);
    
    cout << result->eval() << endl;
    
//    AndGate * AandB = new AndGate(A, B);
//    cout << AandB->eval() << endl;
//    AndGate * AorBandC = new AndGate(AorB, C);
//    NotGate * NotAorBandC = new NotGate(AorBandC);
//    cout << NotAorBandC->eval() << endl;
}
