#include "Person.h"

Person::Person():id(0), name(""){}
Person::Person(int id, string n): id(id), name(n){}
Person::~Person(){} 

void Person:: setName(string n){name = n;};
string Person::getName() const{return name;}

int Person::getID() const{return id;}