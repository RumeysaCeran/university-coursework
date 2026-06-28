#ifndef STAR_HPP
#define STAR_HPP

#include "Shape.hpp"

class Star:public Shape{
    public:
    int x,y,z;
    int height;
    int type;
    Shape *nextShape;
    char (*screen)[80];


    Star(int type,int x,int y,int z,int height,char (*arr)[80]);
  
    void write(ostream& shapeFile) override;
    void draw() override;
    void control(string option) override;


};

#endif