#ifndef PERSON_H
#define PERSON_H
#include<string>
using namespace std;

class Person{ 
    public:
        Person(); 
        Person(int id, string n);
        virtual ~Person(); 
        
        void setName(string n);
        string getName() const;
        int getID() const; 

        virtual void updateDetails() = 0; 
        virtual void display()=0; 

        // Default for non-students
        virtual double getGPA() const { return 0.0; }  


    protected:
        int id;
        string name;

};
#endif