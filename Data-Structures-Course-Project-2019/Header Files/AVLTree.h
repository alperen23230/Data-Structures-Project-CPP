#pragma once
#include <iostream>
#include "Student.h"
#include <string>
#include <vector> 

using namespace std;

class AVL
{
	struct node
	{
		Student student;
		node* left;
		node* right;
		int height;
		node(int no, string name, string surname, string department, int databaseManagementSystemCount) : student(no, name, surname, department,databaseManagementSystemCount) {}
	};

	node* root;
	std::vector<string> nameList;
	std::vector<string> surnameList;
	std::vector<int> numberList;

	

	void makeEmpty(node* t)
	{
		if (t == NULL)
			return;
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}

	node* insert(Student newStudent, node* t)
	{
		if (t == NULL)
		{
			t = new node(newStudent.studentNo, newStudent.studentName, newStudent.studentSurname, newStudent.studentDepartment, newStudent.studentdatabaseManagementSystemCount);
			t->height = 0;
			t->left = t->right = NULL;
		}
		else if (newStudent.studentSurname < t->student.studentSurname)
		{
			t->left = insert(newStudent, t->left);
			if (height(t->left) - height(t->right) == 2)
			{
				if (newStudent.studentSurname < t->left->student.studentSurname)
					t = singleRightRotate(t);
				else
					t = doubleRightRotate(t);
			}
		}
		else if (newStudent.studentSurname > t->student.studentSurname)
		{
			t->right = insert(newStudent, t->right);
			if (height(t->right) - height(t->left) == 2)
			{
				if (newStudent.studentSurname > t->right->student.studentSurname)
					t = singleLeftRotate(t);
				else
					t = doubleLeftRotate(t);
			}
		}

		t->height = fmax(height(t->left), height(t->right)) + 1;
		return t;
	}

	node* singleRightRotate(node* &t)
	{
		node* u = t->left;
		t->left = u->right;
		u->right = t;
		t->height = fmax(height(t->left), height(t->right)) + 1;
		u->height = fmax(height(u->left), t->height) + 1;
		return u;
	}

	node* singleLeftRotate(node* &t)
	{
		node* u = t->right;
		t->right = u->left;
		u->left = t;
		t->height = fmax(height(t->left), height(t->right)) + 1;
		u->height = fmax(height(t->right), t->height) + 1;
		return u;
	}

	node* doubleLeftRotate(node* &t)
	{
		t->right = singleRightRotate(t->right);
		return singleLeftRotate(t);
	}

	node* doubleRightRotate(node* &t)
	{
		t->left = singleLeftRotate(t->left);
		return singleRightRotate(t);
	}

	node* findMin(node* t)
	{
		if (t == NULL)
			return NULL;
		else if (t->left == NULL)
			return t;
		else
			return findMin(t->left);
	}

	node* findMax(node* t)
	{
		if (t == NULL)
			return NULL;
		else if (t->right == NULL)
			return t;
		else
			return findMax(t->right);
	}

	node* deleteNode(node* root, string studentSurname)
	{

		// STEP 1: PERFORM STANDARD BST DELETE  
		if (root == NULL)
			return root;

		// If the key to be deleted is smaller  
		// than the root's key, then it lies 
		// in left subtree  
		if (studentSurname < root->student.studentSurname)
			root->left = deleteNode(root->left, studentSurname);

		// If the key to be deleted is greater  
		// than the root's key, then it lies  
		// in right subtree  
		else if (studentSurname > root->student.studentSurname)
			root->right = deleteNode(root->right, studentSurname);

		// if key is same as root's key, then  
		// This is the node to be deleted  
		else
		{
			// node with only one child or no child  
			if ((root->left == NULL) ||
				(root->right == NULL))
			{
				node *temp = root->left ?
					root->left :
					root->right;

				// No child case  
				if (temp == NULL)
				{
					temp = root;
					root = NULL;
				}
				else // One child case  
					*root = *temp; // Copy the contents of  
								   // the non-empty child  
				free(temp);
			}
			else
			{
				// node with two children: Get the inorder  
				// successor (smallest in the right subtree)  
				node* temp = findMin(root->right);

				// Copy the inorder successor's  
				// data to this node  
				root->student = temp->student;

				// Delete the inorder successor  
				root->right = deleteNode(root->right,
					temp->student.studentSurname);
			}
		}

		// If the tree had only one node 
		// then return  
		if (root == NULL)
			return root;

		// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
		root->height = 1 + max(height(root->left),
			height(root->right));

		// STEP 3: GET THE BALANCE FACTOR OF  
		// THIS NODE (to check whether this  
		// node became unbalanced)  
		int balance = getBalance(root);

		// If this node becomes unbalanced,  
		// then there are 4 cases  

		// Left Left Case  
		if (balance > 1 &&
			getBalance(root->left) >= 0)
			return singleRightRotate(root);

		// Left Right Case  
		if (balance > 1 &&
			getBalance(root->left) < 0)
		{
			root->left = singleLeftRotate(root->left);
			return singleRightRotate(root);
		}

		// Right Right Case  
		if (balance < -1 &&
			getBalance(root->right) <= 0)
			return singleLeftRotate(root);

		// Right Left Case  
		if (balance < -1 &&
			getBalance(root->right) > 0)
		{
			root->right = singleRightRotate(root->right);
			return singleLeftRotate(root);
		}

		return root;
	}

