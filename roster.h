#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

class Roster {
private:
    int lastIndex;
    int capacity;
    Student** classRosterArray; // Part E1 : array of pointers "classRosterArray"

public:
    // Constructor and destructor
    Roster(int capacity);
    ~Roster();

    // Function declarations
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);

    // Getter for classRosterArray
    Student** getClassRosterArray() const { return classRosterArray; }
};

#endif 

