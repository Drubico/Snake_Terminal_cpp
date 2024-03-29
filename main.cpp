#include <iostream>

#include <unistd.h>
#include <termios.h>

#include "./views/colors.h"
#include "./views/usermain.h"
#include "./tools/gameStruct.h"
#include "./views/windows_start.cpp"
#include "./scene/sceneControler.h"
/* 
Para ejecutar:
g++ -pthread main.cpp -o main && ./main
*/
using namespace std;
struct termios term;

void open_buffer();
void close_buffer();
void loadScenes(myGame<nodeuserinfouser>*);

/**
 * Function that loads all the stages from external files
 */
void loadScenes(myGame<nodeuserinfouser>* game){
    chargeScenes(game,"extra1.csv");
    chargeScenes(game,"extra2.csv");
    chargeScenes(game,"extra3.csv");
    chargeScenes(game,"rubi.csv");
    

}

/**
 * MAIN FUNCTION
 */
int main(void) {
    srand(time(NULL));
    myGame<nodeuserinfouser> game;// = new myGame();
    loadScenes(&game);
    
    //game.list=NULL;
    game.user=NULL;
    close_buffer();
    usermain(&game);//ingresando usuario y loading lista

    open_buffer();
    startMenu(&game);//procedemos al menu de inicio
    close_buffer();

    return 0;
};

//Element needed to process each pulse without pressing ENTER after this
void open_buffer(){
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
void close_buffer(){
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
};