/*
* Alumno: Erick Alfredo García Huerta
* Matrícula: A01708119
* 
* El programa está diseñado para recibir un arreglo de datos y ordenarlos de menor a mayor y viceversa
*/

#include <stdio.h>
#include <iostream>
#include <vector>

#include "organizacion.h"

using namespace std;

vector <int> datasheet1= {2,3,4,5,1,6};
vector <string> datasheet2= {"Artoria", "Barghest", "Chiron"};

int main(){

    Organizar<int> org;

    vector <int> prueba;

    prueba= org.ordenarPorNumeros(datasheet1);

    for(int i= 0; i < prueba.size(); i++){
        cout << prueba[i] << ", ";
    }
    
}