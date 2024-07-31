#include"studyGroup.h"


void showMenu() {
	cout << "\n* Press 1 to enter a student's data\n";
	cout << "* Press 2 to update a student's data\n";
	cout << "* Press 3 to delete a student's data\n";
	cout << "* Press 4 to create groups\n";
	cout << "* Press 5 to add a Student to Groups\n";
	cout << "* Press 6 to delete a study group\n";
	cout << "* Press 7 to display all student's data\n";
	//cout << "* Press 8 to display student's data with no groups\n";
	cout << "* Press 8 to display all group's data\n";
	cout << "* Press 0 to exit\n";
};


int main() {
	studyGroups groups;

	/*Group group;
	group.addNewGroup(1);
	group.addNewGroup(2);
	bool blah;
	group.addStudent(1, "Omer", 2.3, 22, "CS", 1, blah);
	group.addStudent(2, "Omer", 2.3, 22, "CS", 1, blah);
	group.display();
	group.deleteStudent(1, 1);
	group.display();
	group.changeGroup(2, "Omer", 2.3, 22, "CS", 1, 2);
	group.display();*/

	cout << "----------------------Student Study Groups Creator----------------------" << endl;

	/*BST bst;
	bst.insert(1, "Omer", 2.4, 23, "asd");
	bst.insert(2, "Omer", 2.4, 23, "asd");
	bst.insert(3, "Omer", 2.4, 23, "asd");
	bst.insert(4, "Omer", 2.4, 23, "asd");

	bst.displayAll();
	cout << endl << bst.haveNoGroup(1) << endl << endl;
	bst.update(5, 1, "ad", 2.4, 23, "234", 4, "Group");
	bst.displayAll();*/

	while (1) {
		showMenu();
		int input;
		cout << "\n--} Enter your choice: ";
		cin >> input;

		if (input == 0) break;
		else if (input == 1) {
			groups.insert();
		}

		else if (input == 2) {
			groups.updateStudentData();
		}

		else if (input == 3) {
			groups.deleteStudentData();
		}

		else if (input == 4) {
			cout << endl << "* Press 1 to create groups automatically\n";
			cout << "* Press 2 to create groups manually\n";

			while (1) {
				cout << "--} Enter input: ";
				cin >> input;

				if (input == 1) {
					// call automatically group creating function
					groups.addStudentsToGroupsAutomatically();
					break;
				}
				else if (input == 2) {
					groups.createNewGroupManually();
					break;
				}
				else cout << "\n--> Invalid Input...!!!\n";
			}
		}

		else if (input == 5) {
			groups.addStudentsToGroups();
		}

		else if (input == 6) {
			groups.deleteGroup();
		}

		else if (input == 7) {
			groups.displayAll();
		}

		/*else if (input == 8) {
			groups.displayWithNoGroup();
		}*/

		else if (input == 8) {
			groups.displayGroups();
		}

		else cout << "\n\n--> Invalid input..!!!!\n\n";
	}
}