#include"Faculty.h"
#include<iostream>
using namespace std;

Faculty::Faculty():Person(), department(""), title(""), salary(0){};
Faculty::Faculty(int id, string n, string d, string t, int s):Person(id, n), department(d), title(t), salary(s){};

void Faculty::setDepartment(string department){this->department = department;}
void Faculty::setTitle(string title){this->title = title;}
void Faculty::setSalary(int salary){this->salary = salary;}

string Faculty::getDepartment() const{return department;}
string Faculty::getTitle() const{return title;}
int Faculty::getSalary() const{return salary;}

void Faculty::display() {
    // reuses operatot<<
    cout << *this << endl;
}

ostream& operator<<(ostream& out, const Faculty& f) {
    out << "Faculty - ID: " << f.id
        << ", Name: " << f.name
        << ", Dept: " << f.department
        << ", Title: " << f.title
        << ", Salary: $" << f.salary;
    return out;
}


void Faculty::updateDetails(){
    string department, title;
    int salary;
    cout << "Enter department: ";
    getline(cin, department);
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter salary: ";
    cin >> salary;
    setDepartment(department);
    setTitle(title);
    setSalary(salary);
};