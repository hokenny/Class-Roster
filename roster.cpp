#include "roster.h"
#include "student.h"
#include <iostream>
#include <sstream>

using namespace std;

// Constructor implementation
Roster::Roster(int capacity) {
    this->capacity = capacity;
    this->lastIndex = -1;
    this->classRosterArray = new Student*[capacity];
}

// Destructor implementation
Roster::~Roster() {
    for (int i = 0; i <= lastIndex; i++) {
        delete classRosterArray[i];
    }
    delete[] classRosterArray;
}

// Part E3a: Add function implementation
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    lastIndex++;
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

// Part E3b: Remove function implementation
void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            delete classRosterArray[i];
            for (int j = i; j < lastIndex; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            lastIndex--;
            cout << "Student ID " << studentID << " removed." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Error: Student ID " << studentID << " was not found." << endl;
    }
}

// Part E3c: Print all students
void Roster::printAll() {
    for (int i = 0; i <= lastIndex; i++) {
        classRosterArray[i]->print();
    }
}

// Part E3d: Print average days in course for a student
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            const int* days = classRosterArray[i]->getDaysInCourse();
            int averageDays = (days[0] + days[1] + days[2]) / 3;
            cout << "Student ID: " << studentID << ", Average Days in Course: " << averageDays << endl;
            return;
        }
    }
    cout << "Error: Student ID " << studentID << " was not found." << endl;
}

// Part E3e: Print invalid emails
void Roster::printInvalidEmails() {
    for (int i = 0; i <= lastIndex; i++) {
        string email = classRosterArray[i]->getEmailAddress();
        if (email.find('@') == string::npos || email.find('.') == string::npos || email.find(' ') != string::npos) {
            cout << email << endl;
        }
    }
}

// Part E3f: Print students by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}
