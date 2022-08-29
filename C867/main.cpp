// Student Class Roster Project for C867 - Scripting and Programming - Applications\nProgramming Language
// This contains (B) degree.h, student.h, student.cpp, roster.h, roster.cpp, main.cpp

#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"
#include "degree.h"

using namespace std;
int main()
{
    //Student data used to make student objects and stored in class roster Modified with persoanl information (A)
    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Zayne,Mayfield,zmayfie@wgu.edu,35,10,12,14,SOFTWARE" };
    //New student data is used to test creating a new student
    const string newStudentData = "A6,Peter,Mackey,pmack@dump.li, 23,8,6,4,NETWORK";
    //1. Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name. (F1)
    cout << "C867 - Scripting and Programming - Applications\nProgramming Language: C++\nName: Zayne Mayfield" << endl;
    //Create class roaster from the student data (F2)
    Roster classRoster(studentData);
    //Print the class roster (F4a)
    classRoster.printAll();
    //Print out any invalid email addresses (F4b)
    classRoster.printInvalidEmails();
    //print out the average number of days each student takes to complete a course (F4c)
    classRoster.printAverageDaysInCourse();
    //Print students that are in the SOFTWARE degree program (F4d)
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    //Remove student with ID A3 (F4e)
    classRoster.remove("A3");
    //Print the class roster (F4f)
    classRoster.printAll();
    //Remove student with ID A3 (F4g)
    classRoster.remove("A3");
    //End application
    return 0;
}
