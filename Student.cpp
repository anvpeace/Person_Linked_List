#include "Student.h"
#include<iostream>
using namespace std;

Student::Student():Person(), major(""), gpa(0.0){};
Student::Student(int id, string name, string major, double gpa):Person(id, name), major(major), gpa(gpa){};

string Student::getMajor() const{return major;}
void Student::setMajor(string major){this->major = major;}

void Student::setGPA(double gpa){this->gpa = gpa;} //points to gpa of student class and allows the value to be modified
double Student::getGPA() const{return gpa;} 

void Student::display() {
    cout << *this << endl;
}

ostream& operator<<(ostream& out, const Student& s) {
    out << "Student - ID: " << s.id
        << ", Name: " << s.name
        << ", Major: " << s.major
        << ", GPA: " << s.gpa;
    return out;
}

void Student::updateDetails() {
    string major;
    double gpa;
    cout << "Enter major: ";
    getline(cin, major);
    cout << "Enter GPA: ";
    cin >> gpa;
    setMajor(major);
    setGPA(gpa);
}