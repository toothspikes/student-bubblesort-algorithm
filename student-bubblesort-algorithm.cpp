#include <iostream>
#include <cstdlib> //srand
#include <ctime> //time
#include <iomanip> //for setprecision
#include <vector> //(personal notes to look back on) IF YOU DONT HAVE A CONSTANT SIZE FOR THE ARRAY PLEASE USE A VECTOR!!!!!!
#include "person.h"
#include "student.h"
using namespace std;

//functions prototypes
int randomAge();
double randomGPA();
int randomID();
void outputStudents(const vector<Student>&);
void bubbleSort(vector<Student>&);

int main() {
	srand(time(0)); //using time for random seed
	int size = 0; //size for the vector

	//first get input from user for size of array
	cout << "How many students are in the class?: " << endl;
	cin >> size;

	//temporary vector to store names before loading them into students object
	vector<string> tempNames;
	for (int i = 0; i < size; i++) {
		string tempName;
		cout << "Student #" << i + 1 << " name: " << endl;
		cin >> tempName;
		tempNames.push_back(tempName);
	}

	//creating a vector of objects and loading it with Student constructor
	vector<Student> students;
	for (int i = 0; i < size; i++) {
		students.push_back(Student(tempNames[i], randomAge(), randomGPA(), randomID()));
	}

	//all the output and sorting
	outputStudents(students);
	cout << endl << endl << "Sorting..." << endl << endl;
	bubbleSort(students);
	outputStudents(students);
	return 0;
}

//random age
int randomAge() {
	int randomAge = rand() % 12 + 20;
	return randomAge;
}

//random gpa
double randomGPA() {
	double minGPA = 0.0;
	double maxGPA = 4.0;
	double randomGPA = minGPA + (maxGPA - minGPA) * (double)rand() / RAND_MAX;
	return randomGPA;
}

//random id
int randomID() {
	int randomID = rand() % 8999 + 1000;
	return randomID;
}

//output from vector of objects
void outputStudents(const vector<Student>& students) {
	cout << "         Students: " << endl;
	for (int i = 0; i < students.size(); i++) {
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Name: " << students[i].getName() << endl;
		cout << "Age:  " << students[i].getAge() << endl;
		//without if statements for the GPA, setprecision(2) will display 1.1 or 0.11, and setprecision(3) will show 1.11 or 0.111
		//if statement guarantees there will always be 2 decimal places in this case
		if (students[i].getGPA() < 1) {
			cout << "GPA:  " << setprecision(2) << students[i].getGPA() << endl;
		}
		else {
			cout << "GPA:  " << setprecision(3) << students[i].getGPA() << endl;
		}
		cout << "ID#:  " << students[i].getID() << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}
}

//BubbleSort: start from the beginning of the array. Compare 2 elements at a time and swap if need be.
//After the first pass through the array, the last number will be in the right position.
//Continue however many times it takes to finish sorting.
void bubbleSort(vector<Student>& students) {
	int SIZE = students.size();

	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = 0; j < SIZE - i - 1; j++) {
			if (students[j].getGPA() < students[j + 1].getGPA()) {
				swap(students[j], students[j + 1]);
			}
		}
	}
}
