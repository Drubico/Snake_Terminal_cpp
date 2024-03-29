#pragma once
#include <iostream>
#include <thread>

#include <stdlib.h>
#include <unistd.h>

#include "matriz.h"
#include "../tools/list.h"
#include "../views/colors.h"

//Constants to be used
#define FOOD 'O'
#define SNAKE '*'
#define CRASH '?'
#define SCENE ' '
#define WALL 'X'
#define Circulo ''
#define Pared ''
using namespace std;

/**
 * Funtion that gets a random number in a range
 */
int getIntRand(int a, int b){   
    return rand() % (b - a + 1) + a;
}

//Structure to define the snake in the game
struct mySnake{
    //Variables
    charMatriz M;
    int FILA;
    int COLUMNA;
    int steep;
    int sizeSnake;
    int points;
    int lifes;
    int level;
    double speed;
    double initialSpeed;
    double speedBost=1.0;
    int sizeMax;
    int velMax;

    bool x2Boosted=false, x3Boosted=false;
    doubleLinked <nodeinfo>* list;

    //Contructors
    mySnake() {}
    mySnake(int _i, int _c) : FILA(_i), COLUMNA(_c) {
        steep=1;
        sizeSnake = 3;
       // speedBost = 1;
        speed = 4;
        initialSpeed = speed + speedBost;
        points= 0;
        sizeMax = 30;
        
        getMatrizChar(&M,FILA,COLUMNA);
    }

    //Functions
    //Initial values (position, size, speed) of the snake
    void inicialiceMySnake(int row, int col) {
        list = new doubleLinked <nodeinfo>();
        FILA = row;
        COLUMNA = col;
        sizeSnake = 3;
        steep=1; 
       // speedBost = 1;
        speed = 5;
        initialSpeed = speed/speedBost;
        velMax = 30;
        sizeMax = 30;
        getMatrizChar(&M,FILA,COLUMNA);
    }

    //Reads the values from a double linked list and 
    //determines wich elements are the body of the snake
    void defineSnake(){
        for(node<nodeinfo>* e = list->front; e!=NULL; e=e->next){
            if(e->info.i>=FILA)
                e->info.i=0;
            if(e->info.j>=FILA)
            e->info.j=0;
            M[e->info.i][e->info.j]=SNAKE;
        }
    }

    //Erases the snake from the matrix and the double linked list
    void deleteSnake(){
        for(node<nodeinfo>* e = list->back; e!=NULL; e=e->prev){
            M[e->info.i][e->info.j]=SCENE;
        }
        list = new doubleLinked <nodeinfo>();
    }

    // Creates randomly a food in the stage calculating a possible space
    void defineFood(){
        int i , j;
        do{
            i = getIntRand( 0 , FILA - 1 );
            j = getIntRand( 0 , COLUMNA - 1 );
        }while (M[i][j]!=SCENE);
        M[i][j] = FOOD;
    }

    // Creates randomly obstacles in the stage calculating a possible space
    void defineObst(int obstaculos){
        for(int k=0 ; k<obstaculos;k++){
            int i , j;
        do{
            i = getIntRand( 0 , FILA - 1 );
            j = getIntRand( 0 , COLUMNA - 1 );
        }while (M[i][j]!=SCENE);
        M[i][j] = WALL;
        }
    }
    

    //Prints the spaces with diferent items depending it they are
    // Snake, wall, food or a blank space
    void show(){
        cout<<COLOR_BOLDBLUE;
        for(int i=0; i< COLUMNA; i++)cout<<"- ";
        cout<<"-"<<endl<<RESET;
        for(int i = 0; i < FILA; i++) {
            cout<<COLOR_BOLDBLUE;
            cout<<'|';
            cout<<RESET;
            for(int j = 0; j < COLUMNA; j++){
                switch (M[i][j])
                {
                //https://unicode-table.com/es/#miscellaneous-mathematical-symbols-b
                case SNAKE:
                    cout<<COLOR_BOLDGREEN<<"\u2B24"<<" "<<RESET;
                    break;
                case WALL:
                    cout<<COLOR_BOLDRED<<"\u2612"<<" "<<RESET;
                    break;
                case FOOD:
                    cout<<COLOR_BOLDYELLOW<<"\u2B24"<<" "<<RESET;
                    break;                
                default:
                    cout<<M[i][j]<<" "; 
                    break;
                }
            }
            cout<<COLOR_BOLDBLUE;
            cout<<'|'<<endl;
            cout<<RESET;
        }  
        cout<<COLOR_BOLDBLUE;
        for(int i=0; i< COLUMNA; i++)cout<<"- ";
        cout<<"-"<<endl;
        cout<<RESET;
}
    //Sets lifes
    void setLive(int live){
        lifes=live;
    }

    
};



