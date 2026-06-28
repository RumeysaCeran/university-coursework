/**
* main.cpp 
* mainlist oluşturularak ekran dizisine değerler atanmakta ve yazdırılmaktadır.Kullanıcıdan alınan bilgilere * göre ekran dizisinde güncellemeler yapılmakta, en son program kapanmadan önce ise tüm değişiklikler
* "shapes.txt" ye kaydedilmektedir.
* ÖDEV-1
* Rümeysa Ceran
*/


#include "Shape.hpp"
#include <iostream>
#include <fstream>
using namespace std;

Shape::Shape(int type,int x,int y,int z,int height,char arr[25][80]){
   
    this->x = x;
    this->y = y;
    this->height = height;
    this->screen = arr;
    this->nextShape=0;
    this->type=type;
}
Shape::~Shape(){}