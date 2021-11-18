/*
* trees.h: Incluye las estructuras de binary search trees que recibiran a los servants de la misma clase y los ordenará
* 
* @file trees.h
* @author Erick Alfredo García Huerta - A01708119
*/
#ifndef TRESS_H_
#define TREES_H_

#include <vector>
#include <string>
#include <sstream>

using namespace std;

class TreeNode{
    private:
        vector<string> datos;
	    TreeNode *left, *right;

	    TreeNode *succesor();
    public:
        TreeNode(vector<string>);
        TreeNode(vector<string>, TreeNode*, TreeNode*);

        vector<vector<string>> extraerServants(vector<vector<string>> &, string);
        vector<string> extraerDatos(vector<vector<string>>);
        void add(vector<vector<string>>);
        bool find(vector<string>);
        void remove(vector<string>);
        void removeChilds();
        void inorder(std::stringstream&) const;
        void preorder(std::stringstream&) const;
};

vector<vector<string>> TreeNode::extraerServants(vector<vector<string>> &listaServants, string clase){
    vector<vector<string>> listaPorClase;

    for(int i=0; i < listaServants.size(); i++){
        
    }
}

#endif