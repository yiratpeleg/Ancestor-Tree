#pragma once
#include <string>
using namespace std;

class Node{
    string name;
    Node * father;   //left side
    Node * mother;   //right side
public:
    Node(string name){
        this->name=name;
        this->father=NULL;
        this->mother=NULL;
    }
    string getName(){
        return this->name;
    }
};

namespace family{
    class Tree {
        Node* root;
    public:
        Tree(string name) { this->root = new Node(name); }

        Tree& addFather(string name, string father);

        Tree& addMother(string name, string mother);

        string relation(string name);

        string find(string name);

        void remove(string name);

        void display();

        Tree& getTree() {
            return *this;
        }
    };


}


