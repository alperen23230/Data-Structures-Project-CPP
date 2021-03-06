#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cctype>
#include <vector> 
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
//Clone stack and sort
Stack sortedStack;

//This is for Database Management Systems Course list (AVL Tree).
AVL databaseAVLTree;


//Clone AVL and sort
AVL sortedAVL;

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
	int courseTakeCount = 0;
	//This variable for number of nodes
	int numberOfNodes = 0;
	//This stack uses in a deletion of spesific student in stack
	Stack auxStack;
	//This variable uses in a deletion of spesific student in stack
	int auxStudentNo;

	AVL moreThanOneAVL;

	Stack moreThanOneStack;

	Stack AVLtoStack;

	Stack mergedStack;

	Stack dataSStack;

	Stack dataMStack;

	AVL otherDepartmentAVL;

	Stack otherDepartmentStack;

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
			std::cout << "\nEnter a student no: ";
			std::cin >> studentNo;
			std::cout << "\nEnter a student name: ";
			std::cin >> studentName; if (std::any_of(studentName.begin(), studentName.end(), ::isdigit)) { std::cout << "Student name cannot contain digit!"; break; }
			std::cout << "\nEnter a student surname: ";
			std::cin >> studentSurname; if (std::any_of(studentSurname.begin(), studentSurname.end(), ::isdigit)) { std::cout << "Student surname cannot contain digit!"; break; }
			std::cout << "\nEnter a student department: ";
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
			std::cout << "\nEnter how many times did you take the lesson: ";
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
						Student deletedStudent = dataStructuresStack.popStudent();
						if (studentNo != deletedStudent.studentNo)
							auxStack.push(deletedStudent);
					}

					while (!auxStack.isEmpty())
					{
						Student auxStudent = auxStack.popStudent();
						dataStructuresStack.push(auxStudent);
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
			std::cout << "\nEnter how many times did you take the lesson: ";
			std::cin >> courseTakeCount;
			if (std::cin.fail()) {
				std::cout << "Please insert correctly!";
				break;
			}
			else {
				if (studentList.FindNode(studentNo) != 0) {
					Student willAddstudent = studentList.FindStudent(studentNo);
					willAddstudent.studentdatabaseManagementSystemCount = courseTakeCount;
					databaseAVLTree.insert(willAddstudent);
					std::cout << "Student added to Database Management System course successfully!" << std::endl;
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
		{
			moreThanOneAVL = *(databaseAVLTree.moreThanOneAVL());

			moreThanOneStack = dataStructuresStack.moreThanOneStack();

			AVLtoStack = *(moreThanOneAVL.AVLToStack());


			if (moreThanOneStack.getNumberOfNode() == 0 || AVLtoStack.getNumberOfNode() == 0)
			{
				std::cout << "\nThere is no common student" << std::endl;
			}
			else
			{
				std::cout << "\n Students of both take classes more than one (with Stack)" << std::endl;


				while (!mergedStack.isEmpty())
				{
					mergedStack.pop();
				}

				while (!moreThanOneStack.isEmpty())
				{
					Student dSNo = moreThanOneStack.popStudent();

					AVLtoStack = *(moreThanOneAVL.AVLToStack());
					while (!AVLtoStack.isEmpty())
					{
						Student dMNo = AVLtoStack.popStudent();

						if (dSNo.studentNo == dMNo.studentNo)
						{
							mergedStack.push(dMNo);
						}

					}
				}

				if (mergedStack.getNumberOfNode() == 0)
				{
					std::cout << "\nThere is no common student" << std::endl;
				}
				else
				{
					mergedStack.DisplayMergedStack();

				}

			}

			


			break;
		}
		case 16:
		{
			std::vector<int> arrDM;
			arrDM = databaseAVLTree.getDataManagementMorethanOneNumberList();

			std::vector<int> arrDS;
			arrDS = dataStructuresStack.getDataStructureMorethanOneNumberList();


			if (arrDM.size() == 0 || arrDS.size() == 0)
			{
				std::cout << "\nThere is no common student" << std::endl;
			}
			else
			{
				std::cout << "\n Students of both take classes more than one (with Array)" << std::endl;

				std::vector<int> numbersVector;

				for (int x : arrDM)
				{
					for (int y : arrDS)
					{
						if (x == y)
						{
							numbersVector.push_back(y);
						}
					}
				}

				if (numbersVector.size() == 0)
				{
					std::cout << "\nThere is no common student" << std::endl;
				}
				else
				{
					for (int x : numbersVector)
					{
						studentList.displayListwithNumber(x);
					}
				}

			}
			break;
		}

		case 17:
		{
			dataSStack = dataStructuresStack.cloneStack();

			dataMStack = *(databaseAVLTree.AVLToStack());

			if (dataMStack.getNumberOfNode() == 0)
			{
				std::cout << "\nList is empty" << std::endl;
			}

			else
			{
				std::cout << "\nStudent list of only Data Management Course (with Stack)" << std::endl;

				bool isOnlyDataManagement = false;

				while (!mergedStack.isEmpty())
				{
					mergedStack.pop();
				}

				if (dataSStack.getNumberOfNode() == 0)
				{
					while (!dataMStack.isEmpty())
					{
						Student dMNo = dataMStack.popStudent();
						mergedStack.push(dMNo);
					}
				}
				else
				{
					while (!dataMStack.isEmpty())
					{
						isOnlyDataManagement = false;
						Student dMNo = dataMStack.popStudent();

						dataSStack = dataStructuresStack.cloneStack();

						while (!dataSStack.isEmpty())
						{
							Student dSNo = dataSStack.popStudent();

							if (dMNo.studentNo == dSNo.studentNo)
							{
								isOnlyDataManagement = false;
								break;
							}
							else isOnlyDataManagement = true;
						}
						if (isOnlyDataManagement)
						{
							mergedStack.push(dMNo);
						}
					}
				}

				if (mergedStack.getNumberOfNode() == 0)
				{
					std::cout << "\nThere is no student who takes only Data Management Course" << std::endl;

				}
				else
				{
					mergedStack.DisplayMergedStack();

				}


			}

			break;
		}

		case 18:
		{
			std::vector<string> arr;
			arr = databaseAVLTree.getDataManagementNameList();
			numberOfNodes = arr.size();

			if (numberOfNodes == 0)
			{
				std::cout << "\nList is empty" << std::endl;
			}
			else
			{
				std::cout << "\nStudent list of only Data Management Course (with Array)" << std::endl;
				string* namesDataManagement = &arr[0];
				int nDManagement = arr.size();

				int nDStructure = dataStructuresStack.getNumberOfNode();;
				string* namesDataStructure = dataStructuresStack.getDataStructureNameList(nDStructure);

				bool isOnlyDataManagement = false;
				std::vector<string> namesVector;

				if (nDStructure == 0)
				{
					for (int i = 0; i < nDManagement; i++)
					{
						namesVector.push_back(namesDataManagement[i]);
					}

				}
				else
				{
					for (int i = 0; i < nDManagement; i++)
					{
						isOnlyDataManagement = false;
						for (int j = 0; j < nDStructure; j++)
						{
							if (namesDataManagement[i] == namesDataStructure[j])
							{
								isOnlyDataManagement = false;
								break;
							}
							else isOnlyDataManagement = true;
						}
						if (isOnlyDataManagement)
						{
							namesVector.push_back(namesDataManagement[i]);
						}
					}
				}

				int nNames = namesVector.size();

				if (nNames == 0)
				{
					std::cout << "\nThere is no student who takes only Data Management Course" << std::endl;

				}
				else
				{
					string* names = &namesVector[0];
					if (nNames == 1)
					{
						studentList.displaySelectionSortedList(names[0]);
					}
					else
					{
						for (size_t i = 0; i < nNames; i++)
						{
							studentList.displaySelectionSortedList(names[i]);
						}
					}
				}


			}
			break;
		}

		case 19:
		{

			otherDepartmentAVL = *(databaseAVLTree.otherDepartmentAVL());

			otherDepartmentStack = dataStructuresStack.otherDepartmentStack();

			AVLtoStack = *(otherDepartmentAVL.AVLToStack());

			if (otherDepartmentStack.getNumberOfNode() == 0 || AVLtoStack.getNumberOfNode() == 0)
			{
				std::cout << "\nThere is no common student" << std::endl;
			}
			else
			{
				std::cout << "\n Students of both take classes but different department (with Stack)" << std::endl;


				while (!mergedStack.isEmpty()) // to clear merged stack if it is not empty
				{
					mergedStack.pop();
				}

				while (!otherDepartmentStack.isEmpty())
				{
					Student dSNo = otherDepartmentStack.popStudent();

					AVLtoStack = *(otherDepartmentAVL.AVLToStack());
					while (!AVLtoStack.isEmpty())
					{
						Student dMNo = AVLtoStack.popStudent();

						if (dSNo.studentNo == dMNo.studentNo)
						{
							mergedStack.push(dMNo);
						}

					}
				}

				if (mergedStack.getNumberOfNode() == 0)
				{
					std::cout << "\nThere is no common student" << std::endl;
				}
				else
				{
					mergedStack.DisplayMergedStack();

				}

			}

			

			break;
		}


		case 20:
		{
			std::vector<int> arrDM;
			arrDM = databaseAVLTree.getDataManagementOtherDepartmentNumberList();

			std::vector<int> arrDS;
			arrDS = dataStructuresStack.getDataStructureOtherDepartmentNumberList();


			if (arrDM.size() == 0 || arrDS.size() == 0)
			{
				std::cout << "\nThere is no common student" << std::endl;
			}
			else
			{
				std::cout << "\n Students of both take classes but different department (with Array)" << std::endl;

				std::vector<int> numbersVector;

				for (int x : arrDM)
				{
					for (int y : arrDS)
					{
						if (x == y)
						{
							numbersVector.push_back(y);
						}
					}
				}

				if (numbersVector.size() == 0)
				{
					std::cout << "\nThere is no common student" << std::endl;
				}
				else
				{
					for (int x : numbersVector)
					{
						studentList.displayQuickSortedList(x);
					}
				}

			}
			break;
		}


		case 21:
		{
			numberOfNodes = dataStructuresStack.getNumberOfNode();
			std::vector<string> arr;
			arr = databaseAVLTree.getDataManagementSurnameList(); // Get Data Management Surname List

			if (arr.size() == 0)
			{
				std::cout << "\nThere is no common student" << std::endl;
			}
			else
			{
				std::cout << "\n Students of both take classes are sorted in order to surnames with Radix Sort" << std::endl;

				string* surnamesDataManagement = &arr[0];
				int nDManagement = arr.size();
				string* surnamesDataStructure = dataStructuresStack.getDataStructureSurnameList(numberOfNodes); // Get Data Structure Surname List
				int nDStructure = numberOfNodes;

				std::vector<string> surnamesVector;

				for (int i = 0; i < nDManagement; i++)
				{

					for (int j = 0; j < nDStructure; j++)
					{
						if (surnamesDataManagement[i] == surnamesDataStructure[j])
						{
							surnamesVector.push_back(surnamesDataStructure[j]);
						}
					}
				}

				int nSurnames = surnamesVector.size();

				if (nSurnames == 0)
				{

					std::cout << "\nThere is no common student" << std::endl;

				}
				else
				{
					string* surnames = &surnamesVector[0];

					Radix sort(surnames, nSurnames);
					sort.sortWithRadix();
					for (size_t i = 0; i < nSurnames; i++)
					{
						studentList.displayRadixSortedList(surnames[i]);
					}
				}

			}
			break;
		}

		case 22:
		{
			dataSStack = dataStructuresStack.cloneStack();

			dataMStack = *(databaseAVLTree.AVLToStack());

			if (dataMStack.getNumberOfNode() == 0)
			{
				std::cout << "\nList is empty" << std::endl;
			}

			else
			{
				std::cout << "\nStudent list of only Data Management Course is sorted with selection sort in order to names (with Stack)" << std::endl;

				bool isOnlyDataManagement = false;

				while (!mergedStack.isEmpty())
				{
					mergedStack.pop();
				}

				if (dataSStack.getNumberOfNode() == 0)
				{
					while (!dataMStack.isEmpty())
					{
						Student dMNo = dataMStack.popStudent();
						mergedStack.push(dMNo);
					}
				}
				else
				{
					while (!dataMStack.isEmpty())
					{
						isOnlyDataManagement = false;
						Student dMNo = dataMStack.popStudent();

						dataSStack = dataStructuresStack.cloneStack();

						while (!dataSStack.isEmpty())
						{
							Student dSNo = dataSStack.popStudent();

							if (dMNo.studentNo == dSNo.studentNo)
							{
								isOnlyDataManagement = false;
								break;
							}
							else isOnlyDataManagement = true;
						}
						if (isOnlyDataManagement)
						{
							mergedStack.push(dMNo);
						}
					}
				}

				numberOfNodes = mergedStack.getNumberOfNode();
				Selection sort(mergedStack, numberOfNodes);

				mergedStack = sort.selectionSortStack();

				mergedStack = mergedStack.reverseStack(); // for reverse stack otherwise they would be sorted bigger to lower

				mergedStack.DisplayMergedStack();
			}

			break;
		}

		case 23:
		{
			std::vector<string> arr;
			arr = databaseAVLTree.getDataManagementNameList();
			numberOfNodes = arr.size();

			if (numberOfNodes == 0)
			{
				std::cout << "\nList is empty" << std::endl;
			}
			else
			{
				std::cout << "\nStudent list of only Data Management Course is sorted with selection sort in order to names (with Array)" << std::endl;
				string* namesDataManagement = &arr[0];
				int nDManagement = arr.size();

				int nDStructure = dataStructuresStack.getNumberOfNode();;
				string* namesDataStructure = dataStructuresStack.getDataStructureNameList(nDStructure);

				bool isOnlyDataManagement = false;
				std::vector<string> namesVector;

				if (nDStructure == 0)
				{
					for (int i = 0; i < nDManagement; i++)
					{
						namesVector.push_back(namesDataManagement[i]);
					}

				}
				else
				{
					for (int i = 0; i < nDManagement; i++)
					{
						isOnlyDataManagement = false;
						for (int j = 0; j < nDStructure; j++)
						{
							if (namesDataManagement[i] == namesDataStructure[j])
							{
								isOnlyDataManagement = false;
								break;
							}
							else isOnlyDataManagement = true;
						}
						if (isOnlyDataManagement)
						{
							namesVector.push_back(namesDataManagement[i]);
						}
					}
				}

				int nNames = namesVector.size();

				if (nNames == 0)
				{
					std::cout << "\nThere is no student who takes only Data Management Course" << std::endl;

				}
				else
				{
					string* names = &namesVector[0];
					if (nNames == 1)
					{
						studentList.displaySelectionSortedList(names[0]);
					}
					else
					{

						Selection sort(names, nNames);
						sort.sortWithSelection();
						for (size_t i = 0; i < nNames; i++)
						{
							studentList.displaySelectionSortedList(names[i]);
						}
					}
				}

			}

			break;
		}
		case 24:
		{
			int sizeStack = dataStructuresStack.getNumberOfNode();

			if (sizeStack == 0)
			{
				std::cout << "\nList is empty" << std::endl;
			}
			else
			{
				std::cout << "\nStudent list of Data Structures Course is sorted with quick sort in order to numbers (with Stack)" << std::endl;

				sortedStack = dataStructuresStack.cloneStack(); // Cloning stack for not changing original stack.
				Quick sort(sortedStack, sizeStack);

				sortedStack = sort.sortWithQuickSortStack();

				sortedStack.DisplayStack();
			}

			break;
		}
		case 25:
			numberOfNodes = dataStructuresStack.getNumberOfNode();
			if (numberOfNodes == 0)
			{
				std::cout << "\nList is empty" << std::endl;
			}
			else
			{
				std::cout << "\nStudent list of Data Structures Course is sorted with quick sort in order to numbers (with Array)" << std::endl;
				int* numbers = dataStructuresStack.getDataStructureNumberList(numberOfNodes);
				Quick sort(numbers, numberOfNodes);
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
	std::cout << "15. Display students who take both classes more than one (with Stack)" << std::endl;
	std::cout << "16. Display students who take both classes more than one (with Array)" << std::endl;
	std::cout << "17. Display students who only take Database Management Systems Course (with Stack)" << std::endl;
	std::cout << "18. Display students who only take Database Management Systems Course (with Array)" << std::endl;
	std::cout << "19. Display students who take both classes but different department (with Stack)" << std::endl;
	std::cout << "20. Display students who take both classes but different department (with Array)" << std::endl;
	std::cout << "21. Sort the student list of both courses with radix sort in order to surnames" << std::endl;
	std::cout << "22. Sort the student list of only Database Management Course with selection sort in order to names (with Stack)" << std::endl;
	std::cout << "23. Sort the student list of only Database Management Course with selection sort in order to names (with Array)" << std::endl;
	std::cout << "24. Sort the student list of Data Structures Course with quick sort in order to numbers (with Stack)" << std::endl;
	std::cout << "25. Sort the student list of Data Structures Course with quick sort in order to numbers (with Array)" << std::endl;
	std::cout << "Insert your selection: ";
}
//This function takes student credentials and insert to the linked list
void addStudentWith(int nodeCount, int studentNo, std::string studentName, std::string studentSurname, std::string studentDepartment) {
	Student student(studentNo, studentName, studentSurname, studentDepartment);
	studentList.InsertNode(nodeCount, student);
}

void addExampleStudentList()
{
	/*addStudentWith(0, 6495, "Abdulhamit", "Akaslan", "bm");
	addStudentWith(1, 6694, "Alperen", "Unal", "bm");
	addStudentWith(2, 6737, "Alperen", "Arici", "ym");
	addStudentWith(3, 6677, "Enes", "Van", "mm");
	addStudentWith(4, 6477, "Kadir", "Ek", "bm");
	addStudentWith(5, 6590, "Emrah", "Batigun", "bm");
	addStudentWith(6, 6457, "Muhammed", "Aytemiz", "ee");
	addStudentWith(7, 6539, "Teyyihan", "Aksu", "bm");*/

	addStudentWith(0, 15, "ahmet", "akaslan", "bm");
	addStudentWith(1, 12, "mehmet", "akasya", "bm");
	addStudentWith(2, 14, "veli", "unal", "bm");
	addStudentWith(3, 13, "celil", "arici", "ee");
	addStudentWith(4, 11, "alperen", "bayraktar", "bm");
	addStudentWith(5, 10, "kazim", "vali", "bm");
	addStudentWith(6, 16, "john", "grosicki", "mm");


}
