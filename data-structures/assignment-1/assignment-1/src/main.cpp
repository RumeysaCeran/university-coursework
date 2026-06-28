/**
* main.cpp 
* mainlist oluşturularak ekran dizisine değerler atanmakta ve yazdırılmaktadır.Kullanıcıdan alınan bilgilere *göre ekran dizisinde güncellemeler yapılmakta, en son program kapanmadan önce ise tüm değişiklikler "shapes.*txt" ye kaydedilmektedir.
* ÖDEV-1
* Rümeysa Ceran
*/

#include<iostream>
using namespace std;
#include <iomanip>
#include "MainList.hpp"
#include <cmath>
#include "ShapeList.hpp"
#include "Shape.hpp"
#include <conio.h> 


char ekran[25][80];


void printScreen(){
     for(int i=0; i<25; i++)
     {
          for(int j=0; j<80; j++)
          {
               cout<<ekran[i][j];
          }
          cout<<endl;
     }
};

int main(){
   
     for(int i=0; i<25; i++)
     {
          for(int j=0; j<80; j++)
          {
               ekran[i][j]= ' ';
          }
     };

     MainList* mainList;
     int index=0;
     string answer;
     string answer1;
     string answer2;

     do{
          cout<<"yeni liste mi oluşturmak isterseniz yoksa dosyadan mi okunmasini istersiniz?(y -> yeni liste / d -> dosyadan): ";
          cin>>answer;
          if(answer == "y")
          {
               mainList = new MainList(ekran);
               mainList->create();
               
          }
          else if(answer == "d")
          {
               mainList = new MainList(ekran);
               mainList->createByFile();
          }
          
     }
     while(answer!="y" && answer != "d"); 
     system("cls");
      
     do{
          system("cls");
          mainList->draw(index);
          printScreen();
          
          cout<<"(ws) hareket (f) listeyi sec (c)sil (g) cikis: ";
          answer1=_getch();       
          if(answer1 == "w")
          {
               mainList->getPrevList(index);      
          }
          else if(answer1 == "s")
          {
               mainList->getNextList(index);                              
          }    
          else if(answer1 == "c")
          {
               mainList->removeList(index);             
          } 
          else if(answer1 == "g"){
               break;
          }
          else if(answer1 == "f")
          {
             do{
               system("cls");
               mainList->draw(index);
               printScreen();
               ShapeList *activeList = mainList->activeList;
               Shape *activeShape = activeList->activeShape;
               cout<<"(wasd) hareket (e)sonraki (q)onceki (c)sil (g)cikis: ";
               answer2=_getch();
               if(answer2=="a")
               {              
                    activeShape->control("a");
               }
               else if(answer2=="w"){
                    activeShape->control("w");        
               }
               else if(answer2=="s"){
                    activeShape->control("s");             
               }
               else if(answer2=="d"){
                    activeShape->control("d");                   
               }
               else if(answer2=="c"){
                    activeList->removeShape();
                    if(activeList->numOfShape == 0){
                         mainList->removeList(index);
                    }
               }
               else if(answer2=="g"){
                    break;
               }
               else if(answer2=="q")
               {
                    activeList->getPrevShape();              
               }
               else if(answer2=="e"){
                    activeList->getNextShape();              
               }
               else{
                    cout<<"gecersiz secim yaptınız!"<<endl;
               }              
               }while(true);         
          } 
          else{
               cout<<"gecersiz secim yaptınız!"<<endl;
          }   
         

     }while(true);
     
     mainList->updateFile();
     delete mainList;    
     system("cls");
}