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
#include <fstream>

using namespace std;

struct servant
{
    int id;
    string name;
    int maxLevel;
    int attackLevel1;
    int healthLevel1;
    int attackLevel100;
    int healthLevel100;
};

class Sorts{
    private:
        servant indiv;
        vector<servant> todos;

        vector<struct servant> createServants(vector<vector<string>>, servant indi);
        void copyArray(vector<struct servant>&, vector<struct servant>&, int, int);
        void mergeArray(vector<struct servant>&, vector<struct servant>&, int, int, int, int);
        void mergeSplit(vector<struct servant>&, vector<struct servant>&, int, int, int);
    public:
        Sorts();
        int toInt(vector<vector<string>>, int, int);
        string printArray();

        vector<struct servant> merge(int);
};

/**
 * @brief Constructor de objeto sorts que abre dentro de sí mismo el archivo que se usa de base de datos, así como crea 
 * un arreglo de constructos tipo servant que se manipularán en los sorts.
 * 
 * @complejidad: O(n) sin contar la complejidad de la función createServants, con la cual sería O(n) + O(n) = O(n^2)
 */
Sorts::Sorts(){
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

        if(pj[0] == "´╗┐ID"){
            pj.clear();
        }

        data.push_back(pj);
        pj.clear();
    }
    todos= createServants(data, indiv);
}

/**
 * @brief Función que recibe un vector de vectores de strings y los índices del servant y los datos que va a convertir
 * 
 * @param dataBase toda la base de datos de los servants
 * @param index1 posición donde se encuentran todos los datos del servant
 * @param index2 dato individual del servant
 * 
 * @complejidad: O(1).
 * 
 * @return int x dato convertido a integer
 */
int Sorts::toInt(vector<vector<string>> dataBase, int index1, int index2){
    string nums= dataBase[index1][index2];
    stringstream dato;
    dato << nums;
    int x=0;
    
    dato >> x;
    
    return x;
}

/**
 * @brief Función que extrae los datos más importantes del gran vector para almacenarlos en una estructura que se 
 * almacena en otro vector más pequeño.
 * 
 * @complejidad: O(n) por el uso de un ciclo for.
 * 
 * @param vector<vector<string>> todos los datos de los servants
 * @param servant indi datos individuales
 * @return vector<struct servant> allservants vector con 
 */
vector<struct servant> Sorts::createServants(vector<vector<string>> dataBase,servant indi){
    vector<struct servant> allServants;


    indi.id = 0;
    indi.name = "Null";
    indi.maxLevel= 0;
    indi.attackLevel1= 0;
    indi.healthLevel1= 0;
    indi.attackLevel100= 0;
    indi.healthLevel100= 0;
    allServants.push_back(indi);

    for(int i= 1; i < dataBase.size(); i++){
        indi.id = toInt(dataBase, i, 0);
        indi.name = dataBase[i][1];
        indi.maxLevel= toInt(dataBase, i, 6);
        indi.attackLevel1= toInt(dataBase, i, 7);
        indi.healthLevel1= toInt(dataBase, i, 8);
        indi.attackLevel100= toInt(dataBase, i, 13);
        indi.healthLevel100= toInt(dataBase, i, 14);

        allServants.push_back(indi);
    }

    allServants.erase(allServants.begin());
    return allServants;
}

/**
 * @brief FUnción que almacena los datos del arreglo en un string stream y lo imprime
 * 
 * @complejidad: O(n) porque usa un ciclo for ligado al tamaño de un arreglo.
 * 
 * @return string todos los datos del arreglo.
 */
string Sorts::printArray(){
    stringstream array;
    
    for(int i= 0; i < todos.size(); i++){
        array << "(ID: ";
        array << todos[i].id;
        array << ", Nombre: ";
        array << todos[i].name;
        array << ")\n";
    }

    return array.str();
}

/**
 * @brief Función principal que usa un merge sort para ordenar los datos de acuerdo a un cierto parámetro que se decide
 * con el int op.
 * 
 * @complejidad: O(n*log(n)) al ser un merge sort.
 * 
 * @param op entero que señala la posición donde se encuentra la estadística que se usará para ordenar los datos.
 * @return vector<struct servant> vector ordenado.
 */
vector<struct servant> Sorts::merge(int op){
    vector<struct servant> temp(todos.size());

    mergeSplit(todos, temp, 0, todos.size()-1, op);

    return todos;
}

