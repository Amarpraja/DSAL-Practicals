// Represent a given graph using adjacency matrix/list to perform DFS and using adjacency 
// list to perform BFS. Use the map of the area around the college as the graph. Identify the 
// prominent land marks as nodes and perform DFS and BFS on that.

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <map>
// #include <string>
// #include <unordered_set>
// #include <stack>

// using namespace std;

// // Function to perform Depth First Search (DFS) using adjacency matrix
// void DFSMatrix(vector<vector<int>>& graph, int node, unordered_set<int>& visited) {
//     stack<int> stk;
//     stk.push(node);

//     while (!stk.empty()) {
//         int current = stk.top();
//         stk.pop();

//         if (visited.find(current) == visited.end()) {
//             visited.insert(current);
//             cout << current << " ";

//             // Visit neighbors in reverse order to maintain DFS order
//             for (int neighbor = graph[current].size() - 1; neighbor >= 0; --neighbor) {
//                 if (graph[current][neighbor] == 1 && visited.find(neighbor) == visited.end()) {
//                     stk.push(neighbor);
//                 }
//             }
//         }
//     }
// }

// // Function to perform Breadth First Search (BFS) using adjacency list
// void BFSList(map<string, vector<string>>& graph, const string& start) {
//     queue<string> q;
//     unordered_set<string> visited;
//     q.push(start);
//     visited.insert(start);

//     while (!q.empty()) {
//         string current = q.front();
//         q.pop();
//         cout << current << " ";

//         for (const string& neighbor : graph[current]) {
//             if (visited.find(neighbor) == visited.end()) {
//                 q.push(neighbor);
//                 visited.insert(neighbor);
//             }
//         }
//     }
// }

// int main() {
//     // Create the graph using adjacency matrix for DFS
//     vector<vector<int>> graphMatrix = {
//         {0, 1, 1, 0, 0, 0},
//         {1, 0, 0, 1, 0, 0},
//         {1, 0, 0, 1, 1, 0},
//         {0, 1, 1, 0, 0, 1},
//         {0, 0, 1, 0, 0, 1},
//         {0, 0, 0, 1, 1, 0}
//     };

//     cout << "DFS traversal using adjacency matrix: ";
//     unordered_set<int> visitedMatrix;
//     DFSMatrix(graphMatrix, 0, visitedMatrix);
//     cout << endl;

//     // Create the graph using adjacency list for BFS
//     map<string, vector<string>> graphList;
//     graphList["College"] = {"Library", "Cafeteria", "Main Gate"};
//     graphList["Library"] = {"College", "Park"};
//     graphList["Cafeteria"] = {"College", "Park", "Auditorium"};
//     graphList["Main Gate"] = {"College", "Hospital"};
//     graphList["Park"] = {"Library", "Cafeteria"};
//     graphList["Auditorium"] = {"Cafeteria"};
//     graphList["Hospital"] = {"Main Gate"};

//     cout << "BFS traversal using adjacency list: ";
//     BFSList(graphList, "College");
//     cout << endl;

//     return 0;
// }



#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <unordered_set>
#include <stack>

using namespace std;

// Function to perform Depth First Search (DFS) using adjacency matrix
void DFSMatrix(vector<vector<int>>& graph, int node, unordered_set<int>& visited) {
    stack<int> stk;
    stk.push(node);

    while (!stk.empty()) {
        int current = stk.top();
        stk.pop();

        if (visited.find(current) == visited.end()) {
            visited.insert(current);
            cout << current << " ";

            // Visit neighbors in reverse order to maintain DFS order
            for (int neighbor = graph[current].size() - 1; neighbor >= 0; --neighbor) {
                if (graph[current][neighbor] == 1 && visited.find(neighbor) == visited.end()) {
                    stk.push(neighbor);
                }
            }
        }
    }
}

// Function to perform Breadth First Search (BFS) using adjacency list
void BFSList(map<string, vector<string>>& graph, const string& start) {
    queue<string> q;
    unordered_set<string> visited;
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        string current = q.front();
        q.pop();
        cout << current << " ";

        for (const string& neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}

int main() {
    int choice;
    cout << "Choose an option:" << endl;
    cout << "1. Perform Depth First Search (DFS)" << endl;
    cout << "2. Perform Breadth First Search (BFS)" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            // Create the graph using adjacency matrix for DFS
            vector<vector<int>> graphMatrix = {
                {0, 1, 1, 0, 0, 0},
                {1, 0, 0, 1, 0, 0},
                {1, 0, 0, 1, 1, 0},
                {0, 1, 1, 0, 0, 1},
                {0, 0, 1, 0, 0, 1},
                {0, 0, 0, 1, 1, 0}
            };

            cout << "DFS traversal using adjacency matrix: ";
            unordered_set<int> visitedMatrix;
            DFSMatrix(graphMatrix, 0, visitedMatrix);
            cout << endl;
            break;
        }
        case 2: {
            // Create the graph using adjacency list for BFS
            map<string, vector<string>> graphList;
            graphList["College"] = {"Library", "Cafeteria", "Main Gate"};
            graphList["Library"] = {"College", "Park"};
            graphList["Cafeteria"] = {"College", "Park", "Auditorium"};
            graphList["Main Gate"] = {"College", "Hospital"};
            graphList["Park"] = {"Library", "Cafeteria"};
            graphList["Auditorium"] = {"Cafeteria"};
            graphList["Hospital"] = {"Main Gate"};

            cout << "BFS traversal using adjacency list: ";
            BFSList(graphList, "College");
            cout << endl;
            break;
        }
        default:
            cout << "Invalid choice. Exiting..." << endl;
            break;
    }

    return 0;
}
