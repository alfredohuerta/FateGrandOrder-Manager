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
        int level, balance;
	    TreeNode *left, *right;
	    TreeNode *predecesor();
    public:
        TreeNode(vector<string>);
        TreeNode(vector<string>, TreeNode*, TreeNode*, int, int);

        int toInt(vector<string> , int);
        void add(vector<string>, int);
        bool find(vector<string>, int);
        void removeChilds();

        friend class Tree;
};

TreeNode::TreeNode(vector<string> servant) : datos(servant), left(0), right(0), level(0), balance(0) {}
TreeNode::TreeNode(vector<string> servant, TreeNode *le, TreeNode *ri, int lvl, int bal) 
    : datos(servant), left(le), right(ri), level(lvl), balance(bal) {}

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
* @param: vector<string> servant -> vector de strings que contiene los datos individuales de un servant.
* @param: int index -> posición del valor que se va a convertir a integers.
* 
+ @return: x -> valor convertido a integers.
*/
int TreeNode::toInt(vector<string> servant, int index){
    string nums= servant[index];
    stringstream dato;
    dato << nums;
    int x=0;
    
    dato >> x;
    
    return x;
}

/*
* Función que añade datos a un nodo del árbol. Recibe el estring con todos los datos del servant, basado en el índice 
* dado por el usuario convierte los datos en integers y el dato convertido lo compara para decidir qué dato irá donde.
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
* @param: vector<string> servant -> datos completos del servant.
* @param: int index -> columna con la estadística a buscar.
* 
* @return: bool
*/
bool TreeNode::find(vector<string> servant, int index){
    int search= toInt(servant, index);
    int current= toInt(datos, index);


    if(servant == datos){
        return true;
    }else if(search < current){
        return (left != 0 && left->find(servant, index));
    }else if(search > current){
        return (right != 0 && right->find(servant, index));
    }
    return false;
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
        vector<string> find(string);
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
            for(int j= 0; j < 38; j++){
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
* @param: string name -> el nombre del servant que se buscará en toda la base de datos.
* 
* @return: vector<string> temp -> regresa los valores del servant en forma de arreglo de strings.
*/
vector<string> Tree::find(string name){
    vector<string> temp;
    bool flag= false;

    for(int i= 0; i < dataBase.size(); i++){
        if(dataBase[i][1] == name){
            for(int j= 0; j < 38; j++){
                temp.push_back(dataBase[i][j]);
            }
        }
    }

    if (root != 0) {
        flag= root->find(temp, servantStat);
        cout << flag << "\n" << endl;
        if(flag){
            return temp;
        }
	}

    temp.clear();
    temp.push_back(":( ");
    temp.push_back("Data not found");
	return temp;
}
#endif