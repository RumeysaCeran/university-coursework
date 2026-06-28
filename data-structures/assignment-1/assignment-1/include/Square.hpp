#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Shape.hpp"

class Square:public Shape{
    
    public:
    int x,y,z;
    int height;
    int type;
    char (*screen)[80];
    Shape *nextShape;

    Square(int type, int x,int y,int z,int height, char (*arr)[80]);

    void write(ostream& shapeFile) override;
    void draw() override;
    void control(string option) override;


};

#endif