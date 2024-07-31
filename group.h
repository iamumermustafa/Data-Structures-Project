#ifndef GROUP_H
#define GROUP_H

#include "linkedList.h"
#include "BST.h"

// Definition of a node in the group linked list
class groupNode {
public:
    linkedList list;          // Linked list of students in the group
    groupNode* next;          // Pointer to the next group node
    int totalStudents;        // Total number of students in the group
    int groupID;              // Group ID

    // Constructor to initialize the group node
    groupNode() {
        next = nullptr;
        totalStudents = 0;
        groupID = 0;
    }
};

// Definition of the Group class
class Group {
    groupNode* root;          // Root of the group linked list
    int totalGroups;          // Total number of groups
    bool anyGroupPresent;     // Flag to indicate if any group is present

public:
    // Constructor to initialize the Group
    Group() {
        totalGroups = 0;
        this->root = nullptr;
        anyGroupPresent = false;
    }

    // Function to add a new group
    void addNewGroup(int groupID) {
        if (this->search(groupID)) {
            cout << "\n--> Group with ID (" << groupID << ") to create new group, already exists..!!!\n";
            return;
        }

        groupNode* newNode = new groupNode;
        newNode->groupID = groupID;
        newNode->next = this->root;
        this->root = newNode;
        totalGroups++;
        anyGroupPresent = true;
        cout << "\nGroup with ID " << groupID << " is created\n";
    }

    // Function to delete a group
    void deleteGroup(int groupID) {
        if (!this->search(groupID)) {
            cout << "\n--> No Group with ID (" << groupID << ") to delete group..!!!\n";
            return;
        }
        else {
            groupNode* temp = this->root;
            if (this->root->groupID == groupID) {
                this->root = this->root->next;
                delete temp;
            }
            else {
                while (temp->next != nullptr) {
                    if (temp->next->groupID == groupID) {
                        groupNode* temp2 = temp->next;
                        temp->next = temp2->next;
                        delete temp2;
                        break;
                    }
                    temp = temp->next;
                }
            }
            totalGroups--;
            cout << "\nGroup with ID " << groupID << " is deleted\n";
            if (totalGroups == 0) {
                root = nullptr;
                anyGroupPresent = false;
            }
        }
    }

    // Function to add a student to a group
    void addStudent(int id, string name, float cgpa, int batch, string department, int groupID, bool& added) {
        if (!this->search(groupID)) {
            cout << "\nNo group with ID (" << groupID << ") to add a student's data...!!!\n";
            return;
        }

        groupNode* temp = this->root;
        while (temp->next != nullptr && temp->groupID != groupID)
            temp = temp->next;

        temp->list.insert(id, name, cgpa, batch, department);
        temp->totalStudents++;
        added = true;

        cout << "\nStudent with ID " << id << " added in group with ID " << groupID << endl;
    }

    // Function to delete a student from a group
    void deleteStudent(int id, int groupID) {
        if (root == nullptr) return;
        groupNode* temp = this->root;
        while (temp != nullptr) {
            if (temp->groupID == groupID) {
                temp->list.deleteNode(id);
                temp->totalStudents--;
                return;
            }
            temp = temp->next;
        }
        cout << "\n--> No Group with ID (" << groupID << ") to delete a student's data...!!!\n";
    }

    // Function to update a student's information in a group
    void update(int originalID, int id, string name, float cgpa, int batch, string department, int groupID, string type) {
        if (this->root == nullptr) return;

        groupNode* temp = this->root;
        while (temp != nullptr) {
            if (temp->groupID == groupID && type != "Group") {
                temp->list.update(originalID, id, name, cgpa, batch, department, type);
                return;
            }
            temp = temp->next;
        }
        cout << "\n--> No Group with ID (" << groupID << ") to update student's data...!!!\n";
    }

    // Function to change a student's group
    void changeGroup(int id, string name, float cgpa, int batch, string department, int prevGroupID, int newGroupID) {
        if (!this->search(prevGroupID) || !this->search(newGroupID)) {
            cout << "\n--> One of the group ID is invalid..!!!!\n";
            return;
        }
        bool added = false;
        this->deleteStudent(id, prevGroupID);
        this->addStudent(id, name, cgpa, batch, department, newGroupID, added);
    }

    // Function to search for a group by ID
    bool search(int groupID) {
        groupNode* temp = this->root;
        while (temp != nullptr) {
            if (temp->groupID == groupID) return true;
            temp = temp->next;
        }
        return false;
    }

    // Function to display all groups and their students
    void display() {
        if (root == nullptr) {
            cout << "\n--> No groups are currently created..!!!\n";
            return;
        }
        else {
            groupNode* temp = this->root;
            while (temp != nullptr) {
                cout << "\nStudents in Group " << temp->groupID << ": ";
                temp->list.display();
                temp = temp->next;
            }
        }
    }

    // Function to return a pointer to a group node by ID
    groupNode* returnGroupNode(int id) {
        groupNode* temp = root; // Use 'root' instead of 'head'
        while (temp != nullptr) {
            if (temp->groupID == id) return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};

#endif
