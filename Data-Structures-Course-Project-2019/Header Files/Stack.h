#pragma once

#include "LinkedList.h"

class Stack : public LinkedList {
public:
	Stack() { head = NULL; }
	~Stack() {}

	Student Top() {
		if (head == NULL) {
			std::cout << "Stack is Empty" << std::endl;
		}
		else {
			return head->student;
		}
	}
	void push(const Student newStudent) {
		InsertNode(0, newStudent);
	}
	int pop() {
		if (head == NULL) {
			std::cout << "Stack is Empty" << std::endl;
			return -1;
		}
		else {
			int deletedStudentNo = head->student.studentNo;
			DeleteNode(deletedStudentNo);
			return deletedStudentNo;
		}
	}
	void DisplayStack() { 
		int num = 0;
		Node* currNode = head;

		while (currNode != NULL)
		{
			currNode->student.displayStudent("DataStructures");
			currNode = currNode->next;
			num++;
		}
		std::cout << "Number of Nodes: " << num << std::endl;
	}

	string* getDataStructureList(int number) {
		int i = 0;
		string* surnames = new string[number];
		Node* currNode = head;
		while (currNode != NULL)
		{
			if (currNode->student.dataStructuresCount > 0)
			{
				std::cout << surnames[i] << std::endl;
				surnames[i] = currNode->student.studentSurname;
			}
			currNode = currNode->next;
			i++;
		}
		return surnames;
	}

	string* getDataStructureList2(int number) { // It will be edit when the database avl tree is added.
		int i = 0;
		string* names = new string[number];
		Node* currNode = head;
		while (currNode != NULL)
		{
			if (currNode->student.dataStructuresCount > 0)
			{
				std::cout << names[i] << std::endl;
				names[i] = currNode->student.studentName;
			}
			currNode = currNode->next;
			i++;
		}
		return names;
	}
};
