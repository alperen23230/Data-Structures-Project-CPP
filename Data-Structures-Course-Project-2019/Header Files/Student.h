#pragma once

#include <string>

struct Student {
	int studentNo;
	std::string studentName;
	std::string studentSurname;
	std::string studentDepartment;
	int dataStructuresCount;
	int databaseManagementSystemCount;
	std::string groupByNo;
	std::string groupBySurname;
	
	//Constructor of struct
	Student(int no, std::string name, std::string surname, std::string department) {
		dataStructuresCount = 0;
		databaseManagementSystemCount = 0;
		studentNo = no;
		studentName = name;
		studentSurname = surname;
		studentDepartment = department;
		groupByNo = FindNoGroup(no);
		groupBySurname = FindSurnameGroup(surname);
	}

private:
	//This char arrays for find student surname group
	char AGroup[22] = {'A','a','b','B','c','C','d','D','e','E','f','F','g','G','h','H','i','I','j','J','k','K' };
	char BGroup[30] = { 'l','L','m','M','n','N','o','O','p','P','q','Q','r','R','s','S','t','T','u','U','v','V','w','W','y','Y','x','X','z','Z' };
	
	//This function for find no group of student. It takes student no as a parameter and return group
	std::string FindNoGroup(int studentNo) {
		if (studentNo % 2 == 0)
			return "B";
		else
			return "A";
	}
	//This function for find surname group of student. It takes student surname as a parameter and return group 
	std::string FindSurnameGroup(std::string studentSurname) {

		for (int i = 0;i < 22;i++) {
			char wantedChar = AGroup[i];

			if (studentSurname.at(0) == wantedChar) {
				return "A";
			}
		}

		for (int i = 0;i < 30;i++) {
			char wantedChar = BGroup[i];

			if (studentSurname.at(0) == wantedChar) {
				return "B";
			}
		}
	}
};