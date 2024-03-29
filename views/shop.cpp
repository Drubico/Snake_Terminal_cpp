#pragma once

#include <iostream>
#include <unistd.h>
#include <termios.h>

#include "./snakeprint.cpp"
#include "../snake/my_snake.h"
#include "../tools/gameStruct.h"

using namespace std;

/**
 * Function that shows the Shop of the game
 */
auto mensajeShop = [](int opc,myGame<nodeuserinfouser>* game, int size) { 
    CLEAR;
    snakeprint();
    messageLine(w.ws_col,"Coins: "+to_string(game->user->info.coin));
    if(game->snake.x2Boosted || game->snake.x3Boosted){
        messageLine(w.ws_col,"Potenciador Activo: x" + to_string((game->snake.x3Boosted)? 3:2) );
    }
    messageSteep(w.ws_col);
    messageSteep(w.ws_col);
    (opc==1)? messageLineREDEmoji(w.ws_col,"*  Vida Extra (っ◔◡◔)っ ❤ (200 monedas)  *", 10):              
        messageLine(w.ws_col,"   Vida Extra (200 monedas)   ");
    (opc==2)? messageLineREDEmoji(w.ws_col,"*  Potenciar Points x2 ☜(ˆ▿ˆc) (500 monedas) * ", 8):   
        messageLine(w.ws_col,"   Potenciar Points x2 (500 monedas)   ");
    (opc==3)? messageLineREDEmoji(w.ws_col,"*  Potenciar Points x3 (͠≖ ͜ʖ͠≖)👌 (1000 monedas) *  ", 12):    
        messageLine(w.ws_col,"   Potenciar Points x3 (1000 monedas)  ");
    (opc==4)? messageLineREDEmoji(w.ws_col,"   *  Velocidad x2 Masoquista (͠◉_◉᷅ )(͠◉_◉᷅ ) (100 monedas) *    ", 16):    
        messageLine(w.ws_col,"   Velocidad x2 Masoquista (100 monedas)  ");
    (opc==5)? messageLineREDEmoji(w.ws_col,"*  Velocidad x3 Demente (ㆆ_ㆆ) (100 monedas) *", 2):    
        messageLine(w.ws_col,"   Velocidad x3 Demente (100 monedas)  ");
    (opc==6)? messageLineREDEmoji(w.ws_col,"*  Velocidad x0.5 Cauteloso (✿◠‿◠) (100 monedas) *", 8)://14    
        messageLine(w.ws_col,"   Velocidad x0.5 Cauteloso (100 monedas)  ");
    (opc==7)? messageLineRED(w.ws_col,"*  REGRESAR *"):    
        messageLine(w.ws_col,"   REGRESAR  ");
    // string cadena = "(͠◉_◉᷅ )";
    // cout<<cadena.size();
    // cin.get();
    messageSteep(w.ws_col);
    messageMargin(w.ws_col);
}; 

int optionSelectionKey(myGame<nodeuserinfouser>* , auto ,int );
int startMenu(myGame<nodeuserinfouser>* game);
int shopMenu(myGame<nodeuserinfouser>* game);

/**
 * Function that implements functionality to buy the x2 points booster
 */
void boostPointsx2(myGame<nodeuserinfouser>* game){
    //Checks if a booster hasn't been buyed before or if has the enough money to buy
	if(!game->snake.x2Boosted && !game->snake.x3Boosted && game->user->info.coin >= 500){
		game->snake.x2Boosted = true;
        game->user->info.coin -= 500;
		messageLine(w.ws_col,"Points potenciado x2");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
	}
    //If a booster has already been selected
    else if(game->snake.x2Boosted || game->snake.x3Boosted){
		messageLine(w.ws_col,"Un potenciador ya habia sido activado");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
    
	}
    //If doesn't have enough money to buy 
    else {
		messageLine(w.ws_col,"Monedas insuficientes");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
    }
}

/**
 * Function that implements functionality to buy the x3 points booster
 */
void boostPointsx3(myGame<nodeuserinfouser>* game){
    //Checks if a booster hasn't been buyed before or if has the enough money to buy
	if(!game->snake.x2Boosted && !game->snake.x3Boosted && game->user->info.coin >=1000){
		game->snake.x3Boosted = true;
        game->user->info.coin -= 1000;
		messageLine(w.ws_col,"Points potenciado x3");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
	}
    //If a booster has already been selected
    else if(game->snake.x2Boosted || game->snake.x3Boosted){
		messageLine(w.ws_col,"Un potenciador ya habia sido activado");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
	} 
    //If doesn't have enough money to buy 
    else {
		messageLine(w.ws_col,"Monedas insuficientes");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
    }
}

/**
 * Function that implements functionality to buy an extra life
 */
void buyLife(myGame<nodeuserinfouser>* game){
    //Checks if has the enough money
    if(game->user->info.coin >= 200){
        game->user->info.coin -= 200;
        game->snake.lifes++;
        messageLine(w.ws_col,"Vida comprada");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
    } else {
        messageLine(w.ws_col,"Monedas insuficientes");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
    }
}


/**
 * Function that implements functionality to boost velocity
 */
void boostVelocity(myGame<nodeuserinfouser>* game, double optn){
    //Checks if a booster hasn't been buyed before or if has the enough money to buy
	if(game->snake.speedBost == 1.0 && game->user->info.coin >=100){
		game->snake.speedBost = optn;
        game->snake.speed/=optn;
        game->user->info.coin -= 100;
		messageLine(w.ws_col,"Velocidad potenciada  x"+to_string(optn));
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
	}
    //If a booster has already been selected
    else if(game->snake.speedBost != 1.0){
		messageLine(w.ws_col,"Un potenciador ya habia sido activado");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
	} 
    //If doesn't have enough money to buy 
    else {
		messageLine(w.ws_col,"Monedas insuficientes");
        messageSteep(w.ws_col);
        messageMargin(w.ws_col);
    }
}

/**
 * Function that implements shop menu functionality
 */
int shopMenuAux(myGame<nodeuserinfouser>* game,int flag){

    //Cheks option selected
    switch (flag) {
        //Buy a life
        case 1:
            buyLife(game);
            break;
        //Boost points x2
        case 2:
            boostPointsx2(game);
            break;
        //Boost points x3
        case 3:
            boostPointsx3(game);
            break;
        //Boost velocity x2
        case 4:
            boostVelocity(game, 2.0);
            break;
        //Boost velocity x3
        case 5:
            boostVelocity(game,3.0);
            break;
        //Boost velocity x0.5
        case 6:
            boostVelocity(game,0.5);
            break;
        //Retuns previous menu 
        case 7:
            return 0;
        default:
            break;
    }
    sleep(1);
    shopMenu(game);

    return 0;
}

/**
 * Function that calls the shop menu implementation
 */
int shopMenu(myGame<nodeuserinfouser>* game){
    return shopMenuAux(game,optionSelectionKey(game,mensajeShop,7));
}








