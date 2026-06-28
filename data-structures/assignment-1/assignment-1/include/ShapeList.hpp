#ifndef SHAPELIST_HPP
#define SHAPELIST_HPP

#include "Triangle.hpp"
#include "Star.hpp"
#include "Square.hpp"
#include "Shape.hpp"
#include <vector>

class ShapeList{
   
    public:
        int numOfShape;
        char (*screen)[80];
        ShapeList *nextList;
        ShapeList *prevList;
        Shape *head;
        Shape *activeShape;
        Shape* getPrevOfActiveShape();
        ShapeList(int numOfShape, char (*arr)[80]);

        ~ShapeList();

        void getPrevShape();
        void getNextShape();
        void removeShape();
        void create(ostream& shapeFile); 
        void createByFile(int type,int x,int y,int z,int height);   
        vector<vector<char>> draw(ShapeList *activeList);
       

};

#endif