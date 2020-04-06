#include "doctest.h"
#include "FamilyTree.hpp"
#include <iostream>
using namespace std;
using namespace family;


TEST_CASE("we check"){
    Tree p("hello");
    for (int i = 0; i <100 ; ++i) {
        CHECK(p.relation("Terah")==string("relation"));
    }

};