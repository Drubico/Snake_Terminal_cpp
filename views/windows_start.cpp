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
#include "../tools/gameStruct.h"


#include "../snake/matriz.cpp"
#include "../snake/keyEvent.h"
#include "./snakeprint.cpp"


//#include <termios.h>
#include <unistd.h>




using namespace std;

int welcomemain(int &P,int&C,string user);

void mensageMarginStart(int opc, myGame<nodeuserinfouser>* game) { 
    CLEAR;
    mensageMargin(w.ws_col);
    mensageSteep(w.ws_col);
    string linea1 =  "WELLCOME " + game->user->info.name + "  TO ...";
    mensageLineMAGENTA(w.ws_col,linea1);
    string linea2[] = {
        "=====   ===    ==   =======   ==  ==   =====",
        "||      ||\\\\   ||   ||   ||   || //    ||   ",
        "====    || \\\\  ||   ||===||   |||      =====",
        "   ||   ||  \\\\ ||   ||   ||   || \\\\    ||   " ,
        "=====   ==   ====   ==   ==   ==  ==   =====" 
    };
    mensageSteep(w.ws_col);
    mensageSnake(w.ws_col,linea2 , 5);
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);
    mensageLineMAGENTA(w.ws_col,string("Tus monedas : "+to_string(game->user->info.coin)));        cout<<RESET;
    mensageLineMAGENTA(w.ws_col,string("Tu Puntaje Maximo: "+to_string(game->user->info.puntaje)));        cout<<RESET;
    mensageLineMAGENTA(w.ws_col,string("Tu Puntaje Actual : "+to_string(game->user->info.puntajeContinuar)));        cout<<RESET;
    mensageLineMAGENTA(w.ws_col,string("Tus vidas : "+to_string(game->user->info.vidas)));        cout<<RESET;
    mensageLineMAGENTA(w.ws_col,string("Tu Nivel : "+to_string(game->user->info.nivel)));        cout<<RESET;
    mensageSteep(w.ws_col);
    mensageSteep(w.ws_col);
    (opc==1)? mensageLine(w.ws_col,"*  START  *"): mensageLine(w.ws_col,"   START   ");
    (opc==2)? mensageLine(w.ws_col,"*  TIENDA * "): mensageLine(w.ws_col,"   TIENDA   ");
    (opc==3)? mensageLine(w.ws_col,"*  TOP  *"): mensageLine(w.ws_col,"   TOP   ");
    (opc==4)? mensageLine(w.ws_col,"*  EXIT * "): mensageLine(w.ws_col,"   EXIT   ");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);

};

auto mensajeStart = [](int opc, myGame<nodeuserinfouser>* game) { 
    mensageMarginStart(opc,game);
};




int startMenuAux(myGame<nodeuserinfouser>* game, auto wellcome,int sizeOption){
    char key; //contenedor de tecla
    int flag = 1;       //opcion actual del menu
    //int sizeOption=3;   //numero total de opciones en el menu
    bool loop = true;   //bandera para el while true

    sleep(0.1);//para corregir fallo de while
    wellcome(flag,game);  //invocacion del menu

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

        wellcome(flag,game);
        sleep(0.01);//para corregir fallo de while
    }
    cin.ignore();

    return 0;
}



int startMenuOpc(myGame<nodeuserinfouser>* game, int flag){
    switch (flag) {
        case 1:
            //cout<<"new game start :v"<<endl;
            //playmatrix(&snake);
            modeMenu(game);
            //playmatrix(&snake);
            // loop=false; //para que termine el juego sin que se regrese al menu :
            break;
        case 2:
            shopMenu(game);
            
            break;
        case 3:
            top_game(game);
            //startMenu(game);
            break;
        case 4:
            cout<<"exit... :'v"<<endl;
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
    }
    startMenu(game);
    return 0;
}

int startMenu(myGame<nodeuserinfouser>* game){
    startMenuOpc(game,startMenuAux(game,mensajeStart,4));
    return 0;
}







