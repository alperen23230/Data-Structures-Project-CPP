#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cctype>
#include "../Header Files/LinkedList.h"
#include "../Header Files/Stack.h"
#include "../Header Files/Sorting.h"
#include "../Header Files/AVLTree.h"

// This is for getting students which are taking data structure class
LinkedList willAddstudent;
//This is for student linked list.
LinkedList studentList;
//This is for Data Structures and Algorithms Course list (Stack).
Stack dataStructuresStack;
//This is for Database Management Systems Course list (AVL Tree).
AVL databaseAVLTree;

void writeOperations();
void addStudentWith(int nodeCount, int studentNo, std::string studentName, std::string studentSurname, std::string studentDepartment);
void addExampleStudentList();

int main() {
	//This variable for take selection number 
	int selection;
	//This variable for control node number of student list 
	int studentListNodes = 0;
	//This variables for stored student credentials
	int studentNo;
	std::string studentName, studentSurname, studentDepartment;
	//For deletion student
	int deletedStudentNo = 0;
	//This variable stores course take count of student
	int courseTakeCount;
	//This variable for number of nodes
	int numberOfNodes = 0;
	//This stack uses in a deletion of spesific student in stack
	Stack auxStack;
	//This variable uses in a deletion of spesific student in stack
	int auxStudentNo;

	//While for application menu
	while (true) {
		writeOperations();
		numberOfNodes = studentList.numberOfNode();

		std::cin >> selection;

		if (std::cin.fail())
		{
			std::cin.clear(); // clear input buffer to restore cin to a usable state
			std::cin.ignore(INT_MAX, '\n'); // ignore last input
			std::cout << "You can only enter numbers.\n";
			std::cout << "Enter a number.\n";
			std::cin >> selection;
		}

		switch (selection)
		{
		case 1:
			std::cout << "\nEnter a student no: " ;
			std::cin >> studentNo; 
			std::cout << "\nEnter a student name: " ;
			std::cin >> studentName; if (std::any_of(studentName.begin(), studentName.end(), ::isdigit)) { std::cout << "Student name cannot contain digit!"; break; }
			std::cout << "\nEnter a student surname: " ;
			std::cin >> studentSurname; if (std::any_of(studentSurname.begin(), studentSurname.end(), ::isdigit)) { std::cout << "Student surname cannot contain digit!"; break; }
			std::cout << "\nEnter a student department: " ; 
			std::cin >> studentDepartment; if (std::any_of(studentDepartment.begin(), studentDepartment.end(), ::isdigit)) { std::cout << "Student department cannot contain digit!"; break; }

			if (std::cin.fail()) {
				std::cout << "Please insert correctly!";
				break;
			}


			else {
				addStudentWith(studentListNodes, studentNo, studentName, studentSurname, studentDepartment);

				studentListNodes++;
			}
		
			break;
		case 2:
			std::cout << "\nEnter the number of the student you wish to delete from the student list: ";
			std::cin >> studentNo;
			if (std::cin.fail()) {
				std::cout << "Please insert correctly!";
				break;
			}
			else {
				if (studentList.DeleteNode(studentNo) != 0) {
					std::cout << "Student deleted from list!!!" << std::endl;
					studentListNodes--;
				}
				else {
					std::cout << "Such a student is not in the student list." << std::endl;
				}
			}
			
			break;
		case 3:
			std::cout << "\nEnter the number of the student you wish to find from the student list: ";
			std::cin >> studentNo;

			if (std::cin.fail()) {
				std::cout << "Please insert correctly!";
				break;
			}
			else {
				if (studentList.FindNode(studentNo) != 0) {
					std::cout << "Found Student!!!" << std::endl;
					studentList.FindStudent(studentNo).displayStudent("");
				}
				else {
					std::cout << "Such a student is not in the student list." << std::endl;
				}
			}
		
			break;

		case 4:
			std::cout << "\nStudent List" << std::endl;
			studentList.DisplayList();
			break;
		case 5:
			std::cout << "\nEnter the number of the student you want to add to Data Structures Course: ";
			std::cin >> studentNo;
			std::cout << "\nEnter how many times do you take the lesson: ";
			std::cin >> courseTakeCount;
			if (std::cin.fail()) {
				std::cout << "Please insert correctly!";
				break;
			}
			else {
				if (studentList.FindNode(studentNo) != 0) {
					Student willAddstudent = studentList.FindStudent(studentNo);
					willAddstudent.dataStructuresCount = courseTakeCount;
					dataStructuresStack.push(willAddstudent);
					std::cout << "Student added to Data Structures course successfully!";
				}
				else {
					std::cout << "Such a student is not in the student list." << std::endl;
				}
			}
		
			break;
		case 6:
			deletedStudentNo = dataStructuresStack.pop();
			if (deletedStudentNo != -1) {
				std::cout << "Deleted Student!!!" << std::endl;
				studentList.FindStudent(deletedStudentNo).displayStudent("DataStructures");
			}
			break;
		case 7:
			std::cout << "\nEnter the number of the student you wish to delete from the data structures course list: ";
			std::cin >> studentNo;

			if (std::cin.fail()) {
				std::cout << "Please insert correctly!";
				break;
			}
			else {
				if (dataStructuresStack.FindNode(studentNo) != 0) {
					while (!dataStructuresStack.isEmpty())
					{
						deletedStudentNo = dataStructuresStack.pop();
						if (studentNo != deletedStudentNo)
							auxStack.push(studentList.FindStudent(deletedStudentNo));
					}

					while (!auxStack.isEmpty())
					{
						auxStudentNo = auxStack.pop();
						dataStructuresStack.push(studentList.FindStudent(auxStudentNo));
					}
				}
				else if (studentList.FindNode(studentNo) == 0) {
					std::cout << "Such a student is not in the student list." << std::endl;
				}
				else {
					std::cout << "Such a student is not in the data structures course list." << std::endl;
				}
			}
		
			break;
		case 8:
			if (dataStructuresStack.isEmpty()) {
				dataStructuresStack.Top();
			}
			else {
				dataStructuresStack.Top().displayStudent("DataStructures");
			}
			break;
		case 9:
			dataStructuresStack.DisplayStack();
			break;
		case 10:
			addExampleStudentList();
			std::cout << "\nExample List has been added" << std::endl;
			break;
		case 11:
			std::cout << "\nEnter the number of the student you want to add to Database Management System Course: ";
			std::cin >> studentNo;
			std::cout << "\nEnter how many times do you take the lesson: ";
			std::cin >> courseTakeCount;
			if (std::cin.fail()) {
				std::cout << "Please insert correctly!";
				break;
			}
			else {
				if (studentList.FindNode(studentNo) != 0) {
					Student willAddstudent = studentList.FindStudent(studentNo);
					willAddstudent.databaseManagementSystemCount = courseTakeCount;
					databaseAVLTree.insert(willAddstudent);
					std::cout << "Student added to Database Management System course successfully!" <<std::endl;
				}
				else {
					std::cout << "Such a student is not in the student list." << std::endl;
				}
			}
			break;
		case 12:
			std::cout << "\nEnter the surname of the student you want to delete from Database Management System Course: ";
			std::cin >> studentSurname; if (std::any_of(studentSurname.begin(), studentSurname.end(), ::isdigit)) { std::cout << "Student surname cannot contain digit!"; break; }
			if (std::cin.fail()) {
				std::cout << "Please insert correctly!";
				break;
			}
			else {
				 
					if (databaseAVLTree.search(studentSurname) == NULL) {
						std::cout << "Such a student is not in the database management system course list." << std::endl;
					}
					else {
						databaseAVLTree.deleteNode(studentSurname);
						databaseAVLTree.display();
					}
			}
			break;
		case 13:
			std::cout << "\nEnter the surname of the student you want to find from Database Management System Course: ";
			std::cin >> studentSurname; if (std::any_of(studentSurname.begin(), studentSurname.end(), ::isdigit)) { std::cout << "Student surname cannot contain digit!"; break; }
			if (std::cin.fail()) {
				std::cout << "Please insert correctly!";
				break;
			}
			else {
				if (databaseAVLTree.search(studentSurname) == NULL) {
					std::cout << "Such a student is not in the database management system course list." << std::endl;
				}
				else {
					databaseAVLTree.search(studentSurname)->student.displayStudent("DatabaseManagement");
				}
			}
			break;
		case 14:
			databaseAVLTree.display();
			break;
		case 15:
			numberOfNodes = dataStructuresStack.getNumberOfNode();
			if (numberOfNodes == 0)
			{
				std::cout << "\nList is empty" << std::endl;
			}
			else
			{
				std::cout << "\nSorted List" << std::endl;
				string* surnames = dataStructuresStack.getDataStructureSurnameList(numberOfNodes);
				Radix sort(surnames, numberOfNodes);
				sort.sortWithRadix();
				for (size_t i = 0; i < numberOfNodes; i++)
				{
					studentList.displayRadixSortedList(surnames[i]);
				}
			}
			break;
		case 16: 
			numberOfNodes = dataStructuresStack.getNumberOfNode();
			if (numberOfNodes == 0)
			{
				std::cout << "\nList is empty" << std::endl;
			}
			else
			{
				std::cout << "\nSorted List" << std::endl;
				string* names = dataStructuresStack.getDataStructureNameList(numberOfNodes); // It will be edit when the database avl tree is added.				
				Selection sort(names, numberOfNodes);									  // Now it is sorting data structure in order to names.
				sort.sortWithSelection();

				for (size_t i = 0; i < numberOfNodes; i++)
				{
					studentList.displaySelectionSortedList(names[i]);
				}
			}
			break;
		case 17:
			numberOfNodes = dataStructuresStack.getNumberOfNode();
			if (numberOfNodes == 0)
			{
				std::cout << "\nList is empty" << std::endl;
			}
			else
			{
				std::cout << "\Sorted the student list of Data Structures Course with quick sort in order to numbers" << std::endl;
				int* numbers = dataStructuresStack.getDataStructureNumberList(numberOfNodes);
				Quick sort(numbers,numberOfNodes);
				sort.sortWithQuickSort();
				for (size_t i = 0; i < numberOfNodes; i++)
				{
					studentList.displayQuickSortedList(numbers[i]);
				}
			}
			break;
			

			
		default:
			break;
		}

	}

	std::cin.get();
}

