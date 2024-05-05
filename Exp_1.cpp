/*Consider telephone book database of N clients. Make use of a hash table implementation 
to quickly look up client‘s telephone number. Make use of two collision handling 
techniques and compare them using number of comparisons required to find a set of 
telephone numbers*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to hold client information
struct Client {
    string name;
    string phoneNumber;
};

// Hash table implementation
class HashTable {
private:
    static const int TABLE_SIZE = 100; // Adjust the size as per your requirements
    vector<vector<Client>> table; // Using vector of vectors for chaining
    int numComparisons;

    // Hash function
    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % TABLE_SIZE;
    }

public:
    HashTable() : numComparisons(0) {
        table.resize(TABLE_SIZE);
    }

    // Insert a client into the hash table
    void insert(const Client& client) {
        int index = hashFunction(client.name);
        table[index].push_back(client);
    }

    // Search for a client's phone number
    string search(const string& name) {
        int index = hashFunction(name);
        for (const Client& client : table[index]) {
            numComparisons++;
            if (client.name == name) {
                return client.phoneNumber;
            }
        }
        return "Not found";
    }

    // Get the number of comparisons made during the last search
    int getNumComparisons() {
        return numComparisons;
    }

    // Reset the number of comparisons
    void resetComparisons() {
        numComparisons = 0;
    }
};

int main() {
    HashTable chainingTable;
    HashTable linearProbingTable;

    int choice;
    do {
        cout << "1. Insert a client" << endl;
        cout << "2. Search for a client's phone number" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                string name, phoneNumber;
                cout << "Enter client's name: ";
                cin >> name;
                cout << "Enter client's phone number: ";
                cin >> phoneNumber;
                Client newClient = {name, phoneNumber};
                chainingTable.insert(newClient);
                linearProbingTable.insert(newClient);
                cout << "Client inserted successfully." << endl;
                break;
            }
            case 2: {
                string name;
                cout << "Enter client's name to search: ";
                cin >> name;
                string phoneNumber = chainingTable.search(name);
                if (phoneNumber != "Not found") {
                    cout << "Phone number found: " << phoneNumber << endl;
                } else {
                    cout << "Client not found." << endl;
                }
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 3);

    return 0;
}
