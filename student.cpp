#include "student.h"
#include <iostream>

using namespace std;

// Constructor implementation
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
    this->degreeProgram = degreeProgram;
}

// Part D2a: Accessors
string Student::getStudentID() const { 
    return studentID; 
}
string Student::getFirstName() const { 
    return firstName; 
}
string Student::getLastName() const { 
    return lastName; 
}
string Student::getEmailAddress() const { 
    return emailAddress; 
}
int Student::getAge() const { 
    return age; 
}
const int* Student::getDaysInCourse() const { 
    return daysInCourse; 
}
DegreeProgram Student::getDegreeProgram() const { 
    return degreeProgram; 
}

// Part D2b: Mutators
void Student::setStudentID(string studentID) { 
    this->studentID = studentID; 
}
void Student::setFirstName(string firstName) { 
    this->firstName = firstName; 
}
void Student::setLastName(string lastName) { 
    this->lastName = lastName; 
}
void Student::setEmailAddress(string emailAddress) { 
    this->emailAddress = emailAddress; 
}
void Student::setAge(int age) { 
    this->age = age; 
}
void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { 
    this->degreeProgram = degreeProgram; 
}

// Part D2e: Print function implementation
void Student::print() const {
    cout << "Student ID: " << studentID
         << "\t First Name: " << firstName
         << "\t Last Name: " << lastName
         << "\t Age: " << age
         << "\t daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}"
         << "\t Degree Program: " << (degreeProgram == SECURITY ? "Security" : degreeProgram == NETWORK ? "Network" : "Software")
         << endl;
}
