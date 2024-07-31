#ifndef studyGroup_h
#define studyGroup_h

#include "group.h"

class studyGroups {
    Group groups;  // Object to manage groups
    BST bst;       // Binary Search Tree to manage students
    int totalGroups;  // Total number of groups
    int totalStudents;  // Total number of students
    int nullStudents;   // Number of students not assigned to any group

public:
    // Constructor initializes counts to zero
    studyGroups() { totalGroups = 0; totalStudents = 0; nullStudents = 0; }

    // Function to insert new student data
    void insert() {
        int num;
        cout << "\nHow many student's data you want to enter?\n";
        cout << "--} Enter Input: ";
        cin >> num;
        totalStudents += num;
        nullStudents += num;

        for (int i = 0; i < num; ) {
            int id, batch;
            string name, department;
            float cgpa;

            cout << "\n--} Enter ID: "; cin >> id;
            if (bst.search(id)) {
                cout << "--> Student with ID (" << id << ") already exists..!!!!" << endl;
            }
            else {
                cout << "--} Enter Name: "; cin >> name;

                // Input and validate CGPA
                while (1) {
                    cout << "--} Enter CGPA: "; cin >> cgpa;
                    if (cgpa <= 4.0 && cgpa >= 0.0) break;
                    else cout << "\n--> CGPA can only be between 0.0 and 4.0\n\n";
                }

                cout << "--} Enter Batch: "; cin >> batch;

                // Input and validate Department
                while (1) {
                    int input;
                    cout << "\n1. Computer Science\n";
                    cout << "2. Software Engineering\n";
                    cout << "3. Artificial Intelligence\n";
                    cout << "4. Data Science\n";
                    cout << "5. Cyber\n";
                    cout << "6. Robotics\n";
                    cout << "--} Select one Department: "; cin >> input;

                    if (input == 1) { department = "Computer Science"; break; }
                    else if (input == 2) { department = "Software Engineering"; break; }
                    else if (input == 3) { department = "Artificial Intelligence"; break; }
                    else if (input == 4) { department = "Data Science"; break; }
                    else if (input == 5) { department = "Cyber"; break; }
                    else if (input == 6) { department = "Robotics"; break; }
                    else cout << "\n\n--> Choose a valid option..!!!\n\n";
                }

                // Insert the student into the BST
                bst.insert(id, name, cgpa, batch, department);
                i++;
            }
        }
        cout << endl;
    }

    // Function to delete student data
    void deleteStudentData() {
        int id;
        cout << "--} Enter the Student's ID: ";
        cin >> id;
        if (!bst.search(id)) {
            cout << "\n-- > Student with ID ( " << id << ") not found.\n";
            return;
        }
        int gnumber = bst.returnGroupNumber(id);  // Get current group number
        bst.deleteNode(id, nullStudents);  // Remove student from BST
        groups.deleteStudent(id, gnumber);  // Remove student from group
        totalStudents--;
    }

    // Function to update student data
    void updateStudentData() {
        int id;
        cout << "--} Enter the Student's ID: ";
        cin >> id;
        if (!bst.search(id)) {
            cout << "\n-- > Student with ID (" << id << ") not found.\n";
            return;
        }

        int input;
        cout << "\n1. ID\n";
        cout << "2. Name\n";
        cout << "3. CGPA\n";
        cout << "4. Batch\n";
        cout << "5. Department\n";
        cout << "6. Group\n";
        cout << "--} Select one you want to update: "; cin >> input;

        // Update based on user choice
        string type;
        if (input == 1) {
            int newID;
            while (1) {
                cout << "--} Enter new ID: "; cin >> newID;
                if (!bst.search(newID)) break;
                cout << "\n--> Student with ID (" << newID << ") already present..!!!\n";
            }
            bst.update(id, newID, "\0", 0.0, 0, "\0", 0, "ID");
            int gID = bst.returnGroupNumber(id);
            groups.update(id, newID, "\0", 0.0, 0, "\0", gID, "ID");
        }
        else if (input == 2) {
            string newName;
            cout << "--} Enter new Name: "; cin >> newName;
            bst.update(id, 0, newName, 0.0, 0, "\0", 0, "Name");
            int gID = bst.returnGroupNumber(id);
            groups.update(id, 0, newName, 0.0, 0, "\0", gID, "Name");
        }
        else if (input == 3) {
            float newCGPA;
            while (1) {
                cout << "--} Enter new CGPA: "; cin >> newCGPA;
                if (newCGPA >= 0.0 && newCGPA <= 4.0) break;
                cout << "\n--> CGPA can only be between 0.0 and 4.0\n";
            }
            bst.update(id, 0, "\0", newCGPA, 0, "\0", 0, "CGPA");
            int gID = bst.returnGroupNumber(id);
            groups.update(id, 0, "\0", newCGPA, 0, "\0", gID, "CGPA");
        }
        else if (input == 4) {
            int newBatch;
            cout << "--} Enter new Batch: "; cin >> newBatch;
            bst.update(id, 0, "\0", 0.0, newBatch, "\0", 0, "Batch");
            int gID = bst.returnGroupNumber(id);
            groups.update(id, 0, "\0", 0.0, newBatch, "\0", gID, "Batch");
        }
        else if (input == 5) {
            string newDepartment;
            cout << "--} Enter new Department: "; cin >> newDepartment;
            bst.update(id, 0, "\0", 0.0, 0, newDepartment, 0, "Department");
            int gID = bst.returnGroupNumber(id);
            groups.update(id, 0, "\0", 0.0, 0, newDepartment, gID, "Department");
        }
        else if (input == 6) {
            int newGroupID;
            groups.display();
            cout << "--} Enter new GroupID: "; cin >> newGroupID;
            BSTNode* node = bst.returnNode(id);

            if (node == nullptr) return;
            int gID = bst.returnGroupNumber(id);
            bst.update(id, 0, "\0", 0.0, 0, "\0", newGroupID, "Group");
            cout << endl << endl << gID << endl << endl;
            groups.changeGroup(node->ID, node->Name, node->CGPA, node->Batch, node->Department, gID, newGroupID);
        }
        else cout << "\n\n--> Choose a valid option..!!!\n\n";
    }

