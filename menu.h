/**
 * @file menu.h
 * @author Erick Alfredo García Huerta - A01708119
 * @brief unificación de los demás métodos
 * @date 2021-11-24
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream> //librería para leer el csv

#include "sorts.h"
#include "estructuraslineales.h"
#include "trees.h"

using namespace std;

class Menu{
    private:
        vector<vector<string>> whole;
    public:
        Menu();
        vector<vector<string>> openCSV();
        void ordenar();
        void crearParty();
        void arbolDeClases();
};

Menu::Menu(){
    whole= openCSV();
}

/*
    * Se abre el archivo FGO_Servant_Data.csv y se almacenan los datos en el vector vidimencional data.
    * 
    * @param FGO_Servant_Data.csv is .csv document
    * @return vector of vectors data
*/
vector<vector<string>> Menu::openCSV(){
    ifstream  servants;
    servants.open("FGO_Servant_Data.csv");

    vector<string> pj;
    vector<vector<string>> data;
    string line, word;

    while(getline(servants, line)){
            
        stringstream s(line);

        while(getline(s, word, ',')){
            pj.push_back(word);
        }

        data.push_back(pj);
        pj.clear();
    }

    return data;
}

void Menu::ordenar(){
    
}

void Menu::crearParty(){
    //
}

void Menu::arbolDeClases(){
    //
}

#endif