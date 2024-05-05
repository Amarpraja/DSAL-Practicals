// Implement all the functions of a dictionary (ADT) using hashing and handle collisions 
// using chaining with / without replacement. 
// Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys 
// must be unique 
// Standard Operations: Insert(key, value), Find(key), Delete(key)


#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to hold key-value pairs
struct KeyValuePair {
    string key;
    string value;
};

// Node structure for chaining
struct Node {
    KeyValuePair pair;
    Node* next;

    Node(const KeyValuePair& kvp) : pair(kvp), next(nullptr) {}
};

// Hash table implementation with chaining
class HashTable {
private:
    static const int TABLE_SIZE = 100; // Adjust the size as per your requirements
    vector<Node*> table;

    // Hash function
    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % TABLE_SIZE;
    }

public:
    HashTable() {
        table.resize(TABLE_SIZE, nullptr);
    }

    // Insert a key-value pair into the hash table
    void insert(const string& key, const string& value) {
        int index = hashFunction(key);
        KeyValuePair kvp = {key, value};
        Node* newNode = new Node(kvp);

        if (table[index] == nullptr) {
            table[index] = newNode;
        } else {
            Node* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Find a value by key
    string find(const string& key) {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->pair.key == key) {
                return current->pair.value;
            }
            current = current->next;
        }
        return "Key not found";
    }

    // Delete a key-value pair by key
    void remove(const string& key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->pair.key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Destructor to free memory
    ~HashTable() {
        for (Node* node : table) {
            while (node != nullptr) {
                Node* temp = node;
                node = node->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashTable dictionary;

    int choice;
    do {
        cout << "1. Insert a key-value pair" << endl;
        cout << "2. Find a value by key" << endl;
        cout << "3. Remove a key-value pair" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                string key, value;
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                dictionary.insert(key, value);
                cout << "Key-value pair inserted successfully." << endl;
                break;
            }
            case 2: {
                string key;
                cout << "Enter key to find value: ";
                cin >> key;
                string value = dictionary.find(key);
                if (value != "Key not found") {
                    cout << "Value found: " << value << endl;
                } else {
                    cout << "Key not found." << endl;
                }
                break;
            }
            case 3: {
                string key;
                cout << "Enter key to remove: ";
                cin >> key;
                dictionary.remove(key);
                cout << "Key-value pair removed successfully." << endl;
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while(choice != 4);

    return 0;
}
