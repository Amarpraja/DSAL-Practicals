// Given sequence k = k1 <k2 < … <kn of n sorted keys, with a search probability pi for each 
// key ki . Build the Binary search tree that has the least search cost given the access 
// probability for each key?


// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <limits>
// #include <functional>

// using namespace std;

// // Structure to represent a node in the binary search tree
// struct TreeNode {
//     int key;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
// };

// // Function to construct the optimal binary search tree
// TreeNode* constructOBST(const vector<int>& keys, const vector<double>& probabilities) {
//     int n = keys.size();
//     vector<vector<double>> cost(n + 1, vector<double>(n + 1, 0.0));
//     vector<vector<int>> root(n, vector<int>(n, 0));

//     // Initialize cost matrix for single keys
//     for (int i = 0; i < n; ++i) {
//         cost[i][i] = probabilities[i];
//         root[i][i] = i;
//     }

//     // Define the lambda function to build the BST recursively
//     function<TreeNode*(int, int)> buildTree = [&](int i, int j) -> TreeNode* {
//         if (i > j) return nullptr;
//         int r = root[i][j];
//         TreeNode* node = new TreeNode(keys[r]);
//         node->left = buildTree(i, r - 1);
//         node->right = buildTree(r + 1, j);
//         return node;
//     };

//     // Compute cost and root matrices
//     for (int d = 1; d < n; ++d) {
//         for (int i = 0; i < n - d; ++i) {
//             int j = i + d;
//             cost[i][j] = numeric_limits<double>::infinity();
//             for (int r = i; r <= j; ++r) {
//                 double c = (r > i ? cost[i][r - 1] : 0) + (r < j ? cost[r + 1][j] : 0);
//                 c += probabilities[r];
//                 if (c < cost[i][j]) {
//                     cost[i][j] = c;
//                     root[i][j] = r;
//                 }
//             }
//         }
//     }

//     // Return root of the optimal BST
//     return buildTree(0, n - 1);
// }

// // Function to print the inorder traversal of a binary tree
// void inorderTraversal(TreeNode* root) {
//     if (root == nullptr) return;
//     inorderTraversal(root->left);
//     cout << root->key << " ";
//     inorderTraversal(root->right);
// }

// int main() {
//     vector<int> keys = {10, 20, 30, 40, 50};
//     vector<double> probabilities = {0.1, 0.2, 0.3, 0.1, 0.3};

//     TreeNode* root = constructOBST(keys, probabilities);

//     cout << "Inorder traversal of the optimal binary search tree: ";
//     inorderTraversal(root);
//     cout << endl;

//     // Free memory
//     // Implement a function to delete the tree nodes to avoid memory leaks

//     return 0;
// }



#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <functional>

using namespace std;

// Structure to represent a node in the binary search tree
struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Function to construct the optimal binary search tree
TreeNode* constructOBST(const vector<int>& keys, const vector<double>& probabilities) {
    int n = keys.size();
    vector<vector<double>> cost(n + 1, vector<double>(n + 1, 0.0));
    vector<vector<int>> root(n, vector<int>(n, 0));

    // Initialize cost matrix for single keys
    for (int i = 0; i < n; ++i) {
        cost[i][i] = probabilities[i];
        root[i][i] = i;
    }

    // Define the lambda function to build the BST recursively
    function<TreeNode*(int, int)> buildTree = [&](int i, int j) -> TreeNode* {
        if (i > j) return nullptr;
        int r = root[i][j];
        TreeNode* node = new TreeNode(keys[r]);
        node->left = buildTree(i, r - 1);
        node->right = buildTree(r + 1, j);
        return node;
    };

    // Compute cost and root matrices
    for (int d = 1; d < n; ++d) {
        for (int i = 0; i < n - d; ++i) {
            int j = i + d;
            cost[i][j] = numeric_limits<double>::infinity();
            for (int r = i; r <= j; ++r) {
                double c = (r > i ? cost[i][r - 1] : 0) + (r < j ? cost[r + 1][j] : 0);
                c += probabilities[r];
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }

    // Return root of the optimal BST
    return buildTree(0, n - 1);
}

// Function to print the inorder traversal of a binary tree
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

int main() {
    int choice;
    vector<int> keys;
    vector<double> probabilities;

    cout << "Choose an option:" << endl;
    cout << "1. Use default values for keys and probabilities" << endl;
    cout << "2. Enter custom values for keys and probabilities" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            // Use default values
            keys = {10, 20, 30, 40, 50};
            probabilities = {0.1, 0.2, 0.3, 0.1, 0.3};
            break;
        case 2: {
            int n;
            cout << "Enter the number of keys: ";
            cin >> n;
            cout << "Enter the keys and corresponding probabilities:" << endl;
            for (int i = 0; i < n; ++i) {
                int key;
                double prob;
                cout << "Key " << i + 1 << ": ";
                cin >> key;
                cout << "Probability " << i + 1 << ": ";
                cin >> prob;
                keys.push_back(key);
                probabilities.push_back(prob);
            }
            break;
        }
        case 3:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Exiting..." << endl;
            return 0;
    }

    TreeNode* root = constructOBST(keys, probabilities);

    cout << "Inorder traversal of the optimal binary search tree: ";
    inorderTraversal(root);
    cout << endl;

    // Free memory
    // Implement a function to delete the tree nodes to avoid memory leaks

    return 0;
}
