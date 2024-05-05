//  Implement the Heap/Shell sort algorithm implemented in Java demonstrating heap/shell
// data structure with modularity of programming language

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function prototypes
void heapify(vector<int> &arr, int n, int i);
void heapSort(vector<int> &arr);
void shellSort(vector<int> &arr);

// Utility function to print an array
void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

// Function to heapify a subtree rooted with node i, n is the size of the heap
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to perform Shell Sort
void shellSort(vector<int> &arr)
{
    int n = arr.size();

    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements arr[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add arr[i] to the elements that have been gap sorted
            // save arr[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for arr[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            // put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

int main()
{
    int choice;
    vector<int> arr;

    do
    {
        cout << "\n----- Menu -----" << endl;
        cout << "1. Add number to array" << endl;
        cout << "2. Sort using Heap Sort" << endl;
        cout << "3. Sort using Shell Sort" << endl;
        cout << "4. Display array" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int num;
            cout << "Enter number to add: ";
            cin >> num;
            arr.push_back(num);
            break;
        }
        case 2:
            if (arr.empty())
            {
                cout << "Array is empty. Please add numbers first." << endl;
            }
            else
            {
                heapSort(arr);
                cout << "Array sorted using Heap Sort: ";
                printArray(arr);
            }
            break;
        case 3:
            if (arr.empty())
            {
                cout << "Array is empty. Please add numbers first." << endl;
            }
            else
            {
                shellSort(arr);
                cout << "Array sorted using Shell Sort: ";
                printArray(arr);
            }
            break;
        case 4:
            if (arr.empty())
            {
                cout << "Array is empty." << endl;
            }
            else
            {
                cout << "Current array: ";
                printArray(arr);
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
