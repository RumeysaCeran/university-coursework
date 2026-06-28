#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>
using namespace std;
#include <fstream>

class Shape{
    public:
    int x,y,z;
    int height;
    int type;
    char (*screen)[80];
    Shape *nextShape;
    virtual ~Shape();
    Shape(int type,int x, int y, int z, int height, char arr[25][80]);
   
    virtual void write(ostream& out) = 0;
    virtual void draw() = 0;
    virtual void control(string option)=0;

};



#endif