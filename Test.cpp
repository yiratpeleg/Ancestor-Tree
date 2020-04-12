#include "doctest.h"
#include "FamilyTree.hpp"
#include <iostream>
using namespace std;
using namespace family;
void BuildTree(Tree T);


    static Tree T("Orian");
    void BuildTree(Tree T) {
        T.addFather("Orian", "Yair")
                .addMother("Orian", "Yardena")
                .addFather("Yair", "Yosef")
                .addMother("Yair", "Shosana")
                .addFather("Yardena", "Moshe")
                .addMother("Yardena", "Mazal")
                .addFather("Yosef", "Avi")
                .addMother("Yosef", "Rachel")
                .addFather("Shosana", "Yakov")
                .addMother("Shosana", "Lea")
                .addFather("Moshe", "Itizk")
                .addMother("Moshe", "Tzipi")
                .addFather("Mazal", "Nati")
                .addMother("Mazal", "Mali")
                .addFather("Avi", "Udi")
                .addMother("Avi", "Bracha")
                .addFather("Rachel", "Shimon")
                .addMother("Rachel", "Batel")
                .addFather("Yakov", "Roei")
                .addMother("Yakov", "Batia")
                .addFather("Lea", "Yarin")
                .addMother("Lea", "Liel")
                .addFather("Itzik", "Yizhak")
                .addMother("Itzik", "Sahar")
                .addFather("Tzipi", "Noam")
                .addMother("Tzipi", "May")
                .addFather("Nati", "Nitay")
                .addMother("Nati", "Meytal")
                .addFather("Mali", "Neria")
                .addMother("Mali", "Reut");
    }


TEST_CASE("addFather"){
    BuildTree(T);
    CHECK(T.relation("Yair")==string("father"));
    CHECK(T.relation("Yosef")==string("grandfather"));
    CHECK(T.relation("Avi")==string("great-grandfather"));
    CHECK(T.relation("Udi")==string("great-great-grandfather"));
    CHECK(T.relation("Shimon")==string("great-great-grandfather"));
    CHECK(T.relation("Yakov")==string("great-grandfather"));
    CHECK(T.relation("Roei")==string("great-great-grandfather"));
    CHECK(T.relation("Yarin")==string("great-great-grandfather"));
    CHECK(T.relation("Moshe")==string("grandfather"));
    CHECK(T.relation("Itzik")==string("great-grandfather"));
    CHECK(T.relation("Nati")==string("great-grandfather"));
    CHECK(T.relation("Yizhak")==string("great-great-grandfather"));
    CHECK(T.relation("Noam")==string("great-great-grandfather"));
    CHECK(T.relation("Nitay")==string("great-great-grandfather"));
    CHECK(T.relation("Neria")==string("great-great-grandfather"));

};

TEST_CASE("addMother function"){
    CHECK(T.relation("Yardena")==string("mother"));
    CHECK(T.relation("Mazal")==string("grandmother"));
    CHECK(T.relation("Shosana")==string("grandmother"));
    CHECK(T.relation("Rachel")==string("great-grandmother"));
    CHECK(T.relation("Lea")==string("great-grandmother"));
    CHECK(T.relation("Bracha")==string("great-great-grandmother"));
    CHECK(T.relation("Batel")==string("great-great-grandmother"));
    CHECK(T.relation("Batia")==string("great-great-grandmother"));
    CHECK(T.relation("Liel")==string("great-great-grandmother"));
    CHECK(T.relation("Sahar")==string("great-great-grandmother"));
    CHECK(T.relation("May")==string("great-great-grandmother"));
    CHECK(T.relation("Meytal")==string("great-great-grandmother"));
    CHECK(T.relation("Reut")==string("great-great-grandmother"));
    CHECK(T.relation("Tzipi")==string("great-grandmother"));
    CHECK(T.relation("Mali")==string("great-grandmother"));

};

TEST_CASE("relation function"){
    CHECK(T.relation("Yardena")==string("mother"));
    CHECK(T.relation("Mazal")==string("grandmother"));
    CHECK(T.relation("Shosana")==string("grandmother"));
    CHECK(T.relation("Rachel")==string("great-grandmother"));
    CHECK(T.relation("Lea")==string("great-grandmother"));
    CHECK(T.relation("Bracha")==string("great-great-grandmother"));
    CHECK(T.relation("Batel")==string("great-great-grandmother"));
    CHECK(T.relation("Batia")==string("great-great-grandmother"));
    CHECK(T.relation("Liel")==string("great-great-grandmother"));
    CHECK(T.relation("Sahar")==string("great-great-grandmother"));
    CHECK(T.relation("May")==string("great-great-grandmother"));
    CHECK(T.relation("Meytal")==string("great-great-grandmother"));
    CHECK(T.relation("Reut")==string("great-great-grandmother"));
    CHECK(T.relation("Tzipi")==string("great-grandmother"));
    CHECK(T.relation("Mali")==string("great-grandmother"));
    CHECK(T.relation("Yair")==string("father"));
    CHECK(T.relation("Yosef")==string("grandfather"));
    CHECK(T.relation("Avi")==string("great-grandfather"));
    CHECK(T.relation("Udi")==string("great-great-grandfather"));
    CHECK(T.relation("Shimon")==string("great-great-grandfather"));
    CHECK(T.relation("Yakov")==string("great-grandfather"));
    CHECK(T.relation("Roei")==string("great-great-grandfather"));
    CHECK(T.relation("Yarin")==string("great-great-grandfather"));
    CHECK(T.relation("Moshe")==string("grandfather"));
    CHECK(T.relation("Itzik")==string("great-grandfather"));
    CHECK(T.relation("Nati")==string("great-grandfather"));
    CHECK(T.relation("Yizhak")==string("great-great-grandfather"));
    CHECK(T.relation("Noam")==string("great-great-grandfather"));
    CHECK(T.relation("Nitay")==string("great-great-grandfather"));
    CHECK(T.relation("Neria")==string("great-great-grandfather"));
    CHECK(T.relation("Orian")==string("me"));
    CHECK_THROWS(T.relation("abra")==string("unrelated"));
    CHECK_THROWS(T.relation("xyz")==string("unrelated"));
    CHECK_THROWS(T.relation("us")==string("unrelated"));
    CHECK_THROWS(T.relation("Yirat")==string("unrelated"));
    CHECK_THROWS(T.relation("notHERE")==string("unrelated"));
};

