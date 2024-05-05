// Read the marks obtained by students of second year in an online examination of
// particular subject. Find out maximum and minimum marks obtained in that subject. Use
// heap data structure. Analyze the algorithm.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    vector<int> marks;
    int choice, mark;

    do
    {
        cout << "\n----- Menu -----" << endl;
        cout << "1. Add marks" << endl;
        cout << "2. Find maximum marks" << endl;
        cout << "3. Find minimum marks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter marks obtained by a student: ";
            cin >> mark;
            marks.push_back(mark);
            break;
        case 2:
            if (marks.empty())
            {
                cout << "No marks added yet." << endl;
            }
            else
            {
                priority_queue<int> maxHeap(marks.begin(), marks.end());
                cout << "Maximum marks obtained: " << maxHeap.top() << endl;
            }
            break;
        case 3:
            if (marks.empty())
            {
                cout << "No marks added yet." << endl;
            }
            else
            {
                priority_queue<int, vector<int>, greater<int>> minHeap(marks.begin(), marks.end());
                cout << "Minimum marks obtained: " << minHeap.top() << endl;
            }
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
