Student Peer Group Formation Console Application
Overview
The Student Peer Group Formation Console Application is designed to manage student data and group formation for a study group setting. This console-based application allows you to perform various operations including adding, updating, and deleting student records, creating and managing study groups, and displaying data.
Features
1.	Add Student Data: Enter new student records into the system.
2.	Update Student Data: Modify existing student records based on their ID.
3.	Delete Student Data: Remove student records from the system.
4.	Create Groups:
○	Automatically: Create groups and distribute students based on their CGPA.
○	Manually: Create groups and add them manually with specified IDs.
5.	Add Students to Groups: Assign students to specific groups.
6.	Delete Groups: Remove a group and reassign students if necessary.
7.	Display Data:
○	All Students: Show all student records.
○	Groups: Show all groups and their associated students.
Instructions
1.	Compiling and Running the Application:
○	Ensure all necessary header files (studyGroup.h, group.h, and any others) are in the same directory.
Compile the code using a C++ compiler (e.g., g++):
css
Copy code
g++ main.cpp -o StudentGroupApp
○	
Run the application:
Copy code
./StudentGroupApp
○	
2.	Using the Application:
○	When the application starts, you will be presented with a menu of options.
○	Enter the number corresponding to the desired operation to execute it.
○	Follow the prompts to input the necessary data.
3.	Menu Options:
○	Press 1: Enter student data.
○	Press 2: Update student data.
○	Press 3: Delete student data.
○	Press 4: Create groups (Choose between automatic or manual creation).
○	Press 5: Add students to groups.
○	Press 6: Delete a group.
○	Press 7: Display all student data.
○	Press 8: Display all group data.
○	Press 0: Exit the application.
4.	Data Entry:
○	For entering student data, provide details such as ID, name, CGPA, batch, and department.
○	For updating data, select the type of information you wish to update and provide new values.
○	For creating and managing groups, follow prompts to add, delete, or view group information.
5.	Error Handling:
○	The application checks for common errors such as duplicate IDs and invalid inputs. Follow the on-screen prompts to correct any issues.

