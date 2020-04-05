#include "FamilyTree.hpp"
#include <iostream>
using namespace family;



int main(){
    family::Tree p("orian");
    cout<< p.getTree()->getName();

    return 0;
}

