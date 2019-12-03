#pragma once

#include "LinkedList.h"

class Stack : public LinkedList {
public:
	Stack() { head = NULL; }
	~Stack() {}

	std::vector<int> numberList;
	std::vector<int> otherDepartmentNumberList;


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

	Student popStudent() {

		if (head == NULL) {

		}
		else {
			Student student = head->student;
			DeleteNode(student.studentNo);
			return student;
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
	void DisplayMergedStack() {
		int num = 0;
		Node* currNode = head;

		while (currNode != NULL)
		{
			currNode->student.displayStudent("");
			currNode = currNode->next;
			num++;
		}
		std::cout << "Number of Nodes: " << num << std::endl;
	}

	Stack cloneStack() {
		Stack cloneStack;
		Node* currNode = head;

		while (currNode != NULL)
		{
			cloneStack.push(currNode->student);
			currNode = currNode->next;
		}

		return cloneStack;
	}

	Stack reverseStack() {
		Stack cloneStack;
		Node* currNode = head;

		while (currNode != NULL)
		{
			cloneStack.push(currNode->student);
			currNode = currNode->next;
		}

		return cloneStack;
	}

	Stack moreThanOneStack() {
		Stack moreThanOneStack;
		Node* currNode = head;

		while (currNode != NULL)
		{
			if (currNode->student.dataStructuresCount > 1)
			{
				moreThanOneStack.push(currNode->student);
			}
			currNode = currNode->next;
		}

		return moreThanOneStack;
	}

	Stack otherDepartmentStack() {
		Stack otherDepartmentStack;
		Node* currNode = head;

		while (currNode != NULL)
		{
			if (currNode->student.studentDepartment != "bm" && currNode->student.dataStructuresCount > 0)
			{
				otherDepartmentStack.push(currNode->student);
			}
			currNode = currNode->next;
		}

		return otherDepartmentStack;
	}


	int getNumberOfNode() {
		int num = 0;
		Node* currNode = head;

		while (currNode != NULL)
		{
			currNode = currNode->next;
			num++;
		}
		return num;
	}

	string* getDataStructureNameList(int number) {
		int i = 0;
		string* names = new string[number];
		Node* currNode = head;
		while (currNode != NULL)
		{
			if (currNode->student.dataStructuresCount > 0)
			{
				names[i] = currNode->student.studentName;
			}
			currNode = currNode->next;
			i++;
		}
		return names;
	}

	string* getDataStructureSurnameList(int number) {
		int i = 0;
		string* surnames = new string[number];
		Node* currNode = head;
		while (currNode != NULL)
		{
			if (currNode->student.dataStructuresCount > 0)
			{
				surnames[i] = currNode->student.studentSurname;
			}
			currNode = currNode->next;
			i++;
		}
		return surnames;
	}


	int* getDataStructureNumberList(int number) {
		int i = 0;
		int* numbers = new int[number];
		Node* currNode = head;
		while (currNode != NULL)
		{
			if (currNode->student.dataStructuresCount > 0)
			{
				numbers[i] = currNode->student.studentNo;
			}
			currNode = currNode->next;
			i++;
		}
		return numbers;
	}


	std::vector<int> getDataStructureMorethanOneNumberList() {
		numberList.clear();
		Node* currNode = head;
		while (currNode != NULL)
		{
			if (currNode->student.dataStructuresCount > 1)
			{
				numberList.push_back(currNode->student.studentNo);
			}
			currNode = currNode->next;
		}
		return numberList;
	}

	std::vector<int> getDataStructureOtherDepartmentNumberList() {
		otherDepartmentNumberList.clear();
		Node* currNode = head;
		while (currNode != NULL)
		{
			if (currNode->student.studentDepartment != "bm" && currNode->student.dataStructuresCount > 0)
			{
				otherDepartmentNumberList.push_back(currNode->student.studentNo);
			}
			currNode = currNode->next;
		}
		return otherDepartmentNumberList;
	}

	void swap(int i, int j)
	{
		Stack stack1;
		Stack stack2;


		int x = 1;
		while (x < i)
		{
			stack1.push(popStudent());
			x++;
		}
		Student d1 = popStudent();

		int y = i + 1;
		while (y < j)
		{
			stack2.push(popStudent());
			y++;
		}
		Student d2 = popStudent();

		push(d1);

		while (!stack2.isEmpty())
		{
			push(stack2.popStudent());
		}

		push(d2);

		while (!stack1.isEmpty())
		{
			push(stack1.popStudent());
		}



	}

};