	int height(node* t)
	{
		return (t == NULL ? -1 : t->height);
	}

	int getBalance(node* t)
	{
		if (t == NULL)
			return 0;
		else
			return height(t->left) - height(t->right);
	}

	void inorder(node* t)
	{
		if (t == NULL)
			return;
		inorder(t->left);
		t->student.displayStudent("DatabaseManagement");
		inorder(t->right);
	}

	struct node* search(struct node* root, string studentSurname)
	{
		// Base Cases: root is null or key is present at root 
		if (root == NULL || root->student.studentSurname == studentSurname)
			return root;

		// Key is greater than root's key 
		if (root->student.studentSurname < studentSurname)
			return search(root->right, studentSurname);

		// Key is smaller than root's key 
		return search(root->left, studentSurname);
	}

public:
	AVL()
	{
		root = NULL;
	}
	


	void insert(Student x)
	{
		root = insert(x, root);
	}

	node* search(string studentSurname) {
		return search(root, studentSurname);
	}

	void deleteNode(string studentSurname) {
		root = deleteNode(root, studentSurname);
	}

	void display()
	{
		inorder(root);
		cout << endl;
	}


	std::vector<string> getDataManagementNameList()
	{
		nameList.clear();
		getNames(root);
		return nameList;
	}

	AVL* cloneAVL()
	{
		AVL* cloneAVL = new AVL();
		getNodes(root,cloneAVL);

		return cloneAVL;

	}

	void getNodes(node* t,AVL* cloneAVL)
	{
		if (t == NULL)
		{
			return;
		}
		getNodes(t->left,cloneAVL);
		cloneAVL->insert(t->student);
		getNodes(t->right,cloneAVL);
	}


	void getNames(node* t)
	{
		if (t == NULL)
		{
	    return;
		}
		getNames(t->left);
		nameList.push_back(t->student.studentName);
		getNames(t->right);
	}

	std::vector<string> getDataManagementSurnameList()
	{
		surnameList.clear();
		getSurnames(root);
		return surnameList;
	}

	void getSurnames(node* t)
	{
		if (t == NULL)
		{
			return;
		}
		getSurnames(t->left);
		surnameList.push_back(t->student.studentSurname);
		getSurnames(t->right);
	}

	std::vector<int> getDataManagementOtherDepartmentNumberList()
	{
		numberList.clear();
		getOtherDepartmenNumbers(root);
		return numberList;
	}

	void getOtherDepartmenNumbers(node* t)
	{
		if (t == NULL)
		{
			return;
		}
		getOtherDepartmenNumbers(t->left);
		if (t->student.studentDepartment != "bm")
		{
			numberList.push_back(t->student.studentNo);
		}
		getOtherDepartmenNumbers(t->right);
	}

	std::vector<int> getDataManagementMorethanOneNumberList()
	{
		numberList.clear();
		getMorethanOneNumbers(root);
		return numberList;
	}

	void getMorethanOneNumbers(node* t)
	{
		if (t == NULL)
		{
			return;
		}
		getMorethanOneNumbers(t->left);
		if (t->student.studentdatabaseManagementSystemCount > 1)
		{
			numberList.push_back(t->student.studentNo);
		}
		getMorethanOneNumbers(t->right);
	}

	AVL* moreThanOneAVL()
	{
		AVL* moreThanOneAVL = new AVL();
		getMoreThanOneAVL(root, moreThanOneAVL);

		return moreThanOneAVL;

	}

	void getMoreThanOneAVL(node* t, AVL* moreThanOneAVL)
	{
		if (t == NULL)
		{
			return;
		}
		getMoreThanOneAVL(t->left, moreThanOneAVL);
		if (t->student.studentdatabaseManagementSystemCount > 1)
		{
			moreThanOneAVL->insert(t->student);
		}
		getMoreThanOneAVL(t->right, moreThanOneAVL);
	}

	AVL* otherDepartmentAVL()
	{
		AVL* otherDepartmentAVL = new AVL();
		getOtherDepartmentAVL(root, otherDepartmentAVL);

		return otherDepartmentAVL;

	}

	void getOtherDepartmentAVL(node* t, AVL* otherDepartmentAVL)
	{
		if (t == NULL)
		{
			return;
		}
		getOtherDepartmentAVL(t->left, otherDepartmentAVL);
		if (t->student.studentDepartment != "bm")
		{
			otherDepartmentAVL->insert(t->student);
		}
		getOtherDepartmentAVL(t->right, otherDepartmentAVL);
	}



	Stack* AVLToStack()
	{
		Stack* stack = new Stack();
		getAVLToStack(root, stack);

		return stack;

	}

	void getAVLToStack(node* t, Stack* stack)
	{
		if (t == NULL)
		{
			return;
		}
		getAVLToStack(t->left, stack);
		stack->push(t->student);
		getAVLToStack(t->right, stack);
	}



};