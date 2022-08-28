#pragma once
#include <string>
#include "student.h"
using namespace std;
//Create class Roster to handle everything with the class roster (E)
class Roster
{
private:
    //Array of points that hold student objects (E1)
    Student* classRosterArray[5];

public:
    //Constructors
    Roster();
    Roster(const string studentData[]);

    //Destructor
    ~Roster();

    //Methods
    void nullArray();
    void add(string studentRecord);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse();
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram program);
    size_t getRosterLength();
    bool notNull(Student* student);
};

