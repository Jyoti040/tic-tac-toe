#include<iostream>
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;
class player{
   public :
     string playerName;
     char playerSymbol;
     long playerPhoneNo;
     string playerEmail;
     int age;

     public:
     
    void setPlayerAllDetails(){  // char s,
   
    string n;
    char s;
    long p;
    string e;
    int a;
    cout<<endl;
    cout << "Enter player name: ";
    cin >> n;
    cout << "Enter player symbol: ";
    cin >> s;
    cout << "Enter player phone number: ";
    cin >> p;
    cout << "Enter player email id: ";
    cin >> e;
    cout << "Enter age: ";
    cin >> a;

    playerName = n;
    playerSymbol = s;
    playerPhoneNo = p;
    playerEmail = e;
    age = a;
}

     void setPlayerBasicDetails(string n,char s,int a){

      playerName=n;
      playerSymbol=s;
       age=a;
     }
     void changeSymbol(char s){
        playerSymbol=s;
     }
     string getPlayerName(){
        //cout<<"Name of the player is : "<<
        return playerName;
     }
     char getPlayerSymbol(){
        // cout<<"Symbol of the player is : "<<playerSymbol;
        return playerSymbol;
     }
     void getPlayerContactDetails(){
      cout<<endl;
        cout<<"Name of the player is : "<<playerName<<endl;
        cout<<"Email id of the player is : "<<playerEmail<<endl;
        cout<<"Phone number of the player is : "<<playerPhoneNo<<endl;
     }
     void getPlayerDetails(){
      cout<<endl;
         cout<<"Name of the player is : "<<playerName<<endl;
        cout<<"Email id of the player is : "<<playerEmail<<endl;
        cout<<"Phone number of the player is : "<<playerPhoneNo<<endl;
          cout<<"Symbol of the player is : "<<playerSymbol<<endl;
            cout<<"Age of the player is : "<<age<<endl;
     }
};
#endif