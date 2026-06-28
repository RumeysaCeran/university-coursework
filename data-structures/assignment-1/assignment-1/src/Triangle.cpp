/**
* Triangle.cpp 
* Triangle sınıfı oluşturularak miras aldığı sınıftan yani "Shape.hpp" fonksiyonlar override edilmektedir.*draw fonksiyonu ile ekran dizisine değerler atanmakta, write fonksiyonu ile "shapes.txt" kapanmadan önce *kayıt işlemi yapılmaktadır.
* ÖDEV-1
* Rümeysa Ceran
*/

#include <string>
#include "Triangle.hpp"
#include <fstream>
#include <iostream>
using namespace std;

Triangle::Triangle(int type,int x,int y, int z, int height, char (*arr)[80]):Shape(type,x,y,z,height,arr){
    this->x=x;
    this->y=y;
    this->z=z;
    this->height=height;
    this->nextShape = 0;
    this->screen = arr;
    this->type = 2;
    
}

void Triangle::write(ostream& shapeFile){
   shapeFile << to_string(this->type) << " " << to_string(this->x) << " " << to_string(this->y) << " " <<to_string(this->z) << " " << to_string(this->height) << endl;
}

void Triangle::draw(){
    int current_x = x;
    for (int i=1; i<=height; i++)
    {
        int temp_y= y+i-1;
        for(int k=1; k<=i*2-1; k++)
        {
            int temp_x = current_x+k-1;
            screen[temp_y][temp_x]='o';
        }
        current_x--;
    }
}

void Triangle::control(string option){
    int maxX=80-height;
    int minX=12+height;
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