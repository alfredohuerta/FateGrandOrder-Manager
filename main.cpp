/*
* Alumno: Erick Alfredo García Huerta
* Matrícula: A01708119
*/

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream> //librería para leer el csv

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

    //Menu de usuario.
    int proceso;
    List party;
    

    cout << "Bienvenido al Administrador de Fate/Grand Order" << endl;

    cout << "Seleccione el proceso que quiere llevar a cabo: " << endl;

    cout << "Ordenar servants de menor a mayor -> 1\n"
            "Crear una party nueva -> 2\n"
            "Generar árbol de clases -> 3\n"
            "Generar casos de prueba -> 4\n"
            "Ingrese su elección: ";
    cin >> proceso;
    cout << "\n";

    
    switch (proceso)
    {
    case 1: //Algoritmo de ordenamiento -> merge sort.
        {            
            Sorts ordenar;
            int desition;

            cout << "Bienvenido al menú de ordenamiento. Todos los datos de los servants serán acomodados del menor al mayor\n"
                    "Crieterios de ordenamiento:\n"
                    "Nivel máximo -> 1\n"
                    "Salud máxima a nivel 1 -> 2\n"
                    "Ataque Máximo a nivel 1 -> 3\n"
                    "Salud máxima a nivel 100 -> 4\n"
                    "Ataque Máximo a nivel 100 ->5\n"
                    "Escoja su criterio de ordenamiento: ";
            cin >> desition;

            switch (desition)
            {
            case 1:
                cout << "Usted ha escogido: Nivel máximo -> 1"
                        "Datos originales: " << endl;
                cout << ordenar.printArray() << endl;
                ordenar.merge(desition);
                
                cout << "\nDatos ordenados: " << endl;
                cout << ordenar.printArray() << endl;
                break;
            case 2:
                cout << "Usted ha escogido: Salud máxima a nivel 1 -> 2"
                        "Datos originales: " << endl;
                cout << ordenar.printArray() << endl;
                ordenar.merge(desition);
                
                cout << "\nDatos ordenados: " << endl;
                cout << ordenar.printArray() << endl;
                break;
            case 3:
                cout << "Usted ha escogido: Ataque Máximo a nivel 1 -> 3"
                        "Datos originales: " << endl;
                cout << ordenar.printArray() << endl;
                ordenar.merge(desition);
                
                cout << "\nDatos ordenados: " << endl;
                cout << ordenar.printArray() << endl;
                break;
            case 4:
                cout << "Usted ha escogido: Salud máxima a nivel 100 -> 4"
                        "Datos originales: " << endl;
                cout << ordenar.printArray() << endl;
                ordenar.merge(desition);
                
                cout << "\nDatos ordenados: " << endl;
                cout << ordenar.printArray() << endl;
                break;
            case 5:
                cout << "Usted ha escogido: Ataque Máximo a nivel 100 ->5"
                        "Datos originales: " << endl;
                cout << ordenar.printArray() << endl;
                ordenar.merge(desition);
                
                cout << "\nDatos ordenados: " << endl;
                cout << ordenar.printArray() << endl;
                break;
            
            default:
                cout << "Ingrese un valor válido" << endl;
                break;
            }

            break;
        }
    case 2: //estructuras lineales ->double linked list
        {
            string servantName;
            int menu1, menu2;
            int i=0;
            bool flag= true;

            cout << "Bienvenido al menú de creación de party's.\n"
                    "Ingrese el nombre del servant para agregarlo en la party. ADVERTENCIA: Sólo se admiten cinco servants por party\n";
                do
                {
                    cout << "Nombre de servant: ";
                    cin >> servantName;
                    party.add(data, servantName);
                    i++;
                    
                    cout << "¿Desea ingresar otro servant a la party?\n"
                            "Servants ingresados: " << i <<
                            "\nSi= 1\n"
                            "No= 0\n" 
                            "Ingrese: ";
                    cin >> menu1;

                    if(menu1 == 0 || i == 5){
                        flag= false;
                    }
                } while (flag);

                cout << "\n Party llena" << endl;
            
            flag= true;

            do
            {
                cout << "\nSeleccione una de las siguiente acciones:\n"
                    "Imprimir party -> 1\n"
                    "Encontrar servant en party -> 2\n"
                    "Remover servant de la party -> 3\n"
                    "Terminar -> 4 \n"
                    "Elección: ";
                cin >> menu2;

                switch (menu2)
                {
                case 1:
                    {
                        cout << party.printParty() << endl;
                        cout << "\n¿Desea volver al menu anterior?\n"
                                "Si= 1\n"
                                "No= 0\n" 
                                "Ingrese: ";
                        cin >> menu2;

                        if(menu2 == 0){
                            flag= false;
                        }
                    }
                    break;
                case 2:
                    {
                        cout << "Ingrese el nombre del servant: ";
                        cin >> servantName;
                        cout << party.search(servantName) << endl;
                        
                        cout << "\n¿Desea volver al menu anterior?\n"
                                "Si= 1\n"
                                "No= 0\n" 
                                "Ingrese: ";
                        cin >> menu2;
                        cout << "\n" << endl;

                        if(menu2 == 0){
                            flag= false;
                        }
                    }
                    break;
                case 3:
                    {
                        cout << "Ingrese el nombre del servant: " << servantName << endl;
                        cin >> servantName;
                        party.remove(servantName);

                        cout << "\n¿Desea volver al menu anterior?\n"
                                "Si= 1\n"
                                "No= 0\n" 
                                "Ingrese: ";
                        cin >> menu2;
                        cout << "\n" << endl;

                        if(menu2 == 0){
                            flag= false;
                        }
                    }
                    break;
                
                default:
                    flag= false;
                    break;
                }
            } while (flag);

            break;
        }
    case 3: //Arbol -> binary tree
        {
            vector<string> ind;
            int stat, menuT;
            string servantClass, buscar; 

            cout << "Bienvenido al menú de creación de árbol de clases\n"
                    "Criterios de ordenamiento, ingrese el número de la categoría:\n"
                    "Ataque a nivel 1 -> 1\n"
                    "Vida a nivel 1 -> 2\n"
                    "Ataque a nivel 100 -> 3 \n"
                    "Vida a nivel 100 -> 3\n"
                    "Selección: ";
            cin >> stat;
            cout << "\n" << endl;

            cout << "Ingrese el nombre de la clase que quiera que conforme el arbol\n"
                    "Saber\n"
                    "Archer\n"
                    "Lancer\n"
                    "Assassin\n"
                    "Rider\n"
                    "Caster\n"
                    "Berserker\n"
                    "Ruler\n"
                    "Avenger\n"
                    "Alterego\n"
                    "Moon Cancer\n"
                    "Foreigner\n";
                    "Selección: ";
            cin >> servantClass;

            switch (stat)
            {
            case 1:
                {
                    Tree arbol(servantClass, 7);
                    cout << arbol.printServant() << endl;

                    cout << "Si desea ver los datos completos de un servant -> 1\n"
                            "Si desea reeimprimir todo el árbol -> 2\n";
                    cout << "\n" << endl;
                    cin >> menuT;
                    switch (menuT)
                    {
                    case 1:
                        {
                            cout << "Ingrese el nombre del servant que busca: ";
                            cin >> buscar;
                            cout << "\n";

                            ind= arbol.find(buscar, 7);

                            for(int i= 0; i < ind.size(); i++){
                                cout << ind[i] << "  ";
                            }
                            break;
                        }
                    
                    case 2:
                        cout << arbol.printServant() << endl;
                        break;

                    default:
                        break;
                    }
                    
                    break;
                }
            
            case 2:
                {
                    Tree arbol(servantClass, 8);
                    cout << arbol.printServant() << endl;

                    cout << "Si desea ver los datos completos de un servant -> 1\n"
                            "Si desea reeimprimir todo el árbol -> 2\n";
                    cout << "\n" << endl;
                    cin >> menuT;
                    switch (menuT)
                    {
                    case 1:
                        {
                            cout << "Ingrese el nombre del servant que busca: ";
                            cin >> buscar;
                            cout << "\n";

                            ind= arbol.find(buscar, 8);

                            for(int i= 0; i < ind.size(); i++){
                                cout << ind[i] << "  ";
                            }
                            break;
                        }
                    
                    case 2:
                        cout << arbol.printServant() << endl;
                        break;

                    default:
                        break;
                    }
                }
            
            case 3:
                {
                    Tree arbol(servantClass, 13);
                    cout << arbol.printServant() << endl;

                    cout << "Si desea ver los datos completos de un servant -> 1\n"
                            "Si desea reeimprimir todo el árbol -> 2\n";
                    cout << "\n" << endl;
                    cin >> menuT;
                    switch (menuT)
                    {
                    case 1:
                        {
                            cout << "Ingrese el nombre del servant que busca: ";
                            cin >> buscar;
                            cout << "\n";

                            ind= arbol.find(buscar, 13);

                            for(int i= 0; i < ind.size(); i++){
                                cout << ind[i] << "  ";
                            }
                            break;
                        }
                    
                    case 2:
                        cout << arbol.printServant() << endl;
                        break;

                    default:
                        break;
                    }
                }
            
            case 4:
                {
                    Tree arbol(servantClass, 14);
                    cout << arbol.printServant() << endl;

                    cout << "Si desea ver los datos completos de un servant -> 1\n"
                            "Si desea reeimprimir todo el árbol -> 2\n";
                    cout << "\n" << endl;
                    cin >> menuT;
                    switch (menuT)
                    {
                    case 1:
                        {
                            cout << "Ingrese el nombre del servant que busca: ";
                            cin >> buscar;
                            cout << "\n";

                            ind= arbol.find(buscar, 14);

                            for(int i= 0; i < ind.size(); i++){
                                cout << ind[i] << "  ";
                            }
                            break;
                        }
                    
                    case 2:
                        cout << arbol.printServant() << endl;
                        break;

                    default:
                        break;
                    }
                }

            default:
                break;
            }
            break;
        }
    case 4: //Casos de prueba
        {
            //hacer casos de prueba con sólo uno pocos datos para comparar.
            vector<string> datosIndividuales;
            vector<string> names= {"Mash_Kyrielight", "Altria_Pendragon", "Altria_Pendragon_(Alter)", "Altria_Pendragon_(Lily)", "Nero_Claudius"};
            string servantN, test, ans;

            cout << "Ordenar por medio de un merge sort" << endl;
            Sorts ordenar;
            ordenar.merge(2);
            ans= "(ID: 174, Nombre: Paul_Bunyan)\n"
                 "(ID: 39, Nombre: Sasaki_Kojirou)\n"
                 "(ID: 259, Nombre: Charlotte_Corday)\n"
                 "(ID: 260, Nombre: Salome)\n"
                 "(ID: 45, Nombre: Mata_Hari)\n"
                 "(ID: 53, Nombre: Asterios)\n"
                 "(ID: 42, Nombre: Jing_Ke)\n"
                 "(ID: 257, Nombre: Bartholomew_Roberts)\n"
                 "(ID: 28, Nombre: Alexander)\n"
                 "(ID: 54, Nombre: Caligula)\n";

            cout << "\nArreglo ordenado por salud a nivel 1:\n" << endl;

            if(ans == ordenar.printArray()){
                cout << "SUCCESS" << endl;
            }

            cout << "\nCrear party" << endl;
            for(int i= 0; i < names.size(); i++){
                party.add(data, names[i]);
            }
            ans= "1 Mash_Kyrielight Galahad Shielder\n"
                 "2 Altria_Pendragon King Arthur-King of Knights Saber\n"
                 "3 Altria_Pendragon_(Alter) King Arthur-King of Knights Saber\n"
                 "4 Altria_Pendragon_(Lily) King Arthur-King of Knights Saber\n"
                 "5 Nero_Claudius Empress of Rose Saber ";
            test= party.printPartyRedux(); 
            if(ans.compare(test)){
                cout << "Crear party -> SUCCESS\n" << endl;
                cout << "Función crear party\n" << party.printPartyRedux() << endl;
            }

            cout << "Borrar datos servant: " << names[1] << endl;
            party.remove(names[1]);
            test= party.printPartyRedux();
            bool flag= !ans.compare(test); 
            if(flag == false){
                cout << "Borrar servant -> SUCCESS\n" << endl;
                cout << "Party post-borrado\n" << party.printPartyRedux() << endl;
            }

            cout << "\nBuscar datos servant: " << names[4] << endl;
            ans= "[5 Nero_Claudius Empress of Rose Saber ]";
            test= party.searchRedux(names[4]); 
            if(test == ans){
                cout << "Servant Search -> SUCCESS" << endl;
                cout << "Servant data: " << test << endl;
            }

            servantN= "Kiyohime";
            cout << "\nAgregar nuevo servant: " << servantN << endl;
            party.add(data, servantN);
            ans= "1 Mash_Kyrielight Galahad Shielder\n"
                 "3 Altria_Pendragon_(Alter) King Arthur-King of Knights Saber\n"
                 "4 Altria_Pendragon_(Lily) King Arthur-King of Knights Saber\n"
                 "5 Nero_Claudius Empress of Rose Saber "
                 "56 Kiyohime Princess Kiyo Kiyo-yo Best Girl Berserker";
            test= party.printPartyRedux();
            if(ans.compare(test)){
                cout << "Agregar nuevo servant -> SUCCESS" << endl;
                cout << "Party post-agregación\n" << party.printPartyRedux() << "\n" << endl;
            }

            cout << "\nCreación de arbol de servants clase Ruler ordenados por Ataque a nivel 1" << endl;
            
            Tree arbol("Ruler", 7);

            ans= "59 Jeanne_d'Arc Joan of Arc-La Pucelle d'Orleans Ruler"
                 "265 Bunny_Altria_Pendragon Lion King Bunny King Ruler"
                 "229 Shi_Huang_Di Qin Shi Huang-Shikoutei Ruler"
                 "135 Summer_Martha Martha of Bethany-Saint of the Waterside Ruler"
                 "233 Quetzalcoatl_(Samba/Santa) Feathered Serpent Ruler"
                 "242 Astraea Goddess of Justice-Luviagelita Edelfelt Ruler"
                 "93 Amakusa_Shirou Kotomine Shirou Ruler";
            test= arbol.printServantRedux();

            if(ans.compare(test)){
                cout << "Imprimir Arbol de rulers -> SUCCESS" << endl;
                cout << "Arbol de servants clase:\n" << test << endl;
            }

            cout << "\nBusqueda de servant:" << endl;
            servantN= "Amakusa_Shirou";
            datosIndividuales= arbol.find(servantN, 7);
            vector<string> vectorAns= {"93", "Amakusa_Shirou", "Kotomine Shirou", "Ruler", "5-star", "16", "90", "1695", "2069", "10972", "14107", "10972", "14107", "12011", "15455", "0.0086", "0.03", "100", "0.1", "0.21", "1", "2", "3", "4", "1", "Man", "Male-Servant-Humanoid-Weak to Enuma Elish", "Konoe Ototsugu", "Uchiyama Kouki", "169 cm", "59 kg", "Lawful Good", "Fate/Apocrypha", "Male", "Historical Fact", "Japan"};
            
            for(int i= 0; i < datosIndividuales.size() && i < vectorAns.size(); i++){
                if(datosIndividuales[i] == vectorAns[i]){
                    ans = "Búsqueda de servant " + servantN + " -> SUCCESS";
                }else{
                    ans= "Busqueda fallida";
                }
            }

            cout << ans << endl;

            cout << "Fin del programa" << endl;

            break;
        }
    default:
        break;
    }
    return 0;
}