    // Function to manually create new groups
    void createNewGroupManually() {
        int groupID;
        cout << "\nHow many groups you want to create..??\n";
        int gnum;

        while (1) {
            cout << "\nHow many groups you want to create..??\n";
            cin >> gnum;
            if (gnum > 0) {
                break;
            }
            cout << "Number of groups must be greater than zero. Please try again.\n";
        }

        for (int i = 0; i < gnum; i++) {
            cout << "Enter group ID: "; cin >> groupID;
            if (groups.search(groupID)) {
                cout << "\nGroup with ID (" << groupID << ") already present..!!!!\n";
                return;
            }

            groups.addNewGroup(groupID);
        }
    }

    // Function to add students to groups
    void addStudentsToGroups() {
        cout << "Students with no current groups:-\n";
        this->displayWithNoGroup(); cout << endl;
        int id, groupID; char input;

        cout << "Do you want to create a new Group? (y/n)\n";
        while (1) {
            cout << "Enter Input: "; cin >> input;
            if (input == 'y' || input == 'Y' || input == 'n' || input == 'N') break;
            cout << "--> Enter a valid input..!!!\n";
        }

        if (input == 'y' || input == 'Y') this->createNewGroupManually();

        while (1) {
            cout << "--} Enter the student's ID: "; cin >> id;
            if (bst.haveNoGroup(id)) break;

            cout << "\n--> Enter a student's id with no group...!!!\n";
            bst.displayWithNoGroups(); break;
        }
        while (1) {
            cout << "--} Enter the group's ID: "; cin >> groupID;
            if (groups.search(groupID)) break;

            cout << "\n--> Enter a valid group ID..!!!\n";
            this->displayGroups(); break;
        }
        BSTNode* temp = bst.returnNode(id);
        bool added = false;
        groups.addStudent(temp->ID, temp->Name, temp->CGPA, temp->Batch, temp->Department, groupID, added);
        if (added) {
            bst.update(id, id, "\0", 0.0, 0, "\0", groupID, "Group");
        }
    }

    // Function to delete a group
    void deleteGroup() {
        int groupID;
        cout << "--} Enter Group ID: "; cin >> groupID;
        if (!groups.search(groupID)) {
            cout << "\n--> No Group with ID (" << groupID << ") to delete from studyGroups..!!!!\n";
            return;
        }

        bst.nullGroupNumber(groupID, nullStudents);
        groups.deleteGroup(groupID);
    }

    // Function to automatically add students to groups based on CGPA
    void addStudentsToGroupsAutomatically() {
        int numGroups;
        while (1) {
            cout << "\nHow many groups you want to create..??\n";
            cin >> numGroups;
            if (numGroups > 0) {
                break;
            }
            cout << "Number of groups must be greater than zero. Please try again.\n";
        }

        // Create an array to hold the students
        const int maxStudents = 100; // Assuming a maximum of 100 students
        BSTNode* students[maxStudents];
        int numStudents = 0;

        // Collect all students
        bst.collectStudents(bst.returnRoot(), students, numStudents);

        // Sort students by CGPA in descending order
        bst.bubbleSort(students, numStudents);

        // Create groups
        for (int i = 1; i <= numGroups; ++i) {
            groups.addNewGroup(i);
        }

        // Distribute students into groups
        for (int i = 0; i < numStudents; ++i) {
            if (students[i]->groupNumber != 0) {
                // Skip students already in a group
                continue;
            }

            int groupID = (i % numGroups) + 1;
            bool added = false;
            groups.addStudent(students[i]->ID, students[i]->Name, students[i]->CGPA, students[i]->Batch, students[i]->Department, groupID, added);

            if (added) {
                cout << students[i]->ID << endl;
                bst.update(students[i]->ID, 0, "", 0, 0, "", groupID, "Group");
                nullStudents--;
            }
        }

        cout << "\n--> Groups created and students assigned automatically based on CGPA.\n";
    }

    // Display all students
    void displayAll() { bst.displayAll(); }

    // Display students with no group
    void displayWithNoGroup() { bst.displayWithNoGroups(); }

    // Display all groups
    void displayGroups() { groups.display(); }
};

#endif
