#include "student.h"
#include <vector>
#include <sstream>
#include <regex>
using namespace std;

//Default constructor
Student::Student()
{
	this->ID = "blank";
	this->firstName = "blank";
	this->lastName = "blank";
	this->email = "blank";
	this->age = 0;
	this->daysToCompleteCourse[0] = 0;
	this->daysToCompleteCourse[1] = 0;
	this->daysToCompleteCourse[2] = 0;
	this->program = DegreeProgram::NETWORK;
	cout << daysToCompleteCourse[1] << "\n\n\n";
}
//Constructor for creating a student
Student::Student(string studentData)
{
	//Create vector to store data while parsing the string
	vector<string> studentInfo;
	stringstream sr(studentData);
	//seperate out properties in studentData string in vector (E1a)
	while (sr.good()) {
		string property;
		getline(sr, property, ',');
		studentInfo.push_back(property);
	}
	//put data from vector into each attribute
	this->ID = studentInfo.at(0);
	this->firstName = studentInfo.at(1);
	this->lastName = studentInfo.at(2);
	this->email = studentInfo.at(3);
	this->age = stoi(studentInfo.at(4));
	this->daysToCompleteCourse[0] = stoi(studentInfo.at(5));
	this->daysToCompleteCourse[1] = stoi(studentInfo.at(6));
	this->daysToCompleteCourse[2] = stoi(studentInfo.at(7));
	if (studentInfo.at(8) == "SECURITY") {
		this->program =  DegreeProgram::SECURITY;
	}
	else if (studentInfo.at(8) == "NETWORK") {
		this->program = DegreeProgram::NETWORK;
	}
	else {
		this->program = DegreeProgram::SOFTWARE;
	}
	return;
}
//desctructor for student (F5)
Student::~Student()
{
	cout << "\nInitializing Destructor for " << firstName << " " << lastName << "\n";
	return;
}
//Get student ID
string Student::getID()
{
	return ID;
}
//Get student first name
string Student::getFirstName()
{
	return firstName;
}
//Get student last name
string Student::getLastName()
{
	return lastName;
}
//Get student email address
string Student::getEmail()
{
	return email;
}
//Get student age
int Student::getAge()
{
	return age;
}
//Get student number of days to complete 3 courses
int * Student::getDaysToCompleteCourse()
{
	return daysToCompleteCourse;
}
//Get the degree program the student is in
DegreeProgram Student::getProgram()
{
	return program;
}
//print student information to console
void Student::print()
{
	cout << ID << "\t";
	cout << "First Name: " << firstName << "\t";
	cout << "Last Name: " << lastName << "\t";
	cout << "Age: " << age << "\t";
	cout << "daysInCourse: {";
	for (auto d : daysToCompleteCourse)
		cout << d << ", ";
	cout << "}\t";
	cout << "Degree Program: ";
	if (program == DegreeProgram::NETWORK) {
		cout << "Network";
	}
	else if (program == DegreeProgram::SECURITY) {
		cout << "Security";
	}
	else {
		cout << "Software";
	}
	cout << "\n";
}
//print invalid student email addresses
void Student::printInvalidEmails()
{
	//set the regex pattern looking for any characters any amount of times \w+ then checks for . or _ optional then the @ symbol then more characters then checks for . and then more characters
	const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	if (!regex_match(this->email, pattern)) {
		cout << "Invalid email: " << this->email << "\tfrom: " << this->firstName << " " << this->lastName << endl;
	}
	return;
}
//set studet ID
void Student::setID(string ID)
{
	this->ID = ID;
	return;
}
//Set student first name
void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
	return;
}
//Set student last name
void Student::setLastName(string lastName)
{
	this->lastName = lastName;
	return;
}
//Set student email address
void Student::setEmail(string email)
{
	this->email = email;
	return;
}
//Set student age
void Student::setAge(int age)
{
	this->age = age;
	return;
}
//Set new days to complete 3 courses
void Student::setDaysToCompleteCourse(int daysToCompleteCourse[])
{
	for (size_t i{ 0 }; i < 3; i++)
		this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	return;
}
//Set new degree program
void Student::setProgram(DegreeProgram program)
{
	this->program = program;
	return;
}
