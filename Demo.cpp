/**
 * Demo for Family Tree
 * 
 * First version by Adam Lev-Ari,  2019-12
 * Second version by Erel Segal-Halevi, 2020-04
 */

#include "FamilyTree.hpp"

#include <iostream>
using namespace std;


int main() {
	family::Tree T ("Yosef");// Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addMother("Rachel","Rivka")
	 .addFather("Rachel","Yoni")
	 .addFather("Yoni","Shlomi")
	 .addMother("Yoni","Vered");
//	 .addMother("Yaakov", "Rivka")
//	 .addFather("Isaac", "Avraham")
//	 .addMother("Isaac","Sara")
//	 .addFather("Avraham", "Terah")
//	 .addFather("Rivka","Betuel")
//	 .addFather("Rachel","Lavan")
//	 .addFather("Sara","Haran")
//	 .addFather("Betuel","Nahor")
//	 .addMother("Betuel","Milca");
//
//	T.remove("Betuel");
//
//     cout<<T.find("great-great-grandmother")<<endl;
//    cout<<T.find("great-great-great-grandmother")<<endl;

T.remove("Rachel");
T.remove("Yaakov");
T.display();
	cout<<T.relation("Yaakov")<<endl;

//	T.display();                        // displays the tree in a human-friendly format.
//	cout << T.relation("Yaakov") << endl;  // prints "father"
//	cout << T.relation("Rachel") << endl;  // prints "mother"
//	cout << T.relation("Rivka") << endl;  // prints "grandmother"
//	cout << T.relation("Avraham") << endl;  // prints "great-grandfather"
//	cout << T.relation("Terah") << endl;  // prints "great-great-grandfather"
//	cout << T.relation("livnat") << endl;  // prints "unrelated"
//	cout << T.relation("Yosef") << endl;  // prints "me"
//
//	cout << T.find("mother") << endl;  // prints "Rachel"
//	cout << T.find("great-great-grandfather") << endl;  // prints "Terah"
//	cout<<T.find("great-grandmother")<<endl;
//
//
//	try {
//		cout << T.find("zd") << endl;  // throws an exception
//	} catch (const exception& ex) {
//	 	cout << ex.what() << endl;  // prints "The tree cannot handle the 'uncle' relation"
//	}
//
//	T.remove("Avraham"); // removes Avraham and Terah
//	cout << T.relation("Terah") << endl;  // prints "unrelated"

    return 0;
}
