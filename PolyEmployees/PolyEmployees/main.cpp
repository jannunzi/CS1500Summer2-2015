//
//  main.cpp
//  PolyEmployees
//
//  Created by Jose Annunziato on 6/22/15.
//  Copyright (c) 2015 Jose Annunziato. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

enum EmployeeType {
    HOURLY, FULL
};

class Employee {
public:
    string first;
    EmployeeType type;
    void display(){
        
    }
    virtual float getWeeklyPay() = 0;
//    {
//        return 123;
//    }
};

class FullTimeEmployee : public Employee {
public:
    float yearlySalary;
    float getWeeklyPay()
    {
        return yearlySalary / 52;
    }
};

class HourlyEmployee : public Employee {
public:
    float rate;
    float hours;
    float getWeeklyPay()
    {
        return rate * hours;
    }
};

int main(int argc, const char * argv[]) {
    FullTimeEmployee* f1 = new FullTimeEmployee();
    f1->yearlySalary = 100000;
    f1->type = FULL;
    
    HourlyEmployee* h1 = new HourlyEmployee();
    h1->hours = 40;
    h1->rate = 70;
    h1->type = HOURLY;
    
    cout << f1->getWeeklyPay() << endl;
    cout << h1->getWeeklyPay() << endl;
    
    Employee* employees[] = {f1, h1};
    for(int i=0; i<2; i++)
    {
        Employee* e = employees[i];
        cout << e->getWeeklyPay() << endl;
        HourlyEmployee* h;
        FullTimeEmployee* f;
        switch (e->type) {
            case HOURLY:
                h = (HourlyEmployee*)e;
                cout << h->getWeeklyPay() << endl;
                break;
            case FULL:
                f = (FullTimeEmployee*)e;
                cout << f->getWeeklyPay() << endl;
                break;
        }
    }
    
    
    for(int i=0; i<2; i++)
    {
        Employee* e = employees[i];
        cout << e->getWeeklyPay() << endl;
    }
}
