#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.hpp"

class Triangle:public Shape{
    public:
    int x,y,z;
    int height;
    int type;
    Shape *nextShape;
    char (*screen)[80];

    Triangle(int type,int x,int y,int z,int height,char (*arr)[80]);
      
    void write(ostream& out ) override;
    void draw() override;
    void control(string option) override;

};

#endif