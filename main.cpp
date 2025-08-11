#include "LinkedList.h"
#include <iostream>
using namespace std;

void showMenu() {
    cout << "\n===== Student Management Menu =====\n";
    cout << "1.  Add Student from Console\n";
    cout << "2.  Add Students from Text File (.txt)\n";
    cout << "3.  Add Students from CSV File (.csv)\n";
    cout << "4.  Add Faculty from Console\n";
    cout << "5.  Add Faculty from Text File (.txt)\n";
    cout << "6.  Add Faculty from CSV File (.csv)\n";
    cout << "7.  Display All Records\n";
    cout << "8.  Search by ID\n";
    cout << "9.  Update by ID\n";
    cout << "10. Delete by ID\n";
    cout << "11. Sort by ID\n";      
    cout << "12. Sort by Name\n";   
    cout << "13. Sort by GPA (Students Only)\n"; 
    cout << "14. Exit\n";
    cout << "Select an option: ";
}


int main() {
    LinkedList list;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                list.addStudentFromConsole();
                break;
            case 2: {
                string filename;
                cout << "Enter .txt filename: ";
                cin >> filename;
                list.addStudentsFromTxtFile(filename);
                break;
            }
            case 3: {
                string filename;
                cout << "Enter .csv filename: ";
                cin >> filename;
                list.addStudentsFromCSVFile(filename);
                break;
            }
            case 4:
                list.addFacultyFromConsole();
                break;
            case 5:{
                string filename;
                cout << "Enter .txt filename: ";
                cin >> filename;
                list.addFacultyFromTxtFile(filename);
                break;
            }
            case 6:{
                string filename;
                cout << "Enter .csv filename: ";
                cin >> filename;
                list.addFacultyFromCSVFile(filename);
                break;
            }
            case 7:
                list.display();
                break;
            case 8: {
                int id;
                cout << "Enter ID to search: ";
                cin >> id;
                if (Person* p = list.search(id)) {
                    p->display();
                } else {
                    cout << "Record not found.\n";
                }
                break;
            }
            case 9: {
                int id;
                cout << "Enter ID to update: ";
                cin >> id;
                list.update(id);
                cout<<"Updated List: ID Updated \n";
                list.display();
                break;
            }
            case 10: {
                int id;
                cout << "Enter ID to delete: ";
                cin >> id;
                list.remove(id);
                cout<<"Updated List: ID Removed \n";
                list.display();
                break;
            }
            case 11: {
                list.sortByID();
                cout << "Sorted by ID \n";
                list.display();
                break;
            }
            case 12:{
                list.sortByName();
                cout << "Sorted by Name.\n";
                list.display();
                break;
            }
            case 13:
                list.sortByGPA();
                cout << "Sorted by GPA (Students only).\n";
                list.display();
                break;
            case 14:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 14);

    return 0;
}