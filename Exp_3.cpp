// A book consists of chapters, chapters consist of sections and sections consist of 
// subsections. Construct a tree and print the nodes. Find the time and space requirements 
// of your method.


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TreeNode {
public:
    string data;
    vector<TreeNode*> children;

    TreeNode(string value) : data(value) {}
};

void printNodes(TreeNode* node, int depth = 0) {
    if (!node)
        return;

    for (int i = 0; i < depth; ++i)
        cout << "    ";
    
    cout << node->data << endl;

    for (TreeNode* child : node->children)
        printNodes(child, depth + 1);
}

int main() {
    string bookTitle;
    cout << "Enter the title of the book: ";
    getline(cin, bookTitle);

    TreeNode* book = new TreeNode(bookTitle);

    int numChapters;
    cout << "How many chapters does the book have? ";
    cin >> numChapters;

    cin.ignore(); // clear the newline character from input buffer

    for (int i = 0; i < numChapters; ++i) {
        string chapterTitle;
        cout << "Enter the title of chapter " << (i + 1) << ": ";
        getline(cin, chapterTitle);
        TreeNode* chapter = new TreeNode(chapterTitle);
        book->children.push_back(chapter);

        int numSections;
        cout << "How many sections does chapter " << (i + 1) << " have? ";
        cin >> numSections;

        cin.ignore(); // clear the newline character from input buffer

        for (int j = 0; j < numSections; ++j) {
            string sectionTitle;
            cout << "Enter the title of section " << (j + 1) << " in chapter " << (i + 1) << ": ";
            getline(cin, sectionTitle);
            TreeNode* section = new TreeNode(sectionTitle);
            chapter->children.push_back(section);

            int numSubsections;
            cout << "How many subsections does section " << (j + 1) << " in chapter " << (i + 1) << " have? ";
            cin >> numSubsections;

            cin.ignore(); // clear the newline character from input buffer

            for (int k = 0; k < numSubsections; ++k) {
                string subsectionTitle;
                cout << "Enter the title of subsection " << (k + 1) << " in section " << (j + 1) << " of chapter " << (i + 1) << ": ";
                getline(cin, subsectionTitle);
                TreeNode* subsection = new TreeNode(subsectionTitle);
                section->children.push_back(subsection);
            }
        }
    }

    cout << "\nPrinting all nodes of the book:\n";
    printNodes(book);

    return 0;
}
