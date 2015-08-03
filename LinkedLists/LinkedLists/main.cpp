//
//  main.cpp
//  LinkedLists
//
//  Created by Jose Annunziato on 7/30/15.
//  Copyright (c) 2015 Jose Annunziato. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct Donut
{
    string flavor;
    Donut* next;
    
    Donut(string flavor)
    {
        this->flavor = flavor;
    }
};

// h --> [d0] --> [d1] --> [d2] --/

void displayDonutList(Donut* head)
{
    Donut* c = head;
    while(c != NULL)
    {
        cout << c->flavor << endl;
        c = c->next;
    }
}

void prepend(Donut* *head, Donut* newDonut)
{
    newDonut->next = *head;
    *head = newDonut;
}

void append(Donut* *tail, Donut* newDonut)
{
    newDonut->next = NULL;
    (*tail)->next = newDonut;
//    (*(*tail)).next = newDonut;
    *tail = newDonut;
}

void appendHard(Donut* head, Donut* newDonut)
{
    Donut* c = head;
    while(c->next != NULL)
    {
        c = c->next;
    }
    newDonut->next = NULL;
    c->next = newDonut;
}

int main(int argc, const char * argv[])
{
    Donut* d0 = new Donut("d0");
    Donut* d1 = new Donut("d1");
    Donut* d2 = new Donut("d2");
    Donut* d3 = new Donut("d3");
    Donut* d4 = new Donut("d4");
    Donut* t = d4;
    
    Donut* h = d0;
    d0->next = d1;
    d1->next = d2;
    d2->next = d3;
    d3->next = d4;
    d4->next = NULL;

    // prepending manually
    Donut* d = new Donut("d5");
    d->next = h;
    h = d;
    
    d = new Donut("d6");
    d->next = h;
    h = d;
    
    d = new Donut("d7");
    d->next = h;
    h = d;
    
    d = new Donut("d8");
    d->next = h;
    h = d;
    
    d = new Donut("d9");
    
    // prepending with a function
    prepend(&h, d);
    
    // appending manually
    d = new Donut("d10");
    d->next = NULL;
    t->next = d;
    t = d;

    d = new Donut("d11");
    d->next = NULL;
    t->next = d;
    t = d;
    
    d = new Donut("d12");
    d->next = NULL;
    t->next = d;
    t = d;
    
    d = new Donut("d13");
    append(&t, d);
    
    d = new Donut("d14");
    append(&t, d);
    
    d = new Donut("d15");
    append(&t, d);
    
    d = new Donut("d16");
    append(&t, d);
    
    d = new Donut("d17");
    appendHard(h, d);
    
    d = new Donut("d18");
    appendHard(h, d);
    
    d = new Donut("d19");
    appendHard(h, d);
    
    d = new Donut("d20");
    appendHard(h, d);
    
//    Donut* c = h;
//    cout << (*c).flavor << endl;
//    c = c->next;
//    cout << (*c).flavor << endl;
//    c = c->next;
//    cout << (*c).flavor << endl;
//    c = c->next;
//    cout << (*c).flavor << endl;
//    c = c->next;
//    cout << (*c).flavor << endl;
    
//    c = h;
//    while(c != NULL)
//    {
//        cout << c->flavor << endl;
//        c = c->next;
//    }
    displayDonutList(h);
}
