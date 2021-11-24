/*
* Alumno: Erick Alfredo García Huerta
* Matrícula: A01708119
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream> //librería para leer el csv

#include "menu.h"
#include "sorts.h"
#include "estructuraslineales.h"
#include "trees.h"

using namespace std;



int main(){
    
    

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


}