//This function for writing operations
void writeOperations() {
	std::cout << "\n\nOperations" << std::endl;
	std::cout << "1. Add a student to student linked list" << std::endl;
	std::cout << "2. Delete a student from student linked list" << std::endl;
	std::cout << "3. Find a student from student linked list" << std::endl;
	std::cout << "4. Display a student list" << std::endl;
	std::cout << "5. Add a student to Data Structures and Algorithms Course (Stack Push)" << std::endl;
	std::cout << "6. Delete a last added student from Data Structures and Algorithms Course (Stack Pop)" << std::endl;
	std::cout << "7. Delete a student from Data Structures and Algorithms Course (Delete student from stack)" << std::endl;
	std::cout << "8. Top student in the Data Structures and Algorithms Course (Stack Top)" << std::endl;
	std::cout << "9. Display Data Structures and Algorithms Course list (Stack Display)" << std::endl;
	std::cout << "10. Add example list to student linked list" << std::endl;
	std::cout << "11. Add a student to Database Management Systems Course (AVL Tree Insertion)" << std::endl;
	std::cout << "12. Delete a student from Database Management Systems Course (AVL Tree Deletion)" << std::endl;
	std::cout << "13. Find a student from Database Management Systems Course (AVL Tree Search)" << std::endl;
	std::cout << "14. Display Database Management Systems Course Students (AVL Tree Display)" << std::endl;
	std::cout << "15. Sort the student list of both courses with radix sort in order to surnames" << std::endl;
	std::cout << "16. Sort the student list of Database Management Course with selection sort in order to names" << std::endl; // It will be edit when the database avl tree is added.
	std::cout << "17. Sort the student list of Data Structures Course with quick sort in order to numbers" << std::endl; // It will be edit when the database avl tree is added.
	std::cout << "Insert your selection: ";
}
//This function takes student credentials and insert to the linked list
void addStudentWith(int nodeCount, int studentNo, std::string studentName, std::string studentSurname, std::string studentDepartment) {
	Student student(studentNo, studentName, studentSurname, studentDepartment);
	studentList.InsertNode(nodeCount, student);
}

void addExampleStudentList()
{
	addStudentWith(0, 15, "ahmet", "akaslan", "bm");
	addStudentWith(1, 12, "mehmet", "akasya", "bm");
	addStudentWith(2, 14, "veli", "unal", "bm");
	addStudentWith(3, 13, "celil", "arici", "ee");
	addStudentWith(4, 11, "alperen", "bayraktar", "bm");
	addStudentWith(5, 10, "kazim", "vali", "bm");
}


