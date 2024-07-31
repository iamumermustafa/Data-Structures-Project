#ifndef BST_H
#define BST_H

#include<iostream>
#include<stack>
using namespace std;

// Definition of a node in the BST
class BSTNode {
public:
    int ID, Batch;               // Student ID and Batch
    string Name, Department;     // Student Name and Department
    float CGPA;                  // Student CGPA
    int groupNumber;             // Group number
    BSTNode* left, * right;      // Pointers to left and right children

    // Constructor to initialize the node
    BSTNode() {
        ID = groupNumber = 0;
        CGPA = 0.0;
        Batch = 0;
        Department = Name = "\0";
        left = right = nullptr;
    }
};

// Definition of the BST class
class BST {
    BSTNode* root;               // Root of the BST
    int dataCount;               // Count of nodes in the BST

public:
    // Constructor to initialize the BST
    BST() { root = nullptr; dataCount = 0; }

    // Function to insert a new node in the BST
    void insert(int id, string name, float cgpa, int batch, string department) {
        BSTNode* newNode = new BSTNode;
        newNode->ID = id;
        newNode->Name = name;
        newNode->CGPA = cgpa;
        newNode->Batch = batch;
        newNode->Department = department;

        if (root == nullptr) {
            root = newNode;
            return;
        }

        BSTNode* parent = nullptr;
        BSTNode* current = root;

        while (current != nullptr) {
            parent = current;
            if (id < current->ID) current = current->left;
            else if (id > current->ID) current = current->right;
            else {
                cout << "--> Data of Student with ID (" << id << ") already exists..!!!!" << endl;
                delete newNode;
                return;
            }
        }

        if (id < parent->ID) parent->left = newNode;
        else parent->right = newNode;
    }

    // Function to search for a node by ID
    bool search(int id) {
        BSTNode* temp = root;
        while (temp != nullptr) {
            if (temp->ID == id) return true;
            else if (id < temp->ID) temp = temp->left;
            else temp = temp->right;
        }
        return false;
    }

    // Function to update a node's information
    void update(int originalID, int id, string name, float cgpa, int batch, string department, int gnumber, string type) {
        BSTNode* temp = root;
        while (temp != nullptr) {
            if (temp->ID == originalID) {
                if (type == "ID") temp->ID = id;
                else if (type == "Name") temp->Name = name;
                else if (type == "CGPA") temp->CGPA = cgpa;
                else if (type == "Batch") temp->Batch = batch;
                else if (type == "Department") temp->Department = department;
                else if (type == "Group") temp->groupNumber = gnumber;
                return;
            }
            else if (originalID < temp->ID) temp = temp->left;
            else temp = temp->right;
        }
    }

    // Function to get the group number of a student by ID
    int returnGroupNumber(int id) {
        BSTNode* temp = root;
        while (temp != nullptr) {
            if (temp->ID == id) return temp->groupNumber;
            else if (id < temp->ID) temp = temp->left;
            else temp = temp->right;
        }
        cout << "--> Student with ID (" << id << ") for finding group number, not found." << endl;
        return -1;
    }

    // Function to return a node by ID
    BSTNode* returnNode(int id) {
        BSTNode* temp = root;
        while (temp != nullptr) {
            if (temp->ID == id) return temp;
            else if (id < temp->ID) temp = temp->left;
            else temp = temp->right;
        }
        cout << "--> Student with ID (" << id << ") for finding node not found." << endl;
        return nullptr;
    }

