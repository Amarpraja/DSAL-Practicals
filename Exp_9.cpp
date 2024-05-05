// A Dictionary stores keywords & its meanings. Provide facility for adding new keywords, 
// deleting keywords, updating values of any entry. Provide facility to display whole data 
// sorted in ascending/ Descending order. Also find how many maximum comparisons may 
// require for finding any keyword. Use Height balance tree and find the complexity for 
// finding a keyword


// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// // Node structure for the AVL tree
// struct Node {
//     string keyword;
//     string meaning;
//     Node* left;
//     Node* right;
//     int height;

//     Node(const string& key, const string& val) : keyword(key), meaning(val), left(nullptr), right(nullptr), height(1) {}
// };

// // AVL Tree class
// class AVLTree {
// private:
//     Node* root;

//     // Helper functions
//     int getHeight(Node* node);
//     int getBalance(Node* node);
//     Node* rotateRight(Node* node);
//     Node* rotateLeft(Node* node);
//     Node* balance(Node* node);
//     Node* minValueNode(Node* node);
//     Node* insertNode(Node* node, const string& key, const string& val);
//     Node* deleteNode(Node* node, const string& key);
//     Node* searchNode(Node* node, const string& key);
//     void inorderTraversal(Node* node);
//     void reverseInorderTraversal(Node* node);

// public:
//     AVLTree() : root(nullptr) {}

//     // Public interface functions
//     void insert(const string& key, const string& val);
//     void remove(const string& key);
//     void update(const string& key, const string& val);
//     void displayAscending();
//     void displayDescending();
//     int maxComparisons(const string& key);
// };

// // Utility function to get height of a node
// int AVLTree::getHeight(Node* node) {
//     return (node == nullptr) ? 0 : node->height;
// }

// // Utility function to get the balance factor of a node
// int AVLTree::getBalance(Node* node) {
//     return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
// }

// // Utility function to perform right rotation
// Node* AVLTree::rotateRight(Node* y) {
//     Node* x = y->left;
//     Node* T2 = x->right;

//     // Perform rotation
//     x->right = y;
//     y->left = T2;

//     // Update heights
//     y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
//     x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

//     return x;
// }

// // Utility function to perform left rotation
// Node* AVLTree::rotateLeft(Node* x) {
//     Node* y = x->right;
//     Node* T2 = y->left;

//     // Perform rotation
//     y->left = x;
//     x->right = T2;

//     // Update heights
//     x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
//     y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

//     return y;
// }

// // Utility function to balance a node
// Node* AVLTree::balance(Node* node) {
//     // Update height
//     node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

//     // Check balance factor
//     int balanceFactor = getBalance(node);

//     // Left heavy
//     if (balanceFactor > 1) {
//         if (getBalance(node->left) < 0) {
//             node->left = rotateLeft(node->left);
//         }
//         return rotateRight(node);
//     }
//     // Right heavy
//     else if (balanceFactor < -1) {
//         if (getBalance(node->right) > 0) {
//             node->right = rotateRight(node->right);
//         }
//         return rotateLeft(node);
//     }

//     return node;
// }

// // Utility function to find node with minimum value in a subtree
// Node* AVLTree::minValueNode(Node* node) {
//     Node* current = node;
//     while (current && current->left != nullptr) {
//         current = current->left;
//     }
//     return current;
// }

// // Utility function to insert a node into the AVL tree
// Node* AVLTree::insertNode(Node* node, const string& key, const string& val) {
//     // Perform standard BST insertion
//     if (node == nullptr) {
//         return new Node(key, val);
//     }

//     if (key < node->keyword) {
//         node->left = insertNode(node->left, key, val);
//     } else if (key > node->keyword) {
//         node->right = insertNode(node->right, key, val);
//     } else { // Duplicate key, update meaning
//         node->meaning = val;
//         return node;
//     }

//     // Update height of current node
//     return balance(node);
// }

// // Utility function to delete a node from the AVL tree
// Node* AVLTree::deleteNode(Node* node, const string& key) {
//     if (node == nullptr) return node;

//     // Perform standard BST delete
//     if (key < node->keyword) {
//         node->left = deleteNode(node->left, key);
//     } else if (key > node->keyword) {
//         node->right = deleteNode(node->right, key);
//     } else {
//         // Node with only one child or no child
//         if (node->left == nullptr || node->right == nullptr) {
//             Node* temp = (node->left != nullptr) ? node->left : node->right;
//             if (temp == nullptr) {
//                 temp = node;
//                 node = nullptr;
//             } else {
//                 *node = *temp;
//             }
//             delete temp;
//         } else {
//             // Node with two children, get the inorder successor
//             Node* temp = minValueNode(node->right);
//             node->keyword = temp->keyword;
//             node->meaning = temp->meaning;
//             node->right = deleteNode(node->right, temp->keyword);
//         }
//     }

//     if (node == nullptr) return node;

