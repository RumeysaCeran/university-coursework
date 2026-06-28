/**
* ShapeList.cpp 
* tek yönlü bağlı liste oluşturulmakta ve bu tek önlü bağlı liste ilk şekli tutmak dışında aktif olan şekli * de tutmaktadır.
* ÖDEV-1
* Rümeysa Ceran
*/


#include "ShapeList.hpp"
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

ShapeList::ShapeList(int numOfShape, char (*arr)[80]){
    this->head = 0; 
    this->numOfShape = numOfShape;
    this->screen = arr;
    this->prevList = 0;
    this->nextList = 0;
    this->activeShape = 0;
   
}
ShapeList::~ShapeList(){
    Shape *temp = head;
    while(temp!=0){
        Shape *del = temp;
        temp = temp->nextShape;
        delete del;
    }
}

void ShapeList::removeShape(){
 
    if(activeShape==0)
    {
        return;
    }   
    Shape *delShape = activeShape;
    if(delShape==head){
        head=delShape->nextShape;
        activeShape=head;
    }  
    else{
        Shape *prevOfActiveShape = getPrevOfActiveShape();
        
        if(prevOfActiveShape){
            prevOfActiveShape->nextShape = delShape->nextShape;
        }
        
        if(delShape->nextShape){
            activeShape=delShape->nextShape;
        }
        else{
            delShape=head;
        }
    }
    delete delShape;
    if(numOfShape==0){return;}
    else{numOfShape--;}
   
}


void ShapeList::create(ostream& shapeFile){   
   
   vector<int> unvalidZ;
    for(int k=0; k<numOfShape; k++)
    {    
        Shape *newShape;
        int randomTypeOfShape = rand() % 3;
    //     // 0 -> star
    //     // 1 -> square
    //     // 2 -> triangle

        int randomHeight = (rand() % 10) + 3;
        int randomY = (rand() % (25-randomHeight+1));
        int randomX;
        int randomZ; 
        do {
            randomZ = (rand() % 7) + 2;
        } while (find(unvalidZ.begin(), unvalidZ.end(), randomZ) != unvalidZ.end());

        unvalidZ.push_back(randomZ);

        if(randomTypeOfShape == 0)
        {
            int max_x = 56 - randomHeight;
            randomX = (rand() % max_x) + 12 + randomHeight;
            newShape = new Star(randomTypeOfShape,randomX,randomY,randomZ,randomHeight,screen);   
        }
        else if(randomTypeOfShape == 1)
        {
            int max_x = 68 - (randomHeight);
            randomX = (rand() % max_x) + 13;
           
            newShape= new Square(randomTypeOfShape,randomX,randomY,randomZ,randomHeight,screen);
        }
        else if(randomTypeOfShape == 2){

            int max_x = 56-randomHeight;
            randomX = (rand() % max_x)+12+randomHeight;
            
            newShape = new Triangle(randomTypeOfShape,randomX,randomY,randomZ,randomHeight,screen);
        }
        if(head==0){
                head=newShape;
                activeShape=newShape;
        }
        else{
            Shape *temp = head;
            while(temp->nextShape!=0)
            {
                temp = temp->nextShape;            
            }
            temp->nextShape = newShape;
        }       
    }
    Shape *temp = head;
    while(temp!=0)
    {
        temp->write(shapeFile);
        temp = temp->nextShape;            
    }
   
}

void ShapeList::createByFile(int type,int x,int y,int z,int height)
{
    Shape *newShape;
    if(type==0)
    {
        newShape = new Star(type,x,y,z,height,screen);
       
    }
    else if(type==1)
    {
        newShape = new Square(type,x,y,z,height,screen);
        

    }
    else if(type==2)
    {
        newShape = new Triangle(type,x,y,z,height,screen);
       

    }
    if(head==0){
            head=newShape;
            activeShape=newShape;
    }
    else{
        Shape *temp = head;
        while(temp->nextShape!=0)
        {
            temp = temp->nextShape;            
        }
        temp->nextShape = newShape;
    } 
}

vector<vector<char>> ShapeList::draw(ShapeList *activeList){
   
    vector<vector<char>> listVector(5, vector<char>(13));
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<13; j++)
        {listVector[i][j] = ' ';}
    }
    
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<13; j++)
        {
            if(i==0 || i==4)
            {
                if(j!=10 && j!=11 && j!=12) listVector[i][j] = '*';
            }
            else if(i==2)
            {
                if(j==0 || j==9)
                {
                    listVector[i][j] = '*';
                } 
                else if(j == 5)
                {
                    listVector[i][j] = numOfShape + '0';
                }         
                if(this==activeList)
                {
                    if(j==10)
                    {listVector[i][j]='<';}
                    else if(j==11||j==12)
                    {listVector[i][j]='-';}
                }              
            }
            if(this==activeList){
                if(i==2||i==3||i==1)
                {
                    if(j==10)
                    {listVector[i][j]='<';}
                    else if(j==11||j==12)
                    {listVector[i][j]='-';}
                }              
            }
                
        }
        
    }

    if(this==activeList){
        Shape *tempShape = this->head;
        int zMin;
        vector<Shape*> shapes;
        while(tempShape!=0){
            shapes.push_back(tempShape);
            tempShape=tempShape->nextShape;
        }
        sort(shapes.begin(), shapes.end(),[](Shape *prev, Shape *next){return prev->z < next->z;}) ;
        for(auto x: shapes){
            x->draw();
        }

    }

    return listVector;
}


Shape* ShapeList::getPrevOfActiveShape(){
    Shape *tempShape = head;
    if(tempShape==0)
    {
        return 0;
    }   
    else if(activeShape==head){
        return 0;
    }  
    while(tempShape->nextShape!=activeShape)
    {
        tempShape=tempShape->nextShape;
    }
    return tempShape;
}

void ShapeList::getPrevShape(){
    if(activeShape==head || activeShape==0)
    {
        return;
    }
    else{
        Shape *prevOfActiveShape = getPrevOfActiveShape();
        activeShape=prevOfActiveShape;
    }
}

void ShapeList::getNextShape(){
    if(activeShape==0)return;
    else if(activeShape->nextShape!=0){
        activeShape = activeShape->nextShape;
    }
}