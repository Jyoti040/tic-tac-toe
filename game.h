#include<iostream>
#include "board.h"
#include "player.h"
#include <limits>

using namespace std;

class game{
    public :
    player players[2];
    board gameBoard;
    int turn;
    int noOfMoves;
    bool gameOver;
    string zero; //have zeroes equal to size of board , size=3 zeroes=000 , 
    string cross;

    public:
    game(player p[2],board b){
        // players=p;
          for (int i = 0; i < 2; i++) {
        players[i] = p[i];
    }
        gameBoard=b;
        turn=0;
        noOfMoves=0;
        gameOver=false;
        zero="";
        cross="";
        for(int i=0;i<gameBoard.size;i++){
            zero=zero+'O';
            cross=cross+'x';
        }
        cout<<endl<<"Rules are : "<<endl<<"1. The game is played on a grid that's "<<gameBoard.size<<" squares by "<<gameBoard.size<<"squares."
        <<endl<<"2. It requires only 2 players ."<<endl<<
"3. The first player to get all of his/her marks in a row (up, down, across, or diagonally or even anti-diagnolly) is the winner." <<endl<<
"When all the  squares are full, the game is over. If no player has all the same marks in a row, the game ends in a tie."<<endl;
     cout<<endl<<"Valid positions are : "<<endl;
     int ct=1;
     for(int i=0;i<gameBoard.size;i++){
        for(int j=0;j<gameBoard.size;j++){
             cout<<ct<<"  ";
             ct=ct+1;
        }
        cout<<endl;
     }
    }


    void printBoardConfig(){
        int sz=gameBoard.size;
        gameBoard.printBoard();
    }

   void play(){
    printBoardConfig();
    int sz=gameBoard.size;
    while(!gameOver){
        noOfMoves++;
        int idx=getIndex();
        int row=idx/sz;
        int col=idx%sz;

        gameBoard.matrix[row][col]=players[turn].getPlayerSymbol() ;
        if(noOfMoves >= sz*sz){
            cout<<endl<<"Game  draw";
            gameOver=true;
            return;
        }
       if(noOfMoves >= 2*sz-1 && checkCombination()){  //min moves until checking ,else not benficial 
          
            printBoardConfig();
            cout<<endl<<"Player is : "<<players[turn].getPlayerName();
              gameOver=true;
              return;}
       turn= (turn +1)%2; //changing turn of player
       printBoardConfig();
    }
   }

   int getIndex(){


    while(true){
        int pos;
       // string name=players[turn].getPlayerName();
        cout<<endl;
        cout<<"Player : "<< players[turn].getPlayerName() <<" give one position : ";
        cin>>pos;
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        pos=pos-1; //making start from 0
        int sz=gameBoard.size;
        int row=pos/sz;
        int col=pos%sz;

        if(row<0 || row>=sz || col<0 || col>=sz){
            cout<<endl<<"Invlaid position !!";
            continue;
        }

        if(gameBoard.matrix[row][col] != gameBoard.symbol){
            cout<<endl<<"Position already occupied !!";
            continue;
        }
        return pos;
    }
   }

   bool checkCombination(){
    int sz=gameBoard.size;

    for(int i=0;i<sz;i++){   //row wise
        string check="";
        for(int j=0;j<sz;j++){
            check=check+(gameBoard.matrix[i][j]);
        }
        if(check==zero || check==cross){
            return true;
        }
    }
      for(int k=0;k<sz;k++){   //column wise
        string check2="";
        for(int l=0;l<sz;l++){
            char ele=gameBoard.matrix[l][k];
            check2=check2+ele;
        }
        if(check2==zero || check2==cross){
            return true;
        }
    }




    int i=0,j=0;
    string check="";
    while(i<sz){  //diagnol
        check=check+(gameBoard.matrix[i][i]);
        i++;
       // j++;
    }
    if(check==zero || check==cross){
            return true;
        }

    i=0,j=sz-1;
    check="";
    while(i<sz){  //anti-diagnol
        check=check+(gameBoard.matrix[i][j]);
        i++;
        j--;
    }
   if(check==zero || check==cross){
            return true;
        }

        return false;
   }
};