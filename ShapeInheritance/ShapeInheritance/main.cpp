//
//  main.cpp
//  ShapeInheritance
//
//  Created by Jose Annunziato on 6/16/15.
//  Copyright (c) 2015 Jose Annunziato. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Shape
{
protected:
    string name;
    string bgColor;
    string fgColor;
    int widthStroke;
public:
    // setters and getters
    void setName(string name) { this->name = name; }
    string getName() { return name; }
    void setBgColor(string color) { this->bgColor = color; }
    string getBgColor() { return bgColor; }
    void setWidthStroke(int width) { this->widthStroke = width; }
    int getWidthStroke() { return this->widthStroke; }

    // default or no argument constructor
    Shape() : Shape("New Shape", "#FFF", "#000", 1)
    {
        // continue here after calling other constructor
    }
    
    // all argument constructor
    Shape(string name, string bgColor, string fgColor, int stroke)
    {
        this->setName(name);
        this->setBgColor(bgColor);
        this->setWidthStroke(stroke);
    }
    
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "BgColor: " << bgColor << endl;
        cout << "FgColor: " << fgColor << endl;
        cout << "Stroke: " << widthStroke << endl;
    }
};

class Point : public Shape
{
private:
    int x;
    int y;
public:
    // setters and getters
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    int getX() { return x; }
    int getY() { return y; }
    
    // default constructor
    Point() {}
    
    // all argument constructor
    Point(string name, string b, string f, int s, int x, int y)
    : Shape(name, b, f, s) // reuse parent constructor to deal with common properties
    {
        this->setName(name);
        setX(x);
        setY(y);
    }
    
    // override parent's display function
    void display(string date)
    {
        Shape::display(); // reuse parent's display
        
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
    }
};

int main(int argc, const char * argv[]) {
    Shape s1;
//    s1.name = "S1";
    s1.setName("S1");
    s1.display();
    Shape* s2 = new Shape("S2","#FFF", "#000", 5);
    s2->display();
    
    Point* a = new Point("Point A", "#F00", "#0F0", 10, 123, 234);
    a->display("11/22/1233");
}
