// Implementation of a direct access file -Insertion and deletion of a record from a direct
// access file

#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;

struct Record
{
    int key;
    string data;

    Record(int k, const string &d) : key(k), data(d) {}
};

class DirectAccessFile
{
private:
    unordered_map<int, Record> records;
    string filename;

public:
    DirectAccessFile(const string &filename) : filename(filename) {}

    void insertRecord(int key, const string &data)
    {
        records.emplace(key, Record(key, data));
        writeToFile();
    }

    void deleteRecord(int key)
    {
        auto it = records.find(key);
        if (it != records.end())
        {
            records.erase(it);
            writeToFile();
            cout << "Record with key " << key << " deleted successfully." << endl;
        }
        else
        {
            cout << "Record with key " << key << " not found." << endl;
        }
    }

    void displayRecords()
    {
        if (records.empty())
        {
            cout << "No records found." << endl;
        }
        else
        {
            cout << "Key\tData" << endl;
            for (const auto &pair : records)
            {
                cout << pair.second.key << "\t" << pair.second.data << endl;
            }
        }
    }

private:
    void writeToFile()
    {
        ofstream outputFile(filename);
        if (outputFile.is_open())
        {
            for (const auto &pair : records)
            {
                outputFile << pair.second.key << " " << pair.second.data << endl;
            }
            outputFile.close();
        }
        else
        {
            cerr << "Error: Unable to open file " << filename << " for writing." << endl;
        }
    }
};

int main()
{
    string filename = "records.txt";
    DirectAccessFile file(filename);

    int choice;
    do
    {
        cout << "\n----- Menu -----" << endl;
        cout << "1. Insert a record" << endl;
        cout << "2. Delete a record" << endl;
        cout << "3. Display all records" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int key;
            string data;
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter data: ";
            cin >> data;
            file.insertRecord(key, data);
            break;
        }
        case 2:
        {
            int key;
            cout << "Enter key of the record to delete: ";
            cin >> key;
            file.deleteRecord(key);
            break;
        }
        case 3:
            cout << "\nAll Records:" << endl;
            file.displayRecords();
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
