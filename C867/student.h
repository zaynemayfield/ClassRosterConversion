#pragma once
#include <iostream>
#include "degree.h"
#include <string>
using namespace std;
//Create Student class to handle everything with students
class Student
{
private:
    //attributes (D1) are private (D2c)
    std::string ID, firstName, lastName, email;
    size_t age;
    DegreeProgram program;
    int daysToCompleteCourse[3];

public:
    //Constructors
    Student();
    //COnstructor (D2d)
    Student(string studentData);

    //Destructor
    ~Student();

    //Accessors (D2a)
    string getID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int * getDaysToCompleteCourse();
    DegreeProgram getProgram();

    //Print Specific student (D2e)
    void print();
    void printInvalidEmails();

    //Mutators (D2b)
    void setID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDaysToCompleteCourse(int daysToCompleteCourse[]);
    void setProgram(DegreeProgram program);
};

