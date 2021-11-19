/*
* estructuraslineales.h: Incluye las estructuras que permitirán al usuario hacer sus party's de Fate/Grand Order, 
* siguiendo las limitaciones del sistema que sólo permite incluir a cinco servants diferentes en la party. Esto se logra
* a través de una double linked list
* 
* @file estructuraslineales.h
* @author Erick Alfredo García Huerta - A01708119
*/
#ifndef ESTRUCTURASLINEALES_H_ 
#define ESTRUCUTRASLINEALES_H_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

class DLink{
    private:
        DLink(vector<string> );
        DLink(vector<string>, DLink*, DLink*);
        DLink(const DLink &);

        vector<string> servantData;
        DLink *next;
        DLink *previous;

        friend class List;
};

DLink :: DLink(vector<string> specs) : servantData(specs), previous(0), next(0) {}
DLink :: DLink(vector<string> specs, DLink *prev, DLink *nxt) : servantData(specs), previous(prev), next(nxt) {}
DLink :: DLink(const DLink &source) : servantData(source.servantData), previous(source.previous), next(source.next) {}

class List{
    public:
    List();
    List(const List &);
    ~List();

    //Funciones de consulta de propiedades.
    void clear(); //Borra todos los datos de la lista.
    bool empty() const; //devuelve un valor boooleano dependiendo de si la lista está vacía o no
    int espaciosUsados() const;

    //Funciones de manejo de datos.
    int extractServant(vector<vector<string>> &, string &);
    string search(string &);
    void addfirst(vector<vector<string>> &, string &);
    void add(vector<vector<string>> &, string &);
    void remove(string &);
    string printParty();

    private:
        DLink *head;
        DLink *tail;
        int size, capacidad; //size -> tamaño máximo de datos que puede almacenar la lista.
                            //capacidad -> número de espacios siendo usados.
};

List::List() : head(0), tail(0), size(5), capacidad(0) {}

List::~List(){
    clear();
}

void List::clear(){
    DLink *p, *q;

	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	tail = 0;
	capacidad = 0;
}

bool List::empty() const{
	return (head == 0 && tail == 0);
}

int List::espaciosUsados() const{
    return capacidad;
}

string List::printParty(){
    stringstream party;
    int pos = 1;
    DLink *p;

    p= head;
    
    while(p != 0){
        for(int i= 0; i < 36; i++){
            party << p->servantData[i];
            party << ", ";
        }
        party << "\n";
        p= p->next;
    }

    return party.str();
}

/*
* Función que de sequential search que compara un string con el nombre completo de cada servant para devolver la 
* posición del vector que contiene toda su información.
* 
* @param: vector<vector<string>> &servants -> vector donde se almacenan todos los datos de los servants.
* @param: string name -> nombre completo del servant que se desea encontrar.
* 
+ @return: posición del vector interno que contiene la información del servant. En caso de no encontrarse, regresa -1.
*/
int List::extractServant(vector<vector<string>> &servantdb, string &name) {
    for(int i= 0; i < servantdb.size(); i++){
        if(servantdb[i][1] == name){
            return i;
        }
    }

    return -1;
}

/*
* Función que busca nodo por nodo el nombre del servant que se necesitay regresa sus datos completos. De no encontrarse 
* el servant, se envía un mensaje de error.
* 
* @param: string name -> nombre completo del servant que se desea buscar en la party.
* @return: todo.srt() -> string stream que contiene todos los datos del nodo a.k.a. servant.
*/
string List::search(string &name){
    stringstream todo;
    DLink *p;

    p= head;

    if(empty()){
        throw "Error: party vacía \n"; 
    }

    for(int i= 0; i <= 5; i++){
        if(p->servantData[1] == name){
            todo << "[";
            for(int i= 0; i < 36; i++){
                todo << p->servantData[i];
                todo << ", ";
            }
            todo << "]";
            return todo.str();
        }
        p= p->next;
    }

    return "Error: El servant no se encuentra en la party";
}

/*
* Función que valida si la lista no está llena, extrae sus datos de la base de datos general y la almacena en un vector
* que después será almacenado en la lista.
* 
* @param: vector<vector<string>> &servants -> vector donde se almacenan todos los datos de los servants.
* @param: string name -> nombre completo del servant que se desea agregar a la party.
*/
void List::addfirst(vector<vector<string>> &servantdb, string &name){
    int pos= extractServant(servantdb, name); //variable en la que se almcena la posición del servant.
    vector<string> individual; //arreglo donde se almacenan los datos del servant.

    if(capacidad == size){
        throw "Party llena. \n";
    }

    for(int i= 0; i < 36; i++){
        individual.push_back(servantdb[pos][i]);
    }

    DLink *newLink;
    newLink= new DLink(individual);

    if(empty()){
        head= newLink;
        tail= newLink;
    } else{
        newLink->next = head;
        head->previous = tail;
        head= newLink;
    }

    capacidad++;
}

/*
* Función que valida si la lista no está llena y en caso de estar vacía, llama a la función addfirst(); extrae sus datos
*  de la base de datos general y la almacena en un vector que después será almacenado en la lista.
* 
* @param: vector<vector<string>> &servants -> vector donde se almacenan todos los datos de los servants.
* @param: string name -> nombre completo del servant que se desea agregar a la party.
*/
void List::add(vector<vector<string>> &servantdb, string &name){
    if(empty()){
        addfirst(servantdb, name);
    }

    if(capacidad == size){
        throw "Party llena. \n";
    }

    int pos= extractServant(servantdb, name);
    vector<string> individual;

    for(int i= 0; i < 36; i++){
        individual.push_back(servantdb[pos][i]);
    }

    DLink *newLink;
    newLink= new DLink(individual);

    tail->next = newLink;
	newLink->previous = tail;
	tail = newLink;

    capacidad++;
}

/*
* Función que elimina un elemento dado de la lista tras validar que no está vacía y diferencía entr el primer elemento
* de la misma y cualquier otro.
* 
* @param: string name -> nombre completo del servant que se desea eliminar de la party.
* @return: 
*/
void List::remove(string &name){
    DLink *p;
    p= head;
    if(empty()){
        throw "Party vacía.\n";
    }
    for(int i= 0; i <= 5; i++){
        if(p->servantData[1] == name && i == 0){
            p->next->previous = p->previous;
            break;
        }else if(p->servantData[1] == name){
            p->previous->next = p->next;
            break;
        }
        p= p->next;
    }
    delete p;
    --capacidad;
}

#endif