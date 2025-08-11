#include "LinkedList.h"
#include "Student.h"
#include "Faculty.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

LinkedList::LinkedList():head(nullptr) {}

// destructor
LinkedList::~LinkedList() {
    // starts from first node in the list
    ListNode<Person*>* current = head;
    while (current != nullptr) {
        ListNode<Person*>* temp = current; //looops through very node until the end is reached
        current = current->next;//stores current node in a temp value
        delete temp->data;//avoid memory leak - moving to the next node before delting the next one
        delete temp;
    }
}

void LinkedList::insert(Person* data) { //points to base class for student or faculty
    ListNode<Person*>* newNode = new ListNode<Person*>(data); //dynmically create new node that stores the data from the person
    if (head == nullptr) { //if the pointer is empty the node is set at the start
        head = newNode;
    } else {
        // else the go through the list 
        ListNode<Person*>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;// sets next pointer to the new node
    }
}

void LinkedList::display() {
    ListNode<Person*>* current = head; //makes the current node set at the start
    while (current != nullptr) {
        current->data->display();
        current = current->next;
    }
}

Person* LinkedList::search(int id) {
    ListNode<Person*>* current = head;
    while (current != nullptr) {
        if (current->data->getID() == id) {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
}

Person* LinkedList::search(string firstName, string lastName) {
    string fullName = firstName + " " + lastName;
    ListNode<Person*>* current = head;
    while (current != nullptr) {
        if (current->data->getName() == fullName) {
            return current->data;
        }
        current = current->next;
    }
    return nullptr;
};

void LinkedList::update(int id) {
    Person* person = search(id);
    if (!person) {
        cout << "No person found with ID: " << id << endl;
        return;
    }

    cout << "Updating details for ID: " << id << endl;
    cin.ignore(); // flush newline
    string n;
    cout << "Enter new name: ";
    getline(cin, n);
    person->setName(n);

    // Let the object update itself
    person->updateDetails();
};

void LinkedList::remove(int id) {
    ListNode<Person*>* current = head;
    ListNode<Person*>* prev = nullptr;

    while (current != nullptr && current->data->getID() != id) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout <<"Person with ID "<< id <<" not found.\n";
        return;
    }

    if (prev == nullptr) {head = current->next;} 
    else {prev->next = current->next;}

    delete current->data;
    delete current;

    cout <<"Person with ID "<< id <<" has been removed.\n";
}

// STUDENT FUNCTIONS
void LinkedList::addStudentFromConsole() {
    int id;
    string name, major;
    double gpa;

    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter major: ";
    getline(cin, major);
    cout << "Enter GPA: ";
    cin >> gpa;

    Student* student = new Student(id, name, major, gpa);
    insert(student);
}


void LinkedList::addStudentsFromTxtFile(const string& filename) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }
    
    string idStr, name, major, gpaStr;

    while (getline(infile, idStr) &&
           getline(infile, name) &&
           getline(infile, major) &&
           getline(infile, gpaStr)) {

        int id = 0;
        double gpa = 0.0;

        {
            stringstream ss(idStr);
            ss >> id;
        }
        {
            stringstream ss(gpaStr);
            ss >> gpa;
        }

        Student* student = new Student(id, name, major, gpa);
        insert(student);  
    }

    infile.close();
}


// 
void LinkedList::addStudentsFromCSVFile(const string& filename) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    while (getline(infile, line)) {

        stringstream ss(line);
        string idStr, name, major, gpaStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, major, ',');
        getline(ss, gpaStr, ',');

        int id = 0;
        double gpa = 0.0;

        {
            stringstream conv(idStr);
            conv>> id;
        }
        {
            stringstream conv(gpaStr);
            conv >> gpa;          
        }

        Student* student = new Student(id, name, major, gpa);
        insert(student);
    }
    infile.close();
}

// FACULTY FUNCTIONS
void LinkedList :: addFacultyFromConsole(){
    int id;
    string name, department, title;
    int salary;

    cout << "Enter Faculty ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Faculty name: ";
    getline(cin, name);
    cout << "Enter Department: ";
    getline(cin, department);
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Salary: ";
    cin>> salary;      

    Faculty* faculty = new Faculty(id, name, department, title, salary);
    insert(faculty);
}

void LinkedList::addFacultyFromTxtFile(const string& filename) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }
        // int idStr;
    string idStr, name, department, title, salaryStr;

    while (getline(infile, idStr) &&
           getline(infile, name) &&
           getline(infile, department) &&
           getline(infile, title) &&
           getline(infile, salaryStr)) {

        int id = 0;
        double salary = 0.0;

        { stringstream ss(idStr); 
            ss >> id; 
        }
        { stringstream ss(salaryStr); 
            ss >> salary; 
        }

        Faculty* faculty = new Faculty(id, name, department, title, salary);
        insert(faculty);
    }

    infile.close();
}


void LinkedList::addFacultyFromCSVFile(const string& filename) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }
    string line;
    while (getline(infile, line)) {
        //split CSV lines by commas
        stringstream ss(line);
        string idStr, name, department, title, salaryStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, department, ',');
        getline(ss, title, ',');
        getline(ss, salaryStr, ',');


        int id = 0;
        double salary = 0.0;  

        {
            stringstream conv(idStr);
            conv >> id;
        }
        {
            stringstream conv(salaryStr);
            conv >> salary;
        }   
        

        Faculty* faculty = new Faculty(id, name, department, title, salary);
        insert(faculty);
    }
    infile.close();
}

// SORTING FUNCTIONS

void LinkedList::sortByID() {
    vector<Person*> people;
    ListNode<Person*>* current = head;

    // Copy to vector
    while (current != nullptr) {
        people.push_back(current->data);
        current = current->next;
    }

    // Sort by ID
    sort(people.begin(), people.end(), [](Person* a, Person* b) {
        return a->getID() < b->getID();
    });

    // RebuildS linked list
    current = head;
    for (Person* p : people) {
        current->data = p;
        current = current->next;
    }
};

void LinkedList::sortByName() {
    vector<Person*> people;
    ListNode<Person*>* current = head;

    while (current != nullptr) {
        people.push_back(current->data);
        current = current->next;
    }

    // .begin() and .end() sorts through forst and last element in a vector
    sort(people.begin(), people.end(), [](Person* a, Person* b) {
        return a->getName() < b->getName();
    });

    current = head;
    for (Person* p : people) {
        current->data = p;
        current = current->next;
    }
};

void LinkedList::sortByGPA() {
    vector<Person*> people;
    ListNode<Person*>* current = head;

    while (current != nullptr) {
        people.push_back(current->data);
        current = current->next;
    }

    sort(people.begin(), people.end(), [](Person* a, Person* b) {
        double gpaA = a->getGPA();
        double gpaB = b->getGPA();
        return gpaA > gpaB;
    });

    current = head;
    for (Person* p : people) {
        current->data = p;
        current = current->next;
    }
}

