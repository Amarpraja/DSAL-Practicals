// Read the marks obtained by students of second year in an online examination of 
// particular subject. Find out maximum and minimum marks obtained in that subject. Use 
// heap data structure. Analyze the algorithm.

// #include <iostream>
// #include <vector>

// using namespace std;

// class Heap {
// private:
//     vector<int> heap;

//     // Helper functions to maintain heap property
//     void heapifyUp(int index);
//     void heapifyDown(int index);

// public:
//     // Function to insert an element into the heap
//     void insert(int value);

//     // Functions to retrieve maximum and minimum elements
//     int getMax();
//     int getMin();

//     // Function to check if the heap is empty
//     bool isEmpty() const { return heap.empty(); }
// };

// void Heap::heapifyUp(int index) {
//     int parent = (index - 1) / 2;
//     while (index > 0 && heap[parent] < heap[index]) {
//         swap(heap[parent], heap[index]);
//         index = parent;
//         parent = (index - 1) / 2;
//     }
// }

// void Heap::heapifyDown(int index) {
//     int leftChild = 2 * index + 1;
//     int rightChild = 2 * index + 2;
//     int largest = index;

//     if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
//         largest = leftChild;
//     }
//     if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
//         largest = rightChild;
//     }

//     if (largest != index) {
//         swap(heap[index], heap[largest]);
//         heapifyDown(largest);
//     }
// }

// void Heap::insert(int value) {
//     heap.push_back(value);
//     heapifyUp(heap.size() - 1);
// }

// int Heap::getMax() {
//     if (!isEmpty()) {
//         int max = heap[0];
//         heap[0] = heap.back();
//         heap.pop_back();
//         heapifyDown(0);
//         return max;
//     }
//     return -1; // Heap is empty
// }

// int Heap::getMin() {
//     if (!isEmpty()) {
//         int min = heap[0];
//         heap[0] = heap.back();
//         heap.pop_back();
//         heapifyDown(0);
//         return min;
//     }
//     return -1; // Heap is empty
// }

// int main() {
//     Heap maxHeap;
//     Heap minHeap;

//     // Example: Marks obtained by students
//     vector<int> marks = {85, 92, 78, 90, 88, 95, 83};

//     // Insert marks into both max and min heaps
//     for (int mark : marks) {
//         maxHeap.insert(mark);
//         minHeap.insert(mark);
//     }

//     // Find maximum and minimum marks
//     int maxMark = maxHeap.getMax();
//     int minMark = minHeap.getMin();

//     cout << "Maximum mark obtained: " << maxMark << endl;
//     cout << "Minimum mark obtained: " << minMark << endl;

//     return 0;
// }



#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> heap;

    // Helper functions to maintain heap property
    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    // Function to insert an element into the heap
    void insert(int value);

    // Functions to retrieve maximum and minimum elements
    int getMax();
    int getMin();

    // Function to check if the heap is empty
    bool isEmpty() const { return heap.empty(); }
};

void Heap::heapifyUp(int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && heap[parent] < heap[index]) {
        swap(heap[parent], heap[index]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void Heap::heapifyDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }
    if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

void Heap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int Heap::getMax() {
    if (!isEmpty()) {
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return max;
    }
    return -1; // Heap is empty
}

int Heap::getMin() {
    if (!isEmpty()) {
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return min;
    }
    return -1; // Heap is empty
}

int main() {
    Heap marksHeap;
    int choice;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Add marks for a student" << endl;
        cout << "2. Find maximum marks" << endl;
        cout << "3. Find minimum marks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int marks;
                cout << "Enter marks obtained by the student: ";
                cin >> marks;
                marksHeap.insert(marks);
                cout << "Marks added." << endl;
                break;
            case 2:
                if (!marksHeap.isEmpty()) {
                    cout << "Maximum marks obtained: " << marksHeap.getMax() << endl;
                } else {
                    cout << "No marks added yet." << endl;
                }
                break;
            case 3:
                if (!marksHeap.isEmpty()) {
                    cout << "Minimum marks obtained: " << marksHeap.getMin() << endl;
                } else {
                    cout << "No marks added yet." << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
