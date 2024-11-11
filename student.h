#pragma once
#include <iostream>
#include <string>
#include "person.h"
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student : public Person {
private:
	double GPA;
	int ID;
public:
	Student(string name, int age, double GPA, int ID) : Person(name, age), GPA{ GPA }, ID { ID }  { }; //constructor
	Student() { }; //default constructor

	void setGPA(double GPA1) { //sets private variable equal to temp variable;
		GPA = GPA1;
	}

	double getGPA() const { //returns private variable
		return GPA;
	}

	void setID(int ID1) {
		ID = ID1;
	}

	int getID() const {
		return ID;
	}
};

#endif
