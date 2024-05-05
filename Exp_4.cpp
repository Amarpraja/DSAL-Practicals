// Beginning with an empty binary search tree, Construct binary search tree by inserting the 
// values in the order given. After constructing a binary tree -
// i. Insert new node 
// ii. Find number of nodes in longest path from root
// iii. Minimum data value found in the tree 
// iv. Change a tree so that the roles of the left and right pointers are swapped at every 
// node 
// v. Search a value


#include <iostream>
#include <climits>

using namespace std;

// Node structure for the binary search tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to find the number of nodes in the longest path from the root
int longestPath(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = longestPath(root->left);
    int rightHeight = longestPath(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// Function to find the minimum value in the BST
int findMin(TreeNode* root) {
    if (root == nullptr) {
        cerr << "Tree is empty!" << endl;
        return INT_MIN;
    }

    while (root->left != nullptr) {
        root = root->left;
    }

    return root->data;
}

// Function to swap left and right pointers at every node in the tree
void swapPointers(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Swap left and right pointers
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively swap for left and right subtrees
    swapPointers(root->left);
    swapPointers(root->right);
}

// Function to search for a value in the BST
bool search(TreeNode* root, int value) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == value) {
        return true;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    TreeNode* root = nullptr;

    int choice;
    do {
        cout << "1. Insert a new node" << endl;
        cout << "2. Find number of nodes in longest path from root" << endl;
        cout << "3. Find minimum data value in the tree" << endl;
        cout << "4. Swap left and right pointers at every node in the tree" << endl;
        cout << "5. Search a value" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int newValue;
                cout << "Enter the value to insert: ";
                cin >> newValue;
                root = insert(root, newValue);
                cout << "Value inserted successfully." << endl;
                break;
            }
            case 2: {
                int longestPathLength = longestPath(root);
                cout << "Number of nodes in longest path from root: " << longestPathLength << endl;
                break;
            }
            case 3: {
                int minData = findMin(root);
                cout << "Minimum data value found in the tree: " << minData << endl;
                break;
            }
            case 4: {
                swapPointers(root);
                cout << "Left and right pointers swapped at every node in the tree." << endl;
                break;
            }
            case 5: {
                int valueToSearch;
                cout << "Enter the value to search: ";
                cin >> valueToSearch;
                bool found = search(root, valueToSearch);
                cout << "Value " << valueToSearch << (found ? " found" : " not found") << endl;
                break;
            }
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