//     // Update height and balance factor
//     return balance(node);
// }

// // Utility function to search for a node with given key
// Node* AVLTree::searchNode(Node* node, const string& key) {
//     if (node == nullptr || node->keyword == key) return node;

//     if (key < node->keyword) {
//         return searchNode(node->left, key);
//     } else {
//         return searchNode(node->right, key);
//     }
// }

// // Utility function to perform inorder traversal
// void AVLTree::inorderTraversal(Node* node) {
//     if (node == nullptr) return;
//     inorderTraversal(node->left);
//     cout << node->keyword << " : " << node->meaning << endl;
//     inorderTraversal(node->right);
// }

// // Utility function to perform reverse inorder traversal
// void AVLTree::reverseInorderTraversal(Node* node) {
//     if (node == nullptr) return;
//     reverseInorderTraversal(node->right);
//     cout << node->keyword << " : " << node->meaning << endl;
//     reverseInorderTraversal(node->left);
// }

// // Public function to insert a keyword with its meaning
// void AVLTree::insert(const string& key, const string& val) {
//     root = insertNode(root, key, val);
// }

// // Public function to remove a keyword
// void AVLTree::remove(const string& key) {
//     root = deleteNode(root, key);
// }

// // Public function to update the meaning of a keyword
// void AVLTree::update(const string& key, const string& val) {
//     Node* node = searchNode(root, key);
//     if (node != nullptr) {
//         node->meaning = val;
//     }
// }

// // Public function to display data in ascending order
// void AVLTree::displayAscending() {
//     inorderTraversal(root);
// }

// // Public function to display data in descending order
// void AVLTree::displayDescending() {
//     reverseInorderTraversal(root);
// }

// // Public function to find the maximum comparisons required for finding a keyword
// int AVLTree::maxComparisons(const string& key) {
//     Node* current = root;
//     int comparisons = 0;
//     while (current != nullptr) {
//         comparisons++;
//         if (key == current->keyword) {
//             return comparisons;
//         } else if (key < current->keyword) {
//             current = current->left;
//         } else {
//             current = current->right;
//         }
//     }
//     return comparisons;
// }

// int main() {
//     AVLTree dictionary;

//     // Add some keywords and their meanings
//     dictionary.insert("apple", "a fruit");
//     dictionary.insert("banana", "another fruit");
//     dictionary.insert("cat", "a pet animal");
//     dictionary.insert("dog", "another pet animal");

//     // Display dictionary data in ascending order
//     cout << "Dictionary data in ascending order:" << endl;
//     dictionary.displayAscending();
//     cout << endl;

//     // Display dictionary data in descending order
//     cout << "\nDictionary data in descending order:" << endl;
//     dictionary.displayDescending();
//     cout << endl;

//     // Update meaning of a keyword
//     dictionary.update("apple", "a fruit and a company");

//     // Display updated dictionary data in ascending order
//     cout << "\nDictionary data after updating 'apple':" << endl;
//     dictionary.displayAscending();
//     cout << endl;

//     // Find the maximum comparisons required for finding a keyword
//     string keyword = "dog";
//     int maxComp = dictionary.maxComparisons(keyword);
//     cout << "\nMaximum comparisons required for finding '" << keyword << "': " << maxComp << endl;

//     return 0;
// }



 #include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Node structure for the AVL tree
struct Node {
    string keyword;
    string meaning;
    Node* left;
    Node* right;
    int height;

    Node(const string& key, const string& val) : keyword(key), meaning(val), left(nullptr), right(nullptr), height(1) {}
};

// AVL Tree class
class AVLTree {
private:
    Node* root;

    // Helper functions
    int getHeight(Node* node);
    int getBalance(Node* node);
    Node* rotateRight(Node* node);
    Node* rotateLeft(Node* node);
    Node* balance(Node* node);
    Node* minValueNode(Node* node);
    Node* insertNode(Node* node, const string& key, const string& val);
    Node* deleteNode(Node* node, const string& key);
    Node* searchNode(Node* node, const string& key);
    void inorderTraversal(Node* node);
    void reverseInorderTraversal(Node* node);

public:
    AVLTree() : root(nullptr) {}

    // Public interface functions
    void insert(const string& key, const string& val);
    void remove(const string& key);
    void update(const string& key, const string& val);
    void displayAscending();
    void displayDescending();
    int maxComparisons(const string& key);
};

