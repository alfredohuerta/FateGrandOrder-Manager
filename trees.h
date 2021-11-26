/*
* trees.h: Incluye las estructuras de binary search trees que recibiran a los servants de la misma clase y los ordenará
* conforme mayor a menor de una estadística dada por el usuario.
* 
* @file trees.h
* @author Erick Alfredo García Huerta - A01708119
*/
#ifndef TRESS_H_
#define TREES_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class TreeNode{
    private:
        vector<string> datos;
	    TreeNode *left, *right;
	    TreeNode *predecesor();
    public:
        TreeNode(vector<string>);
        TreeNode(vector<string>, TreeNode*, TreeNode*);

        int toInt(vector<string> , int);
        void add(vector<string>, int);
        bool find(vector<string>, int);
        void removeChilds();
        void inorder(stringstream &) const;
        void inorderRedux(stringstream &) const;

        friend class Tree;
};

TreeNode::TreeNode(vector<string> servant) : datos(servant), left(0), right(0) {}
TreeNode::TreeNode(vector<string> servant, TreeNode *le, TreeNode *ri) 
    : datos(servant), left(le), right(ri) {}

/*
* Función recursica que borra los nodos del árbol.
* 
* @complejidad: O(n) -> aplicación de ciclo recursivo.
* 
* @param: 
* 
* @return:
*/
void TreeNode::removeChilds(){
    if (left != 0) {
        left->removeChilds();
        delete left;
        left = 0;
    }
    if (right != 0) {
        right->removeChilds();
        delete right;
        right = 0;
    }
}

/*
* Función que convierte los datos de un vector de strings en integers
* 
* 
* @complejidad: O(1) -> no de aplica ningún ciclo.
*
* @param: vector<string> servant -> vector de strings que contiene los datos individuales de un servant.
* @param: int index -> posición del valor que se va a convertir a integers.
* 
+ @return: x -> valor convertido a integers.
*/
int TreeNode::toInt(vector<string> servant, int index){
    string nums= servant[index];
    stringstream dato;
    dato << nums;
    long int x=0;
    
    dato >> x;
    
    return x;
}

/*
* Función que añade datos a un nodo del árbol. Recibe el estring con todos los datos del servant, basado en el índice 
* dado por el usuario convierte los datos en integers y el dato convertido lo compara para decidir qué dato irá donde.
* 
* @complejidad: O(n) -> se aplican ciclos recursivos.
*
* @param: vector<string> individual -> vector con los datos individuales del sercant.
* @param: int index -> número de columna que marca el dato que dictará el valor a tomar en cuenta para el ordenamiento.
* 
+ @return:
*/
void TreeNode::add(vector<string> individual, int index){
    int datoOrig, datoNew;

    datoOrig= toInt(datos, index);
    datoNew= toInt(individual, index);
    
    if(datoNew < datoOrig){
        if(left != 0){
            left->add(individual, index);
        }else{
            left= new TreeNode(individual);
        }
    }else{
        if(right != 0){
            right->add(individual, index);
        }else{
            right= new TreeNode(individual);
        }
    }
}

/*
* Función que recibe los datos completos de un servant y el número de columna con los datos que determinan su posición 
* en el árbol y que controla el ciclo recursivo de búsqueda.
* 
* @complejidad: O(n) -> aplica ciclo recursivo
* 
* @param: vector<string> servant -> datos completos del servant.
* @param: int index -> columna con la estadística a buscar.
* 
* @return: bool
*/
bool TreeNode::find(vector<string> servant, int index){
    long int search= toInt(servant, index);
    long int current= toInt(datos, index);
    
    if(servant[1] == datos[1]){
        return true;
    }else if(search < current){
        return (left != 0 && left->find(servant, index));
    }else if(search > current){
        return (right != 0 && right->find(servant, index));
    }
    return false;
}

void TreeNode::inorder(stringstream &aux) const{
    if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << "\n";
        aux << "\n";
	}
	
    for(int i= 0; i < datos.size(); i++){
        aux << datos[i];
        aux << " ";
    }

	if (right != 0) {
		right->inorder(aux);
	}
}

