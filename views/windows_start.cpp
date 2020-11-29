#pragma once
#include <iostream>
//#include <termios.h>
//#include <unistd.h>
// #ifdef _WIN32 /* Deberia estar definido en windows*/
//#include <windows.h>
//#include <winuser.h>
//#include <cstdlib>
//#include <conio.h>

//#include <thread>
#include "../snake/clear.cpp"
#include "./shop.cpp"
#include "./top.cpp"
#include "./game_over.cpp"
#include "./mode.cpp"


#include "../snake/matriz.cpp"
#include "../snake/keyEvent.h"
#include "./snakeprint.cpp"


//#include <termios.h>
#include <unistd.h>




using namespace std;

int welcomemain(int &P,int&C,string user);

void mensageMarginStart(int opc, node<nodeuserinfouser>* userdata) { 
    CLEAR;
    mensageMargin(w.ws_col);
    mensageSteep(w.ws_col);
    string linea1 =  "WELLCOME " + userdata->info.name + "  TO ...";


    mensageLine(w.ws_col,linea1);
    string linea2[] = {
        "=====   ===    ==   =======   ==  ==   =====",
        "||      ||\\\\   ||   ||   ||   || //    ||   ",
        "====    || \\\\  ||   ||===||   |||      =====",
        "   ||   ||  \\\\ ||   ||   ||   || \\\\    ||   " ,
        "=====   ==   ====   ==   ==   ==  ==   =====" 
    };
    mensageSnake(w.ws_col,linea2 , 5);
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);

    (opc==1)? mensageLine(w.ws_col,"*  START *"): mensageLine(w.ws_col,"   START  ");
    mensageSteep(w.ws_col);
    (opc==2)? mensageLine(w.ws_col,"*  TIENDA * "): mensageLine(w.ws_col,"   TIENDA   ");
    mensageSteep(w.ws_col);
    (opc==3)? mensageLine(w.ws_col,"*  TOP *"): mensageLine(w.ws_col,"   TOP  ");
    mensageSteep(w.ws_col);
    (opc==4)? mensageLine(w.ws_col,"*  EXIT * "): mensageLine(w.ws_col,"   EXIT   ");
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);

};

auto mensajeStart = [](int opc, node<nodeuserinfouser>* userdata) { 
    mensageMarginStart(opc,userdata);
};




int startMenuAux(node<nodeuserinfouser>* userdata, auto wellcome,int sizeOption){
    char key; //contenedor de tecla
    int flag = 1;       //opcion actual del menu
    //int sizeOption=3;   //numero total de opciones en el menu
    bool loop = true;   //bandera para el while true

    sleep(0.1);//para corregir fallo de while
    wellcome(flag,userdata);  //invocacion del menu

    cin.ignore();
    sleep(0.1);//para corregir fallo de whiles

    while(loop){

        key=getchar();//up:65 down:66 o B left:68 rigth:67

        if(key==65 ){
            if(flag > 1){
                flag--;
            }
        }
        
        if(  key=='B'){
            if(flag < sizeOption){
                flag++;
            }
        }

        if( key=='\n'){
            return flag;
        }

        wellcome(flag,userdata);
        sleep(0.01);//para corregir fallo de while
    }
    cin.ignore();

    return 0;
}



int startMenuOpc(node<nodeuserinfouser>* userdata, int flag,doubleLinked<nodeuserinfouser>* userlist){
    switch (flag) {
        case 1:
            //cout<<"new game start :v"<<endl;
            //playmatrix(&snake);
            modeMenu(userdata,userlist);
            //playmatrix(&snake);
            gameOverMenu(userdata,userlist);
            // loop=false; //para que termine el juego sin que se regrese al menu :
            break;
        case 2:
            shopMenu(userdata,userlist);
            startMenu(userdata,userlist);
            break;
        case 3:
            top_game(userdata,userlist);
            startMenu(userdata,userlist);
            break;
        case 4:
            cout<<"exit... :'v"<<endl;
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
    }
    return 0;
}

int startMenu(node<nodeuserinfouser>* userdata,doubleLinked<nodeuserinfouser>* userlist){
    startMenuOpc(userdata,startMenuAux(userdata,mensajeStart,4),userlist);
    return 0;
}







