#ifndef MAINLIST_HPP
#define MAINLIST_HPP
#include <iostream>
#include "ShapeList.hpp"

class MainList{
    public:
        char (*screen)[80];
        MainList(char arr[25][80]);
        ~MainList();
        void removeList(int &index);
        void create();
        void createByFile();
        void draw(int &index);
        void getPrevList(int &index);
        void getNextList(int &index);
        void updateFile();
        ShapeList *activeList;

        int getSizeOfList();
        ShapeList* head;
};


#endif
