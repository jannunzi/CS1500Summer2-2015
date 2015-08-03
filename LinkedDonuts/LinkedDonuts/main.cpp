//
//  main.cpp
//  LinkedDonuts
//
//  Created by Jose Annunziato on 6/2/15.
//  Copyright (c) 2015 Jose Annunziato. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

struct Donut
{
    string name;
    float price;
    // overriding default constructor
    Donut() // default constructor, aka the no argument constructor
    {
        cout << "Hello from Donut" << endl;
    }
    // overloading contructors
    Donut(string name, float price)
    {
        cout << "Constructor for " << name << endl;
        setName(name);
        setPrice(price);
    }
    ~Donut()
    {
        cout << "Good Bye from: " << name << endl;
    }
    void display()
    {
        cout << name << "\t$" << price << endl;
    }
    // API - Application Programming Interface
    // setters and getters
    // mutators
    void setName(string name)
    {
        this->name = name;
    }
    // accessors
    string getName()
    {
        return name;
    }
    void setPrice(float price)
    {
        if(price > 0)
        {
            this->price = price;
        }
    }
    // accessors
    float getPrice()
    {
        return price;
    }
};

Donut * createDonut()
{
    Donut* d = new Donut("d4", 21.32);
    return d;
}

// dont do this
Donut * createLocalDonut()
{
    Donut d("d6", 0.65);
    return &d;
}

const int SIZE = 10;

struct DonutTray
{
    Donut* donuts;
    string name;
    int capacity = SIZE;
    int count = 0;
    DonutTray(){}
    DonutTray(string name, int capacity, int count, Donut* donuts)
    {
        this->name = name;
        this->capacity = capacity;
        this->count = count;
        this->donuts = donuts;
    }
    DonutTray(const DonutTray &other)
    {
        cout << "Copying from " << other.name << endl;
        this->name = other.name;
        this->count = other.count;
        this->capacity = other.capacity;
//      this->donuts = other.donuts;
        this->donuts = new Donut[this->capacity];
        for(int i=0; i<count; i++)
        {
            Donut * d = new Donut(other.donuts[i].name, other.donuts[i].price);
            donuts[i] = *d;
        }
    }
    void display()
    {
        cout << name << "\t\t" << count << endl;
        for(int i=0; i<count; i++)
        {
            donuts[i].display();
        }
    }
};

int main(int argc, const char * argv[])
{
//    Donut d1 = {"d1", -0.54};
//    d1.display();
    Donut d1;
    d1.name = "d1";
    d1.price = 1.23;
    
    Donut d2("d2", 12.23);
    
    d1.display();
    d2.display();
    d2 = d1;
    d2.display();
    d2.setName("d2");
    d2.display();
    d1.display();
    
    Donut * donut;
    Donut * donut2;
    
    donut = new Donut(); // dynamic memory allocation
    donut->setName("d2");
    donut->setPrice(0.65);
    donut->display();
    
    donut->setPrice(-0.76);
    donut->display();
    delete donut; // delete d2
    
    donut = new Donut("d3", -0.87);
    donut->display();
    delete donut; // delete d3
    
    donut = createDonut();
    donut->display();
    donut2 = donut;
    donut2->display();
    donut2->setName("d5");
    donut2->display();
    donut->display();
    
    donut = createLocalDonut();
    donut->display();
    
    Donut* donuts = new Donut[SIZE];
    donuts[0] = d1;
    donuts[1] = d2;
    
    DonutTray donutTray1("tray 1", SIZE, 2, donuts);
    donutTray1.display();
    
    DonutTray donutTray2 = donutTray1;
    donutTray2.name = "tray 2";
    donutTray2.donuts[1].name = "d222";
    donutTray2.display();
    donutTray1.display();
}