void TreeNode::inorderRedux(stringstream &aux) const{
    if (left != 0) {
		left->inorderRedux(aux);
	}
	if (aux.tellp() != 1) {
		aux << "\n";
        aux << "\n";
	}
	
    for(int i= 0; i < 4; i++){
        aux << datos[i];
        aux << " ";
    }

	if (right != 0) {
		right->inorderRedux(aux);
	}
}

/* ------------------------------------------------------ESPACIO------------------------------------------------------ */

class Tree{
    private:
        vector<vector<string>> dataBase;
        int servantStat;
        TreeNode *root;
    public:
        Tree();
        Tree(string, int);
        ~Tree();

        bool empty() const;
        void removeAll();
        void add(vector<string>);
        vector<string> find(string, int);
        string printServant() const;
        string printServantRedux() const;
};

Tree::Tree(){
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

    dataBase= data;
    root= 0;
    servantStat= 0;
}

/*
* Constructor del objeto Tree que en su interior abre el archivo csv para mantenerlo disponible para todos los métodos
*
* @complejidad: O(n^3) -> implementa dos ciclos while que recorren todo el archivo .csv y un ciclo for del tamaño del 
* arreglo donde se guardan los datos completos del csv y un ciclo for con un rango fijo. O(n)+O(n)+O(n)+O(1)= O(n^3).
*
* @param: string servantCLass -> clase de los servants que va a contener el árbol.
* @param: int stat -> número de columna del vector donde se encuentra la estadística que dominará el árbol.
*/
Tree::Tree(string servantClass,int stat){
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

    root= 0;
    servantStat= stat;

    for(int i= 0; i < data.size(); i++){
        if(servantClass == data[i][3]){
            for(int j= 0; j < 36; j++){
                pj.push_back(data[i][j]);
            }
            add(pj);
            pj.clear();
        }
    }

    dataBase= data;
}

Tree::~Tree(){
    removeAll();
}

bool Tree::empty() const{
    return(root == 0);
}

void Tree::removeAll(){
    if (root != 0) {
		root->removeChilds();
	}
	delete root;
	root = 0;
}

/*
* Funcion que recoge la clase de un servant y lo inserta en el árbol, pasandolo a la función add de un nodo.
*
* @complejidad: O(n) -> implementación de ciclos recursivos
* 
* @param: string servantClass -> clase del servant que será agregado al árbol.
* 
* @return:
*/
void Tree::add(vector<string> individual){
    if (root != 0) {
		if (!root->find(individual, servantStat)) {
			root->add(individual, servantStat);
		}
	} else {
		root = new TreeNode(individual);
	}
}

/*
* Función que toma el nombre de un servant y los coteja con la base de datos completa para encontrar el arreglo completo
* donde se encuentran todos sus datos y lo envía a la dunción find de TreeNode
* 
* @complejidad: O(n) -> implementación de dos ciclos for, uno con parámetros fijos (O(1)) y otro del tamaño del array 
* (O(n)). O(1) + O(n) = O(n)
* 
* @param: string name -> el nombre del servant que se buscará en toda la base de datos.
* 
* @return: vector<string> temp -> regresa los valores del servant en forma de arreglo de strings.
*/
vector<string> Tree::find(string name, int stat){
    vector<string> empty = {"Data not found"};
    vector<string> temp;
    bool flag= true;

    for(int i= 0; i < dataBase.size(); i++){
        if(dataBase[i][1] == name){
            for(int j= 0; j < 36; j++){
                temp.push_back(dataBase[i][j]);
            }
        }
    }

    if (root != 0) {
        flag= root->find(temp, stat);
        if(flag){
            return temp;
        }
	}

    return empty;
}

string Tree::printServant() const{
    stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

string Tree::printServantRedux() const{
    stringstream aux;

	if (!empty()) {
		root->inorderRedux(aux);
	}
	return aux.str();
}

#endif