TEST_CASE("find function"){
    CHECK(T.find("me")==string("Orian"));
    CHECK(T.find("father")==string("Yair"));
    CHECK(T.find("mother")==string("Yardena"));
    CHECK((T.find("grandmother")==string("Mazal") || T.find("grandmother")==string("Shosana")) );
    CHECK((T.find("grandfather")==string("Yosef") || T.find("grandfather")==string("Moshe")) );
    CHECK(T.find("great-grandmother")==string("Rachel") || T.find("great-grandmother")==string("Lea") || T.find("great-grandmother")==string("Tzipi") || T.find("great-grandmother")==string("Mali"));
    CHECK(T.find("great-grandfather")==string("Avi") || T.find("great-grandfather")==string("Yakov") || T.find("great-grandfather")==string("Itzik") || T.find("great-grandfather")==string("Nati"));
    CHECK((T.find("great-great-grandmother")==string("Reut") || T.find("great-great-grandmother")==string("Meytal") || T.find("great-great-grandmother")==string("May") || T.find("great-great-grandmother")==string("Liel") || T.find("great-great-grandmother")==string("Sahar") || T.find("great-great-grandmother")==string("Batel") || T.find("great-great-grandmother")==string("Batia") || T.find("great-great-grandmother")==string("Bracha"));
    CHECK((T.find("great-great-grandfather")==string("Udi") || T.find("great-great-grandfather")==string("Shimon") || T.find("great-great-grandfather")==string("Roei") || T.find("great-great-grandfather")==string("Yarin") || T.find("great-great-grandfather")==string("Noam") || T.find("great-great-grandfather")==string("Yizhak") || T.find("great-great-grandfather")==string("Nitay") || T.find("great-great-grandfather")==string("Neria"));

};

TEST_CASE("remove function"){
    T.remove("Udi");
    T.remove("Shimon");
    T.remove("Roei");
    T.remove("Yarin");
    T.remove("Noam");
    T.remove("Yizhak");
    T.remove("Nitay");
    T.remove("Neria");
    T.remove("Reut");
    T.remove("Meytal");
    T.remove("May");
    T.remove("Liel");
    T.remove("Sahar");
    T.remove("Batel");
    T.remove("Batia");
    T.remove("Bracha");
    T.remove("Avi");
    T.remove("Yakov");
    T.remove("Itzik");
    T.remove("Nati");
    T.remove("Rachel");
    T.remove("Lea");
    T.remove("Tzipi");
    T.remove("Mali");
    T.remove("Yosef");
    T.remove("Moshe");
    T.remove("Mazal");
    T.remove("Shosana");
    T.remove("Yardena");
    T.remove("Yair");
    CHECK(T.relation("Yair")==string("unrelated"));
    CHECK(T.relation("Yardena")==string("unrelated"));
    CHECK(T.relation("Moshe")==string("unrelated"));
    CHECK(T.relation("Mazal")==string("unrelated"));
    CHECK(T.relation("Yosef")==string("unrelated"));
    CHECK(T.relation("Shosana")==string("unrelated"));
    CHECK(T.relation("Avi")==string("unrelated"));
    CHECK(T.relation("Rachel")==string("unrelated"));
    CHECK(T.relation("Yakov")==string("unrelated"));
    CHECK(T.relation("Lea")==string("unrelated"));
    CHECK(T.relation("Itzik")==string("unrelated"));
    CHECK(T.relation("Tzipi")==string("unrelated"));
    CHECK(T.relation("Nati")==string("unrelated"));
    CHECK(T.relation("Mali")==string("unrelated"));
    CHECK(T.relation("Udi")==string("unrelated"));
    CHECK(T.relation("Bracha")==string("unrelated"));
    CHECK(T.relation("Shimon")==string("unrelated"));
    CHECK(T.relation("Batel")==string("unrelated"));
    CHECK(T.relation("Roei")==string("unrelated"));
    CHECK(T.relation("Batia")==string("unrelated"));
    CHECK(T.relation("Yarin")==string("unrelated"));
    CHECK(T.relation("Liel")==string("unrelated"));
    CHECK(T.relation("Yizhak")==string("unrelated"));
    CHECK(T.relation("Sahar")==string("unrelated"));
    CHECK(T.relation("Noam")==string("unrelated"));
    CHECK(T.relation("May")==string("unrelated"));
    CHECK(T.relation("Nitay")==string("unrelated"));
    CHECK(T.relation("Meytal")==string("unrelated"));
    CHECK(T.relation("Neria")==string("unrelated"));
    CHECK(T.relation("Reut")==string("unrelated"));

};

TEST_CASE("display function"){

};
