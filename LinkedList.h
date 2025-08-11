#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"
#include "Person.h"
#include <string>
using namespace std;

class LinkedList {
private:
    ListNode<Person*>* head;

public:
    LinkedList();
    ~LinkedList();

    void insert(Person* data);
    void display();
    Person* search(int id);
    Person* search(string firstName, string lastName);
    void update(int id);
    void remove(int id);

    void addStudentFromConsole();
    void addStudentsFromTxtFile(const string& filename);
    void addStudentsFromCSVFile(const string& filename);

    void addFacultyFromConsole();
    void addFacultyFromTxtFile(const string& filename);
    void addFacultyFromCSVFile(const string& filename);

    void sortByID();
    void sortByName();
    void sortByGPA();

};

#endif