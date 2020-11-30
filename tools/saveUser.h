#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include <sstream>
#include "./node.h"


template<class T>
void saveincsv(node<T>* list){
    //auxiliamos el nodo
    node<T>* aux = list;
    ofstream data;
    remove("data/user.csv");
    //abrimos data
    data.open("data/user.csv",ios::app);
    while (aux)
    {
        //segun nuestra lista que llene el csv
        data<<aux->info.name<<","<<
        aux->info.puntaje<<","<<
        aux->info.coin<<","<<
        aux->info.vidas<<","<<
        aux->info.nivel<<","<<
        aux->info.puntajeContinuar<<"\n";
        //saltamos 
        aux= aux->next;
    }
    data.close();
    
}