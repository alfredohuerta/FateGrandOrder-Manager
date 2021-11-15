/*
* Sorts: incluye el algoritmo de ordenamiento de tipo merge sort que ordenará los datos de un vector para el uso del
* usuario. Los algoritmos ordenarán de menor a mayor y viceversar los datos de Ataque máximo, Nivel máximo, Vida máxima
* y Nivel Máximo de los servants.
* 
* @file sorts.h
* @author Erick Alfredo García Huerta - A01708119
*/

#ifndef SORTS_H_
#define SORTS_H_

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Ordenar{
    public:
        vector<int> toInt(vector<vector<string>>&, int);
        void copyArray(vector<>&, vector<int>&, int, int);
        void mergeArray(vector<>&, vector<int>&, int, int, int);
        void mergeSplit(vector<int>&, vector<int>&, int, int);
    private:
        vector<string> mergeSort(const vector<int>&);
};

/*
* Función que convierte un vector de vectores strings en un vector de integers
* 
* @param: vector<vector<string>> &servants -> vector de strings a convertir
* @param: int op -> opción de qué columna se va a convertir en integers.
* 
+ @return: vector<int> servantsNum -> vector de integers.
*/
vector<int> Ordenar :: toInt(vector<vector<string>> &servants, int op){
    vector<int> servantsNum;
    vector<string> temp;
    int x= 0;

    for(int i= 0; i< servants.size(); i++){
        temp.push_back(servants[i][op]);
        stringstream num(temp[i]);
        num >> x;
        servantsNum.push_back(x);
    }
    
    return servantsNum;
}

void Sorts :: copyArray(vector<> &A, vector<> &B, int low, int high){
    for(int i= low; i <= high; i++){
        A[i]= B[i];
    }
}

void Sorts :: mergeArray(vector<> &A, vector<> &B, int low, int high, int mid){
    int i, j, k;

    i= low;
    j= mid+1;
    k= high;

    while (i <= mid && j <= high)
    {
        if(A[i]<A[j]){
            B[k]= A[i];
            i++;
        }else{
            B[k]= A[j];
            j++;
        }
        k++;
    }

    if(i>mid){
        for(; j <=high; j++){
            B[k+1]= A[j];
        }
    }else{
        for(; i <=mid ; i++){
            B[k+1]= A[i];
        }
    }
    
}

void Sorts :: mergeSplit(vector<> &A, vector<> &B, int low, int high){
    int mid;

    if(high-low < 1){
        return;
    }

    mid= (high+low)/2;

    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid+1, high);

    mergeArray(A, B, low, mid, high);

    copyArray(A, B, low, high);
}

vector <string> Sorts :: ordenaMerge(const vector<vector<string>> &prueba){
    vector <> v(prueba);
    vector <> temp(v.size());

    mergeSplit(v, temp, 0, v.size()-1);

    return v;
}

#endif