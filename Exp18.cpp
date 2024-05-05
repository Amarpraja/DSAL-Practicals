// Consider a scenario for Hospital to cater services to different kinds of patients as Serious
// (top priority), b) non-serious (medium priority), c) General Checkup (Least priority).
// Implement the priority queue to cater services to the patients.

#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Structure to represent a patient
struct Patient
{
    string name;
    int priority; // 1: Serious, 2: Non-serious, 3: General Checkup

    // Constructor to initialize a patient
    Patient(string n, int p) : name(n), priority(p) {}

    // Overloading < operator for comparison in priority queue
    bool operator<(const Patient &other) const
    {
        // Higher priority patients should be at the front of the priority queue
        return priority > other.priority;
    }
};

int main()
{
    priority_queue<Patient> patientQueue;

    int choice;
    string name;
    int priority;

    do
    {
        cout << "\n----- Menu -----" << endl;
        cout << "1. Add a serious patient" << endl;
        cout << "2. Add a non-serious patient" << endl;
        cout << "3. Add a general checkup patient" << endl;
        cout << "4. Serve next patient" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the name of the serious patient: ";
            cin >> name;
            patientQueue.push(Patient(name, 1));
            break;
        case 2:
            cout << "Enter the name of the non-serious patient: ";
            cin >> name;
            patientQueue.push(Patient(name, 2));
            break;
        case 3:
            cout << "Enter the name of the patient for general checkup: ";
            cin >> name;
            patientQueue.push(Patient(name, 3));
            break;
        case 4:
            if (patientQueue.empty())
            {
                cout << "No patients in the queue." << endl;
            }
            else
            {
                Patient nextPatient = patientQueue.top();
                cout << "Serving patient: " << nextPatient.name << endl;
                patientQueue.pop();
            }
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
