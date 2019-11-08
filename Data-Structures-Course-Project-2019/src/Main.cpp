#include <iostream>
#include <string>
#include "../Header Files/LinkedList.h"
#include "../Header Files/Sorting.h"

//This is for student linked list.
LinkedList list;

void writeOperations();
void addStudentWith(int nodeCount, int studentNo, std::string studentName, std::string studentSurname, std::string studentDepartment);
void addExampleStudentList();

int main() {
	//This variable for take selection number 
	int selection;
	//This variable for control node number of student list 
	int studentListNodes = 0;
	int numberOfNodes = 0;
	//This variables for stored student credentials
	int studentNo;
	std::string studentName, studentSurname, studentDepartment;

	//While for application menu
	while (true) {
		writeOperations();
		numberOfNodes = list.NumberOfNode();
		std::cin >> selection;

		switch (selection)
		{
		case 1:
			std::cout << "\nEnter a student no: " ;
			std::cin >> studentNo;
			std::cout << "\nEnter a student name: " ;
			std::cin >> studentName;
			std::cout << "\nEnter a student surname: " ;
			std::cin >> studentSurname;
			std::cout << "\nEnter a student department: " ;
			std::cin >> studentDepartment;
			
			addStudentWith(studentListNodes, studentNo, studentName, studentSurname, studentDepartment);

			studentListNodes++;
			break;
		case 2:
			std::cout << "\nEnter the number of the student you wish to delete from the student list: ";
			std::cin >> studentNo;

			if (list.DeleteNode(studentNo) != 0) {
				std::cout << "Student deleted from list!!!" << std::endl;
				studentListNodes--;
			}
			else {
				std::cout << "Such a student is not in the student list." << std::endl;
			}
			break;
		case 3:
			std::cout << "\nEnter the number of the student you wish to find from the student list: ";
			std::cin >> studentNo;

			if (list.FindNode(studentNo) != 0) {
				std::cout << "Found Student!!!" << std::endl;
				list.FindStudent(studentNo).displayStudent();
			}
			else {
				std::cout << "Such a student is not in the student list." << std::endl;
			}
			break;

		case 4:
			std::cout << "\nStudent List" << std::endl;
			std::cout << numberOfNodes << std::endl;
			list.DisplayList();
			break;

		case 5:
			std::cout << "\Sorted List" << std::endl;
			if (numberOfNodes == 0)
			{
				std::cout << "\List is empty" << std::endl;
			}
			else
			{
				string* surnames = list.getList(numberOfNodes);
				Radix sort(surnames, numberOfNodes);
				sort.displayRadixSorted();
			}
		case 6:
			addExampleStudentList();
			std::cout << "\Example List has been added" << std::endl;

		default:
			break;
		}

	}

	std::cin.get();
}

//This function for writing operations
void writeOperations() {
	std::cout << "\nOperations" << std::endl;
	std::cout << "1. Add a student to student linked list" << std::endl;
	std::cout << "2. Delete a student from student linked list" << std::endl;
	std::cout << "3. Find a student from student linked list" << std::endl;
	std::cout << "4. Display a student list" << std::endl;
	std::cout << "5. Sort the list with radix in order to surnames"<< std::endl;
	std::cout << "6. Add example list to student linked list" << std::endl;
	std::cout << "Insert your selection: ";
}
//This function takes student credentials and insert to the linked list
void addStudentWith(int nodeCount, int studentNo, std::string studentName, std::string studentSurname, std::string studentDepartment) {
	Student student(studentNo, studentName, studentSurname, studentDepartment);
	list.InsertNode(nodeCount, student);
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