    // Function to delete a node by ID
    void deleteNode(int id, int& nullStudents) {
        BSTNode* parent = nullptr;
        BSTNode* current = root;

        while (current != nullptr && current->ID != id) {
            parent = current;
            if (id < current->ID) current = current->left;
            else current = current->right;
        }

        if (current == nullptr) {
            cout << "--> Student with ID (" << id << ") to delete node in BST, not found." << endl;
            return;
        }

        if (current->groupNumber == 0) nullStudents--;

        // Case 1: Node to be deleted has no children (leaf node)
        if (current->left == nullptr && current->right == nullptr) {
            if (current == root) root = nullptr;
            else if (parent->left == current) parent->left = nullptr;
            else parent->right = nullptr;
            delete current;
        }

        // Case 2: Node to be deleted has one child
        else if (current->left == nullptr || current->right == nullptr) {
            BSTNode* child = (current->left != nullptr) ? current->left : current->right;
            if (current == root)  root = child;
            else if (parent->left == current) parent->left = child;
            else parent->right = child;
            delete current;
        }

        // Case 3: Node to be deleted has two children
        else {
            BSTNode* successorParent = current;
            BSTNode* successor = current->right;
            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }

            current->ID = successor->ID;
            current->Name = successor->Name;
            current->CGPA = successor->CGPA;
            current->Batch = successor->Batch;
            current->Department = successor->Department;

            if (successorParent == current) {
                successorParent->right = successor->right;
            }
            else {
                successorParent->left = successor->right;
            }
            delete successor;
        }
    }

    // Function to set group number to 0 for nodes with a specific group ID
    void nullGroupNumber(int groupID, int& nullStudents) {
        if (root == nullptr) return;

        stack<BSTNode*> s;
        BSTNode* temp = root;

        while (temp != nullptr || !s.empty()) {
            while (temp != nullptr) {
                s.push(temp);
                temp = temp->left;
            }
            temp = s.top();
            s.pop();

            if (temp->groupNumber == groupID) { temp->groupNumber = 0; nullStudents--; }
            temp = temp->right;
        }
    }

    // Function to display all nodes in the BST
    void displayAll() {
        if (root == nullptr) {
            cout << "\n--> No Student's Data present..!!!!!\n";
            return;
        }

        stack<BSTNode*> s;
        BSTNode* temp = root;

        while (temp != nullptr || !s.empty()) {
            while (temp != nullptr) {
                s.push(temp);
                temp = temp->left;
            }

            temp = s.top();
            s.pop();

            cout << "\n> ID: " << temp->ID << ", Name: " << temp->Name
                << ", CGPA: " << temp->CGPA << ", Batch: " << temp->Batch
                << ", Department: " << temp->Department /*<< ", Group Number: " << temp->groupNumber*/ << endl;

            temp = temp->right;
        }
    }

    // Function to check if a student has no group
    bool haveNoGroup(int id) {
        if (root == nullptr) return false;

        stack<BSTNode*> s;
        BSTNode* temp = root;

        while (temp != nullptr || !s.empty()) {
            while (temp != nullptr) {
                s.push(temp);
                temp = temp->left;
            }

            temp = s.top();
            s.pop();

            if (temp->groupNumber == 0 && temp->ID == id) {
                return true;
            }

            temp = temp->right;
        }
        return false;
    }

    // Function to display students with no group
    void displayWithNoGroups() {
        if (root == nullptr) {
            cout << "\n--> No Student's Data present..!!!!!\n";
            return;
        }

        stack<BSTNode*> s;
        BSTNode* temp = root;

        while (temp != nullptr || !s.empty()) {
            while (temp != nullptr) {
                s.push(temp);
                temp = temp->left;
            }

            temp = s.top();
            s.pop();

            if (temp->groupNumber == 0) {
                cout << "\n> ID: " << temp->ID << ", Name: " << temp->Name
                    << ", CGPA: " << temp->CGPA << ", Batch: " << temp->Batch
                    << ", Department: " << temp->Department << ", Group Number: " << temp->groupNumber << endl;
            }

            temp = temp->right;
        }
    }

    // Function to sort students by CGPA in descending order using bubble sort
    void bubbleSort(BSTNode* arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j]->CGPA < arr[j + 1]->CGPA) {
                    BSTNode* temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Function to collect all students into an array
    void collectStudents(BSTNode* node, BSTNode* students[], int& index) {
        if (node == nullptr) return;
        collectStudents(node->left, students, index);
        students[index++] = node;
        collectStudents(node->right, students, index);
    }

    // Function to return the root of the BST
    BSTNode* returnRoot() {
        return root;
    }
};

#endif
