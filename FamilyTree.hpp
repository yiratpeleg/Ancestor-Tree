#pragma once
#include <string>
using namespace std;

class Node{
    string name;
    int sex;
    int height;
    Node * father;   //left side
    Node * mother;   //right side
public:
    Node(string name,int sex,int height){
        this->name=name;
        this->father=NULL;
        this->mother=NULL;
        this->sex=sex;
        this->height=height;
    }
    string getName(){
        return this->name;
    }
    Node* getMother(){
        return this->mother;
    }
    Node* getFather(){
        return this->father;
    }
    int getSex(){
        return this->sex;
    }
    int getHeight(){
        return this->height;
    }
    void setNode(string toAdd,int sex,int height){
        if(sex == 0) {
            Node *ans = new Node(toAdd,sex,height);
            this->father = ans;
        }
        else{
            Node* ans = new Node(toAdd,sex,height);
            this->mother=ans;
        }
    }
};

namespace family{
    class Tree {
        Node* root;
    public:
        Tree(string name) { this->root = new Node(name,0,0); }

        Tree& addFather(string name, string father);

        Tree& addMother(string name, string mother);

        string relation(string name);

        string find(string name);

        void remove(string name);

        void display();

        Node* getNode(){
            return this->root;
        }

        Tree& getTree() {
            return *this;
        }
    };
}
void addInOrder(Node* root,string name,string toAdd,int sex,int height);

void relationFind(Node * root, string name,int* height,int* sex);

void findRec(Node * root, string name,string& ans);
void printTree(Node* root, int space);



