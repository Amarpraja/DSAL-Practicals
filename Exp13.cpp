#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee {
 int id;
 string name;
 string designation;
 double salary;
};

void addEmployee(fstream &file) {
 Employee emp;
 cout << "Enter employee ID: ";
 cin >> emp.id;
 cout << "Enter employee name: ";
 cin.ignore();
 getline(cin, emp.name);
 cout << "Enter employee designation: ";
 getline(cin, emp.designation);
 cout << "Enter employee salary: ";
 cin >> emp.salary;
 file.seekp(0, ios::end);
 file.write(reinterpret_cast<char*>(&emp), sizeof(Employee));
}

void deleteEmployee(fstream &file, int id) {
 file.seekg(0);
 Employee emp;
 while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
  if (emp.id == id) {
   file.seekp(file.tellp() - sizeof(Employee));
   file.write(reinterpret_cast<char*>(&emp), sizeof(Employee));
   cout << "Employee deleted successfully!" << endl;
   return;
  }
 }
 cout << "Employee not found!" << endl;
}

void displayEmployee(fstream &file, int id) {
 file.seekg(0);
 Employee emp;
 while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
  if (emp.id == id) {
   cout << "Employee ID: " << emp.id << endl;
   cout << "Employee name: " << emp.name << endl;
   cout << "Employee designation: " << emp.designation << endl;
   cout << "Employee salary: " << emp.salary << endl;
   return;
  }
 }
 cout << "Employee not found!" << endl;
}

int main() {
 fstream file("employee.dat", ios::in | ios::out | ios::binary | ios::trunc);
 int choice, id;
 while (true) {
  cout << "1. Add employee" << endl;
  cout << "2. Delete employee" << endl;
  cout << "3. Display employee" << endl;
  cout << "4. Exit" << endl;
  cout << "Enter your choice: ";
  cin >> choice;
  switch (choice) {
   case 1:
    addEmployee(file);
    break;
   case 2:
    cout << "Enter employee ID to delete: ";
    cin >> id;
    deleteEmployee(file, id);
    break;
   case 3:
    cout << "Enter employee ID to display: ";
    cin >> id;
    displayEmployee(file, id);
    break;
   case 4:
    return 0;
  }
 }
}