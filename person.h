#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person {
private:
	string name;
	int age;
public:
	Person(string name, int age) : name{ name }, age{ age } { } //constructor
	Person() { }; //default constructor

	void setName(string name1) {
		name = name1;
	}

	string getName() const {
		return name;
	}

	void setAge(int age1) {
		age = age1;
	}

	int getAge() const {
		return age;
	}
};

#endif
