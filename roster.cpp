/* 
 * File:   roster.cpp
 * Author: Parker Lee
 *
 * Created on January 7, 2020, 10:31 AM
 */

#define ARRAY_LENGTH 5

#include "degree.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "roster.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

// Function that adds student to Roster object
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int num1, int num2, int num3, Degree degree) {
    int nums[3] = {num1, num2, num3};

    switch (degree) {
        case 0:
            classRosterArray[iterator++] = new SecurityStudent(studentID, firstName, lastName, email, age, nums, degree);
            break;
        case 1:
            classRosterArray[iterator++] = new NetworkStudent(studentID, firstName, lastName, email, age, nums, degree);
            break;
        case 2:
            classRosterArray[iterator++] = new SoftwareStudent(studentID, firstName, lastName, email, age, nums, degree);
            break;
        default:
            cout << "Student could not be added to the database." << endl;
    }
}

// Function that removes a student from Roster object based on studentID parameter
void Roster::remove(string studentID) {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        if (classRosterArray[i] != nullptr && studentID == classRosterArray[i]->getStudentID()) {
            classRosterArray[i] = nullptr;
            cout << "Student with ID = " << studentID << " has been removed." << endl;
        } else if (classRosterArray[i] == nullptr) {
            cout << "Student with ID = " << studentID << " does not exist." << endl;
        }
    }
}

// Function that prints studentData based on Degree parameter
void Roster::printByDegreeProgram(Degree degree) {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == SOFTWARE) {
            classRosterArray[i]->print();
        }
    }
}

// Function that prints all studentData in Roster object
void Roster::printAll() {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

// Function that prints average days required for each student to complete a course
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        if (studentID == classRosterArray[i]->getStudentID()) {
            int* nums = classRosterArray[i]->getNumDays();
            double avg = ((double)nums[0] + (double)nums[1] + (double)nums[2]) / 3.0;
            
            cout << fixed << setprecision(1);
            cout << studentID << ": " << avg << " days" << endl;
        }
    }
}

// Function that informs user of invalid email addresses in Roster object
void Roster::printInvalidEmails() {
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        string currentEmail = classRosterArray[i]->getEmail();

        size_t foundAtSymbol = currentEmail.find("@");
        if (foundAtSymbol == string::npos) {
            cout << currentEmail << " ---> Missing '@' character in email" << endl;
        }

        size_t foundPeriod = currentEmail.find(".");
        if (foundPeriod == string::npos) {
            cout << currentEmail << " ---> Missing '.' character in email" << endl;
        }

        size_t foundWhiteSpace = currentEmail.find(" ");
        if (foundWhiteSpace != string::npos) {
            cout << currentEmail << "---> White space not allowed in email" << endl;
        }
    }
}

// Entry point of the program
int main() {
    Roster classRoster;
    Degree degree;
    
    // Student data information
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Parker,Lee,plee75@wgu.edu,24,12,25,54,SOFTWARE"
    };
    
    // Get studentData and store in vector
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        stringstream ss(studentData[i]);

        vector<string> resultVctr;

        while (ss.good()) {
            string subString;
            getline(ss, subString, ',');
            resultVctr.push_back(subString);
        }

        // Change string to Degree type
        if (resultVctr[8] == "SECURITY") {
            degree = Degree::SECURITY;
        }
        if (resultVctr[8] == "SOFTWARE") {
            degree = Degree::SOFTWARE;
        }
        if (resultVctr[8] == "NETWORK") {
            degree = Degree::NETWORK;
        }

        // Add vector results to classRoster object
        classRoster.add(resultVctr[0], resultVctr[1], resultVctr[2], resultVctr[3], stoi(resultVctr[4]), stoi(resultVctr[5]),
                stoi(resultVctr[6]), stoi(resultVctr[7]), degree);
    }
    
    cout << "Course: Scripting and Programming Applications (C867)" << endl;
    cout << "Programming Language Used: C++" << endl;
    cout << "Student ID: 001218750" << endl;
    cout << "Name: Parker Lee" << endl << endl;

    cout << "1. PRINT ROSTER: " << endl;
    classRoster.printAll();
    cout << endl;

    cout << "2. PRINT INVALID EMAIL ADDRESSES: " << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    cout << "3. PRINT AVERAGE TIME TO COMPLETE CLASSES: " << endl;
    for (int i = 0; i < ARRAY_LENGTH; i++) {
        string tempString = "A" + to_string(i + 1);
        classRoster.printAverageDaysInCourse(tempString);
    }
    cout << endl;

    cout << "4. PRINT STUDENTS WITH SOFTWARE DEGREE: " << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    cout << "5. REMOVE STUDENT WITH ID 'A3': " << endl;
    classRoster.remove("A3");
    cout << endl;

    cout << "6. ATTEMPT TO REMOVE STUDENT WITH ID 'A3' AGAIN: " << endl;
    classRoster.remove("A3");
    
    return 0;
}

Roster::~Roster() {}
