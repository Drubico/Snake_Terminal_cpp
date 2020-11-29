#pragma once
#include <iostream>
#include <string>
#include <iostream>
#include <ostream>
//#include "../user/nodeuser.h"
#include "../tools/gameStruct.h"
#include "../snake/clear.cpp"
#include "../user/readuser.cpp"
#include "./snakeprint.cpp"
using namespace std;
void welcomeuser();
template<class T>
void printUsers(myGame<T>* ,string user);

template <class T>
void usermain(myGame<T>* game) {
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    string user;
    welcomeuser();//mostrando mensaje visual para pedir usuario
    cin>>user;

    printUsers(game,user);//cargando lista de usuarios de fuente externa
    
    if(game->user){//revisando si el usuario ya estaba registrado        
        mensageLine(w.ws_col,string("Bienvenido de nuevo! "+game->user->info.name));
        mensageLine(w.ws_col,string("Tus monedas : "+to_string(game->user->info.coin)));
        mensageLine(w.ws_col,string("Tu Puntaje Maximo: "+to_string(game->user->info.puntaje)));
        mensageLine(w.ws_col,string("Tu Actual : "+to_string(game->user->info.puntajeContinuar)));
        mensageLine(w.ws_col,string("Tus vidas : "+to_string(game->user->info.vidas)));
        mensageLine(w.ws_col,string("Tu Nivel : "+to_string(game->user->info.nivel)));

    } else{
        game->list.pushBack(nodeuserinfouser(0,0,0,0,0,user));//creando nuevo usuario
        game->user = game->list.back;
        mensageLine(w.ws_col,string("Bienvenido!"+game->user->info.name));
        mensageLine(w.ws_col,"Esperamos Te guste!");
        mensageLine(w.ws_col,string("Tus monedas : "+to_string(game->user->info.coin)));
        mensageLine(w.ws_col,string("Tu Puntaje Maximo: "+to_string(game->user->info.puntaje)));
        mensageLine(w.ws_col,string("Tu Actual : "+to_string(game->user->info.puntajeContinuar)));
        mensageLine(w.ws_col,string("Tus vidas : "+to_string(game->user->info.vidas)));
        mensageLine(w.ws_col,string("Tu Nivel : "+to_string(game->user->info.nivel)));
    }
    mensageLine(w.ws_col,"presiona ENTER para continuar");
    mensageSteep(w.ws_col);
    mensageMargin(w.ws_col);
    cin.ignore();
    cin.get();
};

template<class T>
void printUsers(myGame<T>* game,string user){
    ifstream data;
    data.open("./data/user.csv",ios::in);
    for(string line; getline(data,line);){
        stringstream data(line);
        string recibo,name;
        int point,pointContinue,coin,lifes,nivel;
        for (int col = 0;getline(data,recibo,',');col++){
            switch (col)
            {
            case 0:
                name = recibo;
                break;
            case 1:
                point = stoi(recibo);
                break;
            case 2:
                coin = stoi(recibo);
                break;
            case 3:
                lifes = stoi(recibo);
                break;
            case 4:
                nivel = stoi(recibo);
                break;
            case 5:
                pointContinue = stoi(recibo);
                game->list.pushBack(T(point,pointContinue,coin,lifes,nivel,name));
                if(name==user){
                    game->user = game->list.back;
                    //cout<<"encontre: "<<name<<endl;
                }
                break;
            default:
                exit(EXIT_FAILURE);
                break;
            }
            
        }

    }
    data.close();


}

void welcomeuser(void){
    // borra esto porque hay nose que conflicto de pragma once
    CLEAR;
    winsize w = screenSize();//obtenemos las dimensiones de nuestra terminal
    snakeprint();
    mensageLine(w.ws_col,"Digita tu  USUARIO");
    mensageLine(w.ws_col,"(si ya tienes un usuario se recuperara tu progreso) ");

}