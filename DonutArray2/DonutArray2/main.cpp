//
//  main.cpp
//  DonutArray2
//
//  Created by Jose Annunziato on 7/27/15.
//  Copyright (c) 2015 Jose Annunziato. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct Donut
{
    string name;
};

struct DonutTray
{
    Donut* donuts;
    int size;
    int count;
};

void displayDonut(Donut d)
{
    cout << d.name << endl;
}

void displayDonutTray(DonutTray* tray)
{
    for(int i=0; i<tray->count; i++)
    {
        displayDonut(tray->donuts[i]);
    }
}
// doesnt work because it's pass by value
void incrementInteger(int x)
{
    cout << x << endl;
    x++;
    cout << x << endl;
}

// works pass by reference using pointer
void incInt(int * x)
{
    cout << *x << endl;
    (*x)++;
    cout << *x << endl;
}

// works pass by reference
void incInt2(int &x)
{
    cout << x << endl;
    x++;
    cout << x << endl;
}

Donut createDonut()
{
    string name;
    cout << "New Donut Name:";
    cin >> name;
    Donut newDonut = {name};
    return newDonut;
}

void addDonutToTray(DonutTray* tray, Donut newDonut)
{
    if(tray->count >= tray->size)
    {
        cout << "Sorry, the tray is full" << endl;
    }
    else
    {
        tray->donuts[tray->count] = newDonut;
        (tray->count)++;
    }
}


int main(int argc, const char * argv[])
{
    int x;
    x = 123;

    cout << x << endl;
    incrementInteger(x);
    cout << x << endl;
    
    cout << x << endl;
    incInt(&x);
    cout << x << endl;
    
    cout << x << endl;
    incInt2(x);
    cout << x << endl;
    
    
    
    int* y = new int;
    *y = 234;
    
    y = new int;
    *y = 345;
    
    
    
    
    Donut d, d2;
    d.name = "Donut 1";
    d2.name = "Donut 2";

    cout << d.name << endl;

    Donut * dptr = &d;
    
    (*dptr).name = "Donut 111";
    dptr->name = "Donut 123321";
    
    Donut* d1 = new Donut();
    (*d1).name = "D1";
    d1->name = "D11";
    
    DonutTray* t1 = new DonutTray();
    t1->donuts = new Donut[5];
    t1->size = 5;
    
    cout << t1->donuts << endl;
    
    t1->donuts[0] = d;
    t1->donuts[1] = d2;
    t1->count = 2;
    
    displayDonut(d);
    displayDonutTray(t1);
    
    Donut newDonut = createDonut();
    displayDonut(newDonut);
    
    addDonutToTray(t1, createDonut());
    addDonutToTray(t1, createDonut());
    addDonutToTray(t1, createDonut());
    addDonutToTray(t1, createDonut());
    
    displayDonutTray(t1);
}
