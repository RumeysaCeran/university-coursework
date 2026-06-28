/**
* MainList.cpp 
* Mainlist iki yölü bağlı listedir ve içinde veri olurak tek yönlü bağlı listeler tutmaktadır.MainList ilk 
* şekil listesini tutmak dışında aktif olan şekil listesini de tutmaktadır
* ÖDEV-1
* Rümeysa Ceran
*/



#include "MainList.hpp"
#include <iostream>
using namespace std;
#include <ctime>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>

MainList::MainList(char arr[25][80]){
    this->head = 0;
    this->screen = arr;
    this->activeList = 0;
}

MainList::~MainList(){
    ShapeList *tempList = head;
    while(tempList!=0)
    {
        ShapeList *del = tempList;
        tempList= tempList->nextList;
        delete del;
    }
}

void MainList::removeList(int &index){
    
    ShapeList *delList = activeList;
    if(activeList==0)
    {
        return;
    }
    else{
        ShapeList* prevOfActiveList = activeList->prevList;
        ShapeList* nextOfActiveList= activeList->nextList;
        
        if(prevOfActiveList)
        {
            prevOfActiveList->nextList=nextOfActiveList;         
        }
        else{
            head=nextOfActiveList;          
        }
        if(nextOfActiveList)
        {
            nextOfActiveList->prevList = prevOfActiveList;
           
        }  
        if(nextOfActiveList)
        {
            activeList = activeList->nextList;
        } 
        else{
            activeList=head;
            index=0;
        }
        delete delList;
    }

    this->draw(index);

}

int MainList::getSizeOfList(){
    int counter=0;
    ShapeList* temp = head;
    while(temp!=0){
        temp = temp->nextList;
        counter++;
    }
    return counter;
}

void MainList::create(){
    ofstream clearFile("shapes.txt", ios::trunc);
    
    ofstream shapeFile("shapes.txt", ios::app);
    if(!shapeFile.is_open()){
         cout<<"dosya acilamadi";
         return;
    }
    srand(static_cast<unsigned int>(time(0)));
    for(int i=0; i<20; i++)
    {    
        int randomNumOfShape = (rand() % 6 ) +2 ; // 2-7 arası sayı   
        ShapeList* newList = new ShapeList(randomNumOfShape, screen);
        shapeFile << randomNumOfShape << endl;
        newList->create(shapeFile);
        if(head==0)
        {
            head=newList;
            activeList=newList;
        } 
        else{
            ShapeList* temp=head;
            while(temp->nextList!=0)
            {
                 temp = temp->nextList;
            }
            newList->prevList=temp;
            temp->nextList=newList;
        }
    }
    shapeFile.close();
    
}

void MainList::draw(int &index){
    int counter=0;
    int i=0;
    for(int k=0; k<25; k++)
    {
        for(int c=0; c<80; c++)
        {
            screen[k][c]= ' ';
        }
    };
    ShapeList* tempList = head;
    if(index<5)
    {
        while(counter<5 && tempList!=0){
            vector<vector<char>> tempVector = tempList->draw(activeList);
            for(int m=0; m<5; m++)
            {
                for(int n=0; n<13; n++)
                {
                    screen[i][n] = tempVector[m][n];
                }
                i++;              
            }          
            tempList = tempList->nextList;
            counter++;
        }
       i=0;
    }
    else if(index>=5 && index<10)
    {
        while(counter<5 && tempList!=0){
            tempList = tempList->nextList;
            counter++;
        }
        while(counter<10 && tempList!=0){
            vector<vector<char>> tempVector = tempList->draw(activeList);
            for(int m=0; m<5; m++)
            {
                for(int n=0; n<13; n++)
                {
                    screen[i][n] = tempVector[m][n];
                }
                i++;             
            }        
            tempList = tempList->nextList;
            counter++;
        }
        i=0;
    }
    else if(index>=10 && index<15)
    {
        while(counter<10 && tempList!=0){
            tempList = tempList->nextList;
            counter++;
        }
        while(counter<15 && tempList!=0){
            vector<vector<char>> tempVector = tempList->draw(activeList);
            for(int m=0; m<5; m++)
            {
                for(int n=0; n<13; n++)
                {
                    screen[i][n] = tempVector[m][n];
                }
                i++;          
            }
            tempList = tempList->nextList;
            counter++;
        }
        i=0;
    }
    else if(index>=15 && index<20)
    {
       while(counter<15 && tempList!=0){
            tempList = tempList->nextList;
            counter++;
        }
        while(counter<20 && tempList!=0){
            vector<vector<char>> tempVector = tempList->draw(activeList);
            for(int m=0; m<5; m++)
            {
                for(int n=0; n<13; n++)
                {
                    screen[i][n] = tempVector[m][n];
                }
                i++;
            } 
           
            tempList = tempList->nextList;
            counter++;
        }
        i=0;
    }
    
}

void MainList::createByFile(){
    ifstream file("shapes.txt"); 
    string line; 
    if(!file.is_open()){
        cout<<"Dosya acilamadi!"<<endl;
        return;
    }
    while(getline(file, line)){
        
        int numOfShape = stoi(line);
        ShapeList* newList = new ShapeList(numOfShape, screen);//içine değer atılmalı
        if(head==0)
        {
            head=newList;
            activeList = newList;
        } 
        else{
            ShapeList* temp=head;
            while(temp->nextList!=0)
            {
                 temp = temp->nextList;
            }
            newList->prevList=temp;
            temp->nextList=newList;
        }
        for(int i=0; i<numOfShape; i++){
            getline(file,line);
            stringstream ss(line);
            vector<int> nums;
            int num;         
            while(ss>>num){nums.push_back(num);}
            int type=nums[0];
            int x=nums[1]; 
            int y=nums[2];
            int z=nums[3];
            int height=nums[4];
            newList->createByFile(type,x,y,z,height);
        }
    }   
    file.close();
    
}

void MainList::getPrevList(int &index){
    if(index>0)
    {
        if(activeList->prevList != 0)
        {
            activeList = activeList->prevList;
            index--;
            this->draw(index);
        }
        
    }
}

void MainList::getNextList(int &index){
    if(index<(this->getSizeOfList())-1)
    {
        if(activeList->nextList != 0)
        {
            activeList = activeList->nextList;
            index++;
            this->draw(index);
            
        }
       
    }  
}

void MainList::updateFile(){

    ofstream shapeFile("shapes.txt", ios::trunc);
    if(!shapeFile.is_open()){
        cout<<"dosya acilamadi" <<endl;
    }
    ShapeList* tempList=head;
    while(tempList!=0)
    {
        shapeFile << tempList->numOfShape <<endl;
        Shape *tempShape = tempList->head;
        while(tempShape!=0)
        {
            tempShape->write(shapeFile);
            tempShape = tempShape->nextShape;            
        }  
        tempList = tempList->nextList;     
    }     
    shapeFile.close();
}