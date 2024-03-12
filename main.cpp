
#include<iostream>
#include "board.h"
#include "player.h"
#include "game.h"

using namespace std;

int main(){
       int boardSize;
         char boardSymbol;
    cout<<endl<<"Enter board size : ";
    cin>>boardSize;
    cout<<endl<<"Enter default symbol : ";
    cin>>boardSymbol;
     board b(boardSize,boardSymbol);
    // b.printBoard();
    player p1;
    player p2;
    
    p1.setPlayerAllDetails(); 
    p1.getPlayerDetails();
    cout<<endl;
    p2.setPlayerAllDetails(); 
    p2.getPlayerDetails();
    player p[2];
    p[0]=p1;
    p[1]=p2;
   
    game g(p,b);
    g.play();
    
    return 0;
}
