/*
* Alumno: Erick Alfredo García Huerta
* Matrícula: A01708119
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream> //librería para leer el csv

//#include "sorts.h"

using namespace std;


int main(){
    
    /*
    * Se abre el archivo FGO_Servant_Data.csv y se almacenan los datos en el vector vidimencional data.
    * 
    * @param FGO_Servant_Data.csv is .csv document
    * @param
    * @return vector of vectors data
    */

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

    /*Ordenar servantList;
    int opcion;

    cout << "Ingrese la accion que quiere llevar a cabo: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        cout << "\n" << endl;
        break;
    
    default:
        break;
    }*/

    
}