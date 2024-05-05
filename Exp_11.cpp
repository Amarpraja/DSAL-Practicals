// Department maintains a student information. The file contains roll number, name, 
// division and address. Allow user to add, delete information of student. Display 
// information of particular employee. If record of student does not exist an appropriate 
// message is displayed. If it is, then the system displays the student details. Use sequential 
// file to main the data.


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

// Structure to represent a student
struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

// Function to add a new student record to the file
void addStudent(const Student& student) {
    ofstream file("student_records.txt", ios::app); // Open file in append mode

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    file << student.rollNumber << " " << student.name << " " << student.division << " " << student.address << endl;
    cout << "Student record added successfully." << endl;

    file.close();
}

// Function to delete a student record from the file
void deleteStudent(int rollNumber) {
    ifstream inFile("student_records.txt");
    ofstream outFile("temp.txt");

    if (!inFile || !outFile) {
        cout << "Error opening file!" << endl;
        return;
    }

    bool found = false;
    string line;
    while (getline(inFile, line)) {
        stringstream ss(line);
        int roll;
        ss >> roll;
        if (roll != rollNumber) {
            outFile << line << endl;
        } else {
            found = true;
        }
    }

    inFile.close();
    outFile.close();

    remove("student_records.txt");
    rename("temp.txt", "student_records.txt");

    if (found) {
        cout << "Student record with roll number " << rollNumber << " deleted successfully." << endl;
    } else {
        cout << "Student record with roll number " << rollNumber << " not found." << endl;
    }
}

// Function to display information of a particular student
void displayStudent(int rollNumber) {
    ifstream file("student_records.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    bool found = false;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        int roll;
        ss >> roll;
        if (roll == rollNumber) {
            found = true;
            cout << "Student Record:" << endl;
            cout << line << endl;
            break;
        }
    }

    if (!found) {
        cout << "Student record with roll number " << rollNumber << " not found." << endl;
    }

    file.close();
}

int main() {
    int choice;
    do {
        cout << "\nStudent Information System" << endl;
        cout << "1. Add Student Record" << endl;
        cout << "2. Delete Student Record" << endl;
        cout << "3. Display Student Record" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Student newStudent;
                cout << "Enter Roll Number: ";
                cin >> newStudent.rollNumber;
                cin.ignore(); // Clear input buffer
                cout << "Enter Name: ";
                getline(cin, newStudent.name);
                cout << "Enter Division: ";
                getline(cin, newStudent.division);
                cout << "Enter Address: ";
                getline(cin, newStudent.address);
                addStudent(newStudent);
                break;
            }
            case 2: {
                int rollNumber;
                cout << "Enter Roll Number to delete: ";
                cin >> rollNumber;
                deleteStudent(rollNumber);
                break;
            }
            case 3: {
                int rollNumber;
                cout << "Enter Roll Number to display: ";
                cin >> rollNumber;
                displayStudent(rollNumber);
                break;
            }
            case 4: {
                cout << "Exiting program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please try again." << endl;
            }
        }
    } while (choice != 4);

    return 0;
}
