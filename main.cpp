#include "roster.h"
#include "student.h"
#include "degree.h"
#include "student.cpp"
#include "roster.cpp"
#include <iostream>
#include <sstream>

using namespace std;

int main() {
    // Part F1: Print course details
    cout << "\nCourse Title: C867 - Scripting and Programming - Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 011472931" << endl;  
    cout << "Name: Kenny Ho\n" << endl << endl;       

    // Part F2: Create an instance of the Roster class called classRoster
    Roster classRoster(5);

    // Part F3: Add each student to classRoster
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Kenny,Ho   ,kho24@wgu.edu,23,35,28,22,SOFTWARE" // Added spaces on my last name to fix the spacing when printing
    };

    for (const auto& data : studentData) {
        istringstream ss(data);
        string token;

        string studentID, firstName, lastName, emailAddress;
        int age, days1, days2, days3;
        DegreeProgram degreeProgram;

        getline(ss, token, ',');
        studentID = token;
        getline(ss, token, ',');
        firstName = token;
        getline(ss, token, ',');
        lastName = token;
        getline(ss, token, ',');
        emailAddress = token;
        getline(ss, token, ',');
        age = stoi(token);
        getline(ss, token, ',');
        days1 = stoi(token);
        getline(ss, token, ',');
        days2 = stoi(token);
        getline(ss, token, ',');
        days3 = stoi(token);
        getline(ss, token, ',');
        if (token == "SECURITY") degreeProgram = SECURITY;
        else if (token == "NETWORK") degreeProgram = NETWORK;
        else if (token == "SOFTWARE") degreeProgram = SOFTWARE;
        else;

        classRoster.add(studentID, firstName, lastName, emailAddress, age, days1, days2, days3, degreeProgram);
    }


    // Part F4: Demonstrate class functionality


    // Print all students
    cout << "All students:" << endl;
    classRoster.printAll();

    // Print invalid emails
    cout << endl << "Invalid emails:" << endl;
    classRoster.printInvalidEmails();

    // Print average days in course for each student
    cout << endl << "Average days in course for each student:" << endl;
    for (int i = 0; i <= 4; i++) {
        classRoster.printAverageDaysInCourse(classRoster.getClassRosterArray()[i]->getStudentID());
    }

    // Print students by degree program: SOFTWARE
    cout << endl << "Students in SOFTWARE program:" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);

    // Remove student by student ID: A3
    cout << endl << "Removing student with ID A3:" << endl;
    classRoster.remove("A3");

    // Print all students after removal
    cout << endl << "All students after removing A3:" << endl;
    classRoster.printAll();

    // Attempt to remove student ID "A3" again
    cout << endl << "Attempting to remove student with ID A3 again:" << endl;
    classRoster.remove("A3");

    // The Roster destructor will be called automatically here as classRoster goes out of scope

    return 0;
}
