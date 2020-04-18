#include "FamilyTree.hpp"
#include <iostream>
using namespace family;
#define COUNT 10

Tree& Tree::addFather(string name, string father){
    int check=0;
    addInOrder(this->root,name,father,0,1,&check);
    if(check==0) throw runtime_error("Cant find the name in the tree.");
    return *this;
}

Tree& Tree::addMother(string name, string mother){
    int check =0;
    addInOrder(this->root,name,mother,1,1,&check);
    if(check==0) throw runtime_error("Cant find the name in the tree.");
    return *this;
}

string Tree:: relation(string name){
    if(this->root->getName()==name)return "me";
    if(this->root->getMother()!=NULL &&this->root->getMother()->getName()==name) return "mother";
    if(this->root->getFather()!=NULL && this->root->getFather()->getName()==name) return "father";
    string ans = "";
    string temp = "great-";
    int height=-1;
    int sex =-1;
    relationFind(this->root,name,&height,&sex);
    if(height==-1 && sex==-1) return "unrelated";
    height=height-2;
    while (height>0){
        ans=temp+ans;
        height--;
    }
    if(sex==0){
        ans = ans+"grandfather";
    }
    else ans = ans+"grandmother";
    return ans;
}

string Tree::find(string name){
    if(name=="me") return this->root->getName();
    if(name=="mother" && this->root->getMother()!=NULL ) return this->root->getMother()->getName();
    if(name=="father" && this->root->getFather()!=NULL) return this->root->getFather()->getName();
    string temp ="";
    string& ans=temp;
    findRec(this->root, name,ans);
    if(ans== "") throw runtime_error("Cant find in the tree.");
    return ans;
}

void Tree::remove(string name) {
    if (this->root->getName() == name) throw runtime_error("Cant delete root");
    Node *toRemove = NULL;
    Node *runner = NULL;
    findSubTree(this->root, name, &toRemove); //find the subtree we want to delete.
    if (toRemove == NULL) throw runtime_error("The name is'nt in the Tree");
    if (toRemove->getMother()!=NULL && toRemove->getMother()->getName() == name){
        runner = toRemove->getMother();
        deleteSubTree(runner);
        toRemove->setMotherNull();
    }
    if (toRemove->getFather()!=NULL && toRemove->getFather()->getName() == name) {
        runner = toRemove->getFather();
        deleteSubTree(runner);
        toRemove->setFatherNull();
    }
  //  deleteSubTree(runner);
}

void Tree::display(){
    printTree(this->root,0);
}

void addInOrder(Node* root ,string name, string toAdd,int sex,int height,int* check){
    if(root==NULL) return;
    if(sex==0 && root->getName()==name && root->getFather()!=NULL){
        throw runtime_error("Father already exist.");
    }
    if(sex==1 && root->getName()==name && root->getMother()!=NULL){
        throw runtime_error("Mother already exist.");
    }
    if(sex==0 && root->getName()==name && root->getFather()==NULL){
        *check=1;
        root->setNode(toAdd,sex,height);
        return;
    }
    if(sex==1 && root->getName()==name && root->getMother()==NULL){
        *check=1;
        root->setNode(toAdd,sex,height);
        return;
    }
    if(root!=NULL){
        addInOrder(root->getMother(), name, toAdd, sex,height+1,check);
        addInOrder(root->getFather(), name, toAdd, sex,height+1,check);
    }
}

void relationFind(Node * root, string name,int* height,int* sex){
    if(root==NULL) return;
    if(root->getName()==name){
        *(height)=root->getHeight();
        *(sex)=root->getSex();
        return;
    }
    relationFind(root->getMother(), name,height,sex);
    relationFind(root->getFather(), name,height,sex);
}

void findRec(Node * root, string name,string &ans) {
    if(root==NULL) return;
    if (root->getMother()!=NULL && name == "grandmother" && root->getMother()->getMother() != NULL) {
        ans = root->getMother()->getMother()->getName();
        return;
    } else if ( root->getFather()!=NULL && name == "grandmother" && root->getFather()->getMother() != NULL) {
        ans = root->getFather()->getMother()->getName();
        return;
    } else if (root->getFather()!=NULL && name == "grandfather" && root->getFather()->getFather() != NULL) {
        ans = root->getFather()->getFather()->getName();
        return;
    } else if (root->getMother()!=NULL && name == "grandfather" && root->getMother()->getFather() != NULL) {
        ans = root->getMother()->getFather()->getName();
        return;
    }
    if((name!="grandmother" && name!="grandfather") && (name.length()<6 || name.substr(0,6)!="great-")) throw runtime_error("The tree cannot handle this relation");
    if((name!="grandmother" && name!="grandfather"))findRec(root->getFather(), name.substr(6), ans);
    if((name!="grandmother" && name!="grandfather")&& ans=="")findRec(root->getMother(), name.substr(6), ans);
}

void printTree(Node* root,int space){
    if(root==NULL) return;
    space+=COUNT;
    printTree(root->getMother(),space);
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->getName()<<"\n";
    printTree(root->getFather(),space);
}

void findSubTree(Node * root, string name, Node** runner){
    if(root==NULL) return;
    if((root->getMother()!=NULL && root->getMother()->getName()==name )||(root->getFather()!=NULL && root->getFather()->getName()==name)){
        *(runner) = root;
        return;
    }
    findSubTree(root->getMother(), name,runner);
    findSubTree(root->getFather(), name,runner);
}
void deleteSubTree(Node* root){
    if(root!= NULL){
        deleteSubTree(root->getFather());
        deleteSubTree(root->getMother());
        delete root;
    }
}

