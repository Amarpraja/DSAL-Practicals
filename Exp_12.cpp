// Company maintains employee information as employee ID, name, designation and salary. 
// Allow user to add, delete information of employee. Display information of particular 
// employee. If employee does not exist an appropriate message is displayed. If it is, then 
// the system displays the employee details. Use index sequential file to maintain the data
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

const string DATA_FILE = "employee_data.txt";
const string INDEX_FILE = "employee_index.txt";

struct Employee {
    int employeeID;
    string name;
    string designation;
    double salary;
};

void addEmployee(const Employee& emp) {
    ofstream dataFile(DATA_FILE, ios::app);
    ofstream indexFile(INDEX_FILE, ios::app);

    if (!dataFile || !indexFile) {
        cerr << "Error opening files!" << endl;
        return;
    }

    dataFile << emp.employeeID << " " << emp.name << " " << emp.designation << " " << emp.salary << endl;
    indexFile << emp.employeeID << " " << dataFile.tellp() << endl;

    cout << "Employee record added successfully." << endl;

    dataFile.close();
    indexFile.close();
}

void deleteEmployee(int employeeID) {
    ifstream indexFile(INDEX_FILE);
    ofstream tempFile("temp_index.txt");

    if (!indexFile || !tempFile) {
        cerr << "Error opening files!" << endl;
        return;
    }

    int id;
    long pos;
    while (indexFile >> id >> pos) {
        if (id != employeeID) {
            tempFile << id << " " << pos << endl;
        }
    }

    indexFile.close();
    tempFile.close();

    remove(INDEX_FILE.c_str());
    rename("temp_index.txt", INDEX_FILE.c_str());
}

void displayEmployee(int employeeID) {
    ifstream indexFile(INDEX_FILE);
    ifstream dataFile(DATA_FILE);

    if (!indexFile || !dataFile) {
        cerr << "Error opening files!" << endl;
        return;
    }

    int id;
    long pos;
    while (indexFile >> id >> pos) {
        if (id == employeeID) {
            dataFile.seekg(pos);
            string line;
            getline(dataFile, line);
            cout << "Line from file: " << line << endl; // Print the line read from the file
            stringstream ss(line);
            Employee emp;
            string field;
            getline(ss, field, ' ');  // Read employee ID
            emp.employeeID = stoi(field);
            getline(ss, emp.name, ' ');  // Read name
            getline(ss, emp.designation, ' ');  // Read designation
            getline(ss, field);  // Read salary
            emp.salary = stod(field);
            cout << "Employee Record:" << endl;
            cout << "Employee ID: " << emp.employeeID << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Designation: " << emp.designation << endl;
            cout << "Salary: " << emp.salary << endl;
            return;
        }
    }

    cout << "Employee record with ID " << employeeID << " not found." << endl;

    indexFile.close();
    dataFile.close();
}




int main() {
    int choice;
    do {
        cout << "\nEmployee Information System" << endl;
        cout << "1. Add Employee Record" << endl;
        cout << "2. Delete Employee Record" << endl;
        cout << "3. Display Employee Record" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                Employee newEmployee;
                cout << "Enter Employee ID: ";
                cin >> newEmployee.employeeID;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, newEmployee.name);
                cout << "Enter Designation: ";
                getline(cin, newEmployee.designation);
                cout << "Enter Salary: ";
                cin >> newEmployee.salary;
                addEmployee(newEmployee);
                break;
            }
            case 2: {
                int employeeID;
                cout << "Enter Employee ID to delete: ";
                cin >> employeeID;
                deleteEmployee(employeeID);
                break;
            }
            case 3: {
                int employeeID;
                cout << "Enter Employee ID to display: ";
                cin >> employeeID;
                displayEmployee(employeeID);
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
