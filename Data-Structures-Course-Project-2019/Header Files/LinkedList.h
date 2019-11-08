#pragma once

#include <iostream>
#include <string>
#include "Student.h"

using std::string;

struct Node {
	Student student;
	Node* next;
	Node(int no, std::string name, std::string surname, std::string department): student(no, name, surname, department) {}
};

class LinkedList {

private:
	Node* head;
	friend class Stack;

public:
	LinkedList() {
		head = NULL;
	}
	~LinkedList() {}

	bool isEmpty() { return head == NULL; }

	Node* InsertNode(int index, Student newStudent) {
		if (index < 0) { return NULL; }

		int currentIndex = 1;
		Node* currNode = head;

		while (currNode && index > currentIndex) {
			currNode = currNode->next;
			currentIndex++;
		}

		if (index > 0 && currNode == NULL) { return NULL; }

		Node* newNode = new Node(newStudent.studentNo, newStudent.studentName, newStudent.studentSurname, newStudent.studentDepartment);
		newNode->student = newStudent;

		if (index == 0) {
			newNode->next = head;
			head = newNode;
		}
		else {
			newNode->next = currNode->next;
			currNode->next = newNode;
		}

		return newNode;
	}

	int FindNode(int studentNo) {
		Node* currNode = head;
		int currentIndex = 1;

		while (currNode && currNode->student.studentNo != studentNo)
		{
			currNode = currNode->next;
			currentIndex++;
		}

		if (currNode) { return currentIndex; }

		return 0;
	}

	Student FindStudent(int studentNo) {
		Node* currNode = head;
		int currentIndex = 1;

		while (currNode && currNode->student.studentNo != studentNo)
		{
			currNode = currNode->next;
			currentIndex++;
		}

		if (currNode) { return currNode->student; }
		
	}

	int DeleteNode(int studentNo) {
		Node* prevNode = NULL;
		Node* currNode = head;
		int currentIndex = 1;

		while (currNode && currNode->student.studentNo != studentNo)
		{
			prevNode = currNode;
			currNode = currNode->next;
			currentIndex++;
		}

		if (currNode) {
			if (prevNode) {
				prevNode->next = currNode->next;
				delete currNode;
			}
			else
			{
				head = currNode->next;
				delete currNode;
			}
			return currentIndex;
		}
		return 0;
	}

	void DisplayList() {
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

	// Getting number of nodes
	int NumberOfNode()
	{
		int count = 0;
		Node* currNode = head;
		while (currNode != NULL)
		{
			currNode = currNode->next;
			count++;
		}
		return count;
	}


	string* getList(int number) {
		int i = 0;
		string* names = new string[number];
		Node* currNode = head;
		while (currNode != NULL)
		{
			names[i] = currNode->student.studentSurname;
			currNode = currNode->next;
			i++;
		}
		return names;
	}

};

