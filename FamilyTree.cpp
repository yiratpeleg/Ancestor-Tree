#include "FamilyTree.hpp"
#include <iostream>
using namespace family;



Tree& Tree::addFather(string name, string father){
    addInOrder(this->root,name,father,0);
    return *this;
}

Tree& Tree::addMother(string name, string mother){
    addInOrder(this->root,name,mother,1);
    return *this;
}
string Tree:: relation(string name){
    return "relation";
}
string Tree::find(string name){
    return "find";
}
void Tree::remove(string name){

}
void Tree::display(){

}

void addInOrder(Node* root ,string name, string toAdd,int sex){
    if(sex==0 && root->getName()==name && root->getFather()==NULL){
        root->setNode(toAdd,sex);
        return;
    }
    if(sex==1 && root->getName()==name && root->getMother()==NULL){
        root->setNode(toAdd,sex);
        return;
    }
    if(root!=NULL){
        addInOrder(root->getMother(), name, toAdd, sex);
        addInOrder(root->getFather(), name, toAdd, sex);
    }
    return;
}

