#ifndef FACULTY_H
#define FACULTY_H
#include "Person.h"
#include<string>
using namespace std;

class Faculty : public Person{
private:
    string department;
    string title; 
    int salary; 
public:
    Faculty();
    Faculty(int id, string n, string d, string t, int s);

    void setTitle(string title);
    string getTitle() const;

    void setSalary(int salary);
    int getSalary() const;

    void setDepartment(string department);
    string getDepartment() const;

    void display() override;   
     
    friend ostream& operator<<(ostream& out, const Faculty& f);
    void updateDetails();

};
#endif