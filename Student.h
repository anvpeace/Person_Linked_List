#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include<string>
using namespace std;

class Student:public Person{
    private:
        string major;
        double gpa; 
    public:
        Student(); 
        Student(int id, string name, string major, double gpa);

        // mutator functions
        string getMajor() const;
        void setMajor(string major);

        double getGPA() const override;
        void setGPA(double gpa);

        void display() override; 
        friend ostream& operator<<(ostream& out, const Student& s);

        // allows switch and case to update info
        void updateDetails();
};
#endif