// Utility function to get height of a node
int AVLTree::getHeight(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Utility function to get the balance factor of a node
int AVLTree::getBalance(Node* node) {
    return (node == nullptr) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Utility function to perform right rotation
Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Utility function to perform left rotation
Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Utility function to balance a node
Node* AVLTree::balance(Node* node) {
    // Update height
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

    // Check balance factor
    int balanceFactor = getBalance(node);

    // Left heavy
    if (balanceFactor > 1) {
        if (getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    // Right heavy
    else if (balanceFactor < -1) {
        if (getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }

    return node;
}

// Utility function to find node with minimum value in a subtree
Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Utility function to insert a node into the AVL tree
Node* AVLTree::insertNode(Node* node, const string& key, const string& val) {
    // Perform standard BST insertion
    if (node == nullptr) {
        return new Node(key, val);
    }

    if (key < node->keyword) {
        node->left = insertNode(node->left, key, val);
    } else if (key > node->keyword) {
        node->right = insertNode(node->right, key, val);
    } else { // Duplicate key, update meaning
        node->meaning = val;
        return node;
    }

    // Update height of current node
    return balance(node);
}

// Utility function to delete a node from the AVL tree
Node* AVLTree::deleteNode(Node* node, const string& key) {
    if (node == nullptr) return node;

    // Perform standard BST delete
    if (key < node->keyword) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->keyword) {
        node->right = deleteNode(node->right, key);
    } else {
        // Node with only one child or no child
        if (node->left == nullptr || node->right == nullptr) {
            Node* temp = (node->left != nullptr) ? node->left : node->right;
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            } else {
                *node = *temp;
            }
            delete temp;
        } else {
            // Node with two children, get the inorder successor
            Node* temp = minValueNode(node->right);
            node->keyword = temp->keyword;
            node->meaning = temp->meaning;
            node->right = deleteNode(node->right, temp->keyword);
        }
    }

    if (node == nullptr) return node;

    // Update height and balance factor
    return balance(node);
}

// Utility function to search for a node with given key
Node* AVLTree::searchNode(Node* node, const string& key) {
    if (node == nullptr || node->keyword == key) return node;

    if (key < node->keyword) {
        return searchNode(node->left, key);
    } else {
        return searchNode(node->right, key);
    }
}

// Utility function to perform inorder traversal
void AVLTree::inorderTraversal(Node* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->keyword << " : " << node->meaning << endl;
    inorderTraversal(node->right);
}

// Utility function to perform reverse inorder traversal
void AVLTree::reverseInorderTraversal(Node* node) {
    if (node == nullptr) return;
    reverseInorderTraversal(node->right);
    cout << node->keyword << " : " << node->meaning << endl;
    reverseInorderTraversal(node->left);
}

// Public function to insert a keyword with its meaning
void AVLTree::insert(const string& key, const string& val) {
    root = insertNode(root, key, val);
}

// Public function to remove a keyword
void AVLTree::remove(const string& key) {
    root = deleteNode(root, key);
}

// Public function to update the meaning of a keyword
void AVLTree::update(const string& key, const string& val) {
    Node* node = searchNode(root, key);
    if (node != nullptr) {
        node->meaning = val;
    }
}

// Public function to display data in ascending order
void AVLTree::displayAscending() {
    inorderTraversal(root);
}

// Public function to display data in descending order
void AVLTree::displayDescending() {
    reverseInorderTraversal(root);
}

// Public function to find the maximum comparisons required for finding a keyword
int AVLTree::maxComparisons(const string& key) {
    Node* current = root;
    int comparisons = 0;
    while (current != nullptr) {
        comparisons++;
        if (key == current->keyword) {
            return comparisons;
        } else if (key < current->keyword) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return comparisons;
}

int main() {
    AVLTree dictionary;
    int choice;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Insert a keyword with meaning" << endl;
        cout << "2. Remove a keyword" << endl;
        cout << "3. Update the meaning of a keyword" << endl;
        cout << "4. Display dictionary data in ascending order" << endl;
        cout << "5. Display dictionary data in descending order" << endl;
        cout << "6. Find the maximum comparisons required for finding a keyword" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string keyword, meaning;
        switch (choice) {
            case 1:
                cout << "Enter keyword: ";
                cin >> keyword;
                cout << "Enter meaning: ";
                cin.ignore(); // Ignore newline character
                getline(cin, meaning);
                dictionary.insert(keyword, meaning);
                cout << "Keyword inserted successfully." << endl;
                break;
            case 2:
                cout << "Enter keyword to remove: ";
                cin >> keyword;
                dictionary.remove(keyword);
                cout << "Keyword removed successfully." << endl;
                break;
            case 3:
                cout << "Enter keyword to update: ";
                cin >> keyword;
                cout << "Enter updated meaning: ";
                cin.ignore(); // Ignore newline character
                getline(cin, meaning);
                dictionary.update(keyword, meaning);
                cout << "Keyword updated successfully." << endl;
                break;
            case 4:
                cout << "Dictionary data in ascending order:" << endl;
                dictionary.displayAscending();
                break;
            case 5:
                cout << "Dictionary data in descending order:" << endl;
                dictionary.displayDescending();
                break;
            case 6:
                cout << "Enter keyword to find maximum comparisons: ";
                cin >> keyword;
                cout << "Maximum comparisons required for finding '" << keyword << "': " << dictionary.maxComparisons(keyword) << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
