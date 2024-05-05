// There are flight paths between cities. If there is a flight between city A and city B then
// there is an edge between the cities. The cost of the edge can be the time that flight take
// to reach city B from A, or the amount of fuel used for the journey. Represent this as a
// graph. The node can be represented by airport name or name of the city. Use adjacency
// list representation of the graph or use adjacency matrix representation of the graph.
// Check whether the graph is connected or not. Justify the storage representation used.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

// Define a structure to represent the flight paths between cities
struct FlightPath
{
    string destination;
    int cost;

    FlightPath(const string &dest, int c) : destination(dest), cost(c) {}
};

// Define a graph class to represent flight paths between cities
class FlightGraph
{
private:
    unordered_map<string, vector<FlightPath>> adjList;

public:
    // Function to add an edge (flight path) between two cities
    void addEdge(const string &source, const string &destination, int cost)
    {
        adjList[source].push_back(FlightPath(destination, cost));
        adjList[destination].push_back(FlightPath(source, cost)); // Assuming flights are bidirectional
    }

    // Function to check whether the graph is connected or not using BFS
    bool isConnected()
    {
        unordered_set<string> visited;
        queue<string> q;

        // Start BFS from an arbitrary node
        if (!adjList.empty())
        {
            q.push(adjList.begin()->first);
            visited.insert(adjList.begin()->first);
        }
        else
        {
            return false; // Graph is empty
        }

        while (!q.empty())
        {
            string current = q.front();
            q.pop();

            // Visit neighbors of the current city
            for (const FlightPath &flight : adjList[current])
            {
                if (visited.find(flight.destination) == visited.end())
                {
                    q.push(flight.destination);
                    visited.insert(flight.destination);
                }
            }
        }

        // Check if all cities are visited
        return visited.size() == adjList.size();
    }
};

int main()
{
    // Create a FlightGraph
    FlightGraph flightGraph;

    int choice;
    do
    {
        cout << "Choose an option:" << endl;
        cout << "1. Add a flight path between cities" << endl;
        cout << "2. Check if the flight paths between cities are connected" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string source, destination;
            int cost;
            cout << "Enter source city: ";
            cin >> source;
            cout << "Enter destination city: ";
            cin >> destination;
            cout << "Enter cost: ";
            cin >> cost;
            flightGraph.addEdge(source, destination, cost);
            cout << "Flight path added successfully." << endl;
            break;
        }
        case 2:
        {
            if (flightGraph.isConnected())
            {
                cout << "The flight paths between cities are connected." << endl;
            }
            else
            {
                cout << "The flight paths between cities are not connected." << endl;
            }
            break;
        }
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
