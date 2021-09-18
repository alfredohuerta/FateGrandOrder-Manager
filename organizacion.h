/*
* Alumno: Erick Alfredo García Huerta
* Matrícula: A01708119
* 
* El programa es capáz de recibir un array de strings y ordenarlos en distintas secuencias.
*
* Orden de las clases: 
* 0 -> Shielder
* 1 -> Saber
* 2 -> Lancer
* 3 -> Archer
* 4 -> Assasin
* 5 -> Rider
* 6 -> Caster
* 7 -> Berserker
*/

#ifndef ORGANIZACION_H
#define ORGANIZACION_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

template <class T>
class Organizar{
    private:
        void swap(vector <T> &, int, int);
    public:
        vector <T> ordenarPorNumeros(vector <T> &);
};

template <class T>
void Organizar<T> :: swap(vector <T> &data, int i, int j){
    T aux= data[i];
    data[i]= data[j];
    data[j]= aux;
}

template <class T>
vector <T> Organizar<T> :: ordenarPorNumeros(vector <T> &data){
    for(int i = 0; i < data.size(); i++){
        for (int j = i; j >= 0 && data[j] < data[j - 1]; j--) {
			swap(data, j, j - 1);
		}
    }
    return data;
}

#endif