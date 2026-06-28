/**
* Square.cpp 
* Square sınıfı oluşturularak miras aldığı sınıftan yani "Shape.hpp" fonksiyonlar override edilmektedir.
* draw fonksiyonu ile ekran dizisine değerler atanmakta, write fonksiyonu ile "shapes.txt" kapanmadan önce  * kayıt işlemi yapılmaktadır.
* ÖDEV-1
* Rümeysa Ceran
*/


#include "Square.hpp"
#include <fstream>
#include <iostream>
using namespace std;

Square::Square(int type,int x, int y, int z, int height, char (*arr)[80]):Shape(type, x, y, z, height, arr){
    this->x = x;
    this->y = y;
    this->z = z;
    this->height = height;
    this->nextShape = 0;
    this->screen = arr;
    this->type = 1;
   

}

void Square::write(ostream& shapeFile){
    shapeFile << this->type << " " << this->x << " " << this->y << " " <<this->z << " " << this->height<< endl;
}

void Square::draw(){//aktif linkte çiz
    for (int i=1; i<=height; i++)
    {
        int gecici_y= y+i-1;
        for(int k=1; k<=height; k++)
        {
            int gecici_x = x+k-1;
            screen[gecici_y][gecici_x]='#';
        }
        
    }
}

void Square::control(string option){
    int maxX=80-height;
    int minX=14;
    int maxY=25-height;
    int minY=0;
    if(option=="w"){
        if(y>minY)y--;
        else{return;}
    }
    else if(option=="a"){
         if(x>minX)x--;
        else{return;}
    }
    else if(option=="s"){
         if(y<maxY)y++;
        else{return;}
    }
    else if(option=="d")
    {
        if(x<maxX)x++;
        else{return;}
    }
}