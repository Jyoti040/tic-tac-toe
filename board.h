#include<iostream>
#ifndef BOARD_H
#define BOARD_H

using namespace std;
class board{
   public :
    char **matrix; //2d matrix pointer 

  int size;
  char symbol;
  board(){

  }

    board(int sz,char sym){
      
      size=sz;
      symbol=sym;
      matrix=new char*[size]; //array of pointers
      for(int i=0;i<size;i++){
        matrix[i]=new char[size];  //individual array
      }
      for(int i=0;i<size;i++){
            for(int j=0; j<size; j++){
                matrix[i][j]=sym;
            }}
    }

    void printBoard(){
        cout<<endl<<"Board : "<<endl<<endl;
        for(int i=0;i<size;i++){
            for(int j=0; j<size; j++){
                cout<<matrix[i][j]<<"   ";
            }
            cout<<endl;
        }
    }
};
#endif