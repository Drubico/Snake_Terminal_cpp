#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <ostream>
//#include "../user/nodeuser.h"
#include "../tools/list.h"
#include "../snake/clear.cpp"
#include "../user/readuser.cpp"
#include "./snakeprint.cpp"
#include <iomanip>

using namespace std;
void top_game(myGame<nodeuserinfouser>* game);
void welcometop();

template<class T>
void printtop(node<T>* front);
void printtopaux(doubleLinked<nodeuserinfouser>* userlist);

void top_game(myGame<nodeuserinfouser>* game){
    welcometop();
    //traverseBegin(userlist->front);
    printtopaux(&game->list);
    mensageLine(w.ws_col,"presiona ENTER para continuar");
    cin.ignore();
    cin.get();
    //startMenuOpc(userdata,startMenu(userdata,userlist),userlist);
    return;
};
void welcometop(){
    // borra esto porque hay nose que conflicto de pragma once
    CLEAR;
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    snakeprint();

}
template<class T>
void printtop(node<T>* front){
  
    //cout<<fwall;
    if(front) {
        string top[]={
        front->info.name,to_string(front->info.coin),to_string(front->info.puntaje)
         };  
        mensageLineSeccion(w.ws_col,top,3);
        mensageMargin(w.ws_col);
        printtop(front->next);
    }
    else    
        cout<<endl;
}

void printtopaux(doubleLinked<nodeuserinfouser>* userlist){

    mensageMargin(w.ws_col);
    string top[]={
        "NOMBRE","MONEDAS","PUNTAJE"
    };
    mensageLineSeccion(w.ws_col,top,3);
    mensageMargin(w.ws_col);


    printtop(userlist->front);
}