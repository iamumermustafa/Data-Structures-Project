#ifndef linkedList_h
#define linkedList_h

#include<iostream>
using namespace std;

// Definition of a node in the linked list
class Node {
public:
    int ID, Batch;               // Student ID and Batch
    string Name, Department;     // Student Name and Department
    float CGPA;                  // Student CGPA
    Node* next;                  // Pointer to the next node

    // Constructor to initialize the node
    Node() {
        ID = 0;
        Batch = 0;
        Name = "\0";
        Department = "\0";
        CGPA = 0.0;
        next = nullptr;
    }
};

// Definition of the linked list class
class linkedList {
    int dataCount;               // Count of nodes in the linked list
    Node* root;                  // Root of the linked list

public:
    // Constructor to initialize the linked list
    linkedList() {
        dataCount = 0;
        root = nullptr;
    }

    // Function to insert a new node in the linked list
    void insert(int id, string name, float cgpa, int batch, string department) {
        Node* newNode = new Node;
        newNode->ID = id;
        newNode->Name = name;
        newNode->CGPA = cgpa;
        newNode->Batch = batch;
        newNode->Department = department;
        if (root == nullptr) {
            root = newNode;
        }
        else {
            Node* temp = root;
            while (temp->next != nullptr) {
                if (temp->ID == id || temp->next->ID == id) {
                    cout << "--> Data of Student with ID (" << id << ") in LL already exists..!!!!" << endl;
                    delete newNode;
                    return;
                }
                temp = temp->next;
            }
            temp->next = newNode;
        }
        dataCount++;
    }

    // Function to delete a node by ID
    void deleteNode(int id) {
        Node* temp = root;
        if (temp->ID == id) {
            root = root->next;
            delete temp;
            dataCount--;
            return;
        }

        while (!isEmpty() && (temp != nullptr || temp->next != nullptr)) {
            if (temp->ID == id) {
                Node* temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;
                dataCount--;
                return;
            }
            temp = temp->next;
        }

        cout << "--> No Student with ID " << id << " in LL..!!!" << endl;
    }

    // Function to display all nodes in the linked list
    void display() {
        Node* temp = root;

        while (!isEmpty() && temp != nullptr) {
            cout << "\n> ID: " << temp->ID << ", Name: " << temp->Name
                << ", CGPA: " << temp->CGPA << ", Batch: " << temp->Batch
                << ", Department: " << temp->Department << endl;

            temp = temp->next;
        }
        cout << endl;
    }

    // Function to update a node's information
    void update(int originalID, int id, string name, float cgpa, int batch, string department, string type) {
        Node* temp = root;
        while (temp != nullptr) {
            if (temp->ID == originalID) {
                if (type == "ID") temp->ID = id;
                else if (type == "Name") temp->Name = name;
                else if (type == "CGPA") temp->CGPA = cgpa;
                else if (type == "Batch") temp->Batch = batch;
                else if (type == "Department") temp->Department = department;
                return;
            }
            temp = temp->next;
        }
        cout << "--> Student with ID (" << originalID << ") to update in LL not found." << endl;
    }

    // Function to search for a node by ID
    bool search(int id) {
        Node* temp = root;
        while (temp != nullptr) {
            if (temp->ID == id) return true;
            temp = temp->next;
        }
        return false;
    }

    // Function to check if the linked list is empty
    bool isEmpty() {
        return root == nullptr;
    }
};

#endif
