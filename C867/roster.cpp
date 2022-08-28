#include "roster.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

//default Constructor
Roster::Roster()
{
	//Calls method to set array to nullptr
	nullArray();
	return;
}
//Constructor to take all student data and create student objects and place them inside classRoster array (F3)
Roster::Roster(const string studentData[])
{
	nullArray();

	//Go through each record
	for (size_t i = 0; i < getRosterLength(); i++)
	{
		//Throw each student record to student class to create an object to add to the classRosterArray (E2b)
		Student* newStudent = new Student(studentData[i]);
		classRosterArray[i] = newStudent;
	}
	return;
}
//destructor for roster (F5)
Roster::~Roster()
{
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i];
	}
	cout << "\nDestructor Initialized\n";
	return;
}
//method for making entire array nullptr
void Roster::nullArray()
{
	for (int i = 0; i < 5; ++i) {
		classRosterArray[i] = nullptr;
	}
	return;
}
//method to add a single student to the class roster (E3a)
void Roster::add(string studentRecord)
{
	//Go through each field of the array and check for nullptr and place new student into that field
	for (size_t i = 0; i < getRosterLength(); i++)
	{
		if (!notNull(classRosterArray[i])) {
			Student* newStudent = new Student(studentRecord);
			classRosterArray[i] = newStudent;
			return;
		}
	}
	//If no available space exists in array then inform user
	cout << "\nClass roster is full, unable to add student\n";
	return;
}
//remove student from class roster (E3b)
void Roster::remove(string studentID)
{
	cout << "\nAttempting to remove student with ID " << studentID << " from class roster.";
	//Go through each field of array and check if it is not null then see if the student ID matches, then delete and replace with nullptr
	for (size_t i = 0; i < getRosterLength(); i++) {
		if(notNull(classRosterArray[i])){
			if (this->classRosterArray[i]->getID() == studentID) {
				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				cout << "\nStudent successfully removed from class roster.\n";
				return;
			}
		}
	}
	//If no student ID found then inform user
	cout << "\nStudent with ID " << studentID << " was not found in the class roster.\n";
	return;
	
}
//Print all students from class roster (E3c)
void Roster::printAll()
{
	cout << "\nComplete class roster" << endl;
	//go through each field and have it use the print method on student if it is not null
	for (size_t i = 0; i < getRosterLength(); i++)
	{
		if (notNull(classRosterArray[i])) {
			classRosterArray[i]->print();
		}
		
	}
}
//print the average number of days it take a student to complete a course (E3d)
void Roster::printAverageDaysInCourse()
{
	cout << "\nAverage days to complete a course by Student ID" << endl;
	//go through each field and get ID and days array, adds sums together and divide by 3 to get average
	for (size_t i = 0; i < getRosterLength(); i++)
	{
		if (notNull(classRosterArray[i])) {
			cout << "Student ID: " << classRosterArray[i]->getID() << " averages: ";
			int* arr = classRosterArray[i]->getDaysToCompleteCourse();
			int sum = arr[0] + arr[1] + arr[2];
			int average = sum / 3;
			cout << average << "\n";
		}
	}
}
//print all of the invalid email addresses (E3e)
void Roster::printInvalidEmails()
{
	cout << "\nStudents with an invalid email address" << endl;
	//go through each field and do printInvalidEmails method which will print it out if it is invalid
	for (size_t i = 0; i < getRosterLength(); i++)
	{
		if (notNull(classRosterArray[i])) {
			classRosterArray[i]->printInvalidEmails();
		}
	}
}
//print out students that are in a specific degree program (E3f)
void Roster::printByDegreeProgram(DegreeProgram program)
{
	cout << "\nStudents by Degree Program: ";
	if (program == DegreeProgram::NETWORK) {
		cout << "Network\n";
	}
	else if (program == DegreeProgram::SECURITY) {
		cout << "Security\n";
	}
	else {
		cout << "Software\n";
	}
	//Go thorugh each field and check if the program matches then print that student to console
	for (size_t i = 0; i < getRosterLength(); i++)
	{
		if (notNull(classRosterArray[i])) {
			if (classRosterArray[i]->getProgram() == program) {
				classRosterArray[i]->print();
			}
		}
	}
}
//Gets the length of the array
size_t Roster::getRosterLength()
{
	size_t length = *(&this->classRosterArray + 1) - this->classRosterArray;
	return length;
}
//checks if the field is a nullptr
bool Roster::notNull(Student* student)
{
	if (student != nullptr)
		return true;
	else
		return false;
	
}
