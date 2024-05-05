// Construct an expression tree from the given prefix expression eg. +--a*bc/def and 
// traverse it using postordertraversal(non recursive) and then delete the entire tree.


// #include <iostream>
// #include <stack>
// #include <cctype>

// using namespace std;

// // Node structure for the expression tree
// struct TreeNode {
//     char data;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
// };

// // Function to construct an expression tree from the given prefix expression
// TreeNode* constructExpressionTree(const string& prefixExpr) {
//     stack<TreeNode*> st;

//     for (int i = prefixExpr.size() - 1; i >= 0; i--) {
//         char ch = prefixExpr[i];
//         TreeNode* newNode = new TreeNode(ch);

//         if (isdigit(ch) || isalpha(ch)) {
//             st.push(newNode);
//         } else {
//             newNode->left = st.top();
//             st.pop();
//             newNode->right = st.top();
//             st.pop();
//             st.push(newNode);
//         }
//     }

//     return st.top();
// }

// // Function to perform postorder traversal of the expression tree (non-recursive)
// void postorderTraversal(TreeNode* root) {
//     if (root == nullptr) return;

//     stack<TreeNode*> st;
//     TreeNode* prev = nullptr;

//     do {
//         while (root != nullptr) {
//             st.push(root);
//             root = root->left;
//         }

//         while (root == nullptr && !st.empty()) {
//             root = st.top();

//             if (root->right == nullptr || root->right == prev) {
//                 cout << root->data << " ";
//                 st.pop();
//                 prev = root;
//                 root = nullptr;
//             } else {
//                 root = root->right;
//             }
//         }
//     } while (!st.empty());
// }

// // Function to delete the entire tree to avoid memory leaks
// void deleteTree(TreeNode* root) {
//     if (root == nullptr) return;

//     deleteTree(root->left);
//     deleteTree(root->right);
//     delete root;
// }

// int main() {
//     string prefixExpr = "+--a*bc/def";

//     // Construct expression tree
//     TreeNode* root = constructExpressionTree(prefixExpr);

//     // Postorder traversal
//     cout << "Postorder traversal: ";
//     postorderTraversal(root);
//     cout << endl;

//     // Delete the entire tree
//     deleteTree(root);

//     return 0;
// }




#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

// Node structure for the expression tree
struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to construct an expression tree from the given prefix expression
TreeNode* constructExpressionTree(const string& prefixExpr) {
    stack<TreeNode*> st;

    for (int i = prefixExpr.size() - 1; i >= 0; i--) {
        char ch = prefixExpr[i];
        TreeNode* newNode = new TreeNode(ch);

        if (isdigit(ch) || isalpha(ch)) {
            st.push(newNode);
        } else {
            newNode->left = st.top();
            st.pop();
            newNode->right = st.top();
            st.pop();
            st.push(newNode);
        }
    }

    return st.top();
}

// Function to perform postorder traversal of the expression tree (non-recursive)
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    stack<TreeNode*> st;
    TreeNode* prev = nullptr;

    do {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }

        while (root == nullptr && !st.empty()) {
            root = st.top();

            if (root->right == nullptr || root->right == prev) {
                cout << root->data << " ";
                st.pop();
                prev = root;
                root = nullptr;
            } else {
                root = root->right;
            }
        }
    } while (!st.empty());
}

// Function to delete the entire tree to avoid memory leaks
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    string prefixExpr;
    cout << "Enter the prefix expression: ";
    cin >> prefixExpr;

    // Construct expression tree
    TreeNode* root = constructExpressionTree(prefixExpr);

    int choice;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Perform postorder traversal" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Postorder traversal
                cout << "Postorder traversal: ";
                postorderTraversal(root);
                cout << endl;
                break;
            }
            case 2:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 2);

    // Delete the entire tree
    deleteTree(root);

    return 0;
}