/**
 * @brief Función que divide en mitades el arreglo para su posterior unión.
 * 
 * @param A vector de estructuras con todos los datos de la base de datos
 * @param B vector temporal vacío del tamaño de vector A
 * @param low posición más baja del arreglo.
 * @param high posición final del arreglo.
 * @param op entero que señala la posición donde se encuentra la estadística que se usará para ordenar los datos.
 */
void Sorts::mergeSplit(vector<struct servant> &A, vector<struct servant> &B, int low, int high, int op){
    int mid;

    if( (high - low) < 1 ){
        return;
    }

    mid= (high + low)/2;

    mergeSplit(A, B, low, mid, op); //mitad inferior
    mergeSplit(A, B, mid+1, high, op); //mitad superior

    mergeArray(A, B, low, mid, high, op); //unir arreglos

    copyArray(A, B, low, high);
}

/**
 * @brief Función que compara los datos del arreglo A y los almacena en el B
 * 
 * @param A vector de estructuras con todos los datos de la base de datos
 * @param B vector temporal vacío del tamaño de vector A
 * @param low posición más baja del arreglo.
 * @param mid valor medio que separa ambas mitades del vector
 * @param high posición final del arreglo.
 * @param op entero que señala la posición donde se encuentra la estadística que se usará para ordenar los datos y es 
 * usado en el switch para escoger el camino a tomar.
 */
void Sorts::mergeArray(vector<struct servant> &A, vector<struct servant> &B, int low, int mid, int high, int op){
    int i, j, k;
	i = low;
	j = mid + 1;
	k = low;

    switch (op)
    {
    case 1:
        while (i <= mid && j <= high) {
            if (A[i].maxLevel < A[j].maxLevel) {
                B[k] = A[i];
                i++;
            } else {
                B[k] = A[j];
                j++;
            }
            k++;
        }
        if (i > mid) {
            for (; j <= high; j++) {
                B[k++] = A[j];
            }
        } else {
            for (; i <= mid; i++) {
                B[k++] = A[i];
            }
        }
        break;
    case 2:
        while (i <= mid && j <= high) {
            if (A[i].healthLevel1 < A[j].healthLevel1) {
                B[k] = A[i];
                i++;
            } else {
                B[k] = A[j];
                j++;
            }
            k++;
        }
        if (i > mid) {
            for (; j <= high; j++) {
                B[k++] = A[j];
            }
        } else {
            for (; i <= mid; i++) {
                B[k++] = A[i];
            }
        }
        break;

    case 3:
        while (i <= mid && j <= high) {
            if (A[i].attackLevel1 < A[j].attackLevel1) {
                B[k] = A[i];
                i++;
            } else {
                B[k] = A[j];
                j++;
            }
            k++;
        }
        if (i > mid) {
            for (; j <= high; j++) {
                B[k++] = A[j];
            }
        } else {
            for (; i <= mid; i++) {
                B[k++] = A[i];
            }
        }
        break;
    case 4:
        while (i <= mid && j <= high) {
            if (A[i].healthLevel100 < A[j].healthLevel100) {
                B[k] = A[i];
                i++;
            } else {
                B[k] = A[j];
                j++;
            }
            k++;
        }
        if (i > mid) {
            for (; j <= high; j++) {
                B[k++] = A[j];
            }
        } else {
            for (; i <= mid; i++) {
                B[k++] = A[i];
            }
        }
        break;
    case 5:
        while (i <= mid && j <= high) {
            if (A[i].attackLevel100 < A[j].attackLevel100) {
                B[k] = A[i];
                i++;
            } else {
                B[k] = A[j];
                j++;
            }
            k++;
        }
        if (i > mid) {
            for (; j <= high; j++) {
                B[k++] = A[j];
            }
        } else {
            for (; i <= mid; i++) {
                B[k++] = A[i];
            }
        }
        break;
    default:
        cout << "Invalido :(" << endl;
        break;
    }
}

/**
 * @brief Función que copia los elementos de un arreglo en otro.
 * 
 * @param A vector con todos los datos de la base de datos
 * @param B vector vacío
 * @param low valor más bajo del arreglo de la base de datos
 * @param high valor más alto del arreglo de la base de datos.
 */
void Sorts::copyArray(vector<struct servant> &A, vector<struct servant> &B, int low, int high){
    for (int i = low; i <= high; i++) {
        A[i] = B[i];
	}
}